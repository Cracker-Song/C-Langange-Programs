#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 256
int main(void)
{
	FILE*fp;
	int i = 0, sum = 0, num = 0,j;
	char str[N];
	fp = fopen("count1.cpp", "r+");
	while (fgets(str, N, fp) != NULL)
	{
		printf("%d  ", i);
		for (j = 0; str[j]; j++)
		{
			if (str[j] == '/'&&str[j + 1] == '/') str[j] = '\0';
			if (str[j] == '/'&&str[j + 1] == '*') str[j] = '\0';
		}
		puts(str);
		i++;
	}
	fclose(fp);
}