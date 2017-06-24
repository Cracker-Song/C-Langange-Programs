#include"polyhead.h"
#define N 20
#define yx(k,x,m) (k*pow(x,m))
#define inf(max,min) ((max-min)/100000)
#define h1 10
#define h2 11
status cut(char a[]);
status creatlist(linklist *L[]);
status print(linklist *L[]);
status insert(linklist *L,link s,link count);
status copypoly(linklist *L[],int i,int j);
status copy(linklist *L[]);
status pluspoly(linklist *L[],int i,int j);
status plus(linklist *L[]);
status minuspoly(linklist *L[],int i,int j);
status minus(linklist *L[]);
status evalua(linklist *L[]);
status delpoly(linklist *L[],int i);
status destroy(linklist *L[]);
status clearpoly(linklist *L[],int i);
status clear(linklist *L[]);
status modify(linklist *L[]);
status multpoly(linklist *L[],int i,int j,int k);
status multiply(linklist *L[]); 
status division(linklist *L[]);
status divpoly(linklist *L[],int i,int j,int n,int m);
status indeinteg(linklist *L[]);
status indefinte(linklist *L);
status definte(linklist *L,float max,float min);
status definteg(linklist *L[]);
status derivative(linklist *L);
status derivpoly(linklist *L[]);
char f[10][10]={0};
int main(void)
{
	system("color 70");
	int z=-1;
	linklist *poly[N];
	for(int i=0;i<N;poly[i]=NULL,i++);
	while(z!=0)
	{
		printf("菜单\n0.退出\n1.创建多项式\n2.显示多项式\n3.复制多项式\n4.求和\n5.求差\n6.求值\n7.销毁多项式\n8.清空多项式\n9.修改多项式\n10.求积\n11.求商\n12.不定积分\n13.定积分\n14.导数\n");
		scanf("%d",&z);
		while(getchar()!='\n');
	    if(z>14||z<0||z==-1)
		{
			printf("输入错误，请重新输入\n");
			fflush(stdin);
			system("pause");
			system("cls");
		}
    	else
    	switch(z)
		{
			case 0:return ok;
			case 1:creatlist(poly);break;
			case 2:print(poly);break;
			case 3:copy(poly);break;
			case 4:plus(poly);break;
			case 5:minus(poly);break;
			case 6:evalua(poly);break;
			case 7:destroy(poly);break;
			case 8:clear(poly);break;
			case 9:modify(poly);break;
			case 10:multiply(poly);break;
			case 11:division(poly);break;
			case 12:indeinteg(poly);break;
			case 13:definteg(poly);break;
			case 14:derivpoly(poly);break;
		}
		z=-1;
	}
	return 0;
}
void cut(char a[])//字符串切割 
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
				else f[i][q-a-1]=*(q);
			}
			a=p;
			i++;
		}
		if(*p=='\0') break;
		p++;
	}
}
status creatlist(linklist *L[])
{
	int i=-1,j=0,n=0,m=0,k=0;
	link p=NULL,tail=NULL;
	char F[100]={0},a[10]={0},b[10]={20};
	flag1:printf("请问要存储在第几个链表\n");
	scanf("%d",&i);
	if(i==0) return ok; 
	if(i>9||i==-1||i<0)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag1;
	}
	fflush(stdin);
	printf("请输入多项式\n");
	gets(F);
	cut(F);
	while(f[n][0]!=0)
	{
		m=0;
		while(f[n][m]!=120&&f[n][m]!=0)
		{
			a[m]=f[n][m];
			a[m+1]=0;
			m++;
		}
		if(m==0&&f[n][0]==120) strcpy(a,"1");
		if(f[n][m+2]!=0)
		{
			m=m+2;
			while(f[n][m]!=0)
			{
				b[k]=f[n][m];
				k++;
				m++;
			}
		}
		else
		if(f[n][m]!=120)
		strcpy(b,"0");
		else
		if(f[n][m]==120)
		strcpy(b,"1");
		makenode(p); 
		setnode(p,(int)atof(a),atof(b));
		p->next=NULL;
		if(L[i-1]!=NULL)
		{
			orderinsert(L[i-1],p);
		}
		else
		{
			L[i-1]=(linklist *)malloc(sizeof(linklist));
			L[i-1]->head=p;
		}
		n++;
		j++;
	}
	L[i-1]->tail=p;
	L[i-1]->len=j;
	delzero(L,i);
	for(int mn=0;mn<N;mn++)
	for(int nm=0;nm<N;f[mn][nm]=0,nm++);
	return ok;
}
status print(linklist *L[])
{
	linklist *p=L[0];
	link q=NULL;
	int i=0,count=0;
	flagprint:printf("请输入要显示的多项式的序号\n");
	scanf("%d",&i);
	if(i==0) return ok;
	if(i>19||i<0)
	{
		printf("输入错误，请重新输入\n");
		goto flagprint;
	}
	if(L[i-1]==NULL)
	{
		printf("多项式不存在\n");
		return ok;
	}
	if(L[i-1]->head==NULL||fabs(L[i-1]->head->coe)<0.000001)
	{
		printf("多项式为0\n");
		return ok;
	}
	p=L[i-1];
	q=p->head;
	delzero(L,i);
	printf("多项式为：");
	while(q!=NULL)
	{
		if(fabs(q->coe-1)<0.000001)
		{
			if(q->exp!=1&&q->exp!=0)
			printf("x^%d",q->exp);
			if(q->exp==1)
			printf("x",q->coe);
			if(q->exp==0)
			printf("1");
			count++;
		}
		else
		{
			if(fabs(q->coe)>0.000001)
			{
				if(q->exp!=1&&q->exp!=0)
				printf("%0.3fx^%d",q->coe,q->exp);
				if(q->exp==1)
				printf("%0.3fx",q->coe);
				if(q->exp==0)
				printf("%0.3f",q->coe);
				count++;
			}
		}
		q=q->next;
		if(q!=NULL&&count==1)
		{
			count--;
			printf("+");
		}
	}
	printf("\n");
	return ok;
}
status insert(linklist *L,link s,link p)
{
	link q=NULL;
	if(p==NULL) p=L->head;
	while(1)
	{
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
status copy(linklist *L[])
{
	int i=-1,j=-1;
	flag2:printf("请输入要复制的多项式序号\n");
	scanf("%d",&i);
	if(i==0) return ok;
	if(L[i-1]==NULL)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag2;
	}
	if(i>9||i==-1||i<0)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag2;
	}
	flag3:printf("请输入目标多项式序号\n");
	scanf("%d",&j);
	if(j==0) return ok;
	if(j>9||j==-1||j<0)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag3;
	}
	copypoly(L,i,j);
	return ok;
}
status copypoly(linklist *L[],int i,int j)
{
	link p=NULL,q=NULL;
	q=L[i-1]->head;
	while(1)
	{
		if(q==NULL) break;
		makenode(p); 
		setnode(p,q->coe,q->exp);
		p->next=NULL;
		if(L[j-1]!=NULL)
		{
			orderinsert(L[j-1],p);
		}
		else
		{
			L[j-1]=(linklist *)malloc(sizeof(linklist));
			L[j-1]->head=p;
		}
		q=q->next;
	}
	L[j-1]->tail=p;
	L[j-1]->len=L[i-1]->len;
	//p->next=NULL;
	return ok;
}
status pluspoly(linklist *L[],int i,int j)
{
	link p=NULL,q=NULL,count=NULL;
	q=L[i-1]->head;
	while(1)
	{
		if(q==NULL) break;
		makenode(p); 
		setnode(p,q->coe,q->exp);
		p->next=NULL;
		if(L[j-1]!=NULL)
		{
			insert(L[j-1],p,count);
		}
		else
		{
			L[j-1]=(linklist *)malloc(sizeof(linklist));
			L[j-1]->head=p;
		}
		q=q->next;
	}
	L[j-1]->tail=p;
	L[j-1]->len=L[i-1]->len;
	return ok;
}
status plus(linklist *L[])
{
	flag4:int i=-1,j=-1,k=-1;
	printf("请输入要相加的两个多项式的序号\n");
	scanf("%d%d",&i,&j);
	if(i==0||j==0) return ok;
	if(L[j-1]==NULL||L[i-1]==NULL)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag4;
	}
	if((i==-1||j==-1)||(i>9||j>9)||(i<0||j<0))
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag4;
	}
	flag5:printf("请输入和存储位置\n");
	scanf("%d",&k);
	if(k==0) return ok;
	if(k==-1||k>9||k<0)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag5;
	}
	if(L[i-1]->head==NULL||L[j-1]->head==NULL)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag5;
	}
	if(i!=k) pluspoly(L,i,k);
	if(j!=k) pluspoly(L,j,k);
	delzero(L,k);
	return ok;
}
status minuspoly(linklist *L[],int i,int j)
{
	link p=NULL,q=NULL;
	q=L[i-1]->head;
	while(1)
	{
		if(q==NULL) break;
		makenode(p); 
		setnode(p,-q->coe,q->exp);
		p->next=NULL;
		if(L[j-1]!=NULL)
		{
			orderinsert(L[j-1],p);
		}
		else
		{
			L[j-1]=(linklist *)malloc(sizeof(linklist));
			L[j-1]->head=p;
		}
		q=q->next;
	}
	L[j-1]->tail=p;
	L[j-1]->len=L[i-1]->len;
	return ok;
}
status minus(linklist *L[])
{
	flag6:int i=-1,j=-1,k=-1;
	printf("请输入要相减的两个多项式的序号\n");
	scanf("%d%d",&i,&j);
	if(i==0||j==0) return ok;
	if(L[j-1]==NULL||L[i-1]==NULL)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag6;
	}
	if((i==-1||j==-1)||(i>9||j>9)||(i<0||j<0))
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag6;
	}
	flag7:printf("请输入差存储位置\n");
	scanf("%d",&k);
	if(k==0) return ok;
	if(k==-1||k>9||k<0)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag7;
	}
	if(L[i-1]->head==NULL||L[j-1]->head==NULL)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag6;
	}
	if(i!=k) pluspoly(L,i,k);
	if(j!=k) minuspoly(L,j,k);
	delzero(L,k);
	return ok;
}
status evalua(linklist *L[])
{
	int i=-1;
	char a=0;
	float sum,x;
	link p=NULL;
	flag7:printf("请输入X的值\n");
	scanf("%f",&x);
	flag8:printf("请输入要求值的多项式序号\n");
	scanf("%d",&i);
	if(i==0) return ok;
	if(L[i-1]==NULL)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag8;
	}
	if(i==-1||i>9||i<0)
	{
		fflush(stdin);
		printf("输入错误，请重新输入\n");
		goto flag8;
	}
	p=L[i-1]->head;
	while(p!=NULL)
	{
		sum+=p->coe*pow(x,p->exp);
		p=p->next;
	}
	printf("当X为%.3f时该多项式的值为%.3f\n",x,sum);
	return ok;
}
status delpoly(linklist *L[],int i)
{
	link p=NULL,q=NULL;
	p=L[i-1]->head;
	if(p==NULL)
	{
		free(L[i-1]);
		L[i-1]=NULL;
		return ok;
	}
	if(p==NULL) free(L[i-1]);
	while(p->next!=NULL)
	{
		q=p->next;
		free(p);
		p=q;
	}
	free(p);
	if(L[i-1]!=NULL)
	{
		free(L[i-1]);
		L[i-1]=NULL;
	}
	return ok;
}
status destroy(linklist *L[])
{
	int i=-1;
	flag9:printf("请输入要删除的多项式的序号\n");
	scanf("%d",&i);
	if(i==0) return ok;
	if(i==-1||i>9||i<0)
	{
		fflush(stdin);
		printf("输入错误，请重新输入\n");
		goto flag9;
	}
	if(L[i-1]==NULL)
	{
		printf("多项式不存在，请重新选择\n");
		i=-1;
		goto flag9;
	}
	delpoly(L,i);
	return ok;
}
status clearpoly(linklist *L[],int i)
{
	link p=NULL,q=NULL;
	p=L[i-1]->head;
	if(p==NULL)
	{
		free(L[i-1]);
		L[i-1]=NULL;
		return ok;
	}
	while(p->next!=NULL)
	{
		q=p->next;
		free(p);
		p=q;
	} 
	free(p);
	if(L[i-1]->head!=NULL) L[i-1]->head=NULL;
	return ok;
}
status clear(linklist *L[])
{
	int i=-1;
	flag10:printf("请输入要清空的多项式的序号\n");
	scanf("%d",&i);
	if(i==0) return ok;
	if(i==-1||i>9||i<0)
	{
		fflush(stdin);
		printf("输入错误，请重新输入\n");
		goto flag10;
	}
	if(L[i-1]==NULL)
	{
		printf("多项式不存在，请重新选择\n");
		i=-1;
		goto flag10; 
	}
	if(L[i-1]->head==NULL)
	{
		printf("多项式为0\n");
		return ok;
	}
	clearpoly(L,i);
	return ok;
}
status modify(linklist *L[])
{
	int i=-1,j=-1,b=-1;
	float a=0;
	link p=NULL,s=NULL,add=NULL;
	flag11:printf("请选择要修改的多项式序号\n");
	scanf("%d",&i);
	if(i==0) return ok; 
	if(i==-1||i>9||i<0)
	{
		fflush(stdin);
		printf("输入错误，请重新输入\n");
		goto flag11;
	}
	if(L[i-1]==NULL)
	{
		printf("多项式不存在\n");
		goto flag11;
	}
	p=L[i-1]->head;
	if(L[i-1]->head==NULL)
	{
		printf("多项式为0\n");
		goto flag11;
	}
	flag12:printf("请选择要修改的项的系数\n");
	scanf("%d",&j);
	if(j==-1)
	{
		fflush(stdin);
		printf("输入错误，请重新输入\n");
		j=-1;
		goto flag12;
	}
	while(p!=NULL)
	{
		if(p->exp==j)
		{
			printf("请输入新的系数和指数\n");
			flag13:scanf("%f%d",&a,&b);
			if(b<0)
			{
				fflush(stdin);
				printf("输入错误，请重新输入\n");
				b=-1;
				goto flag13;
			}
			makenode(s);
			s->coe=-(p->coe);
			s->exp=p->exp;
			s->next=NULL;
			orderinsert(L[i-1],s);
			delzero(L,i);
			makenode(add);
			add->coe=a;
			add->exp=b;
			add->next=NULL;
			orderinsert(L[i-1],add);
			return ok;
		}
		p=p->next;
	}
	printf("该系数不存在，请重新输入\n");
	goto flag11;
	return ok;
}
status multiply(linklist *L[])
{
	int i=-1,j=-1,k=-1;
	link p=NULL,q=NULL,s=NULL;
	flag12:printf("请输入要相乘的两项的序数\n");
	scanf("%d%d",&i,&j);
	if(i==0||j==0) return ok;
	if(L[j-1]==NULL||L[i-1]==NULL)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag12;
	}
	if((i==-1||j==-1)||(i>9||j>9)||(i<0||j<0))
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag12;
	}
	if(L[i-1]->head==NULL||L[j-1]->head==NULL)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag12;
	}
	flag13:printf("请输入积存储位置\n");
	scanf("%d",&k);
	if(k==0) return ok;
	if(k==-1||k>9||k<0)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag13;
	}
	multpoly(L,i,j,k);
	return ok;
}
status multpoly(linklist *L[],int i,int j,int k)
{
	link p=NULL,q=NULL,s=NULL;
	L[k-1]=NULL;
	p=L[i-1]->head;
	while(p!=NULL)
	{
		q=L[j-1]->head;
		while(q!=NULL)
		{
			makenode(s);
			s->next=NULL;
			setnode(s,(q->coe)*(p->coe),(q->exp)+(p->exp));
			if(L[k-1]==NULL)
			{
				L[k-1]=(linklist *)malloc(sizeof(linklist));
				L[k-1]->head=s;
			}
			else orderinsert(L[k-1],s);
			q=q->next;
		}
		p=p->next;
	}
}
status division(linklist *L[])
{
	int i=-1,j=-1,k=-1,n=-1;
	link p=NULL,q=NULL,s=NULL;
	flag14:printf("请输入要相除的两项的序数\n");
	scanf("%d%d",&i,&j);
	if(i==0||j==0) return ok;
	if(L[j-1]==NULL||L[i-1]==NULL)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag14;
	}
	if((i==-1||j==-1)||(i>9||j>9)||(i<0||j<0))
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag14;
	}
	if(L[i-1]->head==NULL||L[j-1]->head==NULL)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag14;
	}
	flag15:printf("请输入商存储位置\n");
	scanf("%d",&k);
	if(k==0) return ok;
	if(k==-1||k>9||k<0)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag15;
	}
	flag16:printf("请输入余数存储位置\n");
	scanf("%d",&n);
	if(n==0) return ok;
	if(n==-1||n>9||n<0)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag16;
	}
	divpoly(L,i,j,k,n);
	return ok;
}
status divpoly(linklist *L[],int i,int j,int n,int m)
{
	link q=L[i-1]->head,p=L[j-1]->head,quo=NULL,remain=NULL;
	linklist *s=NULL;
	link ss=NULL;
	float a,b;
	if(L[n-1]!=NULL) delpoly(L,n);
	if(L[m-1]!=NULL) delpoly(L,m);
	L[n-1]=(linklist *)malloc(sizeof(linklist));
	L[m-1]=(linklist *)malloc(sizeof(linklist));
	L[n-1]->head=quo;
	L[m-1]->head=remain;
	if(q->exp<p->exp)
	{
		makenode(quo);
		setnode(quo,0,0);
		delpoly(L,m);
		copypoly(L,i,m);
		return ok;
	}
	if(q->exp==p->exp&&q->coe>p->coe)
	{
		delpoly(L,m);
		makenode(quo);
		quo->next=NULL;
		setnode(quo,(q->coe)/(p->coe),0);
		L[n-1]->head=quo;
		multpoly(L,n,j,11);
		copypoly(L,i,m);
		minuspoly(L,11,m);
		delpoly(L,11);
		return ok;
	}
	link P=L[n-1]->head,Q=NULL;
	makenode(Q);
	setnode(Q,(L[i-1]->head->coe)/(L[j-1]->head->coe),(L[i-1]->head->exp)-(L[j-1]->head->exp));
	P=Q;
	L[n-1]->head=P;
	L[h1]=(linklist *)malloc(sizeof(linklist));
	L[h1]->head=NULL;
	while(1)
	{
		if(L[h1]!=NULL) delpoly(L,h1+1);
		copypoly(L,i,h1+1);
		multpoly(L,j,n,h2+1);
		minuspoly(L,h1+1,h2+1);
		delzero(L,h1+1);
		if(L[h1]->head==NULL) break;
		flag21:if(fabs(L[h1]->head->coe)<0.00001&&L[h1]->head->next==NULL) break;
		else
		if(fabs(L[h1]->head->coe)<0.00001)
		{
			L[h1]->head=L[h1]->head->next;
			goto flag21;
		}
		if(L[h1]->head->exp<L[j-1]->head->exp) break;
		if(L[h1]->head->exp==L[j-1]->head->exp&&L[h1]->head->coe<L[j-1]->head->coe) break;
		makenode(Q);
		Q->next=NULL;
		setnode(Q,(L[h1]->head->coe)/(L[j-1]->head->coe),(L[h1]->head->exp)-(L[j-1]->head->exp));
		P->next=Q;
		P=P->next;
	}
	delpoly(L,h1+1);
	delpoly(L,h2+1);
	multpoly(L,j,n,h1+1);
	pluspoly(L,i,m);
	minuspoly(L,h1+1,m);
	delpoly(L,h1+1);
	delzero(L,n);
	return ok;
}
status indefinte(linklist *L)
{
	link p=NULL;
	p=L->head;
	while(p!=NULL)
	{
		setnode(p,(p->coe)/(p->exp+1),p->exp+1);
		p=p->next;
	}
	return ok;
}
status indeinteg(linklist *L[])
{
	int i=-1;
	flag17:printf("请输入求不定积分的多项式序数\n");
	scanf("%d",&i);
	if(i==0) return ok;
	if(i==-1||i>9||i<0||L[i-1]==NULL||L[i-1]->head==NULL)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag17;
	}
	indefinte(L[i-1]);
	return ok;
}
status definte(linklist *L,float max,float min)
{
	link p=NULL;
	float sum1=0,sum2=0;
	indefinte(L);
	p=L->head;
	while(p!=NULL)
	{
		sum1+=p->coe*pow(max,p->exp);
		p=p->next;
	}
	p=L->head;
	while(p!=NULL)
	{
		sum2+=p->coe*pow(min,p->exp);
		p=p->next;
	}
	printf("定积分值为%f\n",sum1-sum2);
	derivative(L);
	return ok;
}
status definteg(linklist *L[])
{
	int i=-1;
	float min,max;
	link p=NULL;
	flag18:printf("请输入求定积分的多项式序数\n");
	scanf("%d",&i);
	if(i==0) return ok;
	if(i==-1||i>9||i<0||L[i-1]==NULL||L[i-1]->head==NULL)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag18;
	}
	printf("请输入积分上下限\n");
	scanf("%f%f",&max,&min);
	definte(L[i-1],max,min);
	return ok;
}
status derivative(linklist *L)
{
	link p=NULL;
	p=L->head;
	while(p!=NULL)
	{
		if(p->exp>=1) setnode(p,(p->coe)*(p->exp),(p->exp)-1);
		else setnode(p,0,0);
		p=p->next;
	}
	return ok;
}
status derivpoly(linklist *L[])
{
	int i=-1,n=0;
	flag19:printf("请输入求导的多项式序数\n");
	scanf("%d",&i);
	if(i==0) return ok;
	if(i==-1||i>9||i<0||L[i-1]==NULL||L[i-1]->head==NULL)
	{
		printf("输入错误请重新输入\n");
		fflush(stdin);
		goto flag19;
	}
	flag20:printf("请输入求导阶数\n");
	scanf("%d",&n);
	if(n==0) return ok;
	while(n>0)
	{
		derivative(L[i-1]);
		n--;
	}
	delzero(L,i-1);
	return ok;
}
