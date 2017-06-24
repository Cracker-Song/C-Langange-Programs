#include<stdio.h>
#include<string.h>
int main(void)
{
	char s[10]={0};
	gets(s);
	strcat(s,".txt");
	fopen(s,"w");
}
