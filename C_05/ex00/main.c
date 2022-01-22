#include <stdio.h>

int ft_iterative_factorial(int nb);

int main(void)
{
	for (int i = -5; i < 20 ; i++)
	{
		printf("%d\n", ft_iterative_factorial(i));
	}
	return (0);
}
