#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*ret;
	int		lenRet;
	char	*buf;
	int		status;

	lenRet = 0;
	buf = get_one_buffer(fd);
	
	if (status == 0)
}