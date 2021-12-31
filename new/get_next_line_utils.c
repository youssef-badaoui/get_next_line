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
	char *line;
	


	i = 0;
	line = malloc(ft_strlen(buffer) + 2);
	while(buffer[i] != '\n' && buffer[i] !=  '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if(buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	//free(buffer);

	return (line);
}


char	*ft_strdup(char *str)
{
	int		size;
	char	*ptr;
	int		i;

	i = 0;
	size = ft_strlen(str);
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (0);
	while (i < size)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = 0;
	free(str);
	return (ptr);
}

char *get_rest(char *buffer)
{
	int i;
	int j;
	char *rest;

	if(!buffer)
		NULL;
	i = 0;
	j = 0;
	rest = malloc(ft_strlen(buffer));
	while(buffer[i])
	{
		if(buffer[i] == '\n')
			{
				i++;
				rest[j] = buffer[i];
				j++;
			}
		i++;
	}
	rest = ft_strdup(rest);
	free(buffer);
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
	if(!s2)
		{
            s2 = malloc(1);
            s2[0] = '\0';
        }
   if(!s1)
        {
            s1 = malloc (1);
            s1[0] = '\0';
        }
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
    //free(s2);
	p[i] = 0;
	return (p);
}