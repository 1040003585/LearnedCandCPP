//国嵌unix，第三天第一集 

1.进程ID(PID):标识进程的唯一数字
2.父进程的ID(PPID)
3.启动进程的用户ID(UID)

4.调度算法：
a.先来先服务调度算法
b.短进程优先调度算法   《指时间的长短》
c.高优先级优先调度算法
d.时间片轮转法

5.获取ID：

#include<sys/types.h>
#include<unistd.h>



aaaaaaaaaaaaaaaaaaaaaaa.

pid_t getpid(void)
	获取本进程ID


bbbbbbbbbbbbbbbbbbbbbbbbbbbb. 

pid_t getppid(void)
	获取父进程


cccccccccccccccccccccccccccccc.

pid_t fork(void)   // #include<unistd.h>
	功能：创建子进程 //fork奇妙之处在于被调用一次返回两次，可能有3种不同的返回值
-在父进程中，fork返回新建的子进程的PID；
-在子进程中，fork返回0；（返回给子进程）
-如果出现错误，fork返回一个负值；

--fork时只拷贝数据（数据空间），堆栈空间，不拷贝代码（共享代码）！



dddddddddddddddddddddddddddddddd.

pid_t vfork()
	功能：创建子进程

和fork区别：
-fork：子进程拷贝父进程的数据段
-vfork：子进程和父进程共享数据段

-fork：父子进程的执行次序不确定
-vfork：子进程先运行，父进程后运行


eeeeeeeeeeeeeeeeeeeeeeeeeeee.

exec用被执行的程序替换调用它的程序
区别：
fork创建一个新的进程，产生一个新的PID。
exec启动一个新程序，替代原有进程，因此进程的PID不变。

 int execl(const char *path, const char * arg1,....)(#include<unistd.h>)
参数：
  path：被执行程序名（含完整路径）
  arg1-argn：被执行程序所需要的命令行参数，含程序名，以空指针（NULL）结束。
『例如：execl("/bin/ls", "ls", "-al", "/etc/passwd", (char *)0 )』	
  


ffffffffffffffffffffffffff.

int execlp(const char *path, const char *arg1,...)(#include<unistd.h>)
参数：
path：被执行的程序名（不含路径，将从path环境变量中查找该程序）
arg1-argn：被执行程序所需的命令行参数，含程序名。译空指针（NULL）结束。
『例如：execlp("ls", "ls", "-al", "etc/passwd", (char *)0)』



iiiiiiiiiiiiiiiiiiiiiiii.

execv(const char *path, char *const argv[ ])
参数：
path：被执行程序名（含完整路径）
argv[]：被执行程序所需的命令行参数数组。
『例如：char *argv[] = {"ls","-al", "/etc/passwd", (char*)0}
		execv("/bin/ls", argv)』


jjjjjjjjjjjjjjjjjjjj.

int system(const char *string)[#include<stdlib.h>]
功能：
	调用fork产生子进程，由子进程来调用 /bin/sh/ -c string 来执行参数string所代表的命令。
『例如：system("ls -al /etc/passwd")』



6.进程的等待

a.

pid_t wait(int status)[#include<sys/types.h> #include<sys/wait.h>]
功能：
	阻塞该进程，直到某个子进程退出/



7.
进程间的通信
a.通信方式：
	-管道（pipe）和有名管道（FIFO）【有名和无名，前者用于父子进程的通信，后者可以是任意两个进程间的通信】
	-信号（signal）
	-消息队列
	-共享内存
	-信号量
	-套接字（socket）
//必须掌握5个以上
//管道是 单向的，先进先出的

无名管道：int pipe(int filedis[2]);  //filedis[0]用于读管道，filedis[1]用来写管道
                                     //filedis是自己定义的一个数组。先定义后用 ,
				    //filedis两个元素都要close掉
 //注意必须先fork再pipe！！！

b. 
int mkfifo(const char *pathname, mode_t mode)
//	[#include<sys/types.h> #include<sys/stat.h>]
	pathname:FIFO文件名
	mode：属性
	（一旦创建了FIFO，就可用open打开它，一般的文件访问函数（close，read，write等））都可以用于FIFO。

c.操作
当打开FIFO时，非阻塞标志（O_NONBLOCK）将对以后的读写产生如下影响
-没有使用"O_NONBLOCK":访问要求无法满足时进程将阻塞。试图读空FIFO，将导致进程阻塞
-使用"O_NONBLOCK"：访问要求无法满足不阻塞，立即出错返回，errno是NEXIO。

