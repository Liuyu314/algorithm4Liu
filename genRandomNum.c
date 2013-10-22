#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int MAXNUM;
	if (argc == 2) //genRandomNum filename
		MAXNUM = 100000;
	else if (argc == 3) //genRandomNum 10000 filename
		MAXNUM = atoi(argv[1]);
	else {
		printf("error: wrong arguments\n");
		exit(-1);
	}

	printf("%d\n", MAXNUM);

	FILE *fp;
	int i, enter = 0;
	int len, num;
	len = 1;
	num = MAXNUM;
	while (num != 0) {
		num = num / 10;
		len++;
	}
	
	char strNum[len];
	
	if ((fp = fopen(argv[2], "w")) != NULL) {
		sprintf(strNum, "%d", MAXNUM);
		fprintf(fp, "#MAXNUM %s \n", strNum);
		for (i = 0; i < MAXNUM - 1; i++) {
			sprintf(strNum, "%d", rand() % MAXNUM);
			fprintf(fp, "%s ", strNum);
		}
		sprintf(strNum, "%d", rand() % MAXNUM);
		fprintf(fp, "%s", strNum);
	}
	fclose(fp);
	return 0;
}
