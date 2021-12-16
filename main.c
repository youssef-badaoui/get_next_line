#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
char *next(int fd)
{
	static char *str;
	str = malloc(1000);
	read(fd, str, 1);
	return str;
}
char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	char	*p;
	int		size1;
	int		size2;
	int		sizep;

	i = 0;
	if(!s1 || !s2)
		return 0;
	size1 = strlen((char *)s1);
	size2 = strlen((char *)s2);
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
int main()
{
	int fd = open("texty",O_RDWR);
	char *join;
	join = calloc(6,1);
	printf("%d", fd);
	for(int i = 0; i < 12; i++)
	{
		join = ft_strjoin(join, next(1));
		printf("\n%s", join);
	}
//	printf("%s",str);
}
