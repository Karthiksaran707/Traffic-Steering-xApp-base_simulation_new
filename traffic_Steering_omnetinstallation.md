## Install OMNeT++ on Windows 11
Step 1: Download OMNeT++
1.	Go to the official website: https://omnetpp.org/download/
2.	Download the Windows version (e.g., omnetpp-6.0.2-windows-x86_64.zip)
![alt text](<Screenshot 2026-01-31 134028.png>)

Step 2: Extract the Archive
1.	Extract the downloaded ZIP file to a simple path like:
✅C:\omnetpp-6.0.2
2.	Avoid paths with spaces or special characters
❌C:\Program Files\ omnetpp-6.0.2
<img width="632" height="86" alt="image" src="https://github.com/user-attachments/assets/c2553570-d3d5-43ae-90a9-71df09e11127" />


Step 3: Set Up the Environment
1.	Navigate to the extracted folder
2.	Double-click on mingwenv.cmd to open the OMNeT++ shell
<img width="837" height="958" alt="image" src="https://github.com/user-attachments/assets/93bec622-c45a-4bd7-9d14-27ba55ab7eac" />


Step 4: Configure and Build
In the OMNeT++ shell, run these commands:
# Configure the build
./configure
![alt text](<Screenshot 2026-01-31 145052.png>)
# Build OMNeT++ (this may take 10-30 minutes)
make -j4
![alt text](<Screenshot 2026-01-31 145420.png>)
Step 5: Verify Installation
Bash
# Run the OMNeT++ IDE or IDE application
omnetpp
Step 6: Test with a Sample
1.	In the IDE, go to File → Import → Existing Projects
2.	Browse to samples/aloha

## System Requirements
•	RAM: 4GB minimum (8GB recommended)
•	Disk Space: ~2GB
•	Windows 11 (64-bit)
