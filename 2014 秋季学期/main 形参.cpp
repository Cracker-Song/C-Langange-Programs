#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double atof1(char a[])
{
	int i=0,j=0,k=0;
	double sum=0;
	while(a[i]!='\0')
	{
		if(a[i]<'0'||a[i]>'9')
		if(a[i]!='.')
		{
			printf("wrong\n");
			return 0;
		}
		i++;
	}
	i=0;
	while(a[i]!='.'&&a[i]!='\0') i++;
	while(a[j]!='\0') j++;
	//printf("%d  %d\n",i,j);
	//printf("%lf\n",double(a[0]-48)*pow(10.0,0));
	for(k=0;k<i;sum+=double(a[k]-'0')*pow(10,i-1-k),k++);
	//printf("%d\n",k);
	for(k=j;k>=i+2;sum+=double(a[k]-48)/pow(10,k-i-1),k--);
	//printf("%d\n",k);
	//printf("%lf",sum);
	return sum;
}
main(int argc,char *argv[])
{
	printf("上底为%0.3f下底为%0.3f高为%0.3f面积为%0.3f\n",atof1(argv[1]),atof1(argv[2]),atof1(argv[3]),(atof1(argv[1])+atof1(argv[2]))*atof1(argv[3])/2);
	system("pause");
}
