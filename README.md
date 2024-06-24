# Forge - C++ Web Server

Forge is a minimalist web server implemented in C++. It is designed to be lightweight, efficient, and easy to use. The goal of Forge is to provide a simple foundation for building web applications and services in C++.

## Getting Started

#### Prerequisites

* C++11 or higher
* g++ compiler
* Make

#### Installation

1. Clone the repository:

```
git clone https://github.com/Elh-Ayoub/Forge
cd forge
```

2. Build the project:

```
make
```
3. Run the server:

```
make run
```

#### Example Usage

main.cpp
```
#include "core/server.h"

int main(){
    init();
}
```

Setup your routes in routes.cpp
```
#include "core/router/router.h"
#include "controllers/controller.h"


void routes(){
    Router::GET("/", UserController::index);
    Router::POST("/test", UserController::test2);
}
```

Controllers: controllers/*.cpp
```
#include "controller.h"
#include <iostream>

Response UserController::index(Request request, Response response){
    return response.json("{'message': 'Index'}");
}

Response UserController::test2(Request request, Response response){
    return response.text("Test 2").setStatus(401);
}
```

# Contributing

We welcome contributions! Feel free to submit issues and pull requests.


# License
Forge is released under the MIT `License`. See LICENSE for more information.


# Contact
If you have any questions, feel free to open an issue or contact me at `contact@aelhaddadi.com`
