//==========================================================================
// Core Network Module Definition
// Handles authentication, IP assignment, and routing
//==========================================================================

package fiveg_simulation;

simple CoreNetwork
{
    parameters:
        string ipPool = default("10.0.1.");  // IP address pool prefix
        double authDelay @unit(s) = default(0.05s);  // Authentication delay
        
        @display("i=abstract/cloud");
        
    gates:
        inout gNBGate[];    // Gates to gNBs
        inout serverGate;   // Gate to Server
}
