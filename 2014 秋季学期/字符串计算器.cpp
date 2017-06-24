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
void str_puts(char words[][1000])
{
	int i;
	for(i=0;i<num;i++)
	{
		puts(words[i]);
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
void str_long(char words[][1000])
{
	int i;
	for(i=0;i<num;i++) printf("��%d���ַ�������Ϊ%d\n",i,str_Long(words[i]));
}
void str_cat(char a[],char b[])
{
	int i=str_Long(a),j;
	for(j=0;j<i;j++)
	{
		a[j+i]=b[j];
	}
}
void str_connect(char words[][1000])
{
	int i,k;
	printf("������Ҫ���ӵ������ַ�������\n");
	scanf("%d%d",&i,&k);
	if(i>=num||k>=num)
	{
		printf("����������������\n");
		return;
	}
	str_cat(words[i],words[k]);
	str_puts(words);
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
void str_cpy(char a[],char b[])
{
	int i;
	for(i=0;i<str_Long(b);a[i]=0,i++);
	for(i=0;i<str_Long(a);i++)
	{
		a[i]=b[i];
	}
}
void str_copy(char words[][1000])
{
	int i,k;
	printf("�����뽫�ڼ����ַ������Ƶ��ڼ����ַ���\n");
	scanf("%d%d",&i,&k);
	if(i>=num||k>=num)
	{
		printf("����������������\n");
		return;
	}
	str_cpy(words[k],words[i]);
	str_puts(words);
}
void str_upr(char a[])
{
	int i;
	for(i=0;i<str_Long(a);i++)
	{
		if(a[i]>='a'&&a[i]<='z') a[i]=a[i]-32;
	}
} 
void str_lwr(char a[])
{
	int i;
	for(i=0;i<str_Long(a);i++)
	{
		if(a[i]>='A'&&a[i]<='Z') a[i]=a[i]+32;
	}
}
void str_uper(char words[][1000])
{
	int i;
	printf("������Ҫת���ɴ�д������\n");
	scanf("%d",&i);
	if(i>=num)
	{
		printf("����������������\n");
		return;
	}
	str_upr(words[i]);
	str_puts(words);
}
void str_lower(char words[][1000])
{
	int i;
	printf("������Ҫת����Сд������\n");
	scanf("%d",&i);
	if(i>=num)
	{
		printf("����������������\n");
		return;
	}
	str_lwr(words[i]);
	str_puts(words);
}
void str_in(char words[][1000])
{
	int pos,i,j,k;
	char in[10000];
	printf("������Ҫ�����Ŀ���ַ������±�\n");
	scanf("%d%d",&j,&pos);
	if(j>=num)
	{
		printf("����������������\n");
		return;
	}
	if(pos>=str_Long(words[j]))
	{
		printf("�����ڸ��±�\n");
		return;
	}
	fflush(stdin);
	printf("�������������\n");
	gets(in);
	i=str_Long(in);
	for(k=str_Long(words[j])-1;k>=pos;k--)
	{
		words[j][k+i]=words[j][k];
	}
	for(k=0;k<i;k++)
	{
		words[j][k+pos+1]=in[k];
	}
	str_puts(words);
}
void str_sub(char words[][1000])
{
	int pos,n,i,j,k;
	printf("������ڼ����ַ���\n");
	scanf("%d",&j);
	if(j>=num)
	{
		printf("����������������\n");
		return;
	}
	printf("�������Ӵ���ʼλ�úʹ���\n");
	scanf("%d%d",&pos,&n);
	if(pos+n>str_Long(words[j])) printf("�ѳ���Դ�ַ���\n");
	for(i=pos;i<pos+n;i++)
	{
		words[num][i-pos]=words[j][i];
	}
	num++;
	str_puts(words);
}
void str_search(char words[][1000])
{
	int i,j,k,m=0,n=0;
	char a[1000];
	printf("������Ҫ���ҵ��ַ���\n");
	gets(a); 
	for(i=0;i<num;i++)
	{
		for(j=0;j<str_Long(words[i]);j++)
		{
			if(words[i][j]==a[0])
			{
				for(k=0;k<str_Long(a);k++)
				{
					if(a[k]==words[i][j+k]) m++;
					else m=0;
				}
				if(m!=0)
				{
					printf("�������ַ����ڵ�%d�е�%d��\n",i,j);
					puts(words[i]);
					n++;
				}
			}
		}
	}
	if(n==0) printf("������������ַ���\n");
}
void str_exchange(char words[][1000])
{
	char a[1000],b[1000];
	int i,j,k,m,n,x;
	printf("�����뱻�û��Ĵ�\n");
	gets(a);
	printf("�������滻����ַ���\n");
	gets(b);
	for(i=0;i<num;i++)
	{
		for(j=0;j<str_Long(words[i]);j++)
		{
			if(words[i][j]==a[0])
			{
				for(k=0;k<str_Long(a);k++)
				{
					if(a[k]==words[i][j+k]) m++;
					else m=0;
				}
				if(m!=0)
				{
					for(x=j;x<str_Long(words[i])-str_Long(a)+1;x++)
					{
						words[i][x]=words[i][x+str_Long(a)];
					}
					for(x=str_Long(words[i])-1;x>=j;x--)
					{
						words[i][x+str_Long(b)]=words[i][x];
					}
					for(x=j;x<j+str_Long(b);x++)
					{
						words[i][x]=b[x-j];
					}
					words[i][str_Long(words[i])+str_Long(b)-str_Long(a)]='\0';
				}
			}
		}
	}
	if(n==0) printf("������������ַ���\n");
	str_puts(words);
}
int main()
{
	int z;
	char words[1000][1000];
	while(z!=0)
	{
	fflush(stdin);
	printf("0.�˳�\n1.�����ַ���\n2.��ʾ�ַ���\n3.�󴮳�\n4.������\n5.���Ƚ�\n6.������\n7.ת�ɴ�д\n8.ת��Сд\n9.������\n10.���Ӵ�\n11.������\n12.���û�\n\n");	
	scanf("%d",&z);while(getchar()!='\n');
    if(z>12||z<0) printf("�����������������\n\n\n"),system("pause"),system("cls");
    else
    	switch(z)
    	{
    		case 0:
				return 0;
    		case 1:
    			str_input(words);
    			break;
    		case 2:
    			str_puts(words);
    			break;
    		case 3:
    			str_long(words);
				break;
			case 4:
				str_connect(words);
				break;	
			case 5:
				str_compare(words);
				break;
			case 6:
				str_copy(words);
				break;
			case 7:
				str_uper(words);
				break;
			case 8:
				str_lower(words);
				break;
			case 9:
				str_in(words);
				break;
			case 10:
				str_sub(words);
				break;
			case 11:
				str_search(words);
				break;
			case 12:
				str_exchange(words);
				break;
    	}
    	system("pause");
    	system("cls");
	}
	return 0;
}

