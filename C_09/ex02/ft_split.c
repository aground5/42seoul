/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:53:03 by sgi               #+#    #+#             */
/*   Updated: 2022/01/22 19:39:42 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

bool	is_char_separator(char c, char *charset)
{
	while (*charset != '\x00')
	{
		if (c == *charset)
			return (true);
		charset++;
	}
	return (false);
}

int	count_words(char *str, char *charset)
{
	int	words;

	words = 0;
	if (!(is_char_separator(*str, charset)))
		words++;
	while (*str != '\x00')
	{
		if (*(str + 1) != '\x00'
			&& is_char_separator(*str, charset)
			&& !(is_char_separator(*(str + 1), charset)))
			words++;
		str++;
	}
	return (words);
}

int	ft_strlen_cterminator(char *s, char *charset)
{
	int	len;

	len = 0;
	while (*s && !(is_char_separator(*s, charset)))
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_strndup(char *src, int len)
{
	int		i;
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

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		words;
	char	**ret;
	int		wordLen;

	words = count_words(str, charset);
	ret = (char **)malloc(sizeof(char *) * (words + 1));
	if (ret == NULL)
		return (NULL);
	ret[words] = 0;
	i = 0;
	while (i < words)
	{
		wordLen = ft_strlen_cterminator(str, charset);
		while (wordLen == 0)
			wordLen = ft_strlen_cterminator(++str, charset);
		ret[i] = ft_strndup(str, wordLen);
		if (ret[i] == NULL)
			return (NULL);
		str += wordLen + 1;
		i++;
	}
	return (ret);
}
