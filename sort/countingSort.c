#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void countingSort(int a[], int b[], int k, int max)
{
	int i;
	int c[k];

	for (i = 0; i < k; i++)
		c[i] = 0;
	for (i = 0; i < max; i++)
		c[a[i]]++;
	for (i = 1; i < k; i++)
		c[i] = c[i] + c[i - 1];
	for (i = max - 1; i >= 0; i--) {
		b[c[a[i]] - 1] = a[i];
		c[a[i]]--;
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
	int afterSort[maxnum];

	for (i = 0; i < maxnum; i++)
		fscanf(fp, "%d", &randomNum[i]);
	
	start = clock();
	countingSort(randomNum, afterSort, maxnum, maxnum);
	end = clock();

	cost_time = (double) (end - start) / CLOCKS_PER_SEC;
	printf("%f,%d\n", cost_time, maxnum);
	
	fclose(fp);
	
		
	/*	
	for (i = 0; i < maxnum; i++)
		printf("%d ", afterSort[i]);
	*/

	return 0;
}
