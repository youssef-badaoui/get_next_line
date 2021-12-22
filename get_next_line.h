#include "get_next_line"

char *strset(char *buffer)
{
	static char *rest;
	char 		*tmp;

	tmp = buffer;
	buffer = strjoin(rest,get_line(buffer));
	rest = get_rest(tmp);
	return (buffer);
}

char *read_intel(int fd, int BUFFER_SIZE)
{
	char	*buffer;
	char	*str;

	str = malloc(BUFFER_SIZE);
	str[0] = 0;
	while(is_it_end(str) == 0)
	{
		read(fd, str, BUFFER_SIZE);
		buffer = strjoin(buffer, str);
	}
	free(str);
	return (buffer);
}
char *get_next_line(int fd)
{
	char *buffer;
	int BUFFER_SIZE;

	buffer = read_intel(fd, BUFFER_SIZE);
	return (strset(buffer));
}
