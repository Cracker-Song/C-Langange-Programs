#include <stdlib.h>
#include <stdio.h>
#define maxN 10
#define maxnumber 30
#define MAXQUEUE 10               // 队列的最大容量
int N,number;
struct node                       /* 图的顶点结构定义     */
{
   int vertex;
   struct node *nextnode;
};
typedef struct node *graph;       /*  图的结构指针        */
struct node head[maxN+1];            
int visited[maxN+1];                
int queue[MAXQUEUE];              /* 定义序列数组         */
int front = -1;                  
int rear = -1;                
void creategraph(int node[][2],int num)
{
   graph newnode;                 /*  顶点指针           */
   graph ptr;
   int from;                   
   int to;                     
   int i;
   for (i=0;i<num;i++ )    /* 第i条边的信息处理    */
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
   if (rear>=MAXQUEUE )        /* 检查伫列是否全满     */
      return -1;                
   rear++;                   
   queue[rear]=value;        
}
int dequeue()
{
   if (front==rear)          /* 队列是否为空         */
      return -1;                 
   front++;                    
   return queue[front];           /* 从队列中取出信息     */
}
void bfs(int current)
{
   graph ptr;
   enqueue(current);              /* 将顶点存入队列       */
   visited[current] = 1;        
   printf(" Vertex[%d]\n",current);   /* 打印输出遍历顶点值 */
   while (front!=rear)        /* 队列是否为空         */
   {
      current=dequeue();   
      ptr=head[current].nextnode;  
      while(ptr!=NULL)          
      {
         if (visited[ptr->vertex]==0) /*顶点没有遍历过*/
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
   printf("请输入顶点数，边数\n");
   scanf("%d%d",&N,&number); 
   for(int j=0;j<number;)
   {
   	   printf("请输入入顶点、出顶点\n");
	   scanf("%d%d",&node[j][0],&node[j][1]);
	   j++;
   }
   int i;
   for (i=1;i<=N;i++ )        /*顶点结构数组初始化*/
   {
      head[i].vertex=i;
      head[i].nextnode=NULL;
      visited[i]=0;
   }
   creategraph(node,number);       /* 图信息转换，邻接表的建立 */
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
