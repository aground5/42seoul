#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(s);
	ret = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	while (i < len)
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	return (ret);
}