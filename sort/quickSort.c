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

int partition(int arr[], int p, int r)
{
	int x = arr[r];
	int i = p - 1;
	int j;

	for (j = p; j < r; j++) {
		if (arr[j] <= x) {
			i++;
			exchange(&arr[i], &arr[j]);
		}	
	}
	exchange(&arr[i + 1], &arr[r]);
	return i + 1;
}

int randomPartition(int arr[], int p, int r)
{
	int i = p + rand() % (r - p + 1);
	exchange(&arr[r], &arr[i]);
	return partition(arr, p, r);
}

void quickSort(int arr[], int p, int r)
{
	int q;

	if (p < r) {
		q = randomPartition(arr, p, r);
		quickSort(arr, p, q - 1);
		quickSort(arr, q + 1, r);
	}
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
	quickSort(randomNum, 0, maxnum - 1);
	end = clock();

	cost_time = (double) (end - start) / CLOCKS_PER_SEC;
	printf("%f,%d\n", cost_time, maxnum);
	
	fclose(fp);
	/*
	int i;
	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	*/

	return 0;
}
