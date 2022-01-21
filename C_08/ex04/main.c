#include <stdio.h>
#include "ft_strs_to_tab.c"

int main(int argc, char **argv)
{
	t_stock_str	*translated_str;
	translated_str = ft_strs_to_tab(argc, argv);

	for (int i = 0; i < argc; i++)
	{
		printf("len = %d\n", (translated_str + i) -> size);
		printf("str = %p, %s\n", (translated_str + i) -> str, (translated_str + i) -> str);
		printf("copy = %p, %s\n", (translated_str + i) -> copy, (translated_str + i) -> copy);
	}
}
