#include "controller.h"
#include <iostream>

void UserController::index(Request request){
    std::cout << "Index here" << std::endl;
}

void UserController::test2(Request request){
    std::cout << "Another test!" << std::endl;
}
