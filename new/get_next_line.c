#include "get_next_line.h"

int the_end(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '\n')
            return 1;
        i++;
    }
    return 0;
}

char    *get_intel(int fd, int size)
{
    char    *str;
    char    *buffer;
    int      n;

    buffer = NULL;
    str = (char *)malloc(size + 1);
    str[0] = 0;
    n = 1;
    while(n > 0 && the_end(str) == 0)
    {

        n = read(fd, str, size);
        if(n <= 0)
            break;
        str[n] = '\0';
        buffer = ft_strjoin(buffer, str);
        //printf("%s", buffer);
    }
    free(str);
    return buffer;
}


char    *get_next_line(int fd)
{
    
    static char    *rest;
    char *line;
    char    *buffer;
    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

   buffer =  get_intel(fd, BUFFER_SIZE);
   //printf("%s\n", buffer);
   if(!buffer)
    return NULL;

   
   if(!get_line(buffer))
    return NULL;
   line = ft_strjoin(rest, get_line(buffer));
   rest = get_rest(buffer);
  free(buffer);
   return (line);
}




// int main()
// {
// 	//char str[] = "hello \n youssef";
//    int fd = open("multiple_nlx5", O_RDWR);
//     printf("%d\n", fd);
//     printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
// }
