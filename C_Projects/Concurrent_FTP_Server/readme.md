              Concurrent FTP Server

This project demonstrates how socket programming in Linux is used to build a File Transfer System where
multiple clients can connect to a server simultaneously and download files.
The server listens on a specific port, accepts client requests, and sends the requested file over the network. Each client
is handled in a separate process using fork(), which allows multiple users to download files at the same time
without blocking others.

Server Application
• Creates a TCP socket
• Binds to a port
• Listens for client connections
• Accepts multiple clients
• Uses fork() to handle each client concurrently
• Reads requested filename
• Sends file size header
• Transfers file data to client
Client Application
• Connects to server using IP + Port
• Sends filename to server
• Reads file size from header
• Receives file data
• Saves file locally

There are two programs:
1) Server → Provides files
2) Client → Requests and downloads files
Communication happens using TCP sockets over network.

Complete Execution Flow

Server Startup
Step 1 – Server creates socket
Server creates a TCP communication endpoint.

Allows the server to talk over the network.

Step 2 – Bind socket to port
Server attaches the socket to:
• IP address (local machine)
• Port number (example: 9000)
So clients know where to connect.

Step 3 – Listen for clients
Server enters listening mode.
Waits continuously for client requests.
At this stage:
Server ready... waiting for connection...
Client Startup
Step 4 – Client creates socket
Client also creates its own socket.
To communicate with server.
Step 5 – Client connects to server
Client sends a connection request using:
• Server IP
• Server Port
Establish TCP connection.
Now connection is established:


Marvellous Infosystems : Logic Building.
Client ↔ Server connected
Server Accepts Client
Step 6 – Server accepts connection
Server accepts the incoming client request.
Creates a separate communication channel for that client.

Concurrency
Step 7 – Server creates new process
Server uses process creation (fork).
• Parent → keeps listening for new clients
• Child → handles current client
This allows:
Multiple clients at same time
No waiting/blocking
Concurrent downloads
Example:
Client A → Process 1
Client B → Process 2
Client C → Process 3
File Request
Step 8 – Client sends filename
Client sends:
Requested file name
Example:
Demo.txt
Tell server which file is needed.

Server Processing
Step 9 – Server receives filename
Child process reads the filename.

Step 10 – Server checks file
Server:
• Opens file
• Checks if exists
Two cases:
Case A – File not found
Server sends:
ERR
Connection ends.
Case B – File found
Server:
• Gets file size
• Prepares header
Example header:
OK 1700
File exists and size = 1700 bytes

Data Transfer
Step 11 – Server sends header
First sends:
OK size
Client knows:
• file exists
• how much data to expect


Step 12 – Server sends file data
Server:
• Reads file in chunks
• Sends chunk by chunk

Efficient transfer for large files

Client Receiving
Step 13 – Client reads header
Client reads:
OK 1700
Extracts:
FileSize = 1700
Know how many bytes to download

Step 14 – Client creates new file
Client creates output file locally.
Example:
A.txt
Step 15 – Client receives data
Client:
• Reads data from socket
• Writes into file
• Repeats until full size received

Store complete file safely

Completion
Step 16 – Transfer complete
Client:
• Closes file
• Closes socket
• Shows:
Download complete
Server:
• Child process exits
• Parent keeps listening for new clients

Continuous Loop
Server always runs:
Accept → Fork → Handle → Repeat

So:
• Many clients can connect anytime
• Server never stop

Project Flow
Client Start
↓
Connect to Server
↓
Send Filename
↓

-------------------------
Server Accepts
↓
Forks new process
↓
Open file
↓
Send Header
↓
Send Data

-------------------------

↓

Client receives data

↓
Save file
↓
Download Complete
