#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/poll.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>


#define FILE_NAME "/dev/btn"


void my_func(int sign_no)
{
	if (sign_no == SIGINT)
		printf("I have got SIGINT\n");
	else if (sign_no == SIGQUIT)
		printf("I have got SIGQUIT\n");
}


int main(int argc, char **argv)
{
	printf("Waiting for signal SIGINT or SIGQUIT \n ");
	signal(SIGINT, my_func);
	signal(SIGQUIT, my_func);
	pause();
	
	printf("OK\n");

	return 0;
}

