#include<stdio.h> 
void Creat(int HT[],int a[])
{
	int i=0,j,k;
	HT[a[i]%17]=a[i];
	i++;
	for(;i<14;i++)
	{
		j=a[i]%17;
		while(HT[j]!=9999)j=(j+1)%17;
		HT[j]=a[i];
	}
}

void Print(int HT[])
{
	int i;
	for(i=0;i<17;i++) printf("%d--%d\n",i+1,HT[i]);
	printf("\n");
}

int Search(int HT[],int b)
{
	int a=b%17,i;
	for(i=1;HT[a]!=b;a=(a+1)%17)
	{
		if(HT[a]==9999){printf("����ʧ�ܣ�\n");return i;}
		i++;
	}
	printf("�±�Ϊ%d\n",a);
	return i;
}

int Search2(int HT[],int b)
{
	int a=b%17,i;
	for(i=1;HT[a]!=b;a=(a+1)%17)
	{
		if(HT[a]==9999){printf("����ʧ�ܣ�\n");return i;}
		i++;
	}
	printf("�±�Ϊ%d\n",a);
	return a;
}

int Search1(int HT[],int b)
{
	int a=b%17,i;
	for(i=1;HT[a]!=b;a=(a+1)%17)
	{
		if(HT[a]==9999)return i;
		i++;
	}
	return i;
}

double ASL(int HT[],int b[])
{
	int i;
	double a=0;
	for(i=0;i<14;i++) a=a+Search1(HT,b[i]);
	a=a/14;
	return a;
}

void Delete(int HT[],int a)
{
	HT[Search2(HT,a)]=8888;
}

void Insert(int HT[],int a)
{
	int i,b=a%17;
	for(i=0;HT[b]!=9999&&HT[b]!=8888;b=(b+1)%17);
	HT[b]=a;
}

int main()
{
	int i,a[14]={49,30,10,41,57,14,47,23,53,66,18,68,20,44},HT[17],b;
	for(i=0;i<17;i++) HT[i]=9999; 
	while(1)
	{
		printf("1.������ϣ��\n2.��ʾ��ϣ��\n3.����\n4.����ASL\n5.ɾ������\n6.�������\n7.�˳�\n");
		scanf("%d",&i); 
		switch(i)
		{
			case 1:Creat(HT,a);break;
			case 2:Print(HT);break;
			case 3:printf("����Ҫ����Ԫ�أ�");scanf("%d",&b);printf("�Ƚ�%d��\n",Search(HT,b));break;
			case 4:printf("�ȸ�������²��ҳɹ�ASLΪ��%lf\n",ASL(HT,a));break;
			case 5:printf("����Ҫɾ����Ԫ�أ�");scanf("%d",&b);Delete(HT,b);break;
			case 6:printf("����Ҫ�����Ԫ�أ�");scanf("%d",&b);Insert(HT,b);break;
			case 7:return 0;
		}
	}
}
