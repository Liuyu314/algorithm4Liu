insertSort: insertSort.c randomNum.h
	gcc insertSort.c -o insertSort

genRandomNum: genRandomNum.c
	gcc genRandomNum.c -o genRandomNum

test:
	./test.sh

clean:
	-rm -rf *.o 
