#include <string>
#include <vector>
#include "../http/request.h"
#include "../http/response.h"
#include <iostream>
#ifndef ROUTER_H
#define ROUTER_H

class Route{
    
    public:
        Route(std::string path, Response (*func)(Request, Response), std::string method);
        std::string path;
        std::string method;
        Response (*func)(Request, Response);
};

class Router{
    public:
        static std::vector<Route> routes;
        static void GET(std::string path, Response (*func)(Request, Response));
        static void POST(std::string path, Response (*func)(Request, Response));
        static void PATCH(std::string path, Response (*func)(Request, Response));
        static void DELETE(std::string path, Response (*func)(Request, Response));
        static void run(Request req, int fd);
    private:
        static void add(std::string path, Response (*func)(Request, Response), std::string method);

};

void routes();
#endif
 