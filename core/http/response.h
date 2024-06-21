#include <string>
#ifndef RESPONSE_H
#define RESPONSE_H

class Response{

    int status;
    std::string type;
    std::string body;
    
    public:
        Response();
        Response text(std::string);
        Response json(std::string);
        Response setStatus(int);
        void exec(int fd);
};

#endif
