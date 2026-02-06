//==========================================================================
// RIC.cc - RAN Intelligent Controller Implementation
// Implements load balancing and handover xApps
//==========================================================================

#include "RIC.h"
#include "Messages_m.h"

Define_Module(RIC);

RIC::RIC()
{
    analysisTimer = nullptr;
}

RIC::~RIC()
{
    cancelAndDelete(analysisTimer);
}

void RIC::initialize()
{
    loadBalanceThreshold = par("loadBalanceThreshold");
    signalThreshold = par("signalThreshold").doubleValue();
    hysteresis = par("hysteresis").doubleValue();
    analysisInterval = par("analysisInterval").doubleValue();
    enableLoadBalancing = par("enableLoadBalancing");
    enableHandover = par("enableHandover");
    
    loadBalanceDecisionsSignal = registerSignal("loadBalanceDecisions");
    handoverDecisionsSignal = registerSignal("handoverDecisions");
    
    analysisTimer = new cMessage("analysisTimer");
    scheduleAt(simTime() + analysisInterval, analysisTimer);
    
    EV << "RIC initialized with:" << endl;
    EV << "  Load Balance Threshold: " << loadBalanceThreshold << "%" << endl;
    EV << "  Signal Threshold: " << signalThreshold << " dBm" << endl;
    EV << "  Load Balancing: " << (enableLoadBalancing ? "enabled" : "disabled") << endl;
    EV << "  Handover: " << (enableHandover ? "enabled" : "disabled") << endl;
}

void RIC::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage()) {
        if (msg == analysisTimer) {
            runAnalysis();
            scheduleAt(simTime() + analysisInterval, analysisTimer);
        }
    }
    else if (dynamic_cast<LoadReport*>(msg)) {
        handleLoadReport(msg);
        delete msg;
    }
    else if (dynamic_cast<MeasurementReport*>(msg)) {
        handleMeasurementReport(msg);
        delete msg;
    }
    else {
        delete msg;
    }
}

void RIC::handleLoadReport(cMessage *msg)
{
    LoadReport *report = check_and_cast<LoadReport*>(msg);
    
    GNBStatus status;
    status.gNBId = report->getGNBId();
    status.load = report->getCurrentLoad();
    status.connectedUEs = report->getConnectedUEs();
    status.availableRBs = report->getAvailableRBs();
    status.averageLatency = report->getAverageLatency();
    status.lastUpdate = simTime();
    
    gNBStatuses[report->getGNBId()] = status;
    
    EV << "RIC received Load Report from gNB " << report->getGNBId() 
       << ": load=" << report->getCurrentLoad() << "%" << endl;
}

void RIC::handleMeasurementReport(cMessage *msg)
{
    MeasurementReport *report = check_and_cast<MeasurementReport*>(msg);
    
    UEMeasurement measurement;
    measurement.ueId = report->getUeId();
    measurement.servingGNBId = report->getServingGNBId();
    measurement.servingSignal = report->getServingSignalStrength();
    measurement.timestamp = simTime();
    
    // Store neighbor measurements
    for (size_t i = 0; i < report->getNeighborGNBIdsArraySize(); i++) {
        measurement.neighborSignals[report->getNeighborGNBIds(i)] = 
            report->getNeighborSignalStrengths(i);
    }
    
    ueMeasurements[report->getUeId()] = measurement;
}

//==========================================================================
// Analysis and xApps
//==========================================================================

void RIC::runAnalysis()
{
    EV << "RIC running network analysis..." << endl;
    
    if (enableLoadBalancing) {
        runLoadBalancingXApp();
    }
    
    if (enableHandover) {
        runHandoverXApp();
    }
}

void RIC::runLoadBalancingXApp()
{
    EV << "Running Load Balancing xApp..." << endl;
    
    // Find overloaded gNBs
    for (auto& pair : gNBStatuses) {
        GNBStatus& status = pair.second;
        
        if (status.load > loadBalanceThreshold && status.connectedUEs > 1) {
            EV << "  gNB " << status.gNBId << " is overloaded (" 
               << status.load << "%)" << endl;
            
            // Find a UE to move
            int ueToMove = -1;
            for (auto& uePair : ueMeasurements) {
                if (uePair.second.servingGNBId == status.gNBId) {
                    ueToMove = uePair.first;
                    break;
                }
            }
            
            if (ueToMove >= 0) {
                int targetGNB = findLeastLoadedGNB();
                
                if (targetGNB >= 0 && targetGNB != status.gNBId) {
                    EV << "  Moving UE " << ueToMove << " to gNB " << targetGNB << endl;
                    sendLoadBalanceCommand(status.gNBId, targetGNB, ueToMove);
                    emit(loadBalanceDecisionsSignal, 1);
                }
            }
        }
    }
}

void RIC::runHandoverXApp()
{
    EV << "Running Handover xApp..." << endl;
    
    for (auto& pair : ueMeasurements) {
        UEMeasurement& measurement = pair.second;
        
        // Check if serving signal is below threshold
        if (measurement.servingSignal < signalThreshold) {
            EV << "  UE " << measurement.ueId << " has weak signal (" 
               << measurement.servingSignal << " dBm)" << endl;
            
            // Find best neighbor
            int bestNeighbor = -1;
            double bestSignal = measurement.servingSignal;
            
            for (auto& neighborPair : measurement.neighborSignals) {
                // Apply hysteresis
                if (neighborPair.second > bestSignal + hysteresis) {
                    bestSignal = neighborPair.second;
                    bestNeighbor = neighborPair.first;
                }
            }
            
            if (bestNeighbor >= 0) {
                EV << "  Triggering handover to gNB " << bestNeighbor 
                   << " (signal: " << bestSignal << " dBm)" << endl;
                sendHandoverCommand(measurement.ueId, measurement.servingGNBId, bestNeighbor);
                emit(handoverDecisionsSignal, 1);
            }
        }
    }
}

int RIC::findLeastLoadedGNB()
{
    int leastLoaded = -1;
    double minLoad = 100.0;
    
    for (auto& pair : gNBStatuses) {
        if (pair.second.load < minLoad) {
            minLoad = pair.second.load;
            leastLoaded = pair.first;
        }
    }
    
    return leastLoaded;
}

//==========================================================================
// Command Sending
//==========================================================================

void RIC::sendLoadBalanceCommand(int overloadedGNB, int targetGNB, int ueId)
{
    LoadBalanceCommand *cmd = new LoadBalanceCommand("LoadBalanceCommand");
    cmd->setOverloadedGNBId(overloadedGNB);
    cmd->setTargetGNBId(targetGNB);
    cmd->setUeIdToMove(ueId);
    
    int gateIdx = findGateToGNB(overloadedGNB);
    if (gateIdx >= 0) {
        send(cmd, "gNBGate$o", gateIdx);
    } else {
        delete cmd;
    }
}

void RIC::sendHandoverCommand(int ueId, int sourceGNB, int targetGNB)
{
    HandoverCommand *cmd = new HandoverCommand("HandoverCommand");
    cmd->setUeId(ueId);
    cmd->setSourceGNBId(sourceGNB);
    cmd->setTargetGNBId(targetGNB);
    cmd->setReason(0);  // Signal-based
    
    int gateIdx = findGateToGNB(sourceGNB);
    if (gateIdx >= 0) {
        send(cmd, "gNBGate$o", gateIdx);
    } else {
        delete cmd;
    }
}

void RIC::sendPolicyUpdate(int gNBId)
{
    PolicyUpdate *policy = new PolicyUpdate("PolicyUpdate");
    policy->setGNBId(gNBId);
    policy->setLoadThreshold(loadBalanceThreshold);
    policy->setSignalThreshold(signalThreshold);
    policy->setEnableLoadBalancing(enableLoadBalancing);
    policy->setEnableHandover(enableHandover);
    
    int gateIdx = findGateToGNB(gNBId);
    if (gateIdx >= 0) {
        send(policy, "gNBGate$o", gateIdx);
    } else {
        delete policy;
    }
}

int RIC::findGateToGNB(int gNBId)
{
    int numGates = gateSize("gNBGate");
    for (int i = 0; i < numGates; i++) {
        // FIXED: Renamed 'gate' to 'outGate'
        cGate *outGate = this->gate("gNBGate$o", i);
        if (outGate->isConnected()) {
            cModule *connectedModule = outGate->getPathEndGate()->getOwnerModule();
            if (connectedModule->par("gNBId").intValue() == gNBId) {
                return i;
            }
        }
    }
    return -1;
}

void RIC::finish()
{
    EV << "RIC Statistics:" << endl;
    EV << "  Monitored gNBs: " << gNBStatuses.size() << endl;
    EV << "  Tracked UEs: " << ueMeasurements.size() << endl;
}
