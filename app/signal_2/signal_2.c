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
	int ret;
/*调用alarm定时器函数*/
//	ret = alarm(5);
	pause();
	printf("I have been waken up.\n");



	return 0;
}

