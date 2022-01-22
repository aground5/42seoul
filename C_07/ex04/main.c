#include <stdio.h>
#include "ft_convert_base.c"
#include "ft_convert_base2.c"

int main(int argc, char **argv)
{
	char *result;

	result = ft_convert_base(argv[1], argv[2], argv[3]);
	if (result == NULL)
		return 0;
	printf("%s\n", result);
}
