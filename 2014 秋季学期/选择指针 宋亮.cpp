#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void exchange(int &a,int &b){
	int c;
	if(a<b) c=a,a=b,b=c;
} 
void rand(int a[],int b){
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<b;a[i]=rand(),i++);
}
int main()
{
	int *p,*q,i;
	int num[100000];
	scanf("%d",&i);
	rand(num,i);
	p=&num[0];
	q=&num[0];
	while(*q!='\0')
	{
		while(*p!='\0')
		{
			exchange(*q,*p++);
		}
		q++;
		p=q;
	}
	p=&num[0];
	while(*p!='\0')
	{
		printf("%d\n",*p);
		p++;
	}
}
