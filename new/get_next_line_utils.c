#include "get_next_line.h"

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i]!= 0)
		i++;
	return (i);
}

char *get_line(char *buffer)
{
	int	i;
	int j;
	char *line;
	
	i = 0;
	j = 0;
	if(!buffer)
		return NULL;
	while(buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (line);
	while(j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char *get_rest(char *buffer)
{
	int i;
	int j;
	char *rest;

	if(!buffer)
		return (NULL);
	i = 0;
	j = 0;
	while(buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	rest = malloc(ft_strlen(buffer) - i + 1);
	while(buffer[i])
	{
		rest[j] = buffer[i];
		i++;
		j++;
	}
	rest[j] = '\0';
	return (rest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*p;
	int		size1;
	int		size2;
	int		sizep;

	i = 0;
   if(s1 == NULL)
    {
	    s1 = malloc(1);
        s1[0] = '\0';
    }
	if(!s2)
		return s1;
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
   	free(s1);
	p[i] = 0;
	return (p);
}