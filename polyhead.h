#include"head.h"
typedef struct lnode
{
	float coe;
	int exp;
	struct lnode*next;
}*link;
typedef struct
{
	link head,tail;
	int len;
}linklist;
status makenode(link &p)
{
	p=(link)malloc(sizeof(lnode));
	if(p==NULL) return overflow;
	return ok;
}
status setnode(link &p,float a,int b)
{
	p->coe=a;
	p->exp=b;
	return ok;
}
status initpoly(linklist &L)
{
	L.head=L.tail=(link)malloc(sizeof(lnode));
	if(!L.head) return overflow;
	L.head->next=NULL;
	L.len=0;
	return ok;
}
status delzero(linklist *L[],int i)
{
	link p=NULL,q=NULL;
	p=L[i-1]->head;
	while(fabs(p->coe<0.000001)&&p->next!=NULL)
	{
		L[i-1]->head=p->next;
		free(p);
		p=L[i-1]->head;
	}
	while(p->next!=NULL&&p->next->next!=NULL)
	{
		if(p->next->coe<0.000001)
		{
			q=p->next;
			p->next=p->next->next;
			free(p);
		}
		p=p->next;
	}
	if(p->next!=NULL&&fabs(p->next->coe)<0.000001)
	{
		free(p->next);
		p->next=NULL;
	}
	if(fabs(L[i-1]->head->coe)<0.000001)
	{
		p=L[i-1]->head;
		free(p);
		L[i-1]->head=NULL;
	}
	if(p->next==NULL&&fabs(p->coe)<0.000001)
	{
		free(p);
		L[i-1]->head=NULL;
	}
	return ok;
}
status orderinsert(linklist *L,link s)
{
	link p=L->head,q=NULL,m=NULL;
	while(1)
	{
		if(p==NULL)
		{
			L->head=s;
			s->next=NULL;
			break;
		}
		if(p->next==NULL&&p->exp>s->exp)
		{
			p->next=s;
			s->next=NULL;
			break;
		}
		else
		if(p->next==NULL&&p->exp<s->exp)
		{
			L->head=s;
			s->next=p;
			break;
		}
		else
		if(p->exp>s->exp&&p->next->exp<s->exp)
		{
			q=p->next;
			p->next=s;
			s->next=q;
			break;
		}
		else
		if(p->exp==s->exp)
		{
			p->coe+=s->coe;
			break;
		}
		else
		{
			p=p->next;
		}
	}
	return ok;
}
