#include "get_next_line.h"

int is_it_end(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return 0;
	while(str[i] != 0)
	{
		if(str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int main()
{
	char str[] = ""; 

//	str = malloc(5);

	printf("%d",is_it_end(str));
}	:q

