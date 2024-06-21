# Specify the compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Directories
SRC_DIR = core
HTTP_DIR = core/http
ROUTER_DIR = core/router
CONTROLLER_DIR = controllers
BUILD_DIR = build

# Source files
MAIN_SRC = main.cpp
ROUTES_SRC = routes.cpp
SERVER_SRC = $(wildcard $(SRC_DIR)/*.cpp)
HTTP_SRC = $(wildcard $(HTTP_DIR)/*.cpp)
ROUTER_SRC = $(wildcard $(ROUTER_DIR)/*.cpp)
CONTROLLER_SRC = $(wildcard $(CONTROLLER_DIR)/*.cpp)

# Object files
MAIN_OBJ = $(BUILD_DIR)/main.o
ROUTES_OBJ = $(BUILD_DIR)/routes.o
SERVER_OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SERVER_SRC))
HTTP_OBJ = $(patsubst $(HTTP_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(HTTP_SRC))
ROUTER_OBJ = $(patsubst $(ROUTER_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(ROUTER_SRC))
CONTROLLER_OBJ = $(patsubst $(CONTROLLER_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CONTROLLER_SRC))

# The final output executable
OUTPUT = $(BUILD_DIR)/output

# Default target
all: $(OUTPUT)

# Rule to link all object files into the final executable
$(OUTPUT): $(SERVER_OBJ) $(HTTP_OBJ) $(CONTROLLER_OBJ) $(ROUTER_OBJ) $(MAIN_OBJ) $(ROUTES_OBJ)
	$(CXX) $^ -o $@

# Rule to compile main.cpp into main.o
$(BUILD_DIR)/main.o: $(MAIN_SRC)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile routes.cpp into routes.o
$(BUILD_DIR)/routes.o: $(ROUTES_SRC)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile core/*.cpp into build/*.o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile core/http/*.cpp into build/*.o
$(BUILD_DIR)/%.o: $(HTTP_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile controllers/*.cpp into build/*.o
$(BUILD_DIR)/%.o: $(ROUTER_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile controllers/*.cpp into build/*.o
$(BUILD_DIR)/%.o: $(CONTROLLER_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run target to execute the program
run: $(OUTPUT)
	./$(OUTPUT)

# Clean target to remove generated files
clean:
	rm -rf $(BUILD_DIR)/*.o $(OUTPUT)
