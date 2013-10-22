#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int key, i, j;
	int swap;
	FILE *fp;

	clock_t start, end;
	double cost_time;
	if (argc != 2) {
		printf("Wrong argument!\n");
		exit(1);
	}

	if (NULL == (fp = fopen(argv[1], "r"))) {
		printf("Cannot open the file %s!\n", argv[1]);
		exit(1);
	}
	char label[10];
	int maxnum;

	fscanf(fp, "%s %d", label, &maxnum);
	
	int randomNum[maxnum];

	for (i = 0; i < maxnum; i++)
		fscanf(fp, "%d", &randomNum[i]);
	for (i = 0; i < maxnum; i++)
		printf("%d ", randomNum[i]);
	putchar('\n');

	start = clock();
	for (j = 1; j < maxnum; j++) {
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
	for (i = 0; i < maxnum; i++)
		printf("%d ", randomNum[i]);
	putchar('\n');
	*/
	end = clock();
	cost_time = (double) (end - start) / CLOCKS_PER_SEC;
	printf("%f,%d\n", cost_time, maxnum);
	return 0;
}
