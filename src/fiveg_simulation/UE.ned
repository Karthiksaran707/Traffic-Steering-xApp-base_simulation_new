//==========================================================================
// User Equipment (UE) Module Definition
// Represents a mobile device in the 5G network
//==========================================================================

package fiveg_simulation;

simple UE
{
    parameters:
        int ueId;                                   // Unique identifier
        double initialX @unit(m);                   // Initial X position
        double initialY @unit(m);                   // Initial Y position
        double speed @unit(mps) = default(1.0mps);  // Movement speed
        double txPower @unit(dBm) = default(23dBm); // Transmission power
        double dataRate @unit(Mbps) = default(10Mbps); // Data generation rate
        double measurementInterval @unit(s) = default(0.1s); // Measurement reporting interval
        
        @display("i=device/cellphone");
        
    gates:
        inout radioGate[];  // Gates to connect to multiple gNBs
}
