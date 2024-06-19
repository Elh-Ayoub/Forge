#include <vector>
#include <string>
#include <iostream>
#include "request.h"
using namespace std;

Request::Request(){

}

Request::Request(vector<string> parsedBuffer, string ip){
    // parse(buffer);
    const auto& row1 = parsedBuffer.at(0);

    
    // Method
    vector<string> lines;
    string line1;

    for (char ch : row1) {
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

Request::Request(char* ip, char* method, char* url){

}
