# Tree and Heap
#
#create  huang_zhen@2012.11.23
#

CC=g++

CFLAGS += -pipe -Wall -g

OBJ=main.o  #BinarySearchTree.o

tree:$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o tree

main.o: main.cpp BinarySearchTree.hpp AvlSearchTree.hpp BinaryHeap.hpp LeftistHeap.hpp BinomialQueue.hpp
	$(CC) $(CFLAGS)  -c main.cpp

#BinarySearchTree.o: BinarySearchTree.hpp BinarySearchTree.cpp
#	$(CC) -c BinarySearchTree.cpp

.PHONY : clean

clean :
	@rm -f tree $(OBJ) 



#CC=g++
#
#OBJ=main_test.o code_test.o code.o
#
#code_test:$(OBJ)
#    $(CC) $(OBJ) $(GLIBS) -lpthread -o code_test 
#code.o:code.c code.h
#    $(CC) -c code.c
#code_test.o:code_test.c
#    $(CC) -I$(INCDIR) -c code_test.c
#main_test.o:main_test.c
#    $(CC) -I$(INCDIR) -c main_test.c
