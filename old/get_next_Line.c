
#include "get_next_line.h"

/*                       SET STEP                   */

char *strset(char *buffer)
{
	static char *rest;
	char 		*tmp;

	if(!buffer)
		return rest;

	tmp = buffer;
	buffer = ft_strjoin(rest, get_line(buffer));
	rest = get_rest(tmp);
	return (buffer);
}

/*                        READ STEP                  */

char *read_intel(int fd, int SIZE)
{
	char	*buffer;
	char	*str;
	int		n;
	int i;

	i = 0;

	str = malloc(SIZE + 1);
	buffer =  NULL;
	while(is_it_end(str) == 0)
	{
		n = read(fd, str, SIZE);




		if(n <= 0)
			break;


		if(str[0] == 0)
		{
			buffer = ft_strjoin(buffer, str);
			free(str);
			return (buffer);
		}

		if(n < SIZE)
		{
			str[n] = '\0';
			buffer = ft_strjoin(buffer, str);
			free(str);
			return buffer;
		}



		str[n] = 0;
		buffer = ft_strjoin(buffer, str);
		if(n < SIZE)
			break;
	}
	free(str);
	return (buffer);
}

char *get_next_line(int fd)
{
	char *buffer;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_intel(fd, BUFFER_SIZE);
	if(buffer == NULL)
		return NULL;
	return (strset(buffer));
}
