#include "core/router/router.h"
#include "controllers/controller.h"


void routes(){
    Router::GET("/", UserController::index);
    Router::POST("/test", UserController::test2);
}
