#include<stdio.h>
#include<stdlib.h>
struct my
{
	int num;
	struct my*next;
};
void print(struct my*p)
{
	printf("ѧ����%d\n", p->num);
}
void printall(struct my*head)
{
	struct my*p;
	p = head;
	while (p != NULL)
	{
		print(p);
		p = p->next;
	}
}
struct my*creatlistf(void)
{
	struct my*head;
	struct my*p;
	int no;
	head = NULL;
	printf("������һ��ѧ��\n");
	scanf("%d", &no);
	while (no != 0)
	{
		p = (struct my*)malloc(sizeof(struct my));
		p->num = no;
		p->next = head;
		head = p;
		system("cls");
		//print(p);
		printf("��������һ��ѧ�ţ�����0����\n");
		scanf("%d", &no);
	}
	return head;
}
void bubble(struct my*head)
{
	struct my*p;
	struct my*q;
	int change;
	p = head;
	q = head;
	while ((p->next) != NULL)
	{
		while ((q->next) != NULL)
		{
			if ((q->num)>(q->next)->num)
			{
				change = q->num;
				(q->num) = ((q->next)->num);
				((q->next)->num) = change;
			}
			q = q->next;
		}
		q = head;
		p = p->next;
	}
}
int main(void)
{
	struct my*p;
	p = NULL;
	p=creatlistf();
	bubble(p);
	printall(p);
	return 0;
}