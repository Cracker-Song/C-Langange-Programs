#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int exchange(int &a,int &b){
	int c;
	if(a>b) c=a,a=b,b=c;
} 
int rand(int a[],int b){
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<b;a[i]=rand(),i++);
}
int print(int a[],int b){
	int i;
	for(i=0;i<b;printf("array~%d=%d\n",i,a[i]),i++);
}
int maxsort2(int a[],int b){
	int i,n;
	for(i=0;i<b;i++){
		for(n=0;n<b-i;exchange(a[i],a[n+i]),n++);
	}
}
main(){
	int array[100000],b;
	scanf("%d",&b);
	rand(array,b);
	print(array,b);
	maxsort2(array,b);
	print(array,b);
}
