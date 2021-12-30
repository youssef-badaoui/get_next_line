#include "get_next_line.h"

int main()
{
	//char *str;
	int fd = open("41_no_nl", O_RDWR);
	printf("%s", get_next_line(fd));
		//printf("%s", get_next_line(fd));
}
