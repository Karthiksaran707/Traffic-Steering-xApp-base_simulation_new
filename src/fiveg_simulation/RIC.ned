//==========================================================================
// RAN Intelligent Controller (RIC) Module
// Implements xApps for load balancing and handover optimization
//==========================================================================

package fiveg_simulation;

simple RIC
{
    parameters:
        double loadBalanceThreshold = default(80.0);    // Load % to trigger balancing
        double signalThreshold @unit(dBm) = default(-100dBm);  // Signal threshold for handover
        double hysteresis @unit(dB) = default(3dB);     // Handover hysteresis
        double analysisInterval @unit(s) = default(0.5s);  // Analysis interval
        bool enableLoadBalancing = default(true);
        bool enableHandover = default(true);
        
        @display("i=block/control");
        
    gates:
        inout gNBGate[];    // Gates to gNBs
}
