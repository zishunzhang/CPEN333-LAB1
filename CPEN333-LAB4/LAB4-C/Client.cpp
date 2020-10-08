#include <iostream>
#include <WS2tcpip.h>
#include <string>
#include "rt.h"
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	// initialize default port number and max connection cout
	int     port = 54000;
	string  ipAddress = "127.0.0.1";

	// Initialize WinSock
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cout << "Can't start Winsock, Err #" << wsResult << "\n";
		return 0;
	}

	// Create socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		cout << "Can't create socket, Err #" << WSAGetLastError() << "\n";
		WSACleanup();
		return 0;
	}

	// Fill in a hint structure
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	//Create child process for parent/client
	cout << "Client create child process.....\n";
	CProcess p1("C:\\CPEN333-LAB4-C\\Debug\\Server.exe",	// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);


	// Connect to server
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR)
	{
		cout << "Can't connect to server, Err #" << WSAGetLastError() << "\n";
		closesocket(sock);
		WSACleanup();
		return 0;
	}

	// Do-while loop to send and receive data
	char buf[4096];
	string userInput;

	do
	{
		// Prompt the user for some text
		cout << "> ";
		getline(cin, userInput);

		if (userInput.size() > 0)		// Make sure the user has typed in something
		{
			// Send the text
			int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
			if (sendResult != SOCKET_ERROR)
			{
				// Wait for response
				ZeroMemory(buf, 4096);
				int bytesReceived = recv(sock, buf, 4096, 0);
				if (bytesReceived > 0)
				{
					// Echo response to console
					cout << "Response from server:  " << string(buf, 0, bytesReceived) << endl;
				}
			}
		}

	} while (userInput.size() > 0);

	// Close down everything
	p1.WaitForProcess(); // wait for process to finish
	closesocket(sock);
	WSACleanup();

	return 0;
}