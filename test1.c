#include "get_next_line.h"

char *read_intel(int fd, int SIZE)
{
	char	*buffer;
	char	*str;
	int		n;

	str = malloc(SIZE);
	buffer = NULL;
	while(is_it_end(str) == 0)
	{
	//	str = 0;
		n = read(fd, str, SIZE);
//		printf("%s\n", str);
		//str  = 	NULL;
		buffer = ft_strjoin(buffer, str);
//		puts(buffer);
	}
//	printf("%d",n);
	free(str);
	return (buffer);
}

int main()
{
	int fd = open("text", O_RDWR);
	printf("%s\n\n\n", read_intel(fd , 4));
//	printf("%s", read_intel(fd, 4));
}
