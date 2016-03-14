#include <stdio.h>
#include <winsock2.h>
#pragma comment (lib,"ws2_32.lib")

#define CLIENTSEND_EXIT 1
#define CLIENTSEND_TRAN 2
#define CLIENTSEND_LIST 3

#define SERVERSEND_SELFID 1
#define SERVERSEND_NEWUSR 2
#define SERVERSEND_SHOWMSG 3
#define SERVERSEND_ONLINE 4

FILE *ioutfileServer;
FILE *ioutfileClient;

struct CReceivePackage
{
	int iType;			//存放消息类型
	int iToID;			//存放目标用户ID
	int iFromID;		//存放原用户ID
	char cBuffer[1024];	//存放消息内容
};

struct CSendPackage
{
	int iType;			//消息类型
	int iCurConn;		//当前在线用户数量
	char cBuffer[1024];	//存放消息内容
};

struct CUserSocketInfo
{
	int ID;				//用户的ID
	char cDstIP[64];	//用户的IP地址,扩展使用
	int iPort;			//用户应用程序端口扩展使用
	SOCKET sUserSocket;	//网络句柄
};

struct CUser
{
	int ID;				//用户的ID
	char cDstIP[64];	//用户的IP地址 扩展时使用
};

struct CUser usr[20];
int bSend=0;//是否可以发送消息
int iMyself;//自己的id
int iNew=0;//在线用户数

struct CUserSocketInfo usrinfo[20]; 


void ExitSystem()
{
	if(ioutfileServer!=NULL)
		fclose(ioutfileServer);
	if(ioutfileClient!=NULL)
		fclose(ioutfileClient);
	WSACleanup();
	exit(0);
}

DWORD WINAPI threadproClient(LPVOID pParam)
{
	SOCKET hsock=(SOCKET)pParam;
	char cRecvBuffer[1024];
	char cShowBuffer[1024];
	int num=0;                                                                                                                                                                                                                                                                                                                                                                                  
	if(hsock!=INVALID_SOCKET)
		printf("start:\n");
	while(1)
	{
		num = recv(hsock,cRecvBuffer,1024,0);
		if(num >= 0)
		{		
			cRecvBuffer[num]='\0';
			sprintf(cShowBuffer,"to me : %s\n",cRecvBuffer);
			printf("%s",cShowBuffer);
			fwrite(cShowBuffer ,sizeof(char),strlen(cShowBuffer),ioutfileClient);
			fflush(ioutfileClient);
			if(strcmp("exit",cRecvBuffer)==0)
			{
				ExitSystem();
			}
		}
	}
	return 0;
}

DWORD WINAPI threadproServer(LPVOID pParam)
{
	SOCKET hsock=(SOCKET)pParam;
	char cRecvBuffer[1024];
	char cShowBuffer[1024];
	int num=0;
	if(hsock!=INVALID_SOCKET)
		printf("start:\n");
	while(1)
	{
		num = recv(hsock,cRecvBuffer,1024,0);
		if(num >= 0)
		{		
			cRecvBuffer[num]='\0';
			sprintf(cShowBuffer,"to me : %s\n",cRecvBuffer);
			printf("%s",cShowBuffer);
			fwrite(cShowBuffer ,sizeof(char),strlen(cShowBuffer),ioutfileServer);
			fflush(ioutfileServer);
			if(strcmp("exit",cRecvBuffer)==0)
			{
				ExitSystem();
			}
		}
	}
	return 0;
}


void CreateServer()
{
	SOCKET m_SockServer;
	struct sockaddr_in serveraddr;//本地地址信息
	struct sockaddr_in serveraddrfrom;//连接的地址信息

	int iPort=4600;//设定为固定端口
	int iBindResult=-1;//绑定结果
	int iWhileCount=200;

	struct hostent* localHost;
	char* localIP;

	SOCKET m_Server;

	char cWelcomBuffer[]="Welcome to you\0";

	int len=sizeof(struct sockaddr);
	int iWhileListenCount=10;

	DWORD nThreadId = 0;
	int ires;//发送的返回值

	char cSendBuffer[1024];//发送消息缓存
	char cShowBuffer[1024];//接收消息缓存

	ioutfileServer= fopen("MessageServer.txt","a");//打开记录消息的文件
	m_SockServer = socket ( AF_INET,SOCK_STREAM,  0);
	
	printf("本机绑定的端口号(大于1024)：");
	scanf("%d",&iPort);
	localHost = gethostbyname("");
	localIP = inet_ntoa (*(struct in_addr *)*localHost->h_addr_list);
	//设置网络地址信息
	serveraddr.sin_family = AF_INET;					
	serveraddr.sin_port = htons(iPort);	//端口			
	serveraddr.sin_addr.S_un.S_addr = inet_addr(localIP);//地址
	//绑定地址信息
	iBindResult=bind(m_SockServer,(struct sockaddr*)&serveraddr,sizeof(struct sockaddr));
	//如果端口不能被绑定，重新设置端口
	while(iBindResult!=0 && iWhileCount > 0)
	{
		printf("绑定失败，重新输入：");
		scanf("%d",iPort);
		//设置网络地址信息
		serveraddr.sin_family = AF_INET;					
		serveraddr.sin_port = htons(iPort);//端口	
		serveraddr.sin_addr.S_un.S_addr = inet_addr(localIP);//IP
		//绑定地址信息
		iBindResult = bind(m_SockServer,(struct sockaddr*)&serveraddr,sizeof(struct sockaddr));
		iWhileCount--;
		if(iWhileCount<=0)
		{
			printf("端口绑定失败,重新运行程序\n");
			exit(0);
		}
	}

	while(iWhileListenCount>0)
	{
		printf("start listen\n");
		listen(m_SockServer,0);//返回值判断单个监听是否超时
		m_Server=accept(m_SockServer,(struct sockaddr*)&serveraddrfrom,&len);
			if(m_Server!=INVALID_SOCKET)
			{
				//有连接成功，发送欢迎信息
				send(m_Server,cWelcomBuffer,sizeof(cWelcomBuffer),0);
				//启动接收消息的线程
				CreateThread(NULL,0,threadproServer,(LPVOID)m_Server,0,&nThreadId );
				break;
			}
		printf(".");
		iWhileListenCount--;
		if(iWhileListenCount<=0)
		{
			printf("\n建立连接失败\n");
			exit(0);
		}
	}
	
		
	while(1)
	{
		memset(cSendBuffer,0,1024);
		scanf("%s",cSendBuffer);//输入消息
		if(strlen(cSendBuffer)>0)//输入消息不能为空
		{
			ires = send(m_Server,cSendBuffer,strlen(cSendBuffer),0);//发送消息
			if(ires<0)
			{
				printf("发送失败");
			}
			else
			{
				sprintf(cShowBuffer,"Send to : %s\n",cSendBuffer);
				printf("%s",cShowBuffer);
				fwrite(cShowBuffer ,sizeof(char),strlen(cShowBuffer),ioutfileServer);//将消息写入日志
			}
			if(strcmp("exit",cSendBuffer)==0)
			{
				ExitSystem();
			}
		}
	}
}
int CheckIP(char *cIP)
{
	char IPAddress[128];//IP地址字符串
	char IPNumber[4];//IP地址中每组的数值
	int iSubIP=0;//IP地址中4段之一
	int iDot=0;//IP地址中'.'的个数
	int iResult=0;
	int iIPResult=1;
	int i;//循环控制变量
	memset(IPNumber,0,4);
	strncpy(IPAddress,cIP,128);
	for(i=0;i<128;i++)
	{
		if(IPAddress[i]=='.')
		{
			iDot++;
			iSubIP=0;
			if(atoi(IPNumber)>255)
				iIPResult = 0;
			memset(IPNumber,0,4);
		}
		else
		{
			IPNumber[iSubIP++]=IPAddress[i];
		}
		if(iDot==3 && iIPResult!=0)
			iResult= 1;
	}
	return iResult;
}
void CreateClient()
{
	SOCKET m_SockClient;
	struct sockaddr_in clientaddr;
	char cServerIP[128];
	int iWhileIP=10;//循环次数
	int iCnnRes;//连接结果
	DWORD nThreadId = 0;//线程ID值
	char cSendBuffer[1024];//发送缓存
	char cShowBuffer[1024];//显示缓存
	char cRecvBuffer[1024];//接收缓存
	int num;//接收的字符个数
	int ires;//发送消息的结果
	int iIPRes;//检测IP是否正确
	m_SockClient = socket ( AF_INET,SOCK_STREAM, 0 );
	printf("请输入服务器地址：");
	scanf("%s",cServerIP);
	//IP地址判断
	if(strlen(cServerIP)==0)
		strcpy(cServerIP,"127.0.0.1");//没有输入地址，使用回环地址
	else
	{
		iIPRes=CheckIP(cServerIP);
		while(!iIPRes && iWhileIP>0)
		{
			printf("请重新输入服务器地址：\n");
			scanf("%s",cServerIP);//重新输入IP地址
			iIPRes=CheckIP(cServerIP);//检测IP的合法性
			iWhileIP--;
			if(iWhileIP<=0)
			{
				printf("输入次数过多\n");
				exit(0);
			}
		}
	}

	ioutfileClient= fopen("MessageServerClient.txt","a");//打开记录消息的文件
	clientaddr.sin_family = AF_INET;
	//客户端向服务端请求的端口好，应该和服务端绑定的一致			
	clientaddr.sin_port = htons(4600);
	clientaddr.sin_addr.S_un.S_addr = inet_addr(cServerIP);

	iCnnRes = connect(m_SockClient,(struct sockaddr*)&clientaddr,sizeof(struct sockaddr));
	if(iCnnRes==0)//连接成功
	{
		num = recv(m_SockClient,cRecvBuffer,1024,0);//接收消息
		if( num > 0 )
		{
			printf("Receive form server : %s\n",cRecvBuffer);
			//启动接收消息的线程
			CreateThread(NULL,0,threadproClient,(LPVOID)m_SockClient,0,&nThreadId );
		}
		while(1)
		{
			memset(cSendBuffer,0,1024);
			scanf("%s",cSendBuffer);	
			if(strlen(cSendBuffer)>0)
			{
				ires=send(m_SockClient,cSendBuffer,strlen(cSendBuffer),0);
				if(ires<0)
				{
					printf("发送失败\n");
				}
				else
				{
					sprintf(cShowBuffer,"Send to : %s\n",cSendBuffer);//整理要显示的字符串
					printf("%s",cShowBuffer);
					fwrite(cShowBuffer ,sizeof(char),strlen(cShowBuffer),ioutfileClient);//记录发送消息
					fflush(ioutfileClient);
				}
				if(strcmp("exit",cSendBuffer)==0)
				{
					ExitSystem();
				}
			}
		}
	}//iCnnRes
	else
	{
		printf("连接不正确\n");
	}
}

DWORD WINAPI threadTranServer(LPVOID pParam) 
{
	SOCKET hsock=(SOCKET)pParam;//获取SOCKET句柄
	SOCKET sTmp;//临时存放用户的SOCKET句柄
	char cRecvBuffer[1024];//接收消息的缓存
	int num=0;//发送的字符串
	int m,j;//循环控制变量
	//char cTmp[2];//临时存放用户ID
	int ires;
	struct CSendPackage sp;//发包
	struct CReceivePackage *p;
	if(hsock!=INVALID_SOCKET)
		printf("start:%d\n",hsock);
	while(1)
	{
		num=recv(hsock,cRecvBuffer,1024,0);//接收发送过来的信息
		if(num>=0)
		{		
			p = (struct CReceivePackage*)cRecvBuffer;
			switch(p->iType)
			{
			case CLIENTSEND_TRAN://对消息进行中转
				for(m=0;m<2;m++)
				{
					if(usrinfo[m].ID==p->iToID)
					{
						//组包
						sTmp=usrinfo[m].sUserSocket;
						memset(&sp,0,sizeof(sp));
						sp.iType=SERVERSEND_SHOWMSG;
						strcpy(sp.cBuffer,p->cBuffer);
						ires = send(sTmp,(char*)&sp,sizeof(sp),0);//发送内容
						if(ires<0)
							printf("发送失败\n");
					}
				}
				break;
			case CLIENTSEND_LIST://发送在线用户
				memset(&sp,0,sizeof(sp));
				for(j=0;j<2;j++)
				{
					if(usrinfo[j].ID!=p->iFromID && usrinfo[j].ID!=0)
					{
						sp.cBuffer[j]=usrinfo[j].ID;
					}
				}
				sp.iType=SERVERSEND_ONLINE;
				send(hsock,(char*)&sp,sizeof(sp),0);
				break;
			case CLIENTSEND_EXIT:
				printf("退出系统\n");
				return 0;//结束线程
				break;
			}
		}
	}
	return 0;
}

DWORD WINAPI NotyifyProc(LPVOID pParam)
{
	struct CSendPackage sp;//发送包
	SOCKET sTemp;//连接用户的socket句柄
	int *p;//接收主线程发送过来的ID值
	int j;//循环控制变量
	p=(int*)pParam;//新用户ID
	
	for(j=0;j<2;j++)//去除新登录的,已经连接的
	{
		if(usrinfo[j].ID !=  (*p))
		{
			sTemp=usrinfo[j].sUserSocket;
			sp.iType=SERVERSEND_NEWUSR;//新上线通知
			sprintf(sp.cBuffer,"%d\n",(*p));
			send(sTemp,(char*)&sp,sizeof(sp),0);//发送新用户上线通知
		}
	}
	return 0;
}

void CreateTranServer()
{
	SOCKET m_SockServer;//开始监听的SOCKET句柄
	struct sockaddr_in serveraddr;//用于绑定的地址信息
	struct sockaddr_in serveraddrfrom;//接收到的连接的地址信息
	int iRes;//获取绑定的结果
	SOCKET m_Server;//已建立连接的SOCKET句柄
	struct hostent* localHost;//主机环境指针
	char* localIP;//本地IP地址
	struct CSendPackage sp;//发送包
	int iMaxConnect=20;//允许的最大连接个数
	int iConnect=0;//建立连接的个数
	DWORD nThreadId = 0;//获取线程的ID值
	char cWarnBuffer[]="It is voer Max connect\0";//警告字符串
	int len=sizeof(struct sockaddr);
	int id;//新分配的客户ID
	localHost = gethostbyname("");
	localIP = inet_ntoa (*(struct in_addr *)*localHost->h_addr_list);//获取本地IP
	serveraddr.sin_family = AF_INET;					
	serveraddr.sin_port = htons(4600);//设置绑定的端口号			
	serveraddr.sin_addr.S_un.S_addr = inet_addr(localIP);//设置本地IP
	//创建套接字
	m_SockServer = socket ( AF_INET,SOCK_STREAM,  0);
	if(m_SockServer == INVALID_SOCKET)
	{
		printf("建立套接字失败\n");
		exit(0);
	}
	//绑定本地IP地址
	iRes=bind(m_SockServer,(struct sockaddr*)&serveraddr,sizeof(struct sockaddr));
	if(iRes < 0)
	{
		printf("建立套接字失败\n");
		exit(0);
	}
	//程序主循环
	while(1)
	{
		listen(m_SockServer,0);//开始监听
		m_Server=accept(m_SockServer,(struct sockaddr*)&serveraddrfrom,&len);//接收连接
		if(m_Server!=INVALID_SOCKET)
		{
			printf("有新用户登录");//对方已登录 
			if(iConnect < iMaxConnect)
			{
				//启动接收消息线程
				CreateThread(NULL,0,threadTranServer,(LPVOID)m_Server,0,&nThreadId );
				//构建连接用户的信息
				usrinfo[iConnect].ID=iConnect+1;//存放用户ID
				usrinfo[iConnect].sUserSocket=m_Server;
				usrinfo[iConnect].iPort=0;//存放端口，扩展用
				//构建发包信息
				sp.iType=SERVERSEND_SELFID;//获取的ID值，返回信息
				sp.iCurConn=iConnect;//在线个数
				id=iConnect+1;
				sprintf(sp.cBuffer,"%d\0",id);
				send(m_Server,(char*)&sp,sizeof(sp),0);//发送客户端的ID值
				//通知各个客户端
				if(iConnect>0)
					CreateThread(NULL,0,NotyifyProc,(LPVOID)&id,0,&nThreadId );
				iConnect++;
			}
			else
				send(m_Server,cWarnBuffer,sizeof(cWarnBuffer),0);//已超出最大连接数
		}
	}
	WSACleanup();
}



DWORD WINAPI threadTranClient(LPVOID pParam) 
{
	SOCKET hsock=(SOCKET)pParam;
	int i;//循环控制变量
	char cRecvBuffer[2048];//接收消息的缓存
	int	num;//接收消息的字符数
	//char cTmp[2];//临时存放在线用户ID
	struct CReceivePackage sp;//服务端的接收包是，客户端的发送包
	struct CSendPackage *p;//服务端的发送包是，客户端的接收包
	int iTemp;//临时存放接收到的ID值
	while(1)
	{
		num = recv(hsock,cRecvBuffer,2048,0);//接收消息
		if(num>=0) 
		{
			p = (struct CSendPackage*)cRecvBuffer;
			if(p->iType==SERVERSEND_SELFID)
			{
				iMyself=atoi(p->cBuffer);
				sp.iType=CLIENTSEND_LIST;//请求在线人员列表
				send(hsock,(char*)&sp,sizeof(sp),0);
			}
			if(p->iType==SERVERSEND_NEWUSR)//登录用户ID
			{
				iTemp = atoi(p->cBuffer);
				usr[iNew++].ID=iTemp;//iNew表示有多少个新用户登录 
				printf("有新用户登录,可以与其聊天\n");
				bSend=1;//可以发送消息聊天
			}
			if(p->iType==SERVERSEND_SHOWMSG)//显示接受的消息
			{
				printf("rec:%s\n",p->cBuffer);
			}
			if(p->iType==SERVERSEND_ONLINE)//获取在线列表
			{
				for(i=0;i<2;i++)
					{
						if(p->cBuffer[i]!=iMyself && p->cBuffer[i]!=0)
						{
							usr[iNew++].ID=p->cBuffer[i];
							printf("有用户在线,可以与其聊天\n");
							bSend=1;//可以发送消息聊天
						}
					}
					if(!bSend)
						printf("在线列表为空\n");
			}
		}
	}
	return 0;
}

void ExitTranSystem()
{
	WSACleanup();
	exit(0);
}
void CreateTranClient()
{
	SOCKET m_SockClient;//建立连接的socket
	struct sockaddr_in clientaddr;//目标的地址信息
	int iRes;//函数执行情况
	char cSendBuffer[1024];//发送消息的缓存
	DWORD nThreadId = 0;//保存线程的ID值
	struct CReceivePackage sp;//发包结构
	char IPBuffer[128];
	printf("输入服务器IP地址\n");
	scanf("%s",IPBuffer);

	clientaddr.sin_family = AF_INET;				
	clientaddr.sin_port = htons(4600);//连接的端口号
	clientaddr.sin_addr.S_un.S_addr = inet_addr(IPBuffer);
	m_SockClient = socket ( AF_INET,SOCK_STREAM, 0 );//创建socket
	//建立与服务端的连接
	iRes = connect(m_SockClient,(struct sockaddr*)&clientaddr,sizeof(struct sockaddr));
	if(iRes < 0)
	{
		printf("连接错误\n");
		exit(0);
	}
	//启动接收消息的线程
	CreateThread(NULL,0,threadTranClient,(LPVOID)m_SockClient,0,&nThreadId );
	while(1)//接收到自己ID
	{
		memset(cSendBuffer,0,1024);
		scanf("%s",cSendBuffer);//输入发送内容
		if(bSend)
		{
			if(sizeof(cSendBuffer)>0)
			{
				memset(&sp,0,sizeof(sp));
				strcpy(sp.cBuffer,cSendBuffer);
				sp.iToID=usr[0].ID;//聊天对象是固定的
				sp.iFromID=iMyself;//自己
				sp.iType=CLIENTSEND_TRAN;
				send(m_SockClient,(char*)&sp,sizeof(sp),0);//发送消息
			}
			if(strcmp("exit",cSendBuffer)==0)
			{
				memset(&sp,0,sizeof(sp));
				strcpy(sp.cBuffer,"退出");//设置发送消息的文本内容
				sp.iFromID=iMyself;
				sp.iType=CLIENTSEND_EXIT;//退出
				send(m_SockClient,(char*)&sp,sizeof(sp),0);//发送消息
				ExitTranSystem();
			}
		}
		else
			printf("没有接收对象,发送失败\n");
	Sleep(10);
	}
}

int main(void)
{
	int iSel=0;
	WSADATA wsd;									
	WSAStartup(MAKEWORD(2,2),&wsd);
	do
	{
		printf("选择程序类型：\n");
		printf("点对点服务端: 1\n");
		printf("点对点客户端: 2\n");
		printf("服务器中转服务端: 3\n");
		printf("服务器中转客户端: 4\n");
		scanf("%d",&iSel);
	}while(iSel<0 || iSel >4);
	switch(iSel)
	{
	case 1:
		CreateServer();
		break;
	case 2:
		CreateClient();
		break;
	case 3:
		CreateTranServer();
		break;
	case 4:
		CreateTranClient();
		break;
	}
	printf("退出系统\n");
	
	return 0;
}

