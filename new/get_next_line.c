#include "get_next_line.h"

int the_end(char *str)
{
    int i;

    i = 0;
    if (str == NULL)
        return (0);
    while(str[i] != '\0')
    {
        if(str[i] == '\n')
            return 1;
        i++;
    }
    return 0;
}

char    *get_intel(int fd, int size, char *buffer)
{
    char    *str;
    int      n;

    // buffer = NULL;
    str = (char *)malloc(size + 1);
    if (!str)
        return (0);
    str[0] = 0;
    n = 1;
    while(n > 0 && the_end(buffer) == 0)
    {
        n = read(fd, str, size);
        //printf("%s", str);
        if(n <= 0)
            break;
        str[n] = '\0';
        buffer = ft_strjoin(buffer, str);
    }
    free(str);
    return buffer;
}


char    *get_next_line(int fd)
{
    static char    *rest;
    char *line;
    char    *buffer = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    if (rest != NULL)
    {
        buffer = ft_strjoin(rest, buffer);
        rest = NULL;
    }
    buffer =  get_intel(fd, BUFFER_SIZE, buffer);
    if (buffer == NULL)
        return (NULL);
    line = get_line(buffer);
    if (ft_strlen(buffer) > ft_strlen(line))
    {
        rest = get_rest(buffer);
    }
    free(buffer);
    return (line);
}



 
// int main()
// {
// 	//char str[] = "hello \n youssef";
//    int fd = open("41_with_nl", O_RDWR);
//   //  printf("%d\n", fd);
//     printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//  }