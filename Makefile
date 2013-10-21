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

# Testing


test_insertSort:
	./test.sh insertSort

test_mergeSort:
	./test.sh mergeSort

# Clean

clean:
	-rm -rf *.o 
	-rm $(BIN)/*
