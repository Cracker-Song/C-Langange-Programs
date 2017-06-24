#include<stdio.h>
#include<stdlib.h>
int num;
void str_input(char words[][1000])
{
	int k;
	printf("请输入字符串数目\n");
	scanf("%d",&num);
	for(k=0;k<num;k++)
	{
		fflush(stdin);
		printf("请输入第%d串字符串\n",k);
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
	for(i=0;i<num;i++) printf("第%d串字符串串长为%d\n",i,str_Long(words[i]));
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
	printf("请输入要连接的两个字符串行数\n");
	scanf("%d%d",&i,&k);
	if(i>=num||k>=num)
	{
		printf("所输入行数不存在\n");
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
	printf("请输入要比较的两个字符串的行数\n");
	scanf("%d%d",&i,&k);
	if(i>=num||k>=num)
	{
		printf("所输入行数不存在\n");
		return;
	}
	j=str_cmp(words[i],words[k]);
	if(j>0) printf("字符串%d小于字符串%d\n",k,i);
	else if(j==0) printf("字符串%d等于字符串%d\n",k,i);
	else printf("字符串%d大于字符串%d\n",k,i);
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
	printf("请输入将第几个字符串复制到第几个字符串\n");
	scanf("%d%d",&i,&k);
	if(i>=num||k>=num)
	{
		printf("所输入行数不存在\n");
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
	printf("请输入要转换成大写的行数\n");
	scanf("%d",&i);
	if(i>=num)
	{
		printf("所输入行数不存在\n");
		return;
	}
	str_upr(words[i]);
	str_puts(words);
}
void str_lower(char words[][1000])
{
	int i;
	printf("请输入要转换成小写的行数\n");
	scanf("%d",&i);
	if(i>=num)
	{
		printf("所输入行数不存在\n");
		return;
	}
	str_lwr(words[i]);
	str_puts(words);
}
void str_in(char words[][1000])
{
	int pos,i,j,k;
	char in[10000];
	printf("请输入要插入的目标字符串和下标\n");
	scanf("%d%d",&j,&pos);
	if(j>=num)
	{
		printf("所输入行数不存在\n");
		return;
	}
	if(pos>=str_Long(words[j]))
	{
		printf("不存在该下标\n");
		return;
	}
	fflush(stdin);
	printf("请输入插入内容\n");
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
	printf("请输入第几行字符串\n");
	scanf("%d",&j);
	if(j>=num)
	{
		printf("所输入行数不存在\n");
		return;
	}
	printf("请输入子串开始位置和串长\n");
	scanf("%d%d",&pos,&n);
	if(pos+n>str_Long(words[j])) printf("已超出源字符串\n");
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
	printf("请输入要查找的字符串\n");
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
					printf("所查找字符串在第%d行第%d列\n",i,j);
					puts(words[i]);
					n++;
				}
			}
		}
	}
	if(n==0) printf("不存在这个子字符串\n");
}
void str_exchange(char words[][1000])
{
	char a[1000],b[1000];
	int i,j,k,m,n,x;
	printf("请输入被置换的串\n");
	gets(a);
	printf("请输入替换后的字符串\n");
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
	if(n==0) printf("不存在这个子字符串\n");
	str_puts(words);
}
int main()
{
	int z;
	char words[1000][1000];
	while(z!=0)
	{
	fflush(stdin);
	printf("0.退出\n1.输入字符串\n2.显示字符串\n3.求串长\n4.串连接\n5.串比较\n6.串复制\n7.转成大写\n8.转成小写\n9.串插入\n10.求子串\n11.串查找\n12.串置换\n\n");	
	scanf("%d",&z);while(getchar()!='\n');
    if(z>12||z<0) printf("输入错误，请重新输入\n\n\n"),system("pause"),system("cls");
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

