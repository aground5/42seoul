#include "get_next_line.h"

char	*ft_realloc(char *s, int len, char *concat, int need)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(len + need + 1);
	if (ret == NULL || len == 0)
		return (ret);
	i = 0;
	while (i < len)
	{
		ret[i] = s[i];
		i++;
	}
	while (i < len + need)
	{
		ret[i] = concat[i - len];
		i++;
	}
	free(s);
	ret[len + need + 1] = '\x00';
	return (ret);
}

int	index_newline(char *buf)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}