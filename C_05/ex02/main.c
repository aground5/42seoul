#include <stdio.h>

int	ft_iterative_power(int nb, int power);

int	main(void)
{
	for (int i = -5; i < 20; i++)
	{
		printf("%d\n", ft_iterative_power(5, i));
	}
}
