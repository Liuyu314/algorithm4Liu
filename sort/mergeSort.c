#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int data[], int p, int q, int r, int maxnum)
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
	
	L[n1] = maxnum;
	R[n2] = maxnum;
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

void mergeSort(int data[], int p, int r, int maxnum)
{
	int q;

	if (p < r) {
		q = (p + r) / 2;
		mergeSort(data, p, q, maxnum);
		mergeSort(data, q + 1, r, maxnum);
		merge(data, p, q, r, maxnum);
	}
}

int main(int argc, char *argv[])
{	
	clock_t start, end;
	int i;
	FILE *fp;

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
	mergeSort(randomNum, 0, maxnum - 1, maxnum);
	end = clock();

	cost_time = (double) (end - start) / CLOCKS_PER_SEC;
	printf("%f,%d\n", cost_time, maxnum);
	
	/*	
	for (i = 0; i < maxnum; i++)
		printf("%d ", randomNum[i]);
	*/

	return 0;
}
