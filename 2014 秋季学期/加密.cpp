#include<stdio.h>
#include<stdlib.h>
#define N 50
int main(void)
{
	FILE*fp;
	char eng[N];
	char *p = eng;
	fp = fopen("ABC.txt", "r");
	fgets(eng,N,fp);
	puts(eng);
	//system("pause");
	while (*p != 0)
	{
		if(*p>='a'&&*p<='z') *p = *p + 1;
		p++;
	}
	fclose(fp);
	fp = fopen("ABC.txt", "w");
	fputs(eng,fp);
	fclose(fp);
}