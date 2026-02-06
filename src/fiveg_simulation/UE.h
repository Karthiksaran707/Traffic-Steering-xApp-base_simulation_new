//==========================================================================
// UE.h - User Equipment Header File
// Defines the UE class with state machine and signal processing
//==========================================================================

#ifndef __UE_H
#define __UE_H

#include <omnetpp.h>
#include <map>
#include <string>

using namespace omnetpp;

// UE State Machine States
enum UEState {
    IDLE,               // Not connected
    SCANNING,           // Scanning for gNBs
    CONNECTING,         // Initial access in progress
    REGISTERING,        // Registration with core network
    CONNECTED,          // Fully connected, can transmit data
    HANDOVER            // Handover in progress
};

class UE : public cSimpleModule
{
  private:
    // Configuration parameters
    int ueId;
    double posX, posY;          // Current position
    double speed;
    double txPower;
    double dataRate;
    double measurementInterval;
    
    // State variables
    UEState currentState;
    int servingGNBId;
    int sessionId;
    std::string assignedIP;
    int sequenceNumber;
    
    // Resource allocation
    int allocatedRBs;
    int timeSlot;
    int frequencySlot;
    
    // Signal measurements
    std::map<int, double> gNBSignalStrengths;  // gNBId -> signal strength
    
    // Self-messages for timers
    cMessage *scanTimer;
    cMessage *dataTimer;
    cMessage *measurementTimer;
    cMessage *movementTimer;
    
    // Statistics
    simsignal_t connectionDelaySignal;
    simsignal_t throughputSignal;
    simsignal_t handoverCountSignal;
    int handoverCount;
    simtime_t connectionStartTime;
    
    // Channel model parameters
    double pathLossExponent;
    double shadowingStdDev;
    double frequency;  // Carrier frequency in Hz
    
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
    
    // State machine handlers
    void handleIdleState();
    void handleScanningState();
    void handleConnectingState(cMessage *msg);
    void handleRegisteringState(cMessage *msg);
    void handleConnectedState(cMessage *msg);
    void handleHandoverState(cMessage *msg);
    
    // Message handlers
    void handleInitialAccessResponse(cMessage *msg);
    void handleRegistrationResponse(cMessage *msg);
    void handleDataAck(cMessage *msg);
    void handleHandoverCommand(cMessage *msg);
    
    // Actions
    void scanForGNBs();
    void sendInitialAccessRequest();
    void sendRegistrationRequest();
    void sendDataPacket();
    void sendMeasurementReport();
    void performHandover(int targetGNBId);
    void updatePosition();
    
    // Channel model
    double calculateSignalStrength(double distance, double txPower);
    double calculatePathLoss(double distance);
    double getDistanceToGNB(int gNBId);
    
    // Utility functions
    int selectBestGNB();
    std::string stateToString(UEState state);
    
  public:
    UE();
    virtual ~UE();
};

#endif
