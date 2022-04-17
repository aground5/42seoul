/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:03:28 by sgi               #+#    #+#             */
/*   Updated: 2022/01/12 13:54:54 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	string_init(char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		*str = 0;
		str++;
		i++;
	}
}

int	validate_base(char *base)
{
	int		len;
	char	hash[0x80];

	len = 0;
	string_init(hash, 0x80);
	while (*base != '\x00')
	{
		if (*base == '-' || *base == '+')
			return (0);
		if (*base < 0)
			return (-1);
		else if (hash[(int)*base] == 0)
			hash[(int)*base] = 1;
		else if (hash[(int)*base] == 1)
			return (0);
		len++;
		base++;
	}
	return (len);
}

int	convert_base(int n, char *converted, int baseLen)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		converted[len] = n % baseLen;
		n /= baseLen;
		len++;
	}
	return (len);
}

void	writenbr_base(char *base, char *converted, int convLen, char minus)
{
	int	i;

	i = convLen - 1;
	while (i >= 0)
	{
		write(1, &base[converted[i] * minus], 1);
		i--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		baseLen;
	char	converted[32];
	int		convLen;

	baseLen = validate_base(base);
	if (baseLen <= 1)
		return ;
	if (nbr == 0)
	{
		write(1, base, 1);
		return ;
	}
	convLen = convert_base(nbr, converted, baseLen);
	if (nbr < 0)
	{
		write(1, "-", 1);
		writenbr_base(base, converted, convLen, -1);
	}
	else
		writenbr_base(base, converted, convLen, 1);
}
