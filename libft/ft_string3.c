#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((const unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((const unsigned char *)s1)[i] != ((const unsigned char *)s2)[i])
			return (((const unsigned char *)s1)[i] -
					((const unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_needle;

	i = 0;
	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return (haystack);
	while (i < len)
	{
		if (haystack[i] == '\x00')
			break ;
		if (haystack[i] == needle[0])
		{
			j = 1;
			while (j < len_needle)
			{
				if (haystack[i + j] != needle[j])
					break ;
				j++;
			}
			if (j == len_needle)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int			len;
	char		*dest;
	char		*ret;

	len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	ret = dest;
	while (*s1)
	{
		*dest = *s1;
		s1++;
		dest++;
	}
	*dest = '\x00';
	return (ret);
}
