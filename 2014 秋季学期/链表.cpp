#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	int num;
	char name[];
	double score;
	struct student*next;
};
struct student*head;
void print()
{
	struct student*p=head;
	while(p!=NULL)
	{
		printf("ѧ��:%d\n����:%s\n�ɼ�:%.3lf\n%d\n",p->num,p->name,p->score,sizeof(p->name));
		//Ϊ��sizeof p->name=0�������� 
		p=p->next;
	}
}
struct student*creatlistf(void)
{
	struct student*head;
	struct student*p;
	int no;
	char name[10];
	head=NULL;
	printf("����һ��ѧ��\n");
	fflush(stdin);
	scanf("%d",&no);
	while(no!=0)
	{
		p=(struct student*)malloc(sizeof(struct student));
		p->num=no;
		printf("����һ��ѧ������\n");
		fflush(stdin);
		gets(name);
		strcpy(p->name,name);
		printf("����һ��ѧ���ɼ�\n");
		fflush(stdin);
		scanf("%lf",&p->score);
		p->next=head;
		head=p;
		printf("����һ��ѧ��,����0����\n");
		fflush(stdin);
		scanf("%d",&no);
	}
	return head;
}
struct student*creatlistr(void)
{
	struct student*head;
	struct student*rear;
	struct student*p;
	int no;
	char name[10];
	head=NULL;
	printf("����һ��ѧ��\n");
	fflush(stdin);
	scanf("%d",&no);
	while(no!=0)
	{
		p=(struct student*)malloc(sizeof(struct student));
		p->num=no;
		printf("����һ��ѧ������\n");
		fflush(stdin);
		gets(name);
		strcpy(p->name,name);
		printf("����һ��ѧ���ɼ�\n");
		fflush(stdin);
		scanf("%lf",&p->score);
		if(head==NULL) head=p;
		else rear->next=p;
		rear=p;
		printf("����һ��ѧ��,����0����\n");
		fflush(stdin);
		scanf("%d",&no);
	}
	if(rear!=NULL)
		rear->next=NULL;
	return head;
}
struct student*creatlist(void)
{
	
	return head;
}
int main()
{
	//char a[]="afdsxd";
	//printf("%d\n",sizeof(a));
	while(1)
	{
		int z,i=1;
		printf("0.�˳�\n1.����ѧ����¼����\n2.��ӡȫ��ѧ����¼\n3.����һ���µ�ѧ����¼\n4.��ѧ��ɾ��һ��ѧ����¼\n5.����������ѧ����¼\n6.ͳ��ѧ������\n7.ͳ��ѧ���ɼ�\n8.����ѧ������\n");
		scanf("%d",&z);
		switch(z)
		{
			case 0:return 0;
			case 1:
				system("cls");
				printf("1.ͷ��\n2.β��\n3.�����\n4.���ļ�\n");
				scanf("%d",&z);
				switch(z)
				{
					case 1:
						head=creatlistf();
						break;
					case 2:
						head=creatlistr();
						break;
					case 3:
						head=creatlist();
						break;
					//case 4:;break;
				}
				//break;
			case 2:
				print();
				break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
