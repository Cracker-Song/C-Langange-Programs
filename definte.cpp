#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define pi 3.141592653
#define e 2.718281
#define y1(k,x,m) (k*pow(x,m))
#define y2(k,w,x) (k*sin(w*x))
#define y3(k,w,x) (k*cos(w*x))
#define y4(A,w,x) (A*pow(e,w*x))
#define inf (fabs(a-b)/500000)
char f[1000][1000];
//double y[1000];
void cut(char a[])//字符串切割 
{
	system("color 70");
	//printf("go\n");
	char *p=a,*q=a,*n=a;
	int i=0;
	while(1)
	{
		if(*p=='+'||*p=='\0'||*p=='-')
		{
			for(q=p-1;q>=a;q--)
			{
				if(i==0) f[i][q-a]=*(q);
				else f[i][q-a-1]=*(q);
			}
			a=p;
			i++;
		}
		if(*p=='\0') break;
		p++;
	}
	i=0;
	/*while(f[i][0]!='\0')
	{
		puts(f[i]);
		i++;
	}*/
}
int judge(char F[])//判断函数类型 
{
	int i,a=0,b=0,c=0,d=0;
	for(i=0;i<strlen(F);i++)
	{
		if(F[i]=='s'&&F[i+1]=='i'&&F[i+2]=='n')
		{
			a++;
		}
		if(a!=0) return 2;
	}//正弦函数判断 
	for(i=0;i<strlen(F);i++)
	{
		if(F[i]=='c'&&F[i+1]=='o'&&F[i+2]=='s')
		{
			a++;
		}
		if(a!=0) return 3;
	}//余弦函数判断 
	for(i=0;i<strlen(F);i++)
	{
		if(F[i]=='x')
		{
			if(F[i+1]==94||F[i+1]=='\0') a++;
		}
		if(a!=0) return 1;
	}//幂函数判断 
}
double F1(double a,double b,char F[])//幂函数积分计算 
{
	char *q=F,*p;
	int i;
	double x,sum=0,k=0,m=0;
	//printf("go\n");
	while(*q!=120)
	{
		q++;
		if(*q=='\0') break;
	}
	p=q;
	if(p-F!=0) for(i=0;i<p-F;i ++) k+=(*(F+i)-48)*pow(10.0,p-F-i-1);
	else k=1.0;
	if(*(p+2)!='\0') for(i=1;*(q+1+i);i++) m+=(*(q+i+1)-48)*pow(10.0,strlen(F)-(q-F)-2-i);
	else m=1.0;   
	//printf("%lf   %lf    %lf   %d   %c   %c\n",k,m,inf,p-F,*(F),*q);
	for(x=a;x<b;sum=sum+fabs(y1(k,x,m)+y1(k,x+inf,m))*inf/2,x=x+inf);
	return sum;
}
double F2(double a,double b,char F[])//正弦函数积分计算 
{
	char *q=F,*p;
	int i;
	double x,sum=0,k=0,w=0;
	//printf("go\n");
	while(*q!='\0')
	{
		if(*q=='s'&&*(q+1)=='i'&&*(q+2)=='n') break;
		q++;
	}
	p=q;
	if(p-F!=0) for(i=0;i<p-F;i ++) k+=(*(F+i)-48)*pow(10.0,p-F-i-1);
	else k=1.0;
	if(*(p+3)!='x') for(i=1;*(q+2+i)-'x';i++) w+=(*(q+i+2)-48)*pow(10.0,strlen(F)-(q-F)-4-i);
	else w=1;
	/*if(*(p+2)!='\0') for(i=1;*(q+1+i);i++) m+=(*(q+i+1)-48)*pow(10.0,strlen(F)-(q-F)-2-i);
	else m=1.0;*/
	//printf("%lf   %lf    %lf   %d   %c   %c\n",k,w,inf,p-F,*(F),*q);
	for(x=a;x<b;sum=sum+fabs(y2(k,w,x)+y2(k,w,x+inf))*inf/2,x=x+inf);
	return sum;
}
double F3(double a,double b,char F[])//余弦函数积分计算 
{
	char *q=F,*p;
	int i;
	double x,sum=0,k=0,w=0;
	//printf("go\n");
	while(*q!='\0')
	{
		if(*q=='c'&&*(q+1)=='o'&&*(q+2)=='s') break;
		q++;
	}
	p=q;
	if(p-F!=0) for(i=0;i<p-F;i ++) k+=(*(F+i)-48)*pow(10.0,p-F-i-1);
	else k=1.0;
	if(*(p+3)!='x') for(i=1;*(q+2+i)-'x';i++) w+=(*(q+i+2)-48)*pow(10.0,strlen(F)-(q-F)-4-i);
	else w=1;
	/*if(*(p+2)!='\0') for(i=1;*(q+1+i);i++) m+=(*(q+i+1)-48)*pow(10.0,strlen(F)-(q-F)-2-i);
	else m=1.0;*/
	//printf("%lf   %lf    %lf   %d   %c   %c\n",k,w,inf,p-F,*(F),*q);
	for(x=a;x<b;sum=sum+fabs(y3(k,w,x)+y3(k,w,x+inf))*inf/2,x=x+inf);
	return sum;
}
double integ()
{
	double a,b,sum=0;
	int i=0;
	char F[10000];
	printf("请输入积分上下限\n");
	scanf("%lf%lf",&a,&b);
	if(a>b)
	{
		int c;
		c=a;
		a=b;
		b=c;  
	}
	printf("请输入函数形式\n");
	fflush(stdin);
	gets(F);//读入函数形式 
	cut(F);//切割函数，分割成多个字符串 
	while(1)//判断函数类型 
	{
		if(judge(f[i])==1) sum+=F1(a,b,f[i]);
		else if(judge(f[i])==2) sum+=F2(a,b,f[i]);
		else if(judge(f[i])==3) sum+=F3(a,b,f[i]);
		/*else if(judge(f[i])==4) sum+=F4(a,b,f[i]);*/
		if(f[i][0]=='\0') break;
		i++;
	}
	//printf("%d\n",i);
	return sum;
}
int main()//主函数，输出结果 
{
	printf("%0.4lf",integ());
	system("pause");
	return 0;
}
