#include<stdio.h>
#include<stdlib.h>
int num;
void str_input(char words[][1000])
{
	int k;
	printf("�������ַ�����Ŀ\n");
	scanf("%d",&num);
	for(k=0;k<num;k++)
	{
		fflush(stdin);
		printf("�������%d���ַ���\n",k);
		gets(words[k]);
	}
}
int str_Long(char words[])
{
	int i=0;
	while(words[i]!='\0')
		{
			i++;
		}
	return i;
}
int str_cmp(char a[],char b[])
{
	int i=0;
	while(1)
	{
		if(a[i]>b[i]) return 1;
		i++;
		if(i>=str_Long(a)) break;
	}
	while(1)
	{
		if(a[i]<b[i]) return 1;
		i++;
		if(i>=str_Long(a)) break;
	}
	return 0;
}
void str_compare(char words[][1000])
{
	int i,j,k;
	printf("������Ҫ�Ƚϵ������ַ���������\n");
	scanf("%d%d",&i,&k);
	if(i>=num||k>=num)
	{
		printf("����������������\n");
		return;
	}
	j=str_cmp(words[i],words[k]);
	if(j>0) printf("�ַ���%dС���ַ���%d\n",k,i);
	else if(j==0) printf("�ַ���%d�����ַ���%d\n",k,i);
	else printf("�ַ���%d�����ַ���%d\n",k,i);
}
int main()
{
	char words[1000][1000];
	str_input(words);
	str_compare(words);
}
