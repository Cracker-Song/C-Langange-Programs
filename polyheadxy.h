#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//#include<windows.h>
#define List_Init_Size 100
#define ListIncrement 10
#define True 1
#define False 0
#define ok 1
#define error 0
#define infeasible -1
#define overflow -2
#define yx(k,x,m) (k*pow(x,m))
#define inf(max,min) ((max-min)/100000)
typedef int Status;
typedef int Length;
typedef struct Lnode{
    double coef;
    int expn;
    struct Lnode *next;
}Lnode,*Linklist;
typedef struct Lopnd{
	Linklist operands;
	struct Lopnd *lnext;
}Lopnd,*Linkopnd;
typedef struct Loptr{
	char operators;
	struct Loptr *cnext;
}Loptr,*Linkoptr;
char f[10][10]={0};
Lnode *Makenode();
Status Setnode(Lnode *,double,int);
Status Initpolyn(Linklist &);
Length Lengthpolyn(Linklist);
Status Orderinsert(Linklist,Lnode *,double,int);
Status Arrfull(Linklist *,int *);
Linklist Createlenpolyn(Length);
Status Initlinkliststack(Linkopnd &);
Status Initcharstack(Linkoptr &);
Status Initcharstack(Linkoptr &);
Status Getlinklisttop(Linkopnd,Linklist &);
Status Pushlinklist(Linkopnd &,Linklist);
Status Pushchar(Linkoptr &,char);
Status Poplinklist(Linkopnd &,Linklist &);
Status Popchar(Linkoptr &,char &);
void cut(char a[]);
Lnode *Makenode(){
	Linklist L;
    L=(Lnode*)malloc(sizeof(Lnode));
    return L;
}
Status Setnode(Lnode *p,double c,int e){
	if(!p)
	    return error;
	p->coef=c;
	p->expn=e;
	p->next=NULL;
	return ok;
}
Status Initpolyn(Linklist &L){//��ͷ����������
	if(L=Makenode()){
		L->next=NULL;
		return ok;
	}
	else
	    return overflow;
}
Length Lengthpolyn(Linklist L){//��������
	if(!L)
	    return -1;
	int len=0;
	Lnode *p=NULL;
	for(p=L->next;p;p=p->next,len++);
	return len;
}
Status Orderinsert(Linklist L,Lnode *s,double c,int e){
	Lnode *p=NULL;
	p=L;
	if(!L)
	    return error;
	for(;p->next&&p->next->expn>=e;p=p->next){
	    if(p->next->expn==e){
	    	p->next->coef+=c;
	    	if(fabs(p->next->coef)<0.000001){
	    		p->next=p->next->next;
	    		free(p->next);
	    		return ok;
	    	}
	    	return ok;
	    }
	}
	if(!s)
	    return error;
	s->next=p->next;
	p->next=s;
	return ok;
}
Status Arrfull(Linklist *a,int *psum){
	int i;
	for(i=0;i<*(psum);i++){
		if(!a[i])
		    return False;
	}
	return True;
}
Linklist Createlenpolyn(Length len){//��ͷ������
	int i;
	Lnode *p=NULL,*L=NULL;
	L=Makenode();
	if(!L)
	    return NULL;
	L->next=NULL;
	for(i=1;i<=len;i++){
		p=Makenode();
		if(!p)
		    return NULL;
		p->next=L->next;
		L->next=p;
	}
	return L;
}
Status Initlinkliststack(Linkopnd &top){
	top=(Linkopnd)malloc(sizeof(Lopnd));
	if(!top)
	    return overflow;
	return ok;
}
Status Getlinklisttop(Linkopnd top,Linklist &opnd){
	if(!top)
	    return error;
    opnd=top->operands;
    return ok;
}
Status Getchartop(Linkoptr top,char &optr){
	if(!top)
	    return error;
	optr=top->operators;
	return ok;
}
Status Pushlinklist(Linkopnd &top,Linklist opnd){
	Lopnd *p=NULL;
	p=(Lopnd*)malloc(sizeof(Lopnd));
	if(!p)
	    return overflow;
	p->operands=opnd;
	p->lnext=top;
	top=p;
	return ok;
}
Status Pushchar(Linkoptr &top,char optr){
	Loptr *p=NULL;
	p=(Loptr*)malloc(sizeof(Loptr));
	if(!p)
	    return overflow;
	p->operators=optr;
	p->cnext=top;
	top=p;
	return ok;
}
Status Poplinklist(Linkopnd &top,Linklist &opnd){
	if(!top)
	    return error;
	Lopnd *p=NULL;
	opnd=top->operands;
	p=top;
	top=top->lnext;
	free(p);
	return ok;
}
Status Popchar(Linkoptr &top,char &optr){
	if(!top)
	    return error;
	Loptr *p=NULL;
	optr=top->operators;
	p=top;
	top=top->cnext;
	free(p);
	return ok;
}
Status Initcharstack(Linkoptr &top){
	top=(Linkoptr)malloc(sizeof(Loptr));
	if(!top)
	    return overflow;
	return ok;
}
void cut(char a[])//�ַ����и�
{
	char *p=a,*q=a,*n=a;
	int i=0;
	while(1)
	{
		if(*p=='+'||*p=='\0'||*p=='-')
		{
			for(q=p-1;q>=a;q--)
			{
				if(i==0) f[i][q-a]=*(q);
				else f[i][q-a]=*(q);
			}
			a=p;
			i++;
		}
		if(*p=='\0') break;
		p++;
	}
}
