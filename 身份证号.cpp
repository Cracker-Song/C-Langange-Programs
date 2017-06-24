#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 14
int main(void)
{
	system("del number.txt");
	char str[N]={0},sex[10]={0};
	int num[N]={0},weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2},sum[500]={0},sex_num=0;
	char number_short[500][4]={0},part[3]={0},number[500][19]={0},last;
	FILE *fp=NULL;
	printf("请输入身份证号前十四位(前六位为地区编码，后八位出生日期)\n");
	scanf("%s",str);
	flag:printf("请输入性别(男:male，女:female)\n");
	scanf("%s",sex);
	if(strcmp(sex,"male")==0) sex_num=1;
	else if(strcmp(sex,"female")==0) sex_num=2;
	else goto flag;
	//for(int i=1;i<=N;num[i-1]=str[i-1]-'0',i++);
	//printf("%d",sex_num);
	if(sex_num==1)
	{
		for(int i=1,j=0;i<1000;)
		{
			char all[3]={0};
			if(i<10)
			{
				itoa(i,part,10);
				strcpy(all,"00");
				strcat(all,part);
			}
			if(i<100&&i>=10)
			{
				itoa(i,part,10);
				strcpy(all,"0");
				strcat(all,part);
			}
			if(i<1000&&i>=100)
			{
				itoa(i,part,10);
				strcpy(all,part);
			}
			strcpy(number_short[j],all);
			i=i+2;
			j++;
		}
	}
	if(sex_num==2)
	{
		for(int i=0,j=0;i<999;)
		{
			char all[3]={0};
			if(i<10)
			{
				itoa(i,part,10);
				strcpy(all,"00");
				strcat(all,part);
			}
			if(i<100&&i>=10)
			{
				itoa(i,part,10);
				strcpy(all,"0");
				strcat(all,part);
			}
			if(i<1000&&i>=100)
			{
				itoa(i,part,10);
				strcpy(all,part);
			}
			strcpy(number_short[j],all);
			i=i+2;
			j++;
		}
	}
	for(int i=1;i<=500;)
	{
		strcpy(number[i-1],str);
		strcat(number[i-1],number_short[i-1]);
		i++;
	}
	for(int i=1;i<=500;)
	{
		for(int j=1;j<=17;)
		{
			sum[i-1]+=(number[i-1][j-1]-'0')*weight[j-1];
			j++;
		}
		i++;
	}
	for(int i=1;i<=500;sum[i-1]%=11,i++);
	for(int i=1;i<=500;)
	{
		switch(sum[i-1])
		{
			case 0:last='1';break;
			case 1:last='0';break;
			case 2:last='x';break;
			case 3:last='9';break;
			case 4:last='8';break;
			case 5:last='7';break;
			case 6:last='6';break;
			case 7:last='5';break;
			case 8:last='4';break;
			case 9:last='3';break;
			case 10:last='2';break;
		}
		number[i-1][17]=last;
		i++;
	}
	//for(int i=1;i<=100;puts(number[i-1]),i++);
	fp=fopen("number.txt","w");
	for(int i=1;i<=500;fprintf(fp,"%s\n",number[i-1]),i++);
	fclose(fp);
	return 0;
} 
