#include<stdio.h>
#include<stdlib.h>
#define N 10
int main(void)
{
	FILE*fp;
	fp = fopen("number1.txt", "r");
	int i, a[N];
	for (i = 0; i < N; i++)
	{
		fscanf(fp, "%d", &a[i]);
		printf("%d\n", a[i]);
	}
	fclose(fp);
	fp = fopen("number1.txt", "w");
	for (i = 0; i < N; i++)
	{
		if (a[i]%2 == 0) fprintf(fp,"%d ",a[i]+1);
		else fprintf(fp,"%d ", a[i]*2);
	}
	fclose(fp);
}