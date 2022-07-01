#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("multiple_line_no_nl", O_RDONLY);
	char *line;
	do {
		line = get_next_line(fd);
		printf("%s", line);
	} while (line != NULL);
	close(fd);
	return (0);
}
