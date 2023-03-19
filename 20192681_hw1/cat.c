#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

void cat(int fd)
{
	int n;
	char buf[BUFF_SIZE];

	while ((n = read(fd, buf, sizeof(buf))) > 0) {
		if (write(1, buf, n) != n) {
			printf("cat: write error\n");
			return;
		}
	}
	if (n < 0) {
		printf("cat: read error \n");
		return;
	}
}

int main(int argc, char *argv[])
{
	int fd, i;

	if (argc <= 1) {
		cat(0);
		exit(0);
	}

	for (i = 1; i < argc; i++) {
		fd = open(argv[i], 0);
		if (fd < 0) {
			printf("cat: cannot open %s\n", argv[i]);
			exit(0);
		}
		cat(fd);
		close(fd);
	}
	exit(0);
}
