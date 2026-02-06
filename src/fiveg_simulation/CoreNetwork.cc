//==========================================================================
// CoreNetwork.cc - Core Network Implementation
//==========================================================================

#include "CoreNetwork.h"
#include "Messages_m.h"

Define_Module(CoreNetwork);

CoreNetwork::CoreNetwork()
{
}

CoreNetwork::~CoreNetwork()
{
}

void CoreNetwork::initialize()
{
    ipPool = par("ipPool").stdstringValue();
    authDelay = par("authDelay").doubleValue();
    nextIP = 1;
    nextSessionId = 1000;
    
    activeSessionsSignal = registerSignal("activeSessions");
    authSuccessSignal = registerSignal("authSuccess");
    
    EV << "Core Network initialized" << endl;
}

void CoreNetwork::handleMessage(cMessage *msg)
{
    if (dynamic_cast<RegistrationRequest*>(msg)) {
        handleRegistrationRequest(msg);
        delete msg;
    }
    else if (dynamic_cast<DataPacket*>(msg)) {
        handleDataPacket(msg);
        // Forward to server
    }
    else if (dynamic_cast<DataAck*>(msg)) {
        // Forward ACK back to gNB
        DataAck *ack = check_and_cast<DataAck*>(msg);
        // Find the gNB that forwarded this packet
        // For simplicity, forward to all gNBs (in real implementation, track routing)
        int numGates = gateSize("gNBGate");
        for (int i = 0; i < numGates; i++) {
            // FIXED: Use gate() method directly without local variable
            if (gate("gNBGate$o", i)->isConnected()) {
                send(msg->dup(), "gNBGate$o", i);
            }
        }
        delete msg;
    }
    else {
        EV << "Core Network received unknown message" << endl;
        delete msg;
    }
}

void CoreNetwork::handleRegistrationRequest(cMessage *msg)
{
    RegistrationRequest *req = check_and_cast<RegistrationRequest*>(msg);
    
    EV << "Core Network processing Registration for UE " << req->getUeId() 
       << " (IMSI: " << req->getImsi() << ")" << endl;
    
    // Create response
    RegistrationResponse *resp = new RegistrationResponse("RegistrationResponse");
    resp->setUeId(req->getUeId());
    
    // Authenticate
    bool authSuccess = authenticateUE(req->getImsi());
    emit(authSuccessSignal, authSuccess ? 1 : 0);
    
    if (authSuccess) {
        // Allocate IP and create session
        std::string ip = allocateIP();
        int sessionId = nextSessionId++;
        
        Session session;
        session.ueId = req->getUeId();
        session.gNBId = req->getGNBId();
        session.ipAddress = ip;
        session.startTime = simTime();
        
        activeSessions[sessionId] = session;
        ueToSession[req->getUeId()] = sessionId;
        
        resp->setAuthenticated(true);
        resp->setIpAddress(ip.c_str());
        resp->setSessionId(sessionId);
        
        emit(activeSessionsSignal, (long)activeSessions.size());
        
        EV << "  Authentication SUCCESS, assigned IP: " << ip << endl;
    }
    else {
        resp->setAuthenticated(false);
        EV << "  Authentication FAILED" << endl;
    }
    
    // Send response back through gNB
    int gateIdx = findGateToGNB(req->getGNBId());
    if (gateIdx >= 0) {
        sendDelayed(resp, authDelay, "gNBGate$o", gateIdx);
    } else {
        delete resp;
    }
}

void CoreNetwork::handleDataPacket(cMessage *msg)
{
    DataPacket *pkt = check_and_cast<DataPacket*>(msg);
    
    EV << "Core Network routing packet from UE " << pkt->getUeId() 
       << " to " << pkt->getDestinationIP() << endl;
    
    // Forward to server
    send(msg, "serverGate$o");
}

std::string CoreNetwork::allocateIP()
{
    char ip[32];
    sprintf(ip, "%s%d", ipPool.c_str(), nextIP++);
    return std::string(ip);
}

bool CoreNetwork::authenticateUE(const char* imsi)
{
    // Simplified authentication - always succeed for valid IMSI format
    return strlen(imsi) > 10;
}

int CoreNetwork::findGateToGNB(int gNBId)
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

void CoreNetwork::finish()
{
    EV << "Core Network Statistics:" << endl;
    EV << "  Total sessions created: " << (nextSessionId - 1000) << endl;
    EV << "  Active sessions at end: " << activeSessions.size() << endl;
}
