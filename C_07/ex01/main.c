#include <stdio.h>
#include "ft_range.c"
#include "../ex00/ft_print_memory.c"

int main(void)
{
	int	i;
	int *tab;

	tab = ft_range(5, 5);
	
	printf("%p",tab);
	printf("\n");
	ft_print_memory(tab, 50);
}
