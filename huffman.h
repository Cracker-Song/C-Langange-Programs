#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#define N 255
#define M 2*N - 1
int ok = 0;
char file[20] = {};
/* ���������ڵ����� */
typedef struct
{
    int data; /* �ַ�ֵ */
    int weight; /* Ȩ�� */
    int parent; /* ˫�׽�� */
    int lchild; /* ���ӽ�� */
    int rchild; /* �Һ��ӽ�� */
}Tree;
/* �������������� */
typedef struct
{
    /* ��Ź������� */
    char cd[N]; 
    int start;
}Code;
/* ���ɽڵ㼰�������� */
Tree ht[M];
Code hcd[N];
