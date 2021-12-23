#include "get_next_line.h"

int main()
{
	int fd = open("text.txt", O_RDWR);
	printf("%s", get_next_line(fd));
}
