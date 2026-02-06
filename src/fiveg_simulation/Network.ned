//==========================================================================
// Network Topology Definition
// Complete 5G network with UEs, gNBs, Core Network, RIC, and Server
//==========================================================================

package fiveg_simulation;

import fiveg_simulation.UE;
import fiveg_simulation.gNB;
import fiveg_simulation.CoreNetwork;
import fiveg_simulation.RIC;
import fiveg_simulation.Server;

network FiveGNetwork
{
    parameters:
        int numUEs = default(2);
        int numGNBs = default(2);
        
        @display("bgb=1200,800");
        
    submodules:
        // User Equipment
        ue[numUEs]: UE {
            parameters:
                ueId = index;
                @display("p=100,600;i=device/cellphone");
        }
        
        // gNodeBs (Base Stations)
        gnb[numGNBs]: gNB {
            parameters:
                gNBId = index;
                @display("p=300,400;i=device/antennatower");
        }
        
        // Core Network
        coreNetwork: CoreNetwork {
            @display("p=600,300;i=abstract/cloud");
        }
        
        // RAN Intelligent Controller
        ric: RIC {
            @display("p=600,500;i=block/control");
        }
        
        // Application Server
        server: Server {
            @display("p=900,300;i=device/server");
        }
        
    connections allowunconnected:
        // Connect all UEs to all gNBs (for handover capability)
        for i=0..numUEs-1, for j=0..numGNBs-1 {
            ue[i].radioGate++ <--> {delay = 1ms;} <--> gnb[j].ueGate++;
        }
        
        // Connect gNBs to Core Network
        for i=0..numGNBs-1 {
            gnb[i].coreGate <--> {delay = 5ms;} <--> coreNetwork.gNBGate++;
        }
        
        // Connect gNBs to RIC
        for i=0..numGNBs-1 {
            gnb[i].ricGate <--> {delay = 1ms;} <--> ric.gNBGate++;
        }
        
        // Connect Core Network to Server
        coreNetwork.serverGate <--> {delay = 10ms;} <--> server.coreGate;
}
