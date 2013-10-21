#include <stdio.h>

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

	for (i = (10 - 1) / 2; i >= 0; i--) 
		max_heapify(arr, i, heap_size);
}

void heapsort(int arr[])
{
	int i, swap;
	int heap_size = 10;

	build_max_heapify(arr, heap_size);
	
	for (i = 9; i >= 0; i--) {
		swap = arr[0];
		arr[0] = arr[i];
		arr[i] = swap;
		heap_size--;
		max_heapify(arr, 0, heap_size);
	}
	
}

int main(void)
{
	int i;
	int arr[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8 ,7};

	heapsort(arr);
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}
