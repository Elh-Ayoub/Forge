#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include "http/parser.h"
#include "http/request.h"

using namespace std;

int init(){
    int port = 8000;
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	printf("init...\n");
	sockaddr_in serverAddres;
	serverAddres.sin_family = AF_INET;
	serverAddres.sin_port = htons(port);
	serverAddres.sin_addr.s_addr = INADDR_ANY;

	if(bind(serverSocket, (struct sockaddr*)&serverAddres, sizeof(serverAddres)) < 0){
		printf("Failed to bind socket!\n");
		return -1;
	}

    printf("Listening on port: %i\n", port);
	while(listen(serverSocket, 100) == 0){
		sockaddr_in clientAddress;
		socklen_t clientAddressLen = sizeof(clientAddress);
		int newsockfd = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLen);
		
		if(newsockfd < 0){
			printf("Failed to accept connect");
		}

		char clientIP[INET_ADDRSTRLEN];
		inet_ntop(AF_INET, &clientAddress.sin_addr, clientIP, INET_ADDRSTRLEN);	

	    char buffer[1024] = { 0 };
		recv(newsockfd, buffer, sizeof(buffer), 0);
		printf("Message from %s:\n%s\n", clientIP, buffer);

        Request req(parse(buffer), clientIP);

		const char* response = 
		"HTTP/1.1 200 OK\r\n"
		"Content-Type: application/json\r\n"
		"\r\n"
		"{\"message\": \"Hello, world\"}";

		// Send the response
		int bytesSent = send(newsockfd, response, strlen(response), 0);
		if (bytesSent < 0) {
			perror("Error sending response");
		}
		close(newsockfd);
	}
	close(serverSocket);
	return 0;
}
