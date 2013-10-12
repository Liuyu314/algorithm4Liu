insertSort: insertSort.c
	gcc insertSort.c -o insertSort

genRandomNum: genRandomNum.c
	gcc genRandomNum.c -o genRandomNum

clean:
	-rm -rf *.o 

