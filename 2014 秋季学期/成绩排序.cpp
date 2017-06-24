#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
	long num;
	char name[10];
	double score;
	char sex;
	long age;
	//struct date bir;
	struct student*next;
};
void bubble(struct student*head)
{
	struct student*p;
	struct student*q;
	int change;
	p = head;
	q = head;
	char b[10];
	double a;
	char c;
	while ((p->next) != NULL)
	{
		while ((q->next) != NULL)
		{
			if ((q->score)>(q->next)->score)
			{
				change = q->num;
				(q->num) = ((q->next)->num);
				((q->next)->num) = change;
				a = q->score;
				(q->score) = ((q->next)->score);
				((q->next)->score) = a;
				strcpy(b, p->name);
				strcpy(p->name, (p->next)->name);
				strcpy((p->next)->name, b);
				change = q->age;
				(q->age) = ((q->next)->age);
				((q->next)->age) = change;
				c = q->sex;
				(q->sex) = ((q->next)->sex);
				((q->next)->sex) = c;
			}
			q = q->next;
		}
		q = head;
		p = p->next;
	}
}
struct student*creatlisto(void)
{
	struct student*head;
	struct student*p;
	int no;
	p = NULL;
	head = NULL;
	printf("请输入一个学号\n");
	scanf("%d", &no);
	while (no != 0)
	{
		p = (struct student*)malloc(sizeof(struct student));
		p->num = no;
		printf("请输入学生姓名\n");
		fflush(stdin);
		gets(p->name);
		printf("请输入学生成绩\n");
		scanf("%lf", &p->score);
		printf("请输入学生性别\n");
		fflush(stdin);
		scanf("%c", &p->sex);
		printf("请输入学生年龄\n");
		scanf("%d", &p->age);
		p->next = head;
		head = p;
		system("cls");
		//print(p);
		printf("请输入下一个学号，输入0结束\n");
		scanf("%d", &no);
	}
	bubble(p);
	return head;
}
void print(struct student*p)
{
	printf("学号是%d\n姓名是%s\n成绩是%.3lf\n性别是%c年龄是%d\n", p->num, p->name, p->score,p->sex,p->age);
}
void printall(struct student*head)
{
	struct student*p;
	p = head;
	if (p == NULL) printf(" 不存在数据\n");
	while (p != NULL)
	{
		print(p);
		p = p->next;
	}
}
int main(void)
{
	struct student*p;
	p = NULL;
	p = creatlisto();
	printall(p);
	return 0;
}