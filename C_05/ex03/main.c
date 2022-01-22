#include <stdio.h>

int	ft_recursive_power(int nb, int power);

int	main(void)
{
	for (int i = -5; i < 25; i++)
	{
		printf("%d\n", ft_recursive_power(5, i));
	}
	return (0);
}
