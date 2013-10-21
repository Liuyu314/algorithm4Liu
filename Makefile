# Local Directories

ROOT = .
SRC  = $(ROOT)

# Compiler

CC = gcc

# Generate random file

genRandomNum: genRandomNum.c
	$(CC) $^ -o $@

insertSort: insertSort.c randomNum.h
	gcc insertSort.c -o insertSort

mergeSort: mergeSort.c randomNum.h
	gcc mergeSort.c -o mergeSort


test_insertSort:
	./test.sh insertSort

test_mergeSort:
	./test.sh mergeSort

clean:
	-rm -rf *.o 
