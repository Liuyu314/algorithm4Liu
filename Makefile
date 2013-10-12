insertSort: insertSort.c randomNum.h
	gcc insertSort.c -o insertSort

mergeSort: mergeSort.c randomNum.h
	gcc mergeSort.c -o mergeSort

genRandomNum: genRandomNum.c
	gcc genRandomNum.c -o genRandomNum

test_insertSort:
	./test.sh insertSort

test_mergeSort:
	./test.sh mergeSort

clean:
	-rm -rf *.o 
