#include<stdio.h>
#define N 10
struct date{ 
    int year;
    int month;
    int day;
};
struct books{
	long num;
	struct date publishdate;
	char bookname[50];
	char authorname[50];
	char publisher[50];
	float price;
};
void read(struct books bk[],int n){
	int i;
	for(i=0;i<n;i++){ 
	    printf("������ͼ�����Ϣ\n");
	    printf("���������,�������,�����·�,������,�۸�\n");
	    scanf("%ld%d%d%d%f",&bk[i].num,&bk[i].publishdate.year,&bk[i].publishdate.month,&bk[i].publishdate.day,&bk[i].price);
	    fflush(stdin);
	    printf("����������\n");
	    scanf("%s",bk[i].bookname);
	    fflush(stdin);
	    printf("������������\n");
	    scanf("%s",bk[i].authorname);
	    fflush(stdin);
	    printf("�������������\n");
	    scanf("%s",bk[i].publisher);
	}
	return;
}
void print(struct books bk[],int n){
	int i;
	for(i=0;i<n;i++){
	    printf("���   ����ʱ��         �۸�   ����   ������   ��������\n");
	    printf("%3ld%10d.%d.%d%8f%8s%8s%8s\n",bk[i].num,bk[i].publishdate.year,bk[i].publishdate.month,bk[i].publishdate.day,\
	    bk[i].price,bk[i].bookname,bk[i].authorname,bk[i].publisher);
	}
	return;
}
float average(struct books bk[],int n){
	float sum;
	int i;
	for(i=0,sum=0.0;i<n;i++)
	    sum+=bk[i].price;
	return sum/n;
}

int main()
{
    struct books bk[N];
	int i;
	read(bk,N);
	print(bk,N);
	printf("�۸�ƽ����Ϊ:%fԪ",average(bk,N)); 
	return 0;	
}
