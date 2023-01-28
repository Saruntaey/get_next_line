#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int fd;
	char *str;

	fd = open("foo.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("fail to open file");	
		return (-1);
	}
	str = get_next_line(fd);
	printf("%s", str);
}
