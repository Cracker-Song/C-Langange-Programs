#include<stdio.h>
#include<string.h>
int count()
{
	char a[10000],*p=a;
	int eng1=0,eng2=0,space=0,num=0,oth=0;
	gets(a);
	while(*p!='\0')
	{
		if(*p>=97&&*p<=122) eng1++;
		else if(*p>=65&&*p<=90) eng2++;
		else if(*p>=48&&*p<=57) num++;
		else if(*p==32) space++;
		else oth++;
		p++;
	}
	printf("小写字母%d大写字母%d数字%d空格%d其他%d",eng1,eng2,num,space,oth);
	return 0;
}
main()
{
	count();
}
