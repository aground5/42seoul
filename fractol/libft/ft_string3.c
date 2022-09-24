/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:21:08 by sgi               #+#    #+#             */
/*   Updated: 2022/04/17 14:17:05 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static char	*ft_strnstr2(const char *haystack, const char *needle, \
						size_t len_needle, size_t len)
{
	size_t	j;

	j = 1;
	while (j < len_needle)
	{
		if (j >= len)
			break ;
		if (haystack[j] == '\x00')
			break ;
		if (haystack[j] != needle[j])
			break ;
		j++;
	}
	if (j == len_needle)
		return ((char *)(haystack));
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_needle;
	char	*ret;

	i = 0;
	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return ((char *)haystack);
	while (i < len)
	{
		if (haystack[i] == '\x00')
			break ;
		if (haystack[i] == needle[0])
		{
			ret = ft_strnstr2(haystack + i, needle, \
								len_needle, len - i);
			if (ret != 0)
				return (ret);
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
