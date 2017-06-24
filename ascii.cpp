#include<stdio.h>
int main(void)
{
	char num[154]={0};
	int ascii[77]={0};
	FILE *fp1=NULL,*fp2=NULL;
	fp1=fopen("hex.txt","r");
	fp2=fopen("ascii.txt","w");
	for(int i=1;i<155;fscanf(fp1,"%c",&num[i-1]),i++);
	for(int i=1,j=1;i<78;ascii[i-1]=10*(num[j-1]-'0')+(num[j]-'0'),i++,j=j+2);
	for(int i=1;i<78;fprintf(fp2,"%c",ascii[i-1]+48),i++);
	//for(int i=1;i<78;printf("%d\n",ascii[i-1]),i++);
	fclose(fp1);
	fclose(fp2);
	printf("\n");
	//for(int i=1;i<155;printf("%c",num[i-1]),i++);
	//printf("\n%c",54);
	return 0;
} 
