#include <stdio.h>
#include <time.h>

#include "randomNum.h"

int main()
{
	int key, i, j;
	int swap;
	
	clock_t start, end;

	double cost_time;
	start = clock();
	for (j = 1; j < MAXNUM; j++) {
		key = randomNum[j];
		i = j - 1;
		while ((i >= 0) && (randomNum[i] > key)) {
			swap = randomNum[i + 1];
			randomNum[i + 1] = randomNum[i];
			randomNum[i] = swap;
			i--;
		}
		randomNum[i + 1] = key;
	}

	/*
	for (i = 0; i < MAXNUM; i++)
		printf("%d ", randomNum[i]);
	putchar('\n');
	*/
	end = clock();
	cost_time = (double) (end - start) / CLOCKS_PER_SEC;
	printf("%f,%d\n", cost_time, MAXNUM);
	return 0;
}
