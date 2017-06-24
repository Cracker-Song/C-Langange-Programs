#include<stdio.h>
#include<stdlib.h>
int sushu(int prime[],int(n)){
	int i,j,k;
	int line[10000];
	for(i=0;i<=n;i++) line[i]=1;
	for(i=2,k=0;i<=n;i++){
		if(line[i]){
			prime[k]=i;k++;
			for(j=i+1;j<=n;j++)
			if(j%i==0) line[j]=0;
		}
	}
	return k;
}
main(){
	int n,prime[100000],k=0,i,j;
	flag:scanf("%d",&n);
	if(n%2!=0)
	{
	printf("Wrong number\n");
	system("pause");
	system("cls");
	goto flag;
	}
	i=sushu(prime,n)-1;//生成比这个数小的所有素数 
	j=i;
	while(prime[k]!=0)
	{
		while(prime[i]+prime[k]>=n){
			if(prime[i]+prime[k]==n) printf("%d=%d+%d\n",n,prime[k],prime[i]);
			if(i>=0) i--;else break;
		}
		if(k>(i+1)/2) break;
		k++;
		i=j;
	}
}

