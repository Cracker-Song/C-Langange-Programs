#include<stdio.h>
#include<string.h>
int len1,len2;
char s1[905];
char s2[905];
int re[905];
void sub()
{
    int i=0;
    int j;
    while(1)
    {
        if(s1[i]=='0')
            i++;
        else
        {
            j=i;
            break;
        }
    }
    for(;i<len2;i++)
    {
        s1[i]=s1[i]-s2[i]+'0';
    }
    for(i=len2-1;i>j;i--)    //��λ��ʼ����Ƿ�С��0
    {
        if(s1[i]<'0')
        {
            s1[i]+=10;
            s1[i-1]--;
        }
    }
}

int main(void)
{
    int i,p;
    while(scanf("%s%s",s1,s2)==2)
    {
        len1=strlen(s1);
        len2=strlen(s2);
        if(len1<len2||(len1==len2&&strncmp(s1,s2,len2)<0))   //���a<b,ֱ�����0
        {
            printf("0\n");
            continue;
        }
        p=0;
        while(1)
        {
            re[p]=0;
            while(strncmp(s1,s2,len2)>=0)       //һֱ���м�����ֱ�����ܼ�Ϊֹ
             {
                sub();
                re[p]++;
            }
            p++;
            if(len1==len2)
                break;
            for(i=len2-1;i>=0;i--)             //��s2ǰ�油0���Ա���м�������
             {
                s2[i+1]=s2[i];
            }
            s2[0]='0';
            len2++;
            s2[len2]='\0';
        }
        i=0;
        while(1)
        {
            if(re[i]==0)
                i++;
            else
                break;
        }
        for(;i<p;i++)
            printf("%d",re[i]);
        printf("\n");
    }
    return 0;
}
