#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char s[20]={0},str,name[10]={0};
	FILE *fp=NULL,*fp1=NULL;
	int i=0,count=0;
	gets(name);
	fp=fopen("creat.txt","r");
	fp1=fopen("creat.cpp","w");
	while(fgets(s,20,fp)!=NULL)
	{
		i=0;
		while(s[i]!=0)
		{
			if(s[i]!=34)
			fprintf(fp1,"%c",s[i]);
			else
			if(count==0)
			{
				fprintf(fp1,"\"%s",name);
				count++;
				while(s[i]!=34) i++;
			}
			else
			if(count!=0)
			{
				fprintf(fp1,"\"");
			}
			i++;
		}
	}
	fclose(fp);
	fclose(fp1);
	system("g++ creat.cpp -o creat");
	system("start creat.exe");
	system("del creat.cpp");
	system("del creat.exe");
	return 0;
}
