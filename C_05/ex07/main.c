#include <stdio.h>
#include <stdlib.h>

int	ft_find_next_prime(int nb);

int main(int argc, char **argv)
{
	printf("%d\n", ft_find_next_prime(atoi(argv[1])));

	return 0;
}
