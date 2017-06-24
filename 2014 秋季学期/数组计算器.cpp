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
	printf("0.退出\n1.生成随机数\n2.显示数组\n3.删除指定下标\n4.删除指定值\n5.查找元素存放下标\n6.求平均值\n7.查找并插入元素\n8.数组排序（交换法）\n9.数组排序（起泡法）\n10.数组排序（选择法）\n11.逆序\n12.是否为顺序\n13.折半查找\n14.刷屏\n\n\n");
	scanf("%d",&z);while(getchar()!='\n');
    if(z>14||z<0) printf("输入错误，请重新输入\n\n\n"),system("pause"),system("cls");
    else
    switch(z)
	{
	case 0:break;
	case 1:printf("生成多少位随机数\n");
	scanf("%d",&a);
	srand((unsigned)time(NULL));
	for(i=0;i<a;i++) array[i]=rand();
	printf("\n");
	break;
	case 2:for(i=0;i<a;i++) printf("array%d=%d\n",i,array[i]);
	printf("\n");
	break;
	case 3:printf("请输入要删除的下标\n");
	scanf("%d",&b);
	if(b>=0&&b<=a){
	for(i=b;i<a;array[i]=array[i+1],i++);
	array[i-1]=0;
	a=a-1;
	printf("\n");
	}
	else printf("不存在该下标\n");
	break;//输入下标为负数会出现什么？
	case 4:g=0;
	printf("请输入要删除的值\n");
	scanf("%d",&c);
	for(i=0;i<a;i++){
		if(array[i]==c){
			g=g+1;
			for(k=i;k<a;array[i]=array[i+1],k++);
			a=a-1;
		}
	}
	if(g==0) printf("不存在这个值\n");
	printf("\n");
	break;
	case 5:g=0;
	printf("请输入要查找的值\n");
	scanf("%d",&d);
	for(i=0;i<a;i++){
		if(array[i]==d) g=g+1,printf("下标是%d\n",i);
	}
	if(g==0) printf("不存在这个值\n");
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
	printf("请输入要查找的值\n");
	scanf("%d",&e);
	printf("请输入要插入的值\n");
	scanf("%d",&f);
	for(i=0;i<a;i++){
		if(array[i]==e){g=g+1;
		printf("下标是%d\n",i);
		for(m=a-1;m>i;array[m+1]=array[m],m--);
		a=a+1;
		array[i+1]=f;
		}
	}
	if(g==0) printf("不存在这个值\n");
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
	if(h!=0){printf("是升序数组 \n\n\n");break;}
	for(i=0;i<a-1;i++){
		if(array[1+i]<array[i]) h++;
		else {h=0;break;
    	}
	}
	if(h!=0){
	printf("是降序数组 \n\n\n");break;
	}
	break;
    case 13:g=0;
	printf("请输入要查找的值\n");
	scanf("%d",&e);
	for(i=0;i<a;i++){
		if(array[i]==e){
		g=g+1;
		printf("下标是%d\n",i);
		}
	}
	if(g==0) printf("不存在这个值\n");
	printf("\n");
	break;
	}
	system("pause");
	system("cls");
    }
    return 0;
}
