#include <stdio.h>
#include <stdlib.h>

int	ft_fibonacci(int index);

int	main(int argc, char **argv)
{
	printf("%d\n", ft_fibonacci(atoi(argv[1])));
	return (0);
}
