#include <stdio.h>
#include <string.h>
#include "ft_strlcat.c"
#include "ft_print_memory.c"

int main(void)
{
	char s1[50] = "I Have a Key.\x00 dfsdfsdfsfsdfsdfsdf";
	char *s2 = "haha!";
	char s3[50] = "I Have a Key.\x00 dfsdfsdfsfsdfsdfsdf";
	char *s4 = "haha!";

	ft_print_memory(s1, 20);

	for (int i = -6; i < 9; i++)
	{	
		printf("%u\n", ft_strlcat(s1, s2, strlen(s1) + i));
		printf("%lu\n", strlcat(s3, s4, strlen(s3) + i));
		
		ft_print_memory(s1, 50);
		ft_print_memory(s3, 50);
	}
}
