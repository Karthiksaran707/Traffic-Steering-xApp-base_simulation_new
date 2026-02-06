//==========================================================================
// gNB.cc - gNodeB Implementation
// Manages radio resources, connections, and handovers
//==========================================================================

#include "gNB.h"
#include "Messages_m.h"

Define_Module(gNB);

gNB::gNB()
{
    loadReportTimer = nullptr;
}

gNB::~gNB()
{
    cancelAndDelete(loadReportTimer);
}

void gNB::initialize()
{
    // Load parameters
    gNBId = par("gNBId");
    posX = par("posX").doubleValue();
    posY = par("posY").doubleValue();
    txPower = par("txPower").doubleValue();
    totalRBs = par("totalRBs");
    maxConnections = par("maxConnections");
    loadThreshold = par("loadThreshold");
    coverageRadius = par("coverageRadius").doubleValue();
    
    // Initialize state
    usedRBs = 0;
    nextTimeSlot = 0;
    nextFrequencySlot = 0;
    
    // Register statistics
    loadSignal = registerSignal("load");
    connectedUEsSignal = registerSignal("connectedUEs");
    handoverOutSignal = registerSignal("handoverOut");
    handoverInSignal = registerSignal("handoverIn");
    
    // Start load reporting timer
    loadReportTimer = new cMessage("loadReportTimer");
    scheduleAt(simTime() + 1.0, loadReportTimer);
    
    EV << "gNB " << gNBId << " initialized at (" << posX << ", " << posY << ")" << endl;
}

void gNB::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage()) {
        if (msg == loadReportTimer) {
            sendLoadReport();
            scheduleAt(simTime() + 1.0, loadReportTimer);
        }
    }
    else if (dynamic_cast<InitialAccessRequest*>(msg)) {
        handleInitialAccessRequest(msg);
        delete msg;
    }
    else if (dynamic_cast<RegistrationRequest*>(msg)) {
        handleRegistrationRequest(msg);
        delete msg;
    }
    else if (dynamic_cast<DataPacket*>(msg)) {
        handleDataPacket(msg);
        // Don't delete - forward to core
    }
    else if (dynamic_cast<MeasurementReport*>(msg)) {
        handleMeasurementReport(msg);
        // Don't delete - forward to RIC
    }
    else if (dynamic_cast<HandoverAck*>(msg)) {
        handleHandoverAck(msg);
        delete msg;
    }
    else if (dynamic_cast<LoadBalanceCommand*>(msg)) {
        handleLoadBalanceCommand(msg);
        delete msg;
    }
    else if (dynamic_cast<PolicyUpdate*>(msg)) {
        handlePolicyUpdate(msg);
        delete msg;
    }
    else if (dynamic_cast<RegistrationResponse*>(msg)) {
        // Forward to UE
        RegistrationResponse *resp = check_and_cast<RegistrationResponse*>(msg);
        int gateIdx = findGateToUE(resp->getUeId());
        if (gateIdx >= 0) {
            send(msg, "ueGate$o", gateIdx);
        } else {
            delete msg;
        }
    }
    else if (dynamic_cast<DataAck*>(msg)) {
        // Forward to UE
        DataAck *ack = check_and_cast<DataAck*>(msg);
        int gateIdx = findGateToUE(ack->getUeId());
        if (gateIdx >= 0) {
            send(msg, "ueGate$o", gateIdx);
        } else {
            delete msg;
        }
    }
    else if (dynamic_cast<HandoverCommand*>(msg)) {
        // Forward to UE
        HandoverCommand *cmd = check_and_cast<HandoverCommand*>(msg);
        int gateIdx = findGateToUE(cmd->getUeId());
        if (gateIdx >= 0) {
            send(msg, "ueGate$o", gateIdx);
        } else {
            delete msg;
        }
    }
    else {
        EV << "gNB " << gNBId << " received unknown message type" << endl;
        delete msg;
    }
}

//==========================================================================
// Initial Access Handling
//==========================================================================

void gNB::handleInitialAccessRequest(cMessage *msg)
{
    InitialAccessRequest *req = check_and_cast<InitialAccessRequest*>(msg);
    
    EV << "gNB " << gNBId << " received Initial Access Request from UE " << req->getUeId() << endl;
    
    InitialAccessResponse *resp = new InitialAccessResponse("InitialAccessResponse");
    resp->setUeId(req->getUeId());
    resp->setGNBId(gNBId);
    
    // Check if we can accept this connection
    bool canAccept = (connectedUEs.size() < (size_t)maxConnections) && 
                     (usedRBs < totalRBs - 5);  // Reserve some RBs
    
    if (canAccept) {
        // Allocate resources
        int rbs, timeSlot, freqSlot;
        allocateResources(req->getUeId(), rbs, timeSlot, freqSlot);
        
        resp->setAccepted(true);
        resp->setAllocatedRBs(rbs);
        resp->setTimeSlot(timeSlot);
        resp->setFrequencySlot(freqSlot);
        
        // Store UE info
        ConnectedUE ueInfo;
        ueInfo.ueId = req->getUeId();
        ueInfo.allocatedRBs = rbs;
        ueInfo.timeSlot = timeSlot;
        ueInfo.frequencySlot = freqSlot;
        ueInfo.signalStrength = req->getSignalStrength();
        ueInfo.connectionTime = simTime();
        ueInfo.packetsReceived = 0;
        connectedUEs[req->getUeId()] = ueInfo;
        
        emit(connectedUEsSignal, (long)connectedUEs.size());
        
        EV << "  Connection ACCEPTED, allocated " << rbs << " RBs" << endl;
    }
    else {
        resp->setAccepted(false);
        EV << "  Connection REJECTED (overloaded)" << endl;
    }
    
    // Find gate to UE and send response
    int numGates = gateSize("ueGate");
    for (int i = 0; i < numGates; i++) {
        // FIXED: Renamed 'gate' to 'outGate'
        cGate *outGate = this->gate("ueGate$o", i);
        if (outGate->isConnected()) {
            cModule *connectedModule = outGate->getPathEndGate()->getOwnerModule();
            if (connectedModule->par("ueId").intValue() == req->getUeId()) {
                send(resp, outGate);
                return;
            }
        }
    }
    delete resp;
}

void gNB::allocateResources(int ueId, int& rbs, int& timeSlot, int& freqSlot)
{
    // Simple resource allocation - allocate 5 RBs per UE
    rbs = 5;
    timeSlot = nextTimeSlot;
    freqSlot = nextFrequencySlot;
    
    usedRBs += rbs;
    nextTimeSlot = (nextTimeSlot + 1) % 10;
    nextFrequencySlot = (nextFrequencySlot + 1) % 20;
}

void gNB::releaseResources(int ueId)
{
    if (connectedUEs.find(ueId) != connectedUEs.end()) {
        usedRBs -= connectedUEs[ueId].allocatedRBs;
        connectedUEs.erase(ueId);
        emit(connectedUEsSignal, (long)connectedUEs.size());
    }
}

//==========================================================================
// Registration Handling
//==========================================================================

void gNB::handleRegistrationRequest(cMessage *msg)
{
    RegistrationRequest *req = check_and_cast<RegistrationRequest*>(msg);
    
    EV << "gNB " << gNBId << " forwarding Registration Request for UE " 
       << req->getUeId() << " to Core Network" << endl;
    
    // Forward to Core Network
    send(req->dup(), "coreGate$o");
}

//==========================================================================
// Data Handling
//==========================================================================

void gNB::handleDataPacket(cMessage *msg)
{
    DataPacket *pkt = check_and_cast<DataPacket*>(msg);
    
    EV << "gNB " << gNBId << " received Data Packet from UE " << pkt->getUeId() << endl;
    
    // Update statistics
    if (connectedUEs.find(pkt->getUeId()) != connectedUEs.end()) {
        connectedUEs[pkt->getUeId()].packetsReceived++;
    }
    
    // Forward to Core Network
    send(msg, "coreGate$o");
}

//==========================================================================
// Measurement and Handover
//==========================================================================

void gNB::handleMeasurementReport(cMessage *msg)
{
    MeasurementReport *report = check_and_cast<MeasurementReport*>(msg);
    
    EV << "gNB " << gNBId << " received Measurement Report from UE " << report->getUeId() << endl;
    
    // Update signal strength
    if (connectedUEs.find(report->getUeId()) != connectedUEs.end()) {
        connectedUEs[report->getUeId()].signalStrength = report->getServingSignalStrength();
    }
    
    // Forward to RIC for analysis
    send(msg, "ricGate$o");
}

void gNB::handleHandoverAck(cMessage *msg)
{
    HandoverAck *ack = check_and_cast<HandoverAck*>(msg);
    
    if (ack->getSuccess()) {
        EV << "gNB " << gNBId << " received Handover ACK from UE " << ack->getUeId() << endl;
        emit(handoverInSignal, 1);
    }
}

void gNB::handleLoadBalanceCommand(cMessage *msg)
{
    LoadBalanceCommand *cmd = check_and_cast<LoadBalanceCommand*>(msg);
    
    EV << "gNB " << gNBId << " received Load Balance Command" << endl;
    EV << "  Moving UE " << cmd->getUeIdToMove() << " to gNB " << cmd->getTargetGNBId() << endl;
    
    initiateHandover(cmd->getUeIdToMove(), cmd->getTargetGNBId(), 1);  // 1 = load balancing
}

void gNB::handlePolicyUpdate(cMessage *msg)
{
    PolicyUpdate *policy = check_and_cast<PolicyUpdate*>(msg);
    
    loadThreshold = policy->getLoadThreshold();
    
    EV << "gNB " << gNBId << " received Policy Update: loadThreshold=" << loadThreshold << endl;
}

void gNB::initiateHandover(int ueId, int targetGNBId, int reason)
{
    EV << "gNB " << gNBId << " initiating handover for UE " << ueId 
       << " to gNB " << targetGNBId << endl;
    
    // Create and send handover command to UE
    HandoverCommand *cmd = new HandoverCommand("HandoverCommand");
    cmd->setUeId(ueId);
    cmd->setSourceGNBId(gNBId);
    cmd->setTargetGNBId(targetGNBId);
    cmd->setReason(reason);
    
    int gateIdx = findGateToUE(ueId);
    if (gateIdx >= 0) {
        send(cmd, "ueGate$o", gateIdx);
        releaseResources(ueId);
        emit(handoverOutSignal, 1);
    } else {
        delete cmd;
    }
}

//==========================================================================
// Load Reporting
//==========================================================================

void gNB::sendLoadReport()
{
    double load = calculateLoad();
    emit(loadSignal, load);
    
    LoadReport *report = new LoadReport("LoadReport");
    report->setGNBId(gNBId);
    report->setCurrentLoad(load);
    report->setConnectedUEs(connectedUEs.size());
    report->setAvailableRBs(totalRBs - usedRBs);
    
    // Calculate average latency (simplified)
    report->setAverageLatency(5.0 + load * 0.1);  // Base latency + load-dependent
    
    EV << "gNB " << gNBId << " Load Report: " << load << "%, " 
       << connectedUEs.size() << " UEs connected" << endl;
    
    send(report, "ricGate$o");
}

double gNB::calculateLoad()
{
    // Load based on resource block utilization
    double rbLoad = (double)usedRBs / totalRBs * 100.0;
    
    // Also consider number of connections
    double connLoad = (double)connectedUEs.size() / maxConnections * 100.0;
    
    // Combined load metric
    return (rbLoad + connLoad) / 2.0;
}

int gNB::findGateToUE(int ueId)
{
    int numGates = gateSize("ueGate");
    for (int i = 0; i < numGates; i++) {
        // FIXED: Renamed 'gate' to 'outGate'
        cGate *outGate = this->gate("ueGate$o", i);
        if (outGate->isConnected()) {
            cModule *connectedModule = outGate->getPathEndGate()->getOwnerModule();
            if (connectedModule->par("ueId").intValue() == ueId) {
                return i;
            }
        }
    }
    return -1;
}

void gNB::finish()
{
    EV << "gNB " << gNBId << " Statistics:" << endl;
    EV << "  Final connected UEs: " << connectedUEs.size() << endl;
    EV << "  Final load: " << calculateLoad() << "%" << endl;
}
