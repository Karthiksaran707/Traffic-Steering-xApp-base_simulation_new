//==========================================================================
// Server.h - Application Server Header
//==========================================================================

#ifndef __SERVER_H
#define __SERVER_H

#include <omnetpp.h>

using namespace omnetpp;

class Server : public cSimpleModule
{
  private:
    double processingDelay;
    
    simsignal_t packetsReceivedSignal;
    simsignal_t latencySignal;
    int totalPackets;
    
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
    
  public:
    Server();
    virtual ~Server();
};

#endif
