#include <stdio.h>
#include "ft_abs.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
	int	a = atoi(argv[1]);
	a = ABS(a);
	printf("%d\n", a);
}
