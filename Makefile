# Local Directories

ROOT = .
BIN  = $(ROOT)/bin
SORT = $(ROOT)/sort

# Compiler

CC = gcc

# Generate random file, you need to config the genRanTest.sh firstly

genRanTest:
	./genRanTest

genRandomNum: genRandomNum.c
	$(CC) $^ -o $@

# Sort Algorithm

insertSort: $(SORT)/insertSort.c 
	$(CC) $^ -o $(BIN)/$@

mergeSort: $(SORT)/mergeSort.c 
	$(CC) $^ -o $(BIN)/$@

heapSort: $(SORT)/heapSort.c 
	$(CC) $^ -o $(BIN)/$@

quickSort: $(SORT)/quickSort.c
	$(CC) $^ -o $(BIN)/$@

bubbleSort: $(SORT)/bubbleSort.c
	$(CC) $^ -o $(BIN)/$@

# Testing: you need to choose the number scale(NumLen) which in the test.sh

test_insertSort:
	./test.sh insertSort

test_mergeSort:
	./test.sh mergeSort

test_heapSort:
	./test.sh heapSort

test_quickSort:
	./test.sh quickSort

test_bubbleSort:
	./test.sh bubbleSort
# Clean

clean:
	-rm *.o 
	-rm $(BIN)/*
	-rm data* 
