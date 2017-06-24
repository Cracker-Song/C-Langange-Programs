#include"huffman.h"
int cmp(const void*, const void*);
int NumberOfChar();
void Reset();
void InputFile();
void Encode(int);
void Decode(int);
void OutputFile(int);
void PrintHuffmanCode(int);
void CreateHT(int);
void CreateHCode(int);
int main(void)
{
    int choice=0;
    int n=0;
    char ch;
    while(1)
    {
        //system("cls");
        printf("1. 读入原文件\n");
        printf("2. 在屏幕上打印哈夫曼代码表\n");
        printf("3. 编码原文件\n");
        printf("4. 解码原文件\n");
        printf("5. 退出\n");
        //printf("Input 1-5:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                Reset();
                InputFile();
                if (ok)
                {
                    /* 排序使得有效字符在前面 */
                    qsort(ht, N, sizeof(Tree), cmp);
                    /* 记下有效字符的个数 */
                    n=NumberOfChar();
                    CreateHT(n);
                    CreateHCode(n);
                    OutputFile(n);
                    system("pause");
                }
                break;
            case 2:
                //system("cls");
                if (ok)
                {
                    PrintHuffmanCode(n);
                }
                else
                {
                    printf("原文件尚未读入!\n");
                }
                system("pause");
                break;
            case 3:
                //system("cls");
                if (ok)
                {
                    Encode(n);
                }
                else
                {
                    printf("原文件尚未读入!\n");
                }
                system("pause");
                break;
            case 4:
                //system("cls");
                if (ok)
                {
                    Decode(n);
                }
                else
                {
                    printf("原文件尚未读入!\n");
                }
                system("pause");
                break;
            case 5:
                return 0;
            default:
                fflush(stdin);//清空缓冲区 
        }
    }
    return 0;
}
/* 快速排序比较函数 */
int cmp(const void *a ,const void *b)
{
    return (*(Tree *)a).weight < (*(Tree *)b).weight ? 1 : -1;
}
/* 统计有效的字符数量 */
int NumberOfChar()
{
    int i,num = 0;
    for (i=0;i<N;i++)
    {
        if (ht[i].weight>0) num++;
    }
    return num;
}
/* 初始化哈夫曼树 */
void Reset()
{
    int i;
    for (i=0;i<M;i++)
    {
        ht[i].weight = 0;
        ht[i].parent = -1;
        ht[i].lchild = -1;
        ht[i].rchild = -1;
    }
}
/* 读入文件内容 */
void InputFile()
{
    FILE *fp;
    char ch;
    //system("cls");
    printf("请输入原文件名:");
    fflush(stdin);
    scanf("%s", file);
    /* 打开原文件 */
    if ((fp = fopen(file, "rt"))==NULL)
    {
        printf("找不到原文件 %s!\n",file);
        ok = 0;
        system("pause");
        return;
    }
    /* 读入字符并处理权重 */
    while (fscanf(fp, "%c", &ch) != EOF)
    {
        ht[ch].data = ch;
        ht[ch].weight++;
    }
 
    /* 关闭文件指针 */
    fclose(fp);
    printf("原文件 %s 读入成功!\n", file);
    ok = 1;
}
/* 编码 */
void Encode(int n)
{
    int i, k;
    char ch;
    FILE *fp1, *fp2;
    /* 利用哈夫曼代码表进行编码 */
    if (access("Huffman_Code.txt",0) != 0)
    {
        printf("找不到代码表 Huffman_Code.txt !\n");
        return;
    }
    /* 打开要编码的原文件 */
    if ((fp1 = fopen(file, "rt")) == NULL)
    {
        printf("找不到原文件 %s !\n", file);
        return;
    }
    /* 生成编码文件 */
    if ((fp2 = fopen("Encode.txt", "wt+")) == NULL)
    {
        printf("编码文件 Encode.txt 创建失败!\n");
        return;
    }
    /* 一个字符一个字符替换 */
    while (fscanf(fp1, "%c", &ch) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            if (ht[i].data == ch)
            {
                for (k = hcd[i].start; k <= n; k++)
                {
                    fprintf(fp2, "%c", hcd[i].cd[k]);
                }
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
    printf("编码成功，结果在 Encode.txt 中!\n");
}
/* 解码 */
void Decode(int n)
{
    int i, k;
    char ch;
    FILE *fp1, *fp2;
    if ((fp1 = fopen("Encode.txt", "rt")) == NULL)
    {
        printf("找不到编码文件 Encode.txt!\n");
        return;
    }
    /* 生成解码文件 */
    if ((fp2 = fopen("Decode.txt", "wt+")) == NULL)
    {
        printf("解码文件 Decode.txt 创建失败!\n");
        return;
    }
    /* 利用哈夫曼树解码 */
    i = 2 * n - 2;
    while (fscanf(fp1, "%c", &ch) != EOF)
    {
        if (ch == '0')
        {
            i = ht[i].lchild;
        }
        else
        {
            i = ht[i].rchild;
        }
        /* 找到叶子节点为止 */
        if (ht[i].lchild == -1)
        {
            fprintf(fp2, "%c", ht[i].data);
            /* 继续从根节点开始查找 */
            i = 2 * n - 2;
        }
    }
    /* 关闭文件指针 */
    fclose(fp1);
    fclose(fp2);
    printf("解码成功，结果在 Decode.txt 中!\n");
}
/* 输出哈弗曼编码到文件 */
void OutputFile(int n)
{
    FILE *fp;
    int i, k;
    /* 生成哈夫曼代码表文件 */
    if ((fp = fopen("Huffman_Code.txt", "wt+")) == NULL)
    {
        printf("代码表文件 Huffman_Code.txt 创建失败!\n");
        return;
    }
    /* 将内存里的东西写入文件 */
    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", ht[i].data);
        for (k = hcd[i].start; k <= n; k++)
        {
            fprintf(fp, "%c", hcd[i].cd[k]);
        }
        if (i < n - 1) fprintf(fp, "\n");
    }
    /* 关闭文件指针 */
    fclose(fp);
    printf("代码表文件 Huffman_Code.txt 生成成功!\n");
}
/* 打印哈夫曼编码到屏幕 */
void PrintHuffmanCode(int n)
{
    int i, k;
    printf("ASCII \t Char \t HuffmanCode\n");
    for (i = 0; i < n; i++)
    {
        printf("%d \t \"%c\" \t ", ht[i].data, ht[i].data);
        for (k = hcd[i].start; k <= n; k++)
        {
            printf("%c", hcd[i].cd[k]);
        }
        printf("\n");
    }
}
/* 构造哈夫曼树 */
void CreateHT(int n)
{
    int i, k ,lmin, rmin;
    int min1, min2;
    /* 一共有2n-1个节点 */
    for (i = n; i < 2 * n - 1; i++)
    {
        /*lmin和rmin为最小权重的两个节点置*/
        min1 = min2 = 0x7FFFFFFF;
        lmin = rmin = -1;
        for (k = 0; k <= i - 1; k++)
        {
            /*只在尚未构造二叉树的节点中查找*/
            if (ht[k].parent == -1)
            {
                if (ht[k].weight < min1)
                {
                    min2 = min1;
                    rmin = lmin;
                    min1 = ht[k].weight;
                    lmin = k;
                }
                else if (ht[k].weight < min2)
                {
                    min2 = ht[k].weight;
                    rmin = k;
                }
            }
        }
        /* 修改2个小权重节点的双亲 */
        ht[lmin].parent = i;
        ht[rmin].parent = i;
        /* 修改双亲的权重 */
        ht[i].weight = ht[lmin].weight + ht[rmin].weight;
        /* 修改双亲的孩子 */
        ht[i].lchild = lmin;
        ht[i].rchild = rmin;
    }
}
/* 得到哈夫曼编码 */
void CreateHCode(int n)
{
    int i, f, c;
    Code hc;
    /* 根据哈夫曼树求哈夫曼编码 */
    for (i = 0; i < n; i++)
    {
        hc.start = n;
        c = i;
        f = ht[i].parent;
        /* 循序直到树根结点 */
        while (f != -1)
        {
            /* 处理左孩子结点 */
            if (ht[f].lchild == c)
            {
                hc.cd[hc.start--] = '0';
            }
            /* 处理右孩子结点 */
            else
            {
                hc.cd[hc.start--] = '1';
            }
            c = f;
            f = ht[f].parent;
        }
        /* start指向哈夫曼编码最开始字符 */
        hc.start++;
        hcd[i] = hc;
    }
}
