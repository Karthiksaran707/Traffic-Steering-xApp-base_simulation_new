//==========================================================================
// Message Definitions for 5G Simulation
// Defines all message types used in the simulation
//==========================================================================

// Phase 1: Initial Access Messages
message InitialAccessRequest
{
    int ueId;               // Unique UE identifier
    double signalStrength;  // Signal strength at UE
    double posX;            // UE X position
    double posY;            // UE Y position
}

message InitialAccessResponse
{
    int ueId;
    int gNBId;
    bool accepted;              // Whether connection is accepted
    int allocatedRBs;           // Allocated Resource Blocks
    int timeSlot;               // Allocated time slot
    int frequencySlot;          // Allocated frequency slot
}

message RegistrationRequest
{
    int ueId;
    int gNBId;
    string imsi;                // International Mobile Subscriber Identity
}

message RegistrationResponse
{
    int ueId;
    bool authenticated;
    string ipAddress;           // Assigned IP address
    int sessionId;
}

// Phase 2: Data Transmission Messages
message DataPacket
{
    int ueId;
    int gNBId;
    int sessionId;
    int sequenceNumber;
    int packetSize;             // Size in bytes
    double timestamp;
    string payload;
    string destinationIP;
    string sourceIP;
}

message DataAck
{
    int ueId;
    int sequenceNumber;
    bool success;
    double latency;
}

// Phase 3: Network Optimization Messages
message MeasurementReport
{
    int ueId;
    int servingGNBId;
    double servingSignalStrength;
    int neighborGNBIds[];           // Array of neighbor gNB IDs
    double neighborSignalStrengths[]; // Signal strengths from neighbors
    double currentLoad;
}

message HandoverCommand
{
    int ueId;
    int sourceGNBId;
    int targetGNBId;
    int reason;                 // 0: signal, 1: load balancing
}

message HandoverAck
{
    int ueId;
    int targetGNBId;
    bool success;
}

message LoadReport
{
    int gNBId;
    double currentLoad;         // Load percentage 0-100
    int connectedUEs;
    int availableRBs;
    double averageLatency;
}

message LoadBalanceCommand
{
    int overloadedGNBId;
    int targetGNBId;
    int ueIdToMove;
}

// RIC Policy Messages
message PolicyUpdate
{
    int gNBId;
    double loadThreshold;
    double signalThreshold;
    bool enableLoadBalancing;
    bool enableHandover;
}
