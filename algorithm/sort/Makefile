# MY TEST
#
#create  @ 2012.11.22
#modefy 1@ 
#
CC=g++

OBJ=main.o InsertionSort.o BubbleSort.o  QuickSort.o ShellSort.o MergeSort.o HeapSort.o

sort:$(OBJ)
	$(CC) $(OBJ) -o sort

main.o: main.cpp InsertionSort.hpp BubbleSort.hpp QuickSort.hpp ShellSort.hpp MergeSort.hpp HeapSort.hpp
	$(CC) -c main.cpp

InsertionSort.o: InsertionSort.cpp InsertionSort.hpp
	$(CC) -c InsertionSort.cpp

BubbleSort.o: BubbleSort.cpp BubbleSort.hpp
	$(CC) -c BubbleSort.cpp

ShellSort.o: ShellSort.cpp ShellSort.hpp
	$(CC) -c ShellSort.cpp

QuickSort.o: QuickSort.cpp QuickSort.hpp InsertionSort.hpp
	$(CC) -c QuickSort.cpp

MergeSort.o: MergeSort.cpp MergeSort.hpp
	$(CC) -c MergeSort.cpp

HeapSort.o: HeapSort.cpp HeapSort.hpp
	$(CC) -c HeapSort.cpp

clean: 
	-rm sort $(OBJ) 

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
