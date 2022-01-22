#include "ft_strncat.c"
#include <stdio.h>
int main(void)
{
	char s1[100] = {'s', 'd', 'a', 'b', '5', 0};
	char *s2 = "!djfjjlj2oi398089!";

	printf("%s\n", ft_strncat(s1, s2, 50));
}
