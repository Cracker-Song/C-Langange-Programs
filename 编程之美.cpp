#include<stdio.h>
#include<math.h>
void multmat(long long a[],long long b[])
{
	int a0=a[1],a1=a[1],a2=a[2],a3=a[3];
	a[0]=a0*b[0]+a1*b[2];
	a[1]=a0*b[1]+a1*b[3];
	a[2]=b[0]*a2+b[2]*a3;
	a[3]=a3*b[3]+a2*b[1];
}
void expmat(long long s[])
{
	int a1=s[0],a2=s[1],a3=s[2],a4=s[3];
	s[0]=a1*a1+a2*a3;
	s[1]=a1*a2+a2*a4;
	s[2]=a1*a3+a4*a3;
	s[3]=a4*a4+a2*a3;
}
void Binary(int n,long long s[])
{
	static int i=0;
	if(n>1) Binary(n/2,s);
	s[i]=n%2;
	i++;
}
int main(void)
{
	int length=0,len=0;
	long long bin[30],mat[4]={0,1,1,1},time[30][4]={0},multiply[4];
	for(int i=0;i<30;bin[i]=-1,i++);
	scanf("%d",&length);
	Binary(length,bin);
	while(bin[len]!=-1) len++;
	for(int i=len-1;i>=0;i--)
	{
		if(i==len-1)
		{
			time[i][0]=0;
			time[i][1]=1;
			time[i][2]=1;
			time[i][3]=1;
		}
		if(i<len-1)
		{
			time[i][0]=time[i+1][0];
			time[i][1]=time[i+1][1];
			time[i][2]=time[i+1][2];
			time[i][3]=time[i+1][3];
			expmat(time[i]);
		}
	}
	if(len==1)
	{
		time[0][0]=1;
		time[0][1]=0;
		time[0][2]=0;
		time[0][3]=1;
	}
	for(int i=0;i<len;i++)
	{
		if(bin[i]==0)
		{
			time[i][0]=1;
			time[i][1]=0;
			time[i][2]=0;
			time[i][3]=1 ;
		}
	}
	multiply[0]=time[0][0];
	multiply[1]=time[0][1];
	multiply[2]=time[0][2];
	multiply[3]=time[0][3];
	for(int i=len-1;i>0;i--)
	{
		multmat(multiply,time[i]);
	}
	printf("%ld",multiply[3]);
	return 0;
}
