#include <stdio.h>
#include "ft_strjoin.c"
#include "ft_print_memory.c"

int main(int argc, char **argv)
{
	char *s = ft_strjoin(argc - 2, &argv[1], argv[argc - 1]);
	printf("%s\n", s);
	ft_print_memory(s - 0x10, 1000);
	free(s);
	ft_print_memory(s - 0x10, 1000);
}
