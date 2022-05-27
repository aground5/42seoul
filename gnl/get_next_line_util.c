#include "get_next_line.h"

char	*get_one_buffer(int fd)
{
	char	*ret;

	ret = (char *)malloc(BUFFER_SIZE + 1);
	if (ret == NULL)
		return (NULL);
	if (read(fd, ret, BUFFER_SIZE) == -1)
	{
		free(ret);
		return (NULL);
	}
	ret[BUFFER_SIZE] = '\x00';
	return (ret);
}

int	concate_buffer(char *line, char *buf, int *lenLine)
{
	int i;

	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n')
		{
			line = 
		}
		else if (buf[i] == EOF)
		{
			
		}
	}
}

char	*ft_realloc(char *s, int len, int need)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(len + need + 1);
	if (len == 0)
		return (ret);
	while (i < len)
	{
		ret[i] = s[i];
		i++;
	}
	free(s);
	return (ret);
}

int	parse_status(char *buf)
{
	int	i;

	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n')
			return (1);
		else if (buf[i] == EOF)
			return (2);
	}
	return (0);
}