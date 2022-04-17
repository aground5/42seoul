/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:20:56 by sgi               #+#    #+#             */
/*   Updated: 2022/04/17 14:43:09 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_int(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		len;
	int		isminus;

	isminus = 1;
	len = len_int(n);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	if (n < 0)
	{
		isminus = -1;
		ret[0] = '-';
	}
	else if (n == 0)
		ret[0] = '0';
	i = len - 1;
	while (n != 0)
	{
		ret[i--] = (n % 10) * isminus + '0';
		n /= 10;
	}
	ret[len] = '\x00';
	return (ret);
}
