/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:24:00 by sgi               #+#    #+#             */
/*   Updated: 2022/01/22 14:15:40 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

void	ft_strjoin_2(int size, char **strs, char *sep, char *joined)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			*joined = strs[i][j];
			j++;
			joined++;
		}
		if (i != size - 1)
		{
			j = 0;
			while (sep[j])
				*(joined++) = sep[j++];
		}
		i++;
	}
	*joined = '\x00';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int		joinedLen;
	int		i;

	if (size < 0)
		return (NULL);
	if (size == 0)
	{
		joined = (char *)malloc(sizeof(char));
		if (joined == NULL)
			return (NULL);
		joined[0] = '\x00';
		return (joined);
	}
	joinedLen = ft_strlen(sep) * (size - 1);
	i = 0;
	while (i < size)
		joinedLen += ft_strlen(strs[i++]);
	joined = (char *)malloc(sizeof(char) * (joinedLen + 1));
	if (joined == NULL)
		return (0);
	ft_strjoin_2(size, strs, sep, joined);
	return (joined);
}
