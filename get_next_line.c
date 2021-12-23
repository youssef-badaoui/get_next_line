#include "get_next_line.h"

char *strset(char *buffer)
{
	static char *rest;
	char 		*tmp;

	tmp = buffer;
	buffer = ft_strjoin(rest,get_line(buffer));
	rest = get_rest(tmp);
	return (buffer);
}

char *read_intel(int fd, int SIZE)
{
	char	*buffer;
	char	*str;

	str = malloc(SIZE);
	str[0] = 0;
	printf("before");
	while(is_it_end(str) == 0)
	{
		printf("after");
		read(fd, str, SIZE);
		buffer = ft_strjoin(buffer, str);
	}
	free(str);
	return (buffer);
}
char *get_next_line(int fd)
{
	char *buffer;

	buffer = read_intel(fd, BUFFER_SIZE);
	return (strset(buffer));
}
