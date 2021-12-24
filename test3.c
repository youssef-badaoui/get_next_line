#include "get_next_line.h"

char *strset(char *buffer)
{
	static char *rest;
	char 		*tmp;

	tmp = buffer;
	//printf("%s", get_line(buffer));
	buffer = ft_strjoin(rest,get_line(buffer));
	rest = get_rest(tmp);
//	printf("%s",rest);
	return (buffer);
}
int main()
{
	char str[] = "hello world \nyes";
	printf("%s", strset(str));
	printf("%s", strset(str));
	printf("%s", strset(str));
}

