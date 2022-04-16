#include "libft.h"

int	len_int(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		n++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		len;

	len = len_int(n);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	if (n < 0)
		ret[0] = '-';
	else if (n == 0)
		ret[0] = '0';
	i = len - 1;
	while (n != 0 && i > 0)
	{
		ret[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	ret[len] = '\x00';
	return (ret);
}
