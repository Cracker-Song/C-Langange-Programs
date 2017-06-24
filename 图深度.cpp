#include <stdlib.h>
#include <stdio.h>
#define maxN 20
#define maxnumber 60
#define MAXQUEUE 20               // 队列的最大容量
int N,number;
struct node                       /* 图顶点结构定义     */
{
   int vertex;                  
   struct node *nextnode;      
};
typedef struct node *graph;       /* 图形的结构新型态   */
struct node head[maxN+1];            
int visited[maxN+1];      
int queue[MAXQUEUE];              /* 定义序列数组         */
int front = -1;                  
int rear = -1;         
void creategraph(int node[][2],int num)/*num指的是图的边数*/
{
   graph newnode;              
   graph ptr;
   int from;                   
   int to;                   
   int i;
   for (i=0;i<num;i++)    /* 读取边线信息，插入邻接表*/
   {
      from=node[i][0];      
      to=node[i][1];        
      newnode=(graph)malloc(sizeof(struct node));
      newnode->vertex=to;        /* 建立顶点内容       */
      newnode->nextnode=NULL;  
      ptr=&(head[from]);      
      while(ptr->nextnode!=NULL ) 
         ptr=ptr->nextnode;    
      ptr->nextnode=newnode;    /* 插入节点        */
   }
}
void dfs(int current)
{
   graph ptr;
   visited[current] = 1;          /* 记录已遍历过       */
   printf("vertex[%d]\n",current);  
   ptr=head[current].nextnode;  
   while(ptr!=NULL)        
   {
      if (visited[ptr->vertex]==0)  /* 如过没遍历过 */
         dfs(ptr->vertex);          
      ptr=ptr->nextnode;             
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
   printf("Vertex[%d]\n",current);   /* 打印输出遍历顶点值 */
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
     		printf("Vertex[%d]\n",ptr->vertex);
         }
         ptr=ptr->nextnode;   
      }
   }
}
int main(void)
{
   graph ptr;
   printf("请输入顶点数，边数\n");
   scanf("%d%d",&N,&number); 
   int node[maxnumber][2]={0},node1[maxnumber][2]={0};
   for(int j=0;j<number;)
   {
   	   printf("请输入入顶点、出顶点\n");
	   scanf("%d%d",&node[j][0],&node[j][1]);
	   node1[j][0]=node[j][0];
	   node1[j][1]=node[j][1];
	   j++;
   }
   int i;
   for (i=1;i<=N;i++)      /*   顶点数组初始化  */
   {
      head[i].vertex = i;         
      head[i].nextnode = NULL;  
      visited[i] = 0;        
   }
   creategraph(node,number);          /*    建立邻接表      */
   printf("Content of the gragh's ADlist is:\n");
   for (i=1;i<=N;i++ )
   {
      printf("vertex%d ->",head[i].vertex); 
      ptr=head[i].nextnode;          
      while (ptr!=NULL )    
      {
         printf(" %d ",ptr->vertex-1);  /* 印出顶点内容   */
         ptr=ptr->nextnode;       
      }
      printf("\n");        
   }
   printf("\nThe end of the DFS are:\n");
   dfs(1);   
   for (i=1;i<=N;i++)      /*   顶点数组初始化  */
   {
      head[i].vertex = i;         
      head[i].nextnode = NULL;  
      visited[i] = 0;        
   }
   creategraph(node1,number);
   for (i=1;i<=N;i++ )
   {
      ptr=head[i].nextnode;          
      while (ptr!=NULL )    
      {
         ptr=ptr->nextnode;       
      }
   }
   printf("The contents of BFS are:\n");
   bfs(1);                  
   return 0;
}
