#include<stdio.h>
#include<string.h>
void exchange(char a[], char b[])
{
	char c[100000];
	if (strcmp(a, b)>0){
		strcpy(c, a);
		strcpy(a, b);
		strcpy(b, c);
	}

}
void main(){
	char words[1000][1000];
	int a, i, j;
	scanf("%d", &a);
	for (i = 0; i <= a; i++){
		gets(words[i]);
	}
	for (j = 0; j<a; j++){
		for (i = 1; i<a; i++) exchange(words[i], words[i + 1]);
	}
	printf("\n\n");
	for (i = 1; i <= a; puts(words[i]), i++);
}