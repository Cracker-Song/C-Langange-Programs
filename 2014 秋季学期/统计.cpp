#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 256
int main(void)
{
	FILE*fp;
	int i = 0,sum=0,num=0,j;
	char str[N];
	fp = fopen("count.cpp", "r");
	/*while(fp!=NULL)
	{
		i++;
		fscanf(fp,"%c",str[i]);
	}*/
	while (fgets(str, N, fp) != NULL)
	{
		puts(str);
		i++;
		for (j = 0; str[j]; j++)
		{
			sum++;
			if (str[j] == ';') num++;
		}
	}
	printf("该程序有%d行有%d个语句有%d个字符", i,num,sum);
	fclose(fp);
}
