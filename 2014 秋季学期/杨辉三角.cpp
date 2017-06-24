#include<stdio.h>
#include<stdlib.h>
int factorial(int i)
{
	int j,k=1;
	for(j=i;j>1;k*=j,j--);
	return k;
}
void triangle(int i)
{
	int j,k;
	for(j=0;j<i;j++)
	{
		for(k=0;k<=i-j;printf("   "),k++);
		for(k=0;k<=j;printf("%4d  ",factorial(j)/(factorial(k)*factorial(j-k))),k++);
		printf("\n\n");
	}
}
int main()
{
	int i;
	printf("请输入杨辉三角高度\n");
	scanf("%d",&i);
	triangle(i);
	return 0;
}
