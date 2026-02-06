//==========================================================================
// CoreNetwork.h - Core Network Header
//==========================================================================

#ifndef __CORENETWORK_H
#define __CORENETWORK_H

#include <omnetpp.h>
#include <map>
#include <string>

using namespace omnetpp;

struct Session {
    int ueId;
    int gNBId;
    std::string ipAddress;
    simtime_t startTime;
};

class CoreNetwork : public cSimpleModule
{
  private:
    std::string ipPool;
    double authDelay;
    int nextIP;
    int nextSessionId;
    
    std::map<int, Session> activeSessions;  // sessionId -> Session
    std::map<int, int> ueToSession;         // ueId -> sessionId
    
    // Statistics
    simsignal_t activeSessionsSignal;
    simsignal_t authSuccessSignal;
    
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
    
    void handleRegistrationRequest(cMessage *msg);
    void handleDataPacket(cMessage *msg);
    
    std::string allocateIP();
    bool authenticateUE(const char* imsi);
    int findGateToGNB(int gNBId);
    
  public:
    CoreNetwork();
    virtual ~CoreNetwork();
};

#endif
