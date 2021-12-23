#include "get_next_line.h"

int is_it_end(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return (0);
	while(str[i] != 0)
	{
		if(str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str && str[i] != '\n')
		i++;
	return (i);
}

char *get_line(char *buffer)
{
	int	i;
	char *line;

	i = 0;
	line = malloc(ft_strlen(buffer + 2));
	while(buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i++] = '\n';
	line[i++] = '\0';
	return (line);
}

char *get_rest(char *buffer)
{
	int i;

	i = 0;
	while(buffer[i])
	{
		if(buffer[i] == '\n')
			return (buffer + i + 1);
		i++;
	}
	return (0);	
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	char	*p;
	int		size1;
	int		size2;
	int		sizep;

	i = 0;
	if(!s1 )
		return ((char*)s2);
	if(!s2)
		return((char*)s1);
	size1 = ft_strlen((char *)s1);
	size2 = ft_strlen((char *)s2);
	sizep = size1 + size2;
	p = (char *)malloc(sizep + 1);
	if (!p)
		return (0);
	while (i < sizep)
	{
		if (i < size1)
			p[i] = s1[i];
		if (i < size2)
			p[i + size1] = s2[i];
		i++;
	}
	p[i] = 0;
	return (p);
}
