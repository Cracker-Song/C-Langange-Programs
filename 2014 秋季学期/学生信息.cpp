#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*struct date
{
long year, month,day;
};*/
struct student
{
	long num;
	char name[10];
	double score;
	//struct date bir;
	struct student*next;
}stu[3];
void print(struct student*p)
{
	printf("ѧ����%d\n������%s\n�ɼ���%.3lf\n", p->num, p->name, p->score);
}
void printall(struct student*head)
{
	struct student*p;
	p = head;
	if (p == NULL)
	{
		printf(" ����������\n");
		return;
	}
	while (p != NULL)
	{
		print(p);
		p = p->next;
	}
}
struct student*creatlistf(void)
{
	struct student*head;
	struct student*p;
	int no;
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
		p->next = head;
		head = p;
		//system("cls");
		//print(p);
		printf("��������һ��ѧ�ţ�����0����\n");
		scanf("%d", &no);
	}
	return head;
}
struct student*creatlistr(void)
{
	struct student*head;
	struct student*p;
	struct student*rear;
	int no;
	head = NULL;
	rear = NULL;
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
		if (head == NULL) head = p;
		else rear->next = p;
		rear = p;
		//system("cls");
		//print(p);
		printf("��������һ��ѧ�ţ�����0����\n");
		scanf("%d", &no);
	}
	if (rear != NULL) rear->next = NULL;
	return head;
}
void bubble(struct student*head)
{
	struct student*p;
	struct student*q;
	int change;
	p = head;
	q = head;
	char b[10];
	double a;
	while ((p->next) != NULL)
	{
		while ((q->next) != NULL)
		{
			if ((q->num)>(q->next)->num)
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
struct student*creatlist(void)
{
	FILE*fp;
	struct student*head = stu;
	struct student*p = NULL;
	int i;
	if ((fp = fopen("read.txt", "r")) == NULL)
	{
		printf("cannot open\n");
		exit(0);
	}
	//printf("������ѧ��\n");
	//scanf("%d", &no);
	for (i = 0; i < 3; i++)
	{
		p = (struct student*)malloc(sizeof(struct student));
		fscanf(fp, "%d %s %lf", &stu[i].num, &stu[i].name, &stu[i].score);
		stu[i].next = &stu[i + 1];
		p = &stu[i];
		//p->next = &stu[i + 1];
		if (i == 0) head = p;
		if (i == 2) p->next = NULL;
		p = p->next;
	}
	//printall(head);
	//system("pause");
	fclose(fp);
	return head;
}
struct student*creat(void)
{
	int z = 1;
	struct student*p;
	p = NULL;
	printf("1.ͷ��\n2.β��\n3.�����\n4.�����ļ�����\n");
	scanf("%d", &z);
	switch (z)
	{
	case 1:p = creatlistf();
		break;
	case 2:p = creatlistr();
		break;
	case 3:p = creatlisto();
		break;
	case 4:p = creatlist();
		//if (p->next == NULL) printf("NULL\n");
		//system("pause");
		//printall(p);
		break;
	}
	//system("cls");
	return p;
}
struct student*insert(struct student*head)
{
	int no;
	struct student*p;
	printf("������һ��ѧ��\n");
	scanf("%d", &no);
	p = (struct student*)malloc(sizeof(struct student));
	p->num = no;
	printf("������ѧ������\n");
	fflush(stdin);
	gets(p->name);
	printf("������ѧ���ɼ�\n");
	scanf("%lf", &p->score);
	p->next = head;
	head = p;
	system("cls");
	//print(p);
	return head;
}
struct student*del(struct student*head)
{
	struct student*p;
	p = head;
	printf("������Ҫɾ����ѧ��\n");
	int d, i = 0;
	scanf("%d", &d);
	if (p->next == NULL || p->num == d)
	{
		head = p->next;
		free(p);
		i++;
		return head;
	}
	while ((p->next)->next != NULL)
	{
		if ((p->next)->num == d)
		{
			p->next = (p->next)->next;
			free(p->next);
			i++;
		}
		p = p->next;
	}
	if ((p->next)->next == NULL && (p->next)->num == d)
	{
		free(p->next);
		p->next = NULL;
		i++;
	}
	if (i == 0) printf("�����ڸ�ѧ��\n");
	return head;
}
void opentext(struct student*head)
{
	FILE *fp;
	struct student*p = head;
	if ((fp = fopen("mine.txt", "w")) == NULL)
	{
		printf("cannot open\n");
		system("pause");
		exit(0);
	}
	while (p != NULL)
	{
		fprintf(fp, "%d  %s  %lf", p->num, p->name, p->score);
		p = p->next;
	}
	fclose(fp);
}
void print1(struct student*head)
{
	int z;
	printf("1.��Ļ���\n2.�����ļ����\n");
	scanf("%d", &z);
	switch (z)
	{
	case 1:printall(head);
		break;
	case 2:opentext(head);
		break;
	}
}
struct student*search(struct student*head)
{
	char z[10];
	struct student*p;
	int i = 0;
	p = head;
	fflush(stdin);
	printf("������Ҫ���ҵ�����\n");
	gets(z);
	while (p != NULL)
	{
		if (strcmp(p->name, z) == 0)
		{
			i++;
			break;
		}
		p = p->next;
	}
	if (p != NULL) print(p);
	if (i == 0) printf("�����ڸ�ѧ��\n");
	return head;
}
int number(struct student*head)
{
	struct student*p;
	p = head;
	int num = 0;
	while (p != NULL)
	{
		num++;
		p = p->next;
	}
	return num;
}
double sum(struct student*head)
{
	double sum = 0;
	struct student*p = head;
	while (p != NULL)
	{
		sum += p->score;
		p = p->next;
	}
	return sum;
}
double max(struct student*head)
{
	struct student*p = head;
	double a = p->score;
	while (p != NULL)
	{
		if (a < p->score) a = p->score;
		p = p->next;
	}
	return a;
}
int sort(struct student*head)
{
	struct student*p = head;
	int num = 0;
	while (p != NULL)
	{
		if (p->score < 60)
			num++;
		p = p->next;
	}
	return num;
}
void count(struct student*head)
{
	struct student*p = head;
	printf("��߷�Ϊ%lf\nƽ���ɼ�Ϊ%lf\n����������Ϊ%d\n", max(head), sum(head) / number(head), sort(head));
}
int main()
{
	struct student*p;
	p = NULL;
	int z = 1;
	while (z != 0)
	{
		printf("0.�������\n1.����ѧ����¼����\n2.��ӡȫ��ѧ����¼\n3.����һ���µ�ѧ����¼\n4.ɾ��һ����Ϣ\n5.����������ѧ����¼\n6.ͳ��ѧ������\n7.ͳ�Ƴɼ�\n8.��������\n");
		scanf("%d", &z);
		switch (z)
		{
		case 0: return 0;
		case 1:p = creat();
			break;
		case 2:print1(p);
			break;
		case 3:p = insert(p);
			break;
		case 4:p = del(p);
			break;
		case 5:p = search(p);
			break;
		case 6:printf("ѧ������Ϊ��%d\n", number(p));
			break;
		case 7:count(p);
			break;
		case 8:free(p);
			p = NULL;
			break;
		default:printf("�����������������\n");
		}
		system("pause");
		system("cls");
	}
	//system("cls");
	//printall(p);
	//printf("END\n");
	//system("pause");
	return 0;
}
