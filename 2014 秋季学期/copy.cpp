#include<stdio.h>
#include<stdlib.h>
#define N 10
int main(void)
{
	FILE*fp1;
	FILE*fp2;
	fp1 = fopen("from.txt", "r");
	fp2 = fopen("to.txt", "w");
	int i,a=0,j;
	scanf("%d", &j);
	for (i = 0; i < N; i++)
	{
		fscanf(fp1, "%d", &a);
		if (a>j) fprintf(fp2, "%d ", a);
	}
	fclose(fp1);
	fclose(fp2);
}