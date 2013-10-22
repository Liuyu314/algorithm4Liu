#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int parent(i)
{
	return (i - 1) / 2;
}

int left(i)
{
	return 2 * i + 1;
}

int right(i)
{
	return 2 * i + 2;
}

void max_heapify(int arr[], int i, int heap_size)
{
	int l = left(i);
	int r = right(i);
	int largest, swap;

	if ((l < heap_size) && (arr[l] > arr[i]))
		largest = l;
	else
		largest = i;

	if ((r < heap_size) && (arr[r] > arr[largest]))
		largest = r;

	if (largest != i) {
		swap = arr[i];
		arr[i] = arr[largest];
		arr[largest] = swap;
		max_heapify(arr, largest, heap_size);
	}
}

void build_max_heapify(int arr[], int heap_size)
{
	int i;

	for (i = (heap_size - 1) / 2; i >= 0; i--) 
		max_heapify(arr, i, heap_size);
}

void heap_sort(int arr[], int max)
{
	int i, swap;
	int heap_size = max;

	build_max_heapify(arr, heap_size);
	
	for (i = max - 1; i >= 0; i--) {
		swap = arr[0];
		arr[0] = arr[i];
		arr[i] = swap;
		heap_size--;
		max_heapify(arr, 0, heap_size);
	}
	
}

int main(int argc, char *argv[])
{
	int i;
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
	
	start = clock();
	heap_sort(randomNum, maxnum);
	end = clock();
	cost_time = (double) (end - start) / CLOCKS_PER_SEC;
	printf("%f,%d\n", cost_time, maxnum);

	fclose(fp);
	
	/*
	for (i = 0; i < maxnum; i++)
		printf("%d ", randomNum[i]);
	putchar('\n');
	*/

	return 0;
}
