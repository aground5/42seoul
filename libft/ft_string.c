#include "libft.h"

int	ft_strlen(char *s)
{
	int	ret;

	ret = 0;
	while (*s)
		ret++;
	return (ret);
}

void	*memset(void *s, int c, size_t n)
{
	void	*ret;
	int		i;

	ret = s;
	i = 0;
	while (i < n)
	{
		((char *)s)[i] = (char)c;
		i++;
	}
}

void	bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\x00';
		i++;
	}
}

void	*memcpy(void *dest, const void *src, size_t n)
{
	
}