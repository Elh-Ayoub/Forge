#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <vector>
#include <string>
using namespace std;

#ifndef REQUEST_H
#define REQUEST_H

void requestListener(int, sockaddr_in);
class Request{
    public:
        Request();
        Request(vector<string> buffer, string ip);
        Request(char* ip, char* method, char* url);
        string ip;
        string method;
        string url;
        char** headers;
        char** body;
        char** query;
    
    // static void init();
};

#endif
