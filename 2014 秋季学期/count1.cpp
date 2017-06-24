#include<stdio.h>
#include<stdlib.h>
#define N 10
int main(void)
{
	FILE*fp;
	int num[N],sum=0,n,i;
	fp = fopen("number.txt", "r");
	printf("请输入给定整数\n");//将被删除 
	scanf("%d", &n);/*将被删除*/ 
	for (i = 0; i < N; i++)
	{
		fscanf(fp, "%d",&num[i]);
		if (num[i] >= n) sum++;
	}
	printf("大于等于%d的整数有%d个", n, sum);
	fclose(fp);
}
