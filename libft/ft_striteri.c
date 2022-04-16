#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		len;
	int		i;

	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, s + i);
		i++;
	}
}