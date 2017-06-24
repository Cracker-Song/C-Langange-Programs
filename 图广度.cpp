#include <stdlib.h>
#include <stdio.h>
#define maxN 10
#define maxnumber 30
#define MAXQUEUE 10               // ���е��������
int N,number;
struct node                       /* ͼ�Ķ���ṹ����     */
{
   int vertex;
   struct node *nextnode;
};
typedef struct node *graph;       /*  ͼ�Ľṹָ��        */
struct node head[maxN+1];            
int visited[maxN+1];                
int queue[MAXQUEUE];              /* ������������         */
int front = -1;                  
int rear = -1;                
void creategraph(int node[][2],int num)
{
   graph newnode;                 /*  ����ָ��           */
   graph ptr;
   int from;                   
   int to;                     
   int i;
   for (i=0;i<num;i++ )    /* ��i���ߵ���Ϣ����    */
   {
      from = node[i][0];          
      to = node[i][1];        
      newnode=(graph)malloc(sizeof(struct node));
      newnode->vertex=to;     
      newnode->nextnode=NULL; 
      ptr=&(head[from]);       
      while(ptr->nextnode!=NULL )
         ptr=ptr->nextnode;      
      ptr->nextnode=newnode;     
   }
}
int enqueue(int value)
{
   if (rear>=MAXQUEUE )        /* ��������Ƿ�ȫ��     */
      return -1;                
   rear++;                   
   queue[rear]=value;        
}
int dequeue()
{
   if (front==rear)          /* �����Ƿ�Ϊ��         */
      return -1;                 
   front++;                    
   return queue[front];           /* �Ӷ�����ȡ����Ϣ     */
}
void bfs(int current)
{
   graph ptr;
   enqueue(current);              /* ������������       */
   visited[current] = 1;        
   printf(" Vertex[%d]\n",current);   /* ��ӡ�����������ֵ */
   while (front!=rear)        /* �����Ƿ�Ϊ��         */
   {
      current=dequeue();   
      ptr=head[current].nextnode;  
      while(ptr!=NULL)          
      {
         if (visited[ptr->vertex]==0) /*����û�б�����*/
         {
            enqueue(ptr->vertex);   
            visited[ptr->vertex] = 1; 
     		printf(" Vertex[%d]\n",ptr->vertex);
         }
         ptr=ptr->nextnode;   
      }
   }
}
int main(void)
{
   graph ptr;
   int node[maxnumber][2]={0};
   printf("�����붥����������\n");
   scanf("%d%d",&N,&number); 
   for(int j=0;j<number;)
   {
   	   printf("�������붥�㡢������\n");
	   scanf("%d%d",&node[j][0],&node[j][1]);
	   j++;
   }
   int i;
   for (i=1;i<=N;i++ )        /*����ṹ�����ʼ��*/
   {
      head[i].vertex=i;
      head[i].nextnode=NULL;
      visited[i]=0;
   }
   creategraph(node,number);       /* ͼ��Ϣת�����ڽӱ�Ľ��� */
   printf("The content of the graph's allist is:\n");
   for (i=1;i<=N;i++)
   {
      printf(" vertex%d =>",head[i].vertex); 
      ptr=head[i].nextnode;            
      while (ptr!=NULL)      
      {
         printf(" %d ",ptr->vertex); 
         ptr=ptr->nextnode;        
      }
      printf("\n");              
   }
   printf("The contents of BFS are:\n");
   bfs(1);                       
   return 0;
}
