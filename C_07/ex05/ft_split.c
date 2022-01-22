/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:18:36 by sgi               #+#    #+#             */
/*   Updated: 2022/01/20 21:36:42 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

bool	is_seperator(char c, char *charset)
{
	while (*charset != '\x00')
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	

char	**ft_split(char *str, char *charset)
{
	int		countCharset;
	char	**splited;
	int		splitedLen;
	int		i;
	int		j;
	int		charsetLen;

	charsetLen = ft_strlen(charset);
	countCharset = ft_count_strstr(str, charset);
	splited = (char **)malloc(sizeof(char *) * countCharset);
	if (splited == NULL)
		return (NULL);
	i = 0;
	while (i < countCharset + 1)
	{
		splitedLen = ft_len_strstr(str, charset);
		splited[i] = (char *)malloc(sizeof(char) * (splitedLen + 1));
		if (splited[i] == NULL)
			return (NULL);
		j = 0;	
		while (j < splitedLen)
		{
			splited[i][j] = str[j];
			j++;
		}
		splited[i][j] = '\x00';
		str += splitedLen + charsetLen;
		i++;
	}
	return (splited);
}
