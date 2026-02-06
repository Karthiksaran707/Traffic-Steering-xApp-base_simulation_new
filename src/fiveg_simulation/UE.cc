//==========================================================================
// UE.cc - User Equipment Implementation
// Implements the UE state machine and communication logic
//==========================================================================

#include "UE.h"
#include "Messages_m.h"
#include <cmath>

Define_Module(UE);

UE::UE()
{
    scanTimer = nullptr;
    dataTimer = nullptr;
    measurementTimer = nullptr;
    movementTimer = nullptr;
}

UE::~UE()
{
    cancelAndDelete(scanTimer);
    cancelAndDelete(dataTimer);
    cancelAndDelete(measurementTimer);
    cancelAndDelete(movementTimer);
}

void UE::initialize()
{
    // Load parameters from NED/INI
    ueId = par("ueId");
    posX = par("initialX").doubleValue();
    posY = par("initialY").doubleValue();
    speed = par("speed").doubleValue();
    txPower = par("txPower").doubleValue();
    dataRate = par("dataRate").doubleValue();
    measurementInterval = par("measurementInterval").doubleValue();
    
    // Initialize state
    currentState = IDLE;
    servingGNBId = -1;
    sessionId = -1;
    sequenceNumber = 0;
    handoverCount = 0;
    
    // Channel model parameters (typical 5G NR values)
    pathLossExponent = 3.5;
    shadowingStdDev = 8.0;  // dB
    frequency = 3.5e9;       // 3.5 GHz (n78 band)
    
    // Register statistics
    connectionDelaySignal = registerSignal("connectionDelay");
    throughputSignal = registerSignal("throughput");
    handoverCountSignal = registerSignal("handoverCount");
    
    // Create timers
    scanTimer = new cMessage("scanTimer");
    dataTimer = new cMessage("dataTimer");
    measurementTimer = new cMessage("measurementTimer");
    movementTimer = new cMessage("movementTimer");
    
    // Start by scanning for gNBs
    EV << "UE " << ueId << " initialized at position (" << posX << ", " << posY << ")" << endl;
    scheduleAt(simTime() + uniform(0, 0.1), scanTimer);
    
    // Start movement timer
    scheduleAt(simTime() + 1.0, movementTimer);
}

void UE::handleMessage(cMessage *msg)
{
    // Handle self-messages (timers)
    if (msg->isSelfMessage()) {
        if (msg == scanTimer) {
            currentState = SCANNING;
            scanForGNBs();
        }
        else if (msg == dataTimer) {
            if (currentState == CONNECTED) {
                sendDataPacket();
                scheduleAt(simTime() + 0.1, dataTimer);
            }
        }
        else if (msg == measurementTimer) {
            if (currentState == CONNECTED) {
                sendMeasurementReport();
                scheduleAt(simTime() + measurementInterval, measurementTimer);
            }
        }
        else if (msg == movementTimer) {
            updatePosition();
            scheduleAt(simTime() + 1.0, movementTimer);
        }
    }
    else {
        // Handle incoming messages
        if (dynamic_cast<InitialAccessResponse*>(msg)) {
            InitialAccessResponse *resp = check_and_cast<InitialAccessResponse*>(msg);
            
            if (resp->getAccepted()) {
                EV << "UE " << ueId << " Initial Access ACCEPTED" << endl;
                allocatedRBs = resp->getAllocatedRBs();
                timeSlot = resp->getTimeSlot();
                frequencySlot = resp->getFrequencySlot();
                
                if (currentState == CONNECTING) {
                    currentState = REGISTERING;
                    sendRegistrationRequest();
                }
                else if (currentState == HANDOVER) {
                    servingGNBId = resp->getGNBId();
                    handoverCount++;
                    emit(handoverCountSignal, handoverCount);
                    currentState = CONNECTED;
                    EV << "UE " << ueId << " Handover COMPLETE" << endl;
                    
                    if (!dataTimer->isScheduled())
                        scheduleAt(simTime() + 0.01, dataTimer);
                    if (!measurementTimer->isScheduled())
                        scheduleAt(simTime() + measurementInterval, measurementTimer);
                }
            }
            else {
                currentState = IDLE;
                scheduleAt(simTime() + 1.0, scanTimer);
            }
        }
        else if (dynamic_cast<RegistrationResponse*>(msg)) {
            RegistrationResponse *resp = check_and_cast<RegistrationResponse*>(msg);
            
            if (resp->getAuthenticated()) {
                assignedIP = resp->getIpAddress();
                sessionId = resp->getSessionId();
                currentState = CONNECTED;
                
                simtime_t delay = simTime() - connectionStartTime;
                emit(connectionDelaySignal, delay);
                
                EV << "UE " << ueId << " CONNECTED, IP: " << assignedIP << endl;
                
                scheduleAt(simTime() + 0.1, dataTimer);
                scheduleAt(simTime() + measurementInterval, measurementTimer);
            }
        }
        else if (dynamic_cast<DataAck*>(msg)) {
            DataAck *ack = check_and_cast<DataAck*>(msg);
            EV << "UE " << ueId << " received ACK #" << ack->getSequenceNumber() << endl;
        }
        else if (dynamic_cast<HandoverCommand*>(msg)) {
            HandoverCommand *cmd = check_and_cast<HandoverCommand*>(msg);
            EV << "UE " << ueId << " Handover Command to gNB " << cmd->getTargetGNBId() << endl;
            currentState = HANDOVER;
            cancelEvent(dataTimer);
            performHandover(cmd->getTargetGNBId());
        }
        
        delete msg;
    }
}

//==========================================================================
// Scanning and Initial Access
//==========================================================================

void UE::scanForGNBs()
{
    EV << "UE " << ueId << " scanning..." << endl;
    gNBSignalStrengths.clear();
    
    int numGates = gateSize("radioGate");
    for (int i = 0; i < numGates; i++) {
        // FIXED: Renamed 'gate' to 'outGate' to avoid naming conflict
        cGate *outGate = gate("radioGate$o", i);
        if (outGate->isConnected()) {
            cModule *gnb = outGate->getPathEndGate()->getOwnerModule();
            int gNBId = gnb->par("gNBId");
            double gNBX = gnb->par("posX").doubleValue();
            double gNBY = gnb->par("posY").doubleValue();
            
            double distance = sqrt(pow(posX - gNBX, 2) + pow(posY - gNBY, 2));
            double signal = calculateSignalStrength(distance, txPower);
            gNBSignalStrengths[gNBId] = signal;
            
            EV << "  gNB " << gNBId << ": " << signal << " dBm" << endl;
        }
    }
    
    int bestGNB = selectBestGNB();
    if (bestGNB >= 0) {
        servingGNBId = bestGNB;
        currentState = CONNECTING;
        connectionStartTime = simTime();
        sendInitialAccessRequest();
    }
    else {
        scheduleAt(simTime() + 1.0, scanTimer);
    }
}

int UE::selectBestGNB()
{
    int best = -1;
    double bestSignal = -1000.0;
    for (auto& p : gNBSignalStrengths) {
        if (p.second > bestSignal) {
            bestSignal = p.second;
            best = p.first;
        }
    }
    return best;
}

void UE::sendInitialAccessRequest()
{
    EV << "UE " << ueId << " -> Initial Access Request to gNB " << servingGNBId << endl;
    
    InitialAccessRequest *req = new InitialAccessRequest("InitialAccessRequest");
    req->setUeId(ueId);
    req->setSignalStrength(gNBSignalStrengths[servingGNBId]);
    req->setPosX(posX);
    req->setPosY(posY);
    
    int numGates = gateSize("radioGate");
    for (int i = 0; i < numGates; i++) {
        // FIXED: Renamed 'gate' to 'outGate'
        cGate *outGate = gate("radioGate$o", i);
        if (outGate->isConnected()) {
            cModule *gnb = outGate->getPathEndGate()->getOwnerModule();
            if (gnb->par("gNBId").intValue() == servingGNBId) {
                send(req, outGate);
                return;
            }
        }
    }
    delete req;
}

void UE::sendRegistrationRequest()
{
    EV << "UE " << ueId << " -> Registration Request" << endl;
    
    RegistrationRequest *req = new RegistrationRequest("RegistrationRequest");
    req->setUeId(ueId);
    req->setGNBId(servingGNBId);
    
    char imsi[20];
    sprintf(imsi, "310260%09d", ueId);
    req->setImsi(imsi);
    
    int numGates = gateSize("radioGate");
    for (int i = 0; i < numGates; i++) {
        // FIXED: Renamed 'gate' to 'outGate'
        cGate *outGate = gate("radioGate$o", i);
        if (outGate->isConnected()) {
            cModule *gnb = outGate->getPathEndGate()->getOwnerModule();
            if (gnb->par("gNBId").intValue() == servingGNBId) {
                send(req, outGate);
                return;
            }
        }
    }
    delete req;
}

void UE::sendDataPacket()
{
    EV << "UE " << ueId << " -> Data Packet #" << sequenceNumber << endl;
    
    DataPacket *pkt = new DataPacket("DataPacket");
    pkt->setUeId(ueId);
    pkt->setGNBId(servingGNBId);
    pkt->setSessionId(sessionId);
    pkt->setSequenceNumber(sequenceNumber++);
    pkt->setPacketSize(1500);
    pkt->setTimestamp(simTime().dbl());
    pkt->setSourceIP(assignedIP.c_str());
    pkt->setDestinationIP("10.0.0.1");
    
    int numGates = gateSize("radioGate");
    for (int i = 0; i < numGates; i++) {
        // FIXED: Renamed 'gate' to 'outGate'
        cGate *outGate = gate("radioGate$o", i);
        if (outGate->isConnected()) {
            cModule *gnb = outGate->getPathEndGate()->getOwnerModule();
            if (gnb->par("gNBId").intValue() == servingGNBId) {
                send(pkt, outGate);
                return;
            }
        }
    }
    delete pkt;
}

void UE::sendMeasurementReport()
{
    // Update measurements
    int numGates = gateSize("radioGate");
    gNBSignalStrengths.clear();
    
    for (int i = 0; i < numGates; i++) {
        // FIXED: Renamed 'gate' to 'outGate'
        cGate *outGate = gate("radioGate$o", i);
        if (outGate->isConnected()) {
            cModule *gnb = outGate->getPathEndGate()->getOwnerModule();
            int gNBId = gnb->par("gNBId");
            double gNBX = gnb->par("posX").doubleValue();
            double gNBY = gnb->par("posY").doubleValue();
            
            double distance = sqrt(pow(posX - gNBX, 2) + pow(posY - gNBY, 2));
            gNBSignalStrengths[gNBId] = calculateSignalStrength(distance, txPower);
        }
    }
    
    MeasurementReport *report = new MeasurementReport("MeasurementReport");
    report->setUeId(ueId);
    report->setServingGNBId(servingGNBId);
    report->setServingSignalStrength(gNBSignalStrengths[servingGNBId]);
    
    std::vector<int> neighborIds;
    std::vector<double> neighborSignals;
    for (auto& p : gNBSignalStrengths) {
        if (p.first != servingGNBId) {
            neighborIds.push_back(p.first);
            neighborSignals.push_back(p.second);
        }
    }
    
    report->setNeighborGNBIdsArraySize(neighborIds.size());
    report->setNeighborSignalStrengthsArraySize(neighborSignals.size());
    for (size_t i = 0; i < neighborIds.size(); i++) {
        report->setNeighborGNBIds(i, neighborIds[i]);
        report->setNeighborSignalStrengths(i, neighborSignals[i]);
    }
    
    for (int i = 0; i < numGates; i++) {
        // FIXED: Renamed 'gate' to 'outGate'
        cGate *outGate = gate("radioGate$o", i);
        if (outGate->isConnected()) {
            cModule *gnb = outGate->getPathEndGate()->getOwnerModule();
            if (gnb->par("gNBId").intValue() == servingGNBId) {
                send(report, outGate);
                return;
            }
        }
    }
    delete report;
}

void UE::performHandover(int targetGNBId)
{
    InitialAccessRequest *req = new InitialAccessRequest("InitialAccessRequest");
    req->setUeId(ueId);
    req->setSignalStrength(gNBSignalStrengths[targetGNBId]);
    req->setPosX(posX);
    req->setPosY(posY);
    
    int numGates = gateSize("radioGate");
    for (int i = 0; i < numGates; i++) {
        // FIXED: Renamed 'gate' to 'outGate'
        cGate *outGate = gate("radioGate$o", i);
        if (outGate->isConnected()) {
            cModule *gnb = outGate->getPathEndGate()->getOwnerModule();
            if (gnb->par("gNBId").intValue() == targetGNBId) {
                send(req, outGate);
                return;
            }
        }
    }
    delete req;
}

void UE::updatePosition()
{
    double direction = uniform(0, 2 * M_PI);
    posX += speed * cos(direction);
    posY += speed * sin(direction);
    
    if (posX < 0) posX = 0;
    if (posX > 1000) posX = 1000;
    if (posY < 0) posY = 0;
    if (posY > 1000) posY = 1000;
}

double UE::calculateSignalStrength(double distance, double txPower)
{
    double pathLoss = calculatePathLoss(distance);
    double shadowing = normal(0, 8.0);
    return txPower - pathLoss + shadowing;
}

double UE::calculatePathLoss(double distance)
{
    if (distance < 1.0) distance = 1.0;
    return 32.4 + 20 * log10(3.5) + 30 * log10(distance);
}

std::string UE::stateToString(UEState state)
{
    switch (state) {
        case IDLE: return "IDLE";
        case SCANNING: return "SCANNING";
        case CONNECTING: return "CONNECTING";
        case REGISTERING: return "REGISTERING";
        case CONNECTED: return "CONNECTED";
        case HANDOVER: return "HANDOVER";
        default: return "UNKNOWN";
    }
}

void UE::finish()
{
    EV << "UE " << ueId << ": Handovers=" << handoverCount
       << ", Packets=" << sequenceNumber << endl;
}
