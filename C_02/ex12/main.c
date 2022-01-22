#include <stdio.h>
#include <stdlib.h>
void *ft_print_memory(void *addr, unsigned int size);

int main(int argc, char **argv)
{
        char *s1 = "sdfsdfsdfqwefsadf";
        char *s2 = "AAAAAAAAAAAAAA";
        char *s3 = "02834098)(*@#)$(*)@";
        char *s4 = "\xaa\x1e\xe7\xb3\xfc\x7f\xe1";
		void *addr = (void *)s4;

        ft_print_memory(addr, atoi(argv[1]));
}
