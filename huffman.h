#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#define N 255
#define M 2*N - 1
int ok = 0;
char file[20] = {};
/* 哈夫曼树节点类型 */
typedef struct
{
    int data; /* 字符值 */
    int weight; /* 权重 */
    int parent; /* 双亲结点 */
    int lchild; /* 左孩子结点 */
    int rchild; /* 右孩子结点 */
}Tree;
/* 哈夫曼编码类型 */
typedef struct
{
    /* 存放哈夫曼码 */
    char cd[N]; 
    int start;
}Code;
/* 生成节点及编码数组 */
Tree ht[M];
Code hcd[N];
