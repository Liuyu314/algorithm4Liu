#include <stdio.h>
#include <time.h>
#include "randomNum.h"

void merge(int data[], int p, int q, int r)
{
	int n1, n2;
	n1 = q - p + 1;
	n2 = r - q;

	int L[n1 + 1], R[n2 + 1];
	int i, j, k;
	for (i = 0; i < n1; i++)
		L[i] = data[p + i];
	for (j = 0; j < n2; j++)
		R[j] = data[q + j + 1];
	
	L[n1] = MAXNUM;
	R[n2] = MAXNUM;
	i = j = 0;
	for (k = p; k < r + 1; k++)
		if (L[i] <= R[j]) {
			data[k] = L[i];
			i++;
		} else {
			data[k] = R[j];
			j++;
		}
}

void mergeSort(int data[], int p, int r)
{
	int q;

	if (p < r) {
		q = (p + r) / 2;
		mergeSort(data, p, q);
		mergeSort(data, q + 1, r);
		merge(data, p, q, r);
	}
}

int main()
{	
	clock_t start, end;

	double cost_time;
	start = clock();

	mergeSort(randomNum, 0, MAXNUM - 1);

	end = clock();
	cost_time = (double) (end - start) / CLOCKS_PER_SEC;
	printf("%f,%d\n", cost_time, MAXNUM);

	/*	
	int i;
	for (i = 0; i < MAXNUM; i++)
		printf("%d ", randomNum[i]);
	*/
	return 0;
}
