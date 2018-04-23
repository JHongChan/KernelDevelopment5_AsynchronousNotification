#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/poll.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>


#define FILE_NAME "/dev/btn"

int main(int argc, char **argv)
{
	pid_t pid;
	int ret;
	if ((pid = fork()) < 0)  /*创建一子进程*/
    {
    	perror("fork");
        exit(1); 
    }
    
    
    if (pid == 0) 
	{     
        raise(SIGSTOP);   /*发出SIGSTOP信号*/
        printf("child process exit…\n");
	    exit(0); 
    }
    else   /*在父进程中检测子进程的状态，调用kill函数*/ 
	{      
        printf("pid = %d\n",pid);
	    if((waitpid(pid, NULL, WNOHANG)) == 0)
	    {     
			kill(pid, SIGKILL);				       
            printf("kill %d\n", pid); 
        }
    }


	return 0;
}

