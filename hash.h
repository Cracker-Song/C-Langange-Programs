#include<ctype.h>
#include<malloc.h>
#include<limits.h>
#include<stdio.h> 
#include<stdlib.h>
#include<math.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1
#define NULLKEY 9999 // 0为无记录标志
//#define N 16 // 数据元素个数
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE
typedef int KeyType; // 设关键字域为整型
struct ElemType // 数据元素类型
{
   KeyType key;
   int ord;
};
int hashsize[]={17,31,47}; // 哈希表容量递增表，一个合适的素数序列
int N=15;
int asl=0;
int m=0; // 哈希表表长，全局变量
struct HashTable
{
   ElemType *elem; // 数据元素存储基址，动态分配数组
   int count; // 当前数据元素个数
   int sizeindex; // hashsize[sizeindex]为当前容量
};
