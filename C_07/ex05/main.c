#include "ft_split.c"
#include <stdio.h>

int main(int argc, char **argv)
{
	char	**s;
	int		i;

	s = ft_split(argv[1], argv[2]);
	i = 0;
	while (s[i] != 0)
	{
		printf("%s\n", s[i]);
		i++;
	}
}
