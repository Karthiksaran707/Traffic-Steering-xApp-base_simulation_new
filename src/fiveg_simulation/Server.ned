//==========================================================================
// Server Module Definition
// Represents the application server
//==========================================================================

package fiveg_simulation;

simple Server
{
    parameters:
        double processingDelay @unit(s) = default(0.001s);
        
        @display("i=device/server");
        
    gates:
        inout coreGate;     // Gate to Core Network
}
