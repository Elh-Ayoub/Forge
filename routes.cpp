#include "core/router/router.h"
#include "controllers/controller.h"


void routes(){
    Router::GET("/", UserController::index);
    Router::GET("/test", UserController::test2);
}
