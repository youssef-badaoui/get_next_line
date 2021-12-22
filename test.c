#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	char *str;
	int fd = open("txt.txt", O_RDWR);
	read(fd, str, 3);
	read(fd,str,3);
	printf("%s", str);
}
