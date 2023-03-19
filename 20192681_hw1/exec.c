//exec.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char *argv[2] = {"ls", 0};

	int pid = fork();

	if (pid > 0 ) {
		printf("parent: child=%d\n", pid);
		wait(0);
		printf("child %d is done", pid);
	} else if (pid == 0) {
		printf("child: exiting\n");
		execve("/bin/ls", argv, NULL);
	} else {
		printf("exec error\n");
	}
}
