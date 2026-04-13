SRC = $(wildcard src/*.cpp)
INC = inc/
LIB = $(wildcard lib/*.a)

SRC_APP = $(SRC) + $(wildcard test/*.cpp)

all $(SRC):
	g++ -std=c++17 -o loui.o $(SRC) -I$(INC) -lm -lpthread -lraylib -lX11

app $(SRC_APP):
	g++ -std=c++17 -o loui.o $(SRC_APP) -I$(INC) -lm -lpthread -lraylib -lX11
