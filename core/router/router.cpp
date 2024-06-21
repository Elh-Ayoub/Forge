#include "router.h"

std::vector<Route> Router::routes;
Route::Route(std::string path, void (*func)(Request), std::string method){
    this->path = path;
    this->func = func;
    this->method = method;
}

void Router::add(std::string path, void (*func)(Request), std::string method){
    Route route(path, func, method);
    routes.push_back(route);
}
void Router::GET(std::string path, void (*func)(Request)){
    Router::add(path, func, "GET");
}
void Router::POST(std::string path, void (*func)(Request)){
    add(path, func, "POST");
}
void Router::PATCH(std::string path, void (*func)(Request)){
    add(path, func, "PATCH");
}
void Router::DELETE(std::string path, void (*func)(Request)){
    add(path, func, "DELETE");
}

void Router::run(Request req){
    
    for(const Route &route : routes){
        if(route.path == req.url && route.method == req.method){
            route.func(req);
            return;
        }
    }

    // Not found
    std::cout << "Not Found" << std::endl;
}
