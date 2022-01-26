#include <unistd.h>

#include "bsq.h"

int	check_map_flood(int fd)
{
	char	c;

	if (read(fd, &c, 1) > 0)
	{
		return (MERRBFCLR);
	}
	return (NORMEX);
}
