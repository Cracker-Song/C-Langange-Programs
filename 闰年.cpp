#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
typedef struct data
{
	int month;
	int date;
	int year; 
}time;
void convert(char s[],int &mon)
{
	if(!strcmp(s,"January")) mon=1;
	else if(!strcmp(s,"February")) mon=2;
	else if(!strcmp(s,"March")) mon=3;
	else if(!strcmp(s,"April")) mon=4;
	else if(!strcmp(s,"May")) mon=5;
	else if(!strcmp(s,"June")) mon=6;
	else if(!strcmp(s,"July")) mon=7;
	else if(!strcmp(s,"August")) mon=8;
	else if(!strcmp(s,"September")) mon=9;
	else if(!strcmp(s,"October")) mon=10;
	else if(!strcmp(s,"November")) mon=11;
	else if(!strcmp(s,"December")) mon=12;
}
int main(void)
{
	int n,j=-1,num[275];
	time *dat[550];
	char mon[10];
	for(int i=0;i<275;num[i]=-1,i++);
	scanf("%d",&n);
	while(n>0)
	{
		j++;
		dat[j]=(time *)malloc(sizeof(data));
		scanf("%s%d,%d",mon,&dat[j]->date,&dat[j]->year);
		convert(mon,dat[j]->month);
		j++;
		dat[j]=(time *)malloc(sizeof(data));
		scanf("%s%d,%d",mon,&dat[j]->date,&dat[j]->year);
		convert(mon,dat[j]->month);
		num[j/2]++;
		for(int i=(dat[j-1]->year);i<=(dat[j]->year);i++)
		{
			if(i%4==0) num[j/2]++;
			if(i%100==0) num[j/2]--;
			if(i%400==0) num[j/2]++;
		}
		if((dat[j-1]->year%4==0&&dat[j-1]->year%100!=0)||dat[j-1]->year%400==0)
			if(dat[j-1]->month>2) num[j/2]--;
		if((dat[j]->year%4==0&&dat[j]->year%100!=0)||dat[j]->year%400==0)
		{
			if(dat[j]->month<2) num[j/2]--;
			if(dat[j]->month==2&&dat[j]->date<29) num[j/2]--;
		}
		n--; 
	}
	for(int j=0;dat[j];free(dat[j]),j++);
	for(int j=0;num[j]!=-1;printf("Case #%d: %d\n",1+j,num[j]),j++);
	return 0;
} 
