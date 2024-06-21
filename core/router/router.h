#include <string>
#include <vector>
#include "../http/request.h"
#include <iostream>
#ifndef ROUTER_H
#define ROUTER_H

class Route{
    
    public:
        Route(std::string path, void (*func)(Request), std::string method);
        std::string path;
        std::string method;
        void (*func)(Request);
};

class Router{
    public:
        static std::vector<Route> routes;
        static void GET(std::string path, void (*func)(Request));
        static void POST(std::string path, void (*func)(Request));
        static void PATCH(std::string path, void (*func)(Request));
        static void DELETE(std::string path, void (*func)(Request));
        static void run(Request req);
    private:
        static void add(std::string path, void (*func)(Request), std::string method);

};

void routes();
#endif
 