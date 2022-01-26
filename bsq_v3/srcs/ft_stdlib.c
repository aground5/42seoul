/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:32:32 by sgi               #+#    #+#             */
/*   Updated: 2022/01/24 21:32:34 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_natoi_positive(char *str, int n)
{
	int				i;
	int				result;

	i = 0;
	result = 0;
	while (i < n)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += str[i] - '0';
		}
		else
			return (-1);
		i++;
	}
	return (result);
}

char	*ft_string_realloc(char *src, int size, int n)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * size);
	if (dest == NULL)
	{
		free(src);
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	free(src);
	return (dest);
}
