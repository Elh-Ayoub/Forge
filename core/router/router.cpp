#include "router.h"
#include <stdlib.h>

std::vector<Route> Router::routes;
Route::Route(std::string path, Response (*func)(Request, Response), std::string method){
    this->path = path;
    this->func = func;
    this->method = method;
}

void Router::add(std::string path, Response (*func)(Request, Response), std::string method){
    Route route(path, func, method);
    routes.push_back(route);
}
void Router::GET(std::string path, Response (*func)(Request, Response)){
    Router::add(path, func, "GET");
}
void Router::POST(std::string path, Response (*func)(Request, Response)){
    add(path, func, "POST");
}
void Router::PATCH(std::string path, Response (*func)(Request, Response)){
    add(path, func, "PATCH");
}
void Router::DELETE(std::string path, Response (*func)(Request, Response)){
    add(path, func, "DELETE");
}

void Router::run(Request req, int fd){
    Response res;
    for(const Route &route : routes){
        if(route.path == req.url && route.method == req.method){
            res = route.func(req, res);
            res.exec(fd);
            return;
        }
    }
    // Not found
    res.text("Not Found");
    res.setStatus(404);
    res.exec(fd);
}
