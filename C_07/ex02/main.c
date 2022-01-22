#include <stdio.h>
#include "ft_ultimate_range.c"
#include "../ex00/ft_print_memory.c"

int main(void)
{
	int *range[1];

	ft_print_memory(*range, 40);
	printf("%d\n", ft_ultimate_range(range, 4, 10));
	ft_print_memory(*range, 40);
	printf("%d\n", ft_ultimate_range(range, 4, 3));
	printf("%p\n", *range);
	printf("%d\n", ft_ultimate_range(range, 4, 4));
	return (0);
}
