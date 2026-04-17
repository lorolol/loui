SRC = $(wildcard src/*.cpp)
INC = inc/
LIB = $(wildcard lib/*.a)

SRC_APP = $(SRC) $(wildcard test/*.cpp)

all $(SRC):
	g++ -std=c++17 -shared -o loui.o $(SRC) -I$(INC) -lm -lpthread -lraylib -lX11 -fPIC

app $(SRC_APP):
	g++ -std=c++17 -g -o app.o $(SRC_APP) -I$(INC) -lm -lpthread -lraylib -lX11
