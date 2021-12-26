
#include "get_next_line.h"

char *strset(char *buffer)
{
	static char *rest;
	char 		*tmp;

	tmp = buffer;
	buffer = ft_strjoin(rest, get_line(buffer));
	rest = get_rest(tmp);
	return (buffer);
}

char *read_intel(int fd, int SIZE)
{
	char	*buffer;
	char	*str;
	int		n;

	str = malloc(SIZE);
	buffer = NULL;
	while(is_it_end(str) == 0)
	{
		n = read(fd, str, SIZE);
		buffer = ft_strjoin(buffer, str);
		if(n < 1)
		{
			free(str);
			return buffer;
		}
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
