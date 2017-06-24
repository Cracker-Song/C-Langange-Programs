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
		printf("学号:%d\n姓名:%s\n成绩:%.3lf\n%d\n",p->num,p->name,p->score,sizeof(p->name));
		//为何sizeof p->name=0？？？？ 
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
	printf("输入一个学号\n");
	fflush(stdin);
	scanf("%d",&no);
	while(no!=0)
	{
		p=(struct student*)malloc(sizeof(struct student));
		p->num=no;
		printf("输入一个学生姓名\n");
		fflush(stdin);
		gets(name);
		strcpy(p->name,name);
		printf("输入一个学生成绩\n");
		fflush(stdin);
		scanf("%lf",&p->score);
		p->next=head;
		head=p;
		printf("输入一个学号,输入0结束\n");
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
	printf("输入一个学号\n");
	fflush(stdin);
	scanf("%d",&no);
	while(no!=0)
	{
		p=(struct student*)malloc(sizeof(struct student));
		p->num=no;
		printf("输入一个学生姓名\n");
		fflush(stdin);
		gets(name);
		strcpy(p->name,name);
		printf("输入一个学生成绩\n");
		fflush(stdin);
		scanf("%lf",&p->score);
		if(head==NULL) head=p;
		else rear->next=p;
		rear=p;
		printf("输入一个学号,输入0结束\n");
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
		printf("0.退出\n1.创建学生记录链表\n2.打印全部学生记录\n3.插入一条新的学生记录\n4.按学号删除一条学生记录\n5.按姓名查找学生记录\n6.统计学生人数\n7.统计学生成绩\n8.销毁学生链表\n");
		scanf("%d",&z);
		switch(z)
		{
			case 0:return 0;
			case 1:
				system("cls");
				printf("1.头插\n2.尾插\n3.有序插\n4.读文件\n");
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
