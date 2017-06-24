#include <iostream>
#include<stdlib.h>
#include<stdio.h> 
using namespace std;
int m, s1, s2;      // m是总结点个数，s1,s2用于筛选出最小和第二小的两个数
typedef struct{
    unsigned int weight;
    unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;      //动态分配数组存储哈夫曼树
typedef char* HuffmanCode;   //动态分配数组存储哈夫曼编码表
//选出weight最小的两个结点,s1保存最小的，s2保存第二小的
void SelectMin(HuffmanTree HT, int nNode)
{
    int i,j;
    for(i=1;i<=nNode;i++)
        if(!HT[i].parent)
        {
            s1=i;
            break;
        }
    for(j=i+1; j<=nNode;j++)
        if(!HT[j].parent)
        {
            s2=j;
            break;
        }
    for(i=1;i<=nNode;i++)
        if((HT[i].weight<HT[s1].weight)&&(!HT[i].parent)&&(s2!=i))
            s1=i;
    for(j=1;j<=nNode;j++)
        if((HT[j].weight<HT[s2].weight)&&(!HT[j].parent)&&(s1!=j))
            s2=j;
    // 以上只筛选出最小的两个，这里保证s1的weight比s2的小
    if(HT[s1].weight > HT[s2].weight)
    {
        int tmp = s1;
        s1 = s2;
        s2 = tmp;
    }
}
// w[]存放nNode个字符的权值（均大于0），构造哈夫曼树HT，
// 并求出nNode个字符的哈夫曼编码HC
void HuffmanCoding(HuffmanTree &HT, HuffmanCode *&HC, int *w, int nNode)
{
    int i, j;
    char *hfcode;
    int p;
    int cdlen;
    if(nNode < 1)
        return;
    m = 2*nNode-1;   //哈夫曼树的结点数，定理公式
 
    /////////////////////////////以下是求Huffman树的初始化/////////////////////////////
    HT = (HTNode*) malloc ((m+1) *sizeof(HTNode));  //0号单元未用
    for(i = 1; i <= nNode; i++)    //初始化
    {
        HT[i].weight = w[i-1];
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    for(i = nNode+1; i <= m; i++)
    {
        HT[i].weight = 0;
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }

    /////////////////////////////以下是Huffman树的构建/////////////////////////////
    for(i = nNode+1; i <= m; i++)
    {
        // 建立哈夫曼树
        // 在HT[1..i-1]中选择parent为0且weight最小的两个节点
        // 其序号分别是s1和s2,并且小的是左孩子 
        SelectMin(HT, i-1);
        HT[s1].parent = i;
        HT[s2].parent = i;
        //cout << "S1 && S2: " << HT[s1].weight << " " << HT[s2].weight << endl;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    //以下是求Huffman树的编码
    //从根出发,递归遍历哈夫曼树,求得编码。标记0，1，2含义如下： 
    //0:搜到一个满足条件的新结点
    //1:当前正在搜其儿子结点的结点，还没有回溯回来 
    //2:不满足条件或者儿子结点已全部搜完，已经回溯回来，则回溯到其父结点
    //注意:当流程走到一个结点后，其标记立即变为下一状态，
    //即：0->1->2->0(最后一步2->0不是必需的)，但执行条件仍然是当前状态 
    
    hfcode = (char *) malloc (nNode * sizeof(char));   //分配求编码的工作空间
    p = m;
    cdlen = 0;
    for(i = 1; i <= m; i++)
        HT[i].weight = 0;   //遍历哈夫曼树时用作结点状态的标志
    
    while(p)        //退出条件：p = 结点m的parent,即为0
    {
        if(HT[p].weight == 0)       //向左走 
        {
            HT[p].weight = 1;
            if(HT[p].lchild != 0)
            {
                p = HT[p].lchild;
                hfcode[cdlen++] = '0';
            }
            //else if(HT[p].rchild == 0)  //左右孩子都为0，叶结点 
            //{
            //  HC[p] = (char *) malloc ((cdlen+1) * sizeof(char));
            //  hfcode[cdlen] = '\0';   //保证后面的不会被复制
            //  strcpy(HC[p], hfcode);   //复制编码
            //}
        }
        else if(HT[p].weight == 1)   //向右走 
        {
            HT[p].weight = 2;
            if(HT[p].rchild != 0)
            {
                p = HT[p].rchild;
                hfcode[cdlen++] = '1';
            }
            //该分支放在这里似乎更合理一点，放上面被注释掉的地方也可以 
            else if(HT[p].rchild == 0)  //左右孩子都为0，叶结点 
            {
                HC[p] = (char *) malloc ((cdlen+1) * sizeof(char));
                hfcode[cdlen] = '\0';   //保证后面的不会被复制
                strcpy(HC[p], hfcode);   //复制编码
            }
        }
        else    //HT[p].weight == 2 退回到父结点，编码长度减一
        {
            HT[p].weight = 0;
            p = HT[p].parent;
            --cdlen;
        }
    }
}
/*Huffman解码函数
 *HT:Huffman树，w[]:权值数组(从下标0开始)，code[]:要解码的串
 */ 
void HuffmanDecode(HuffmanTree HT, int w[], char code[])
{
    char *ch = code;
    int i;
    while( *ch != '\0' ){
        //解码一个结点每次都从树根m开始
        for(i=m; HT[i].lchild !=0 && HT[i].rchild != 0; ){
            if( *ch == '0' )
                i = HT[i].lchild;
            else if( *ch == '1' )
                i = HT[i].rchild;
            ++ch;
        }
        cout<<w[i-1]<<" ";
    }
}
int main(void)
{
	char str[100]={0};//输入字符串 
    HuffmanTree HT = NULL;   // 哈夫曼树
    HuffmanCode *HC;    // 保存哈夫曼编码
    int *w,nNode,i;   // w记录权值
    char CodeStr[100]= {0};  //存放编码后的串
    printf("请输入要编码字符串\n");
    gets(str);
    cout<<"输入结点数(>=2):"<<endl;
    cin>>nNode;
    HC=(HuffmanCode *)malloc(nNode*sizeof(HuffmanCode));
    w=(int *)malloc(nNode*sizeof(int));
    cout<<"输入 "<<nNode<<" 个结点的权值\n";
    for(i=0;i<nNode;i++)
        scanf("%d",&w[i]);
    HuffmanCoding(HT,HC,w,nNode);
    cout<<"\n各结点的哈夫曼编码:"<<endl;
    for(i=1;i<=nNode;i++){ 
        printf("%2d(%d):%s\n",i,w[i-1],HC[i]);
        strcat(CodeStr,HC[nNode-i+1]); //简单生成一个huffman码串
    }
    cout<<"对哈夫曼编码\""<<CodeStr<<"\"的解码如下:"<<endl;
    HuffmanDecode(HT,w,CodeStr);
    return 0;
}
