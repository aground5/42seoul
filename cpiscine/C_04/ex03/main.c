#include <stdlib.h>
#include <stdio.h>
#include "ft_atoi.c"

int main(int argc, char **argv)
{
	printf("ft : %d\n", ft_atoi(argv[1]));
	printf("std : %d\n", atoi(argv[1]));
}
