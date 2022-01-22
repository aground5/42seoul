#include "ft_split.c"
#include <stdio.h>

int main(int argc, char **argv)
{
	char	**s;
	int		len;
	int		i;

	s = ft_split(argv[1], argv[2]);
	len = atoi(argv[3]);

	i = 0;
	while (i < len)
	{
		printf("%s\n", s[i]);
		i++;
	}
}
