#include <string.h>
#include <stdio.h>

int	main(void)
{
	char *s1 = "aaaaabbaa";
	char *s2 = "bbb";

	printf("%s\n", strnstr(s1, s2, 5));
	printf("%s\n", strnstr(s1, s2, 90000000));
	return (0);
}