#include<stdio.h>
#include<stdlib.h>
void genswap(void *a,void *b,int size)
{
	char t;
	int i;
	for(i=0;i<size;i++)
	{
		t=*((char *)b+i);
		*((char *)b+i)=*((char *)a+i);
		*((char *)a+i)=t; 
	}
}
main()
{
	int a,b;
	float c,d;
	char e,f;
	printf("��������������\n");
	fflush(stdin);
	scanf("%d%d",&a,&b);
	genswap(&a,&b,sizeof(int));
	printf("%d\n%d\n",a,b);
	printf("����������������\n");
	fflush(stdin);
	scanf("%f%f",&c,&d);
	genswap(&c,&d,sizeof(float));
	printf("%f\n%f\n",c,d);
	printf("�����������ַ�\n");
	fflush(stdin);
	scanf("%c%c",&e,&f);
	genswap(&e,&f,sizeof(char));
	printf("%c\n%c",e,f);
}
