#include <vector>
#include <string>
#include <iostream>
#include "request.h"
#include "parser.h"
#include "../router/router.h"

using namespace std;

Request::Request(){ }

Request::Request(vector<string> parsedBuffer, string ip){
    vector<string> lines;
    string line1;
    map<string, string> headersMap;
    int i = 0;
    for(const auto& row : parsedBuffer){
        if(i == 0){
            for (char ch : row) {
                if (ch == ' ') {
                    lines.push_back(line1);
                    line1.clear();
                } else {
                    line1 += ch;
                }
            }
            if (!line1.empty()) {
                lines.push_back(line1);
            }
            Request::method = lines.at(0);
            Request::url = lines.at(1);
            Request::ip = ip;
            cout << "Method: " << Request::method << ", Route: " << Request::url << " " << lines.at(2) << endl;
        }
        else{
            // map<string, int> map;
            for (char ch : row) {
                if (ch == ':') {
                    lines.push_back(line1);
                    line1.clear();
                } else {
                    line1 += ch;
                }
            }
            if (!line1.empty()) {
                lines.push_back(line1);
            }
            string value = lines.size() > 1 ? lines.at(1) : "";
            headersMap[lines.at(0)] = value;
        }
        lines.clear();
        line1 = "";
        Request::headers = headersMap;
        i++;
    }
}

Request::Request(char* ip, char* method, char* url){ }

void requestListener(int newsockfd, sockaddr_in clientAddress){
    char clientIP[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &clientAddress.sin_addr, clientIP, INET_ADDRSTRLEN);	

    char buffer[1024] = { 0 };
    recv(newsockfd, buffer, sizeof(buffer), 0);
    // printf("Message from %s:\n%s\n", clientIP, buffer);

    // Init Request
    Request req(parse(buffer), clientIP);
    
    // Init Routes
    routes();

    // run target route
    Router::run(req, newsockfd);

    // close 
    close(newsockfd);
}
