#include <string.h>
#include "ft_strdup.c"
#include "ft_print_memory.c"

int main(void)
{
	char *s1 = "must be duplicated";
	char *s2;
	char *s3;

	s2 = ft_strdup(s1);
	s3 = strdup(s1);

	ft_print_memory(s2, 50);
	ft_print_memory(s3, 50);
}
