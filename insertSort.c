#include <stdio.h>
#include "randomNum.h"

int main()
{
	int key, i, j;
	int swap;

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

	for (i = 0; i < MAXNUM; i++)
		printf("%d ", randomNum[i]);
	putchar('\n');
	return 0;
}
