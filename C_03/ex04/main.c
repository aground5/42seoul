#include <stdio.h>
#include "ft_strstr.c"

int main(void)
{
	char *s1 = "fzz far fao boo";
	char *s2 = "fao";

	printf("%x\n", (unsigned int) ft_strstr(s1, s2));
	printf("%s\n", ft_strstr(s1, s2));
}
