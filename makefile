output: http.o server.o main.o
	g++ build/*.o -o build/output

main.o: main.cpp
	@mkdir -p build
	g++ -c main.cpp -o build/main.o

server.o: core/*.cpp
	@mkdir -p build
	g++ -c core/server.cpp -o build/server.o

http.o: core/http/*.cpp
	@mkdir -p build
	g++ -c core/http/parser.cpp -o build/parser.o
	g++ -c core/http/Request.cpp -o build/request.o

run:
	./build/output

clean: 
	rm -f build/*
