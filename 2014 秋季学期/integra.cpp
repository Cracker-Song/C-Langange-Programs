#include<stdio.h>
#include<math.h>
#define inf (fabs(a-b)/1000000)
#define y1(k,x,m) (k*pow(x,m))
//#define y~sin(k,x,w,m) (k*sin(w*x+m))
char *judge(char F[])
{
	char *p=F;
	int i=0;
	/*while(*p!='\0')
	{
		if(*p==94) i++;
	}
	if(i!=0)*/
	while(*p!=120)
	{
		p++;
		if(*p=='\0') break;
	}
	return p;
}
float integra()
{
	 double a,b,x,sum=0,k=0,m;
	 int i;
	 char F[10000];
	 printf("请输入积分上下限\n");
	 scanf("%lf%lf",&a,&b);
	 printf("请输入函数形式\n");
	 fflush(stdin);
	 gets(F);
	 char *p=judge(F);
	 if(p-F!=0) for(i=0;i<p-F;i++) k+=(*(F+i)-48)*pow(10,p-F-i-1);
	 else k=1;
	 if(*(p+2)!='\0') m=*(p+2)-48;
	 else m=1; 
	 //printf("%lf   %lf    %lf   %d   %c\n",k,m,inf,p-F,*(F+0));
	 for(x=a;x<b;sum=sum+(y1(k,x,m)+y1(k,x+inf,m))*inf/2,x=x+inf);
	 return sum;
}
int main()
{
	printf("%0.3lf",integra());
	return 0;
}
