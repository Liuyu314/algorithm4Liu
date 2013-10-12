#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 1000

int main()
{
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
		fprintf(fp, "#define MAXNUM 1000\n");
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
