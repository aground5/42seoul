#include "libft.h"

size_t	ft_strlen_cterminator(const char *s, const char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

size_t	count_words(const char *str, const char c)
{
	size_t	words;

	words = 0;
	if (*str != c && *str != '\x00')
		words++;
	while (*str != '\x00')
	{
		if (*(str + 1) != '\x00'
			&& *str == c
			&& *(str + 1) != c)
			words++;
		str++;
	}
	return (words);
}

char	*ft_strndup(const char *src, size_t len)
{
	size_t	i;
	char	*dest;
	char	*ret;

	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	ret = dest;
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\x00';
	return (ret);
}

void	on_error(char **split, size_t toBeFree)
{
	size_t	i;

	i = 0;
	while (i < toBeFree)
		free(split[i]);
	free(split);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**split;
	size_t	length;
	size_t	i;

	words = count_words(s, c);
	split = (char **)malloc((words + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	split[words] = NULL;
	i = -1;
	while (++i < words)
	{
		length = ft_strlen_cterminator(s, c);
		while (length == 0)
			length = ft_strlen_cterminator(++s, c);
		split[i] = ft_strndup(s, length);
		if (split[i] == NULL)
		{
			on_error(split, i - 1);
			return (NULL);
		}
		s += length + 1;
	}
	return (split);
}
