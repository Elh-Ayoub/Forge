#include "controller.h"
#include <iostream>

Response UserController::index(Request request, Response response){
    return response.json("{'message': 'Index'}");
}

Response UserController::test2(Request request, Response response){
    return response.text("Test 2").setStatus(401);
}
