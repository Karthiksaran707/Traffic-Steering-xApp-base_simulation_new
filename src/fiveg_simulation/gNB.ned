//==========================================================================
// gNodeB (gNB) Module Definition
// Represents a 5G base station
//==========================================================================

package fiveg_simulation;

simple gNB
{
    parameters:
        int gNBId;                                      // Unique identifier
        double posX @unit(m);                           // X position
        double posY @unit(m);                           // Y position
        double txPower @unit(dBm) = default(46dBm);     // Transmission power
        int totalRBs = default(100);                    // Total Resource Blocks
        int maxConnections = default(50);               // Max UE connections
        double loadThreshold = default(80.0);           // Load threshold for balancing
        double coverageRadius @unit(m) = default(500m); // Coverage radius
        
        @display("i=device/antennatower");
        
    gates:
        inout ueGate[];         // Gates to UEs
        inout coreGate;         // Gate to Core Network
        inout ricGate;          // Gate to RIC
        inout x2Gate[];         // X2 interface to other gNBs
}
