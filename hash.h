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
#define NULLKEY 9999 // 0Ϊ�޼�¼��־
//#define N 16 // ����Ԫ�ظ���
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE
typedef int KeyType; // ��ؼ�����Ϊ����
struct ElemType // ����Ԫ������
{
   KeyType key;
   int ord;
};
int hashsize[]={17,31,47}; // ��ϣ������������һ�����ʵ���������
int N=15;
int asl=0;
int m=0; // ��ϣ�����ȫ�ֱ���
struct HashTable
{
   ElemType *elem; // ����Ԫ�ش洢��ַ����̬��������
   int count; // ��ǰ����Ԫ�ظ���
   int sizeindex; // hashsize[sizeindex]Ϊ��ǰ����
};
