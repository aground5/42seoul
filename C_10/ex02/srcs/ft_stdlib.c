/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:34:19 by sgi               #+#    #+#             */
/*   Updated: 2022/01/25 18:34:20 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_positive(char *str)
{
	int				result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *(str++) - '0';
	}
	if (*str == '\x00')
		return (result);
	return (-1);
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
