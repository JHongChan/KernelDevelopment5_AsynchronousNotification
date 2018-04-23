#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <signal.h>

int fd;
void my_func(int sign_no)
{
	if (sign_no == SIGINT)
	{	
		printf("I have got ctrl + c\n");
		exit(0);
	}
	else if (sign_no == SIGIO)
	{
		if(fd<0)
		{
			printf("it is failed to open file\n");
		}
		else
		{
			char val;
			read(fd,&val,sizeof(val));
			printf("%d\n",val);
		}
	}
}


int main(void)
{
	
	int flags;
	fd = open("/dev/btn_asy_notification",O_RDWR);
	if(fd<0)
	{
		perror("open");
		exit(-1);
	}	
	
	//自定义SIGIO信号的处理函数
	signal(SIGINT, my_func);
	signal(SIGIO, my_func);
	
	//设置可以处理SIGIO信号
	fcntl(fd, F_SETOWN, getpid());
	flags = fcntl(fd, F_GETFL);
	fcntl(fd, F_SETFL, flags | FASYNC);
	
	
	char val;
	
	while(1)
	{
		pause();
	}
	
	
	

	return 0;
}
