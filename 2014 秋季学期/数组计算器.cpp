#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
int min(int(a),int(b)){
	int c;
	if(a<b) c=a;
	else c=b;
	return c;
}
int exchange(int &a,int &b){
	int c;
	if(a>b) c=a,a=b,b=c;
} 
int rand(int a[],int b){
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<b;a[i]=rand(),i++);
}
int print(int a[],int b){
	int i;
	for(i=0;i<b;printf("array~%d=%d\n",i,a[i]),i++);
}
int maxsort1(int a[],int b){
	int i,n;
	for(i=0;i<b;i++){
		for(n=0;n<b-1;exchange(a[n],a[n+1]),n++);
	}
}
int maxsort2(int a[],int b){
	int i,n;
	for(i=0;i<b;i++){
		for(n=0;n<b-i;exchange(a[i],a[n+i]),n++);
	}
}
int main(){
	int z,array[100000],i,a=0,b=0,c,d,e,f,g,m,k,n,array1[100000],sum=0,mi=1000000;
	while(z!=0)
	{
	fflush(stdin);
	printf("0.�˳�\n1.���������\n2.��ʾ����\n3.ɾ��ָ���±�\n4.ɾ��ָ��ֵ\n5.����Ԫ�ش���±�\n6.��ƽ��ֵ\n7.���Ҳ�����Ԫ��\n8.�������򣨽�������\n9.�����������ݷ���\n10.��������ѡ�񷨣�\n11.����\n12.�Ƿ�Ϊ˳��\n13.�۰����\n14.ˢ��\n\n\n");
	scanf("%d",&z);while(getchar()!='\n');
    if(z>14||z<0) printf("�����������������\n\n\n"),system("pause"),system("cls");
    else
    switch(z)
	{
	case 0:break;
	case 1:printf("���ɶ���λ�����\n");
	scanf("%d",&a);
	srand((unsigned)time(NULL));
	for(i=0;i<a;i++) array[i]=rand();
	printf("\n");
	break;
	case 2:for(i=0;i<a;i++) printf("array%d=%d\n",i,array[i]);
	printf("\n");
	break;
	case 3:printf("������Ҫɾ�����±�\n");
	scanf("%d",&b);
	if(b>=0&&b<=a){
	for(i=b;i<a;array[i]=array[i+1],i++);
	array[i-1]=0;
	a=a-1;
	printf("\n");
	}
	else printf("�����ڸ��±�\n");
	break;//�����±�Ϊ���������ʲô��
	case 4:g=0;
	printf("������Ҫɾ����ֵ\n");
	scanf("%d",&c);
	for(i=0;i<a;i++){
		if(array[i]==c){
			g=g+1;
			for(k=i;k<a;array[i]=array[i+1],k++);
			a=a-1;
		}
	}
	if(g==0) printf("���������ֵ\n");
	printf("\n");
	break;
	case 5:g=0;
	printf("������Ҫ���ҵ�ֵ\n");
	scanf("%d",&d);
	for(i=0;i<a;i++){
		if(array[i]==d) g=g+1,printf("�±���%d\n",i);
	}
	if(g==0) printf("���������ֵ\n");
	printf("\n");
	break;
	case 8:for(i=0;i<a;i++){
    for(n=0;n<a;mi=min(mi,array[n]),n++);
    for(g=0;g<a;g++){
		if(array[g]==mi){
        array[g]=1000000;array1[i]=mi;mi=100000;break;
		}
	}
	}
	for(i=0;i<a;array[i]=array1[i],i++);
	mi=100000;
	break;
    case 6:for(i=0;i<a;sum+=array[i],i++);
	printf("average=%f\n",float(sum)/a);
	printf("\n");
	break;
    case 7:g=0;
	printf("������Ҫ���ҵ�ֵ\n");
	scanf("%d",&e);
	printf("������Ҫ�����ֵ\n");
	scanf("%d",&f);
	for(i=0;i<a;i++){
		if(array[i]==e){g=g+1;
		printf("�±���%d\n",i);
		for(m=a-1;m>i;array[m+1]=array[m],m--);
		a=a+1;
		array[i+1]=f;
		}
	}
	if(g==0) printf("���������ֵ\n");
	printf("\n");
	break;
	case 9:b=a;
	maxsort1(array,b);
	break;
	case 10:b=a;
	maxsort2(array,b);
	break;
	case 14:system("cls");
	break;
	case 11:int h;
	for(i=0;i<a/2;i++){
		h=array[i];
		array[i]=array[a-i-1];
		array[a-i-1]=h;
	}
	break;
	case 12:int j;
	for(i=0;i<a-1;i++){
		if(array[i]<array[i+1]) h++;
		else {h=0;break;
		}
	}
	if(h!=0){printf("���������� \n\n\n");break;}
	for(i=0;i<a-1;i++){
		if(array[1+i]<array[i]) h++;
		else {h=0;break;
    	}
	}
	if(h!=0){
	printf("�ǽ������� \n\n\n");break;
	}
	break;
    case 13:g=0;
	printf("������Ҫ���ҵ�ֵ\n");
	scanf("%d",&e);
	for(i=0;i<a;i++){
		if(array[i]==e){
		g=g+1;
		printf("�±���%d\n",i);
		}
	}
	if(g==0) printf("���������ֵ\n");
	printf("\n");
	break;
	}
	system("pause");
	system("cls");
    }
    return 0;
}
