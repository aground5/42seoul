/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:31:48 by sgi               #+#    #+#             */
/*   Updated: 2022/01/18 16:12:36 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	string_init(char *str, unsigned int size, char initChar)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		*str = initChar;
		str++;
		i++;
	}
}

int	validate_base(char *base, char *hash)
{
	int		len;

	len = 0;
	while (*base != '\x00')
	{
		if (*base == '-' || *base == '+'
			|| (*base >= 9 && *base <= 13) || *base == 32)
			return (0);
		if (*base < 0)
			return (-1);
		else if (hash[(int)*base] == -1)
			hash[(int)*base] = len;
		else if (hash[(int)*base] != -1)
			return (0);
		len++;
		base++;
	}
	return (len);
}

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

int	ft_atoi_base(char *str, char *base)
{
	int				baseLen;
	int				isMinus;
	char			baseHash[0x80];
	unsigned int	uResult;
	int				result;

	isMinus = 0;
	string_init(baseHash, 0x80, (char) -1);
	uResult = 0;
	result = 0;
	str = mov_str_to_real_value(str, &isMinus);
	baseLen = validate_base(base, baseHash);
	if (baseLen <= 1)
		return (0);
	while (baseHash[(int)*str] != -1)
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
