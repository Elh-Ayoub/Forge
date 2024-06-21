#include "../core/http/request.h"
#include "../core/http/response.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

class UserController{
    public:
        static Response index(Request ,Response);
        static Response test2(Request, Response);
};

#endif
