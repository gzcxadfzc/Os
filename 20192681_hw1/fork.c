//fork.c
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int pid = fork();

	if (pid > 0) {
		printf("parent: child=%d\n", pid);
		pid = wait(0);
		printf("child %d is done\n", pid);
	} else if (pid == 0) {
		printf("child: exiting\n");
	} else {
		printf("fork error\n");
	}
	return 0;
}
