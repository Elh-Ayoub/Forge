#include <sys/socket.h>
#include <string.h>
#include "response.h"
#include <sstream>

Response Response::json(std::string body){
    this->body = body;
    type = "application/json";
    return (* this);
}
Response Response::text(std::string body){
    this->body = body;
    type = "text/plain";
    return (* this);
}
Response Response::setStatus(int status){
    this->status = status;
    return (* this);
}
void Response::exec(int fd){

    std::ostringstream responseStream;
    responseStream << "HTTP/1.1 " << status << "\r\n";
    responseStream << "Content-Type: " << type << "\r\n";
    responseStream << "\r\n";
    responseStream << body;

    std::string response = responseStream.str();

    int bytesSent = send(fd, response.c_str(), response.size(), 0);
    if (bytesSent < 0) {
        perror("Error sending response");
    }
}
Response::Response(){
    this->status = 200;
    this->type = "text/plain";
}
