#include<stdio.h>
#include<stdlib.h>
#define N 10
int main(void)
{
	FILE*fp;
	int num[N],sum=0,n,i;
	fp = fopen("number.txt", "r");
	printf("�������������\n");//����ɾ�� 
	scanf("%d", &n);/*����ɾ��*/ 
	for (i = 0; i < N; i++)
	{
		fscanf(fp, "%d",&num[i]);
		if (num[i] >= n) sum++;
	}
	printf("���ڵ���%d��������%d��", n, sum);
	fclose(fp);
}
