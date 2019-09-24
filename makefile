CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++14 $(DEBUG) -O0 -pedantic-errors
LFLAGS = -Wall $(DEBUG)

main: ItemType.h ListNode.h SortedLinkedList.h main.cpp ItemType.cpp SortedLinkedList.cpp
        $(CC) $(CFLAGS) -o main main.cpp ItemType.cpp SortedLinkedList.cpp

clean:
        rm -rf main
        rm -rf *.o

