#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "bsq.h"

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	if (argc == 1)
		fd = 0;
	i = 0;
	while (i < argc - 1)
	{
		fd = open(argv[i + 1], O_RDONLY);
		if (fd < 0)
		{
			func_fail_handler();
			return (-1);
		}
		
	}
}
