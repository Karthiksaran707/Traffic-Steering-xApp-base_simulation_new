//==========================================================================
// RIC.h - RAN Intelligent Controller Header
//==========================================================================

#ifndef __RIC_H
#define __RIC_H

#include <omnetpp.h>
#include <map>
#include <vector>

using namespace omnetpp;

struct GNBStatus {
    int gNBId;
    double load;
    int connectedUEs;
    int availableRBs;
    double averageLatency;
    simtime_t lastUpdate;
};

struct UEMeasurement {
    int ueId;
    int servingGNBId;
    double servingSignal;
    std::map<int, double> neighborSignals;
    simtime_t timestamp;
};

class RIC : public cSimpleModule
{
  private:
    // Configuration
    double loadBalanceThreshold;
    double signalThreshold;
    double hysteresis;
    double analysisInterval;
    bool enableLoadBalancing;
    bool enableHandover;
    
    // State
    std::map<int, GNBStatus> gNBStatuses;
    std::map<int, UEMeasurement> ueMeasurements;
    
    // Timer
    cMessage *analysisTimer;
    
    // Statistics
    simsignal_t loadBalanceDecisionsSignal;
    simsignal_t handoverDecisionsSignal;
    
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
    
    void handleLoadReport(cMessage *msg);
    void handleMeasurementReport(cMessage *msg);
    
    void runAnalysis();
    void runLoadBalancingXApp();
    void runHandoverXApp();
    
    void sendLoadBalanceCommand(int overloadedGNB, int targetGNB, int ueId);
    void sendHandoverCommand(int ueId, int sourceGNB, int targetGNB);
    void sendPolicyUpdate(int gNBId);
    
    int findLeastLoadedGNB();
    int findGateToGNB(int gNBId);
    
  public:
    RIC();
    virtual ~RIC();
};

#endif
