CFLAGS =-std=c++11 -g

all: list

list: main.cpp LinkedList.h LinkedListInterface.h
	g++ $(CFLAGS) -ggdb3 -o LinkedList main.cpp