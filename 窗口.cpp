#include<windows.h>
#include<stdio.h>
int main(void)
{
	int choice=MessageBox(NULL,"hello world","first",MB_YESNOCANCEL);
	if(choice==IDYES) printf("hello\n");
	else return 0;
}
