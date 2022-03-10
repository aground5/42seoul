#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 0x7f)
		return (1);
	return (0);
}

int	ft_isprint(int c)
{
	if (c >= 0x20 && c <= 0x7e)
		return (1);
	return (0);
}

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 'a' + 'A');
	return (c);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c - 'A' + 'a');
	return (c);
}
