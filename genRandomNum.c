#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int MAXNUM;
	if (argc == 1) 
		MAXNUM = 100000;
	else if (argc == 2)
		MAXNUM = atoi(argv[1]);
	else {
		printf("error: too much arguments\n");
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
	
	if ((fp = fopen("randomNum.h", "w")) != NULL) {
		sprintf(strNum, "%d", MAXNUM);
		fprintf(fp, "#define MAXNUM %s\n", strNum);
		fprintf(fp, "int randomNum[MAXNUM] = {\n");
		for (i = 0; i < MAXNUM - 1; i++) {
			if (enter == 10) {
				enter = 0;
				fprintf(fp, "\n");
			}
			enter++;
			sprintf(strNum, "%d", rand() % MAXNUM);
			fprintf(fp, "%s, ", strNum);
		}
		sprintf(strNum, "%d", rand() % MAXNUM);
		fprintf(fp, "%s", strNum);
		fprintf(fp, "};\n");
	}
	fclose(fp);
	return 0;
}
