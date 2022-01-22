/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:52:06 by sgi               #+#    #+#             */
/*   Updated: 2022/01/22 14:25:34 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

char	*mov_str_to_real_value(char *str, int *isMinus)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*isMinus ^= 1;
		str++;
	}
	return (str);
}

int	ft_atoi_base(char *str, char *base, int baseLen, unsigned char *baseHash)
{
	int				isMinus;
	unsigned int	uResult;
	int				result;

	isMinus = 0;
	uResult = 0;
	result = 0;
	str = mov_str_to_real_value(str, &isMinus);
	while (baseHash[(int)*str] != 0 || *str == *base)
	{
		uResult *= baseLen;
		uResult += (unsigned int)baseHash[(int)*str];
		str++;
	}
	if (isMinus == 1)
		result = uResult * -1;
	else
		result = (int)uResult;
	return (result);
}

int	convert_base(int n, unsigned char *converted, int baseLen, int minus)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		converted[len] = (n % baseLen) * minus;
		n /= baseLen;
		len++;
	}
	return (len);
}

char	*writenbr_base(char *base, unsigned char *converted, \
		int convLen, bool isMinus)
{
	int		i;
	char	*ret;

	if (isMinus)
		ret = (char *)malloc(sizeof(char) * (convLen + 2));
	else
		ret = (char *)malloc(sizeof(char) * (convLen + 1));
	if (ret == NULL)
		return (NULL);
	if (isMinus)
	{
		*ret = '-';
		ret++;
	}
	i = 0;
	while (i < convLen)
	{
		ret[i] = base[converted[convLen - 1 - i]];
		i++;
	}
	ret[i] = '\x00';
	if (isMinus)
		ret--;
	return (ret);
}

char	*ft_getnbr_base(int nbr, char *base, int baseLen)
{
	unsigned char	converted[32];
	int				convLen;
	char			*ret;

	if (nbr == 0)
	{
		ret = (char *)malloc(sizeof(char) * 2);
		if (ret == NULL)
			return (NULL);
		ret[0] = *base;
		ret[1] = '\x00';
		return (ret);
	}
	if (nbr < 0)
	{
		convLen = convert_base(nbr, converted, baseLen, -1);
		ret = writenbr_base(base, converted, convLen, true);
	}
	else
	{
		convLen = convert_base(nbr, converted, baseLen, 1);
		ret = writenbr_base(base, converted, convLen, false);
	}
	return (ret);
}
