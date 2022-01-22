#include "ft_strncmp.c"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	printf("%d\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
	printf("%d\n", strncmp(argv[1], argv[2], atoi(argv[3])));

	return (0);
}
