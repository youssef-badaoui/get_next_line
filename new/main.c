#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char str[1000];
	int fd = open("txt", O_RDWR);
	int n = read(fd, str, 54);
	int n2=  read(fd, str, 54);
	printf("%d\n%d\n%d\n%s",fd,n,n2,str);
}

