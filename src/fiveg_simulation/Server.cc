//==========================================================================
// Server.cc - Application Server Implementation
//==========================================================================

#include "Server.h"
#include "Messages_m.h"

Define_Module(Server);

Server::Server()
{
}

Server::~Server()
{
}

void Server::initialize()
{
    processingDelay = par("processingDelay").doubleValue();
    totalPackets = 0;
    
    packetsReceivedSignal = registerSignal("packetsReceived");
    latencySignal = registerSignal("latency");
    
    EV << "Server initialized" << endl;
}

void Server::handleMessage(cMessage *msg)
{
    if (dynamic_cast<DataPacket*>(msg)) {
        DataPacket *pkt = check_and_cast<DataPacket*>(msg);
        
        totalPackets++;
        emit(packetsReceivedSignal, totalPackets);
        
        double latency = (simTime().dbl() - pkt->getTimestamp()) * 1000;  // ms
        emit(latencySignal, latency);
        
        EV << "Server received packet #" << pkt->getSequenceNumber() 
           << " from UE " << pkt->getUeId() 
           << ", latency: " << latency << " ms" << endl;
        
        // Send acknowledgment back
        DataAck *ack = new DataAck("DataAck");
        ack->setUeId(pkt->getUeId());
        ack->setSequenceNumber(pkt->getSequenceNumber());
        ack->setSuccess(true);
        ack->setLatency(latency);
        
        sendDelayed(ack, processingDelay, "coreGate$o");
        
        delete msg;
    }
    else if (dynamic_cast<DataAck*>(msg)) {
        // Forward ACK to Core Network
        send(msg, "coreGate$o");
    }
    else {
        delete msg;
    }
}

void Server::finish()
{
    EV << "Server Statistics:" << endl;
    EV << "  Total packets received: " << totalPackets << endl;
}
