#include "../core/http/request.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

class UserController{
    public:
        static void index(Request request);
        static void test2(Request request);
};

#endif
