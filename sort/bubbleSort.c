#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exchange(int *a, int *b)
{
	int swap;

	swap = *b;
	*b = *a;
	*a = swap;
}

void bubbleSort(int arr[], int p, int r)
{
	int i, j;

	for (i = p; i < r; i++)
		for (j = i + 1; j < r; j++)
			if (arr[i] > arr[j])
				exchange(&arr[j], &arr[i]);
}

int main(int argc, char *argv[])
{
	FILE *fp;
	int i;

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
	
	start = clock();
	bubbleSort(randomNum, 0, maxnum);
	end = clock();

	cost_time = (double) (end - start) / CLOCKS_PER_SEC;
	printf("%f,%d\n", cost_time, maxnum);
	
	fclose(fp);
	
	/*	
	int i;
	for (i = 0; i < maxnum; i++)
		printf("%d ", randomNum[i]);
	*/

	return 0;
}
