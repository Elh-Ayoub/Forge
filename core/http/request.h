#include <vector>
#include <string>
using namespace std;

#ifndef REQUEST_H
#define REQUEST_H

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

    private: 
        char buffer[];
    
    // static void init();
};

#endif
