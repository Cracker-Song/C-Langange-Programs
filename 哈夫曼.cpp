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
        printf("1. ����ԭ�ļ�\n");
        printf("2. ����Ļ�ϴ�ӡ�����������\n");
        printf("3. ����ԭ�ļ�\n");
        printf("4. ����ԭ�ļ�\n");
        printf("5. �˳�\n");
        //printf("Input 1-5:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                Reset();
                InputFile();
                if (ok)
                {
                    /* ����ʹ����Ч�ַ���ǰ�� */
                    qsort(ht, N, sizeof(Tree), cmp);
                    /* ������Ч�ַ��ĸ��� */
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
                    printf("ԭ�ļ���δ����!\n");
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
                    printf("ԭ�ļ���δ����!\n");
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
                    printf("ԭ�ļ���δ����!\n");
                }
                system("pause");
                break;
            case 5:
                return 0;
            default:
                fflush(stdin);//��ջ����� 
        }
    }
    return 0;
}
/* ��������ȽϺ��� */
int cmp(const void *a ,const void *b)
{
    return (*(Tree *)a).weight < (*(Tree *)b).weight ? 1 : -1;
}
/* ͳ����Ч���ַ����� */
int NumberOfChar()
{
    int i,num = 0;
    for (i=0;i<N;i++)
    {
        if (ht[i].weight>0) num++;
    }
    return num;
}
/* ��ʼ���������� */
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
/* �����ļ����� */
void InputFile()
{
    FILE *fp;
    char ch;
    //system("cls");
    printf("������ԭ�ļ���:");
    fflush(stdin);
    scanf("%s", file);
    /* ��ԭ�ļ� */
    if ((fp = fopen(file, "rt"))==NULL)
    {
        printf("�Ҳ���ԭ�ļ� %s!\n",file);
        ok = 0;
        system("pause");
        return;
    }
    /* �����ַ�������Ȩ�� */
    while (fscanf(fp, "%c", &ch) != EOF)
    {
        ht[ch].data = ch;
        ht[ch].weight++;
    }
 
    /* �ر��ļ�ָ�� */
    fclose(fp);
    printf("ԭ�ļ� %s ����ɹ�!\n", file);
    ok = 1;
}
/* ���� */
void Encode(int n)
{
    int i, k;
    char ch;
    FILE *fp1, *fp2;
    /* ���ù������������б��� */
    if (access("Huffman_Code.txt",0) != 0)
    {
        printf("�Ҳ�������� Huffman_Code.txt !\n");
        return;
    }
    /* ��Ҫ�����ԭ�ļ� */
    if ((fp1 = fopen(file, "rt")) == NULL)
    {
        printf("�Ҳ���ԭ�ļ� %s !\n", file);
        return;
    }
    /* ���ɱ����ļ� */
    if ((fp2 = fopen("Encode.txt", "wt+")) == NULL)
    {
        printf("�����ļ� Encode.txt ����ʧ��!\n");
        return;
    }
    /* һ���ַ�һ���ַ��滻 */
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
    printf("����ɹ�������� Encode.txt ��!\n");
}
/* ���� */
void Decode(int n)
{
    int i, k;
    char ch;
    FILE *fp1, *fp2;
    if ((fp1 = fopen("Encode.txt", "rt")) == NULL)
    {
        printf("�Ҳ��������ļ� Encode.txt!\n");
        return;
    }
    /* ���ɽ����ļ� */
    if ((fp2 = fopen("Decode.txt", "wt+")) == NULL)
    {
        printf("�����ļ� Decode.txt ����ʧ��!\n");
        return;
    }
    /* ���ù����������� */
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
        /* �ҵ�Ҷ�ӽڵ�Ϊֹ */
        if (ht[i].lchild == -1)
        {
            fprintf(fp2, "%c", ht[i].data);
            /* �����Ӹ��ڵ㿪ʼ���� */
            i = 2 * n - 2;
        }
    }
    /* �ر��ļ�ָ�� */
    fclose(fp1);
    fclose(fp2);
    printf("����ɹ�������� Decode.txt ��!\n");
}
/* ������������뵽�ļ� */
void OutputFile(int n)
{
    FILE *fp;
    int i, k;
    /* ���ɹ�����������ļ� */
    if ((fp = fopen("Huffman_Code.txt", "wt+")) == NULL)
    {
        printf("������ļ� Huffman_Code.txt ����ʧ��!\n");
        return;
    }
    /* ���ڴ���Ķ���д���ļ� */
    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", ht[i].data);
        for (k = hcd[i].start; k <= n; k++)
        {
            fprintf(fp, "%c", hcd[i].cd[k]);
        }
        if (i < n - 1) fprintf(fp, "\n");
    }
    /* �ر��ļ�ָ�� */
    fclose(fp);
    printf("������ļ� Huffman_Code.txt ���ɳɹ�!\n");
}
/* ��ӡ���������뵽��Ļ */
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
/* ����������� */
void CreateHT(int n)
{
    int i, k ,lmin, rmin;
    int min1, min2;
    /* һ����2n-1���ڵ� */
    for (i = n; i < 2 * n - 1; i++)
    {
        /*lmin��rminΪ��СȨ�ص������ڵ���*/
        min1 = min2 = 0x7FFFFFFF;
        lmin = rmin = -1;
        for (k = 0; k <= i - 1; k++)
        {
            /*ֻ����δ����������Ľڵ��в���*/
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
        /* �޸�2��СȨ�ؽڵ��˫�� */
        ht[lmin].parent = i;
        ht[rmin].parent = i;
        /* �޸�˫�׵�Ȩ�� */
        ht[i].weight = ht[lmin].weight + ht[rmin].weight;
        /* �޸�˫�׵ĺ��� */
        ht[i].lchild = lmin;
        ht[i].rchild = rmin;
    }
}
/* �õ����������� */
void CreateHCode(int n)
{
    int i, f, c;
    Code hc;
    /* ���ݹ������������������ */
    for (i = 0; i < n; i++)
    {
        hc.start = n;
        c = i;
        f = ht[i].parent;
        /* ѭ��ֱ��������� */
        while (f != -1)
        {
            /* �������ӽ�� */
            if (ht[f].lchild == c)
            {
                hc.cd[hc.start--] = '0';
            }
            /* �����Һ��ӽ�� */
            else
            {
                hc.cd[hc.start--] = '1';
            }
            c = f;
            f = ht[f].parent;
        }
        /* startָ������������ʼ�ַ� */
        hc.start++;
        hcd[i] = hc;
    }
}
