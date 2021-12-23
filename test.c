#include "get_next_line.h"
char *read_intel(int fd, int SIZE)
{
	char	*buffer;
	char	*str;
	int		n;

	str = malloc(SIZE);
	while(is_it_end(str) == 0)
	{
		n = read(fd, str, SIZE);
	//	printf("%d\n",n);
		printf("%s", str);
		buffer = ft_strjoin(buffer, str);
	}
	printf("after2");
	free(str);
	return (buffer);
}
int main()
{
	int fd = open("text", O_RDWR);
	printf("%d", fd);
	printf("%s", read_intel(fd, 6));
//	printf("%s\n",str);
}
