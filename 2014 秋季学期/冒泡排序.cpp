#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void exchange(int &a,int &b){
	int c;
	if(a>b) c=a,a=b,b=c;
} 
void rand(int a[],int b){
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<b;a[i]=rand(),i++);
}
void print(int a[],int b){
	int i;
	for(i=0;i<b;printf("array~%d=%d\n",i,a[i]),i++);
}
void maxsort1(int a[],int b){
	int i,n;
	for(i=0;i<b;i++){
		for(n=0;n<b-1;exchange(a[n],a[n+1]),n++);
	}
}
main(){
	int array[100000],b;
	scanf("%d",&b);
	rand(array,b);
	print(array,b);
	maxsort1(array,b);
	print(array,b);
}
