#include"head.h"
#include<time.h>
#define N 10
void swap(int a,int b)
{
	int i;
	i=a;
	a=b;
	b=i;
}
status random(int a[],int b)
{
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<b;a[i]=rand(),i++);
	return ok;
}
status insertion(int array[],int insert[])
{
	for(int i=1;i<=N;insert[i]=array[i-1],i++);
	int j;
	for(int i=2;i<=N;){
		if(insert[i]<insert[i-1])
		{
			insert[0]=insert[i];
			insert[i]=insert[i-1];
			for(j=i-2;insert[j]>insert[0];j--)
			{
				insert[j+1]=insert[j];
			}
			insert[j+1]=insert[0];
		}
		i++;
	}
	return ok;
}
status shell(int array[],int s[])
{
	int cut1[5][N/5]={0},cut2[2][N/2]={0},cut3[N]={0};
	int s1[5][N/5]={0},s2[2][N/2]={0};
	for(int i=0;i<N;s[i+1]=array[i],i++);
	for(int i=0;i<N;*(i+&cut1[0][0])=array[i],i++);
	for(int i=1;i<=5;insertion(cut1[i-1],s1[i-1]),i++);
	for(int i=0;i<N;*(i+&cut2[0][0])=*(i+&cut1[0][0]),i++);
	for(int i=1;i<=2;insertion(cut2[i-1],s2[i-1]),i++);
	for(int i=0;i<N;*(i+&cut3[0])=*(i+&cut2[0][0]),i++);
	insertion(cut3,s);
	return ok;
}
int partition(int quick[],int low,int high)
{
	int key=quick[low],i=low,j=high;
	quick[0]=quick[low];
	while(i<j)
	{
		while(j>i&&quick[j]>=key) j--;
		quick[i]=quick[j];
		while(i<j&&quick[i]<=key) i++;
		quick[j]=quick[i];
	}
	quick[i]=quick[0];
	return i;
}
status qsort(int quick[],int low,int high)
{
	int key;
	if(low<high)
	{
		key=partition(quick,low,high);
		qsort(quick,low,key-1);
		qsort(quick,key+1,high);
	}
	return ok;
}
status quicksort(int array[],int quick[])
{
	for(int i=1;i<=N;quick[i]=array[i-1],i++);
	qsort(quick,1,N);
	return ok;
}
void HeapAdjust(int *a,int i,int size)  //������ 
{
    int lchild=2*i;       //i�����ӽڵ���� 
    int rchild=2*i+1;     //i���Һ��ӽڵ���� 
    int max=i;            //��ʱ���� 
    if(i<=size/2)          //���i����Ҷ�ڵ�Ͳ��ý��е��� 
    {
        if(lchild<=size&&a[lchild]>a[max])
        {
            max=lchild;
        }    
        if(rchild<=size&&a[rchild]>a[max])
        {
            max=rchild;
        }
        if(max!=i)
        {
            swap(a[i],a[max]);
            HeapAdjust(a,max,size);    //�������֮����maxΪ���ڵ���������Ƕ� 
        }
    }        
}
void BuildHeap(int *a,int size)    //������ 
{
    int i;
    for(i=size/2;i>=1;i--)    //��Ҷ�ڵ�������ֵΪsize/2 
    {
        HeapAdjust(a,i,size);    
    }    
} 
void HeapSort(int a[],int size)    //������ 
{
    int i;
    BuildHeap(a,size);
    for(i=size;i>=1;i--)
    {
        swap(a[1],a[i]);  
        HeapAdjust(a,1,i-1); 
    }
} 
status heapsort(int array[],int heap[])
{
    int i;
    int size=N;
    for(i=1;i<=size;i++)
		heap[i]=array[i-1];
    HeapSort(heap,size);
	return ok;
}
int main(void)
{
	int array[N]={0},insert[N+1]={0},shellarray[N+1]={0},quick[N+1]={0},heap[N+1]={0};
	status sat=0;
	sat=random(array,N);
	if(sat!=1) printf("����ʧ��\n");
	for(int i=1;i<=N;printf("%d\n",array[i-1]),i++);
	printf("\n\n");
	shell(array,shellarray);
	for(int i=1;i<=N;printf("%d\n",shellarray[i]),i++);
	quicksort(array,quick);
	printf("\n\n");
	for(int i=1;i<=N;printf("%d\n",quick[i]),i++);
	//heapsort(array,heap);
	//for(int i=1;i<=N;printf("%d\n",heap[i]),i++);
	return ok;
}
