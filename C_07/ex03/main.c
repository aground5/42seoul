#include <stdio.h>
#include "ft_strjoin.c"

int main(int argc, char **argv)
{
	printf("%s\n", ft_strjoin(argc - 2, &argv[1], argv[argc - 1]));
}
