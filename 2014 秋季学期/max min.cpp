#include<stdio.h>
#include<time.h>
#include<stdlib.h>
float fmax(float a,float b)
{
	if(a>b) return a;
	else return b;
}
float fmin(float a,float b)
{
	if(a<b) return a;
	else return b;
}
float proarray(float a[],int n,float *result,float (*p)(float a,float b))
{
	int j;
	result=a;
	for(j=0;j<n-1;j++) *result=(*p)(*result,a[j]);
	return *result;
}
void rand(float a[],int b)
{
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<b;a[i]=rand()/10.0,i++);
}
int main(int argc,char *a[])
{
	float num[10000];
	//scanf("%d",&i);
	int i=a[1][0]-48;
	rand(num,i);
	float *result=num;
	printf("最大值%f最小值%f\n",proarray(num,i,result,fmax),proarray(num,i,result,fmin));
	printf("%d",i);
	system("pause");
	return 0;
}
