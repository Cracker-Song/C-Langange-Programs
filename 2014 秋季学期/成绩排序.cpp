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
	printf("������һ��ѧ��\n");
	scanf("%d", &no);
	while (no != 0)
	{
		p = (struct student*)malloc(sizeof(struct student));
		p->num = no;
		printf("������ѧ������\n");
		fflush(stdin);
		gets(p->name);
		printf("������ѧ���ɼ�\n");
		scanf("%lf", &p->score);
		printf("������ѧ���Ա�\n");
		fflush(stdin);
		scanf("%c", &p->sex);
		printf("������ѧ������\n");
		scanf("%d", &p->age);
		p->next = head;
		head = p;
		system("cls");
		//print(p);
		printf("��������һ��ѧ�ţ�����0����\n");
		scanf("%d", &no);
	}
	bubble(p);
	return head;
}
void print(struct student*p)
{
	printf("ѧ����%d\n������%s\n�ɼ���%.3lf\n�Ա���%c������%d\n", p->num, p->name, p->score,p->sex,p->age);
}
void printall(struct student*head)
{
	struct student*p;
	p = head;
	if (p == NULL) printf(" ����������\n");
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