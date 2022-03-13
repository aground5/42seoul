#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[dstsize] = '\x00';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst > dstsize || dstsize == 0)
		return (dstsize + len_src);
	i = len_dst;
	dst += len_dst;
	while (i < dstsize - 1 && *src != '\x00')
	{
		*dst = *src;
		i++;
		dst++;
		src++;
	}
	*dst = '\x00';
	return (len_dst + len_src);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	size_t	len;
	size_t	i;

	ret = 0;
	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == c)
			ret = &s[i];
	}
	return (ret);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		if (!(s1[i] && s2[i]))
			return (0);
		i++;
	}
	return (0);
}
