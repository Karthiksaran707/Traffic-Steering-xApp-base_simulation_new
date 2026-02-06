//==========================================================================
// gNB.h - gNodeB Header File
// Defines the gNB class managing radio resources and connections
//==========================================================================

#ifndef __GNB_H
#define __GNB_H

#include <omnetpp.h>
#include <map>
#include <set>
#include <vector>

using namespace omnetpp;

// Connected UE information
struct ConnectedUE {
    int ueId;
    int allocatedRBs;
    int timeSlot;
    int frequencySlot;
    double signalStrength;
    simtime_t connectionTime;
    int packetsReceived;
};

class gNB : public cSimpleModule
{
  private:
    // Configuration
    int gNBId;
    double posX, posY;
    double txPower;
    int totalRBs;
    int maxConnections;
    double loadThreshold;
    double coverageRadius;
    
    // State
    std::map<int, ConnectedUE> connectedUEs;  // ueId -> info
    int usedRBs;
    int nextTimeSlot;
    int nextFrequencySlot;
    
    // Neighbor gNBs
    std::set<int> neighborGNBs;
    
    // Timers
    cMessage *loadReportTimer;
    
    // Statistics
    simsignal_t loadSignal;
    simsignal_t connectedUEsSignal;
    simsignal_t handoverOutSignal;
    simsignal_t handoverInSignal;
    
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
    
    // Message handlers
    void handleInitialAccessRequest(cMessage *msg);
    void handleRegistrationRequest(cMessage *msg);
    void handleDataPacket(cMessage *msg);
    void handleMeasurementReport(cMessage *msg);
    void handleHandoverAck(cMessage *msg);
    void handleLoadBalanceCommand(cMessage *msg);
    void handlePolicyUpdate(cMessage *msg);
    
    // Actions
    void sendLoadReport();
    void allocateResources(int ueId, int& rbs, int& timeSlot, int& freqSlot);
    void releaseResources(int ueId);
    void initiateHandover(int ueId, int targetGNBId, int reason);
    
    // Utility
    double calculateLoad();
    int findGateToUE(int ueId);
    
  public:
    gNB();
    virtual ~gNB();
};

#endif
