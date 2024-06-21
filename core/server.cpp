#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <thread>
#include "http/parser.h"
#include "http/request.h"
#include <csignal>

using namespace std;
vector<thread> threads;
int serverSocket;

void handleExit(int signal) {
	cout << "\nExit." << endl;
    close(serverSocket);
    exit(signal);
}

int init(){
	int port = 8000;
	signal(SIGINT, handleExit);
	
	printf("Initializing...\n");
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket < 0) {
        perror("Failed to create server");
        return 1;
    }

	sockaddr_in serverAddres;
	serverAddres.sin_family = AF_INET;
	serverAddres.sin_port = htons(port);
	serverAddres.sin_addr.s_addr = INADDR_ANY;

	// Allow socket reuse
    int opt = 1;
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt(SO_REUSEADDR) failed");
    }
	if(bind(serverSocket, (struct sockaddr*)&serverAddres, sizeof(serverAddres)) < 0){
		printf("Failed to bind socket!\n");
		close(serverSocket);
		return -1;
	}

	printf("Listening on port: %i\n", port);
	if (listen(serverSocket, 100) < 0) {
		perror("Failed to listen on socket");
		close(serverSocket);
		return 1;
	}

	try
	{
		while(true){
			sockaddr_in clientAddress;
			socklen_t clientAddressLen = sizeof(clientAddress);
			int newsockfd = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLen);
			
			if(newsockfd < 0){
				printf("Failed to accept connect");
			}
			
			threads.emplace_back(thread(requestListener, newsockfd, clientAddress));
			threads.back().detach();
		}
	}
	catch(const exception& e)
	{
		cerr << e.what() << '\n';
	}
	close(serverSocket);
	return 0;
}
