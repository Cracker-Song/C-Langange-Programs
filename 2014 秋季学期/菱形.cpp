#include<stdio.h>
main()
{
	int a,b,i,k=1; 
	scanf("%d%d",&a,&b);
	a=2*a-1;
	for(k=1;k<=(a+1)/2;k++){
		for(i=1;i<=(a+1)/2-k;printf(" "),i++);
		if(2*b>=2*k-1) for(i=1;i<=(2*k-1);printf("*"),i++);
		else for(i=1;i<=(b);printf("*"),i++);
		if(2*b<2*k-1) for(i=b+1;i<=2*k-b-1;printf(" "),i++);
		if(2*b<2*k-1) for(i=2*k-b;i<=2*k-1;printf("*"),i++);
		printf("\n");
	};
	for(k=(a-1)/2;k>=1;k--){
		for(i=1;i<=(a+1)/2-k;printf(" "),i++);
		if(2*b>=2*k-1) for(i=1;i<=(2*k-1);printf("*"),i++);
		else for(i=1;i<=(b);printf("*"),i++);
		if(2*b<2*k-1) for(i=b+1;i<=2*k-b-1;printf(" "),i++);
		if(2*b<2*k-1) for(i=2*k-b;i<=2*k-1;printf("*"),i++);
		printf("\n");
	};
}
