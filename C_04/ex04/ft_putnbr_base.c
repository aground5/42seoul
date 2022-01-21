/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:03:28 by sgi               #+#    #+#             */
/*   Updated: 2022/01/12 10:39:07 by sgi              ###   ########.fr       */
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
		{
			write(1, "base has negative!!", 19);
			return (-1);
		}
		else if (hash[*base] == 0)
			hash[*base] = 1;
		else if (hash[*base] == 1)
			return (0);
		len++;
		base++;
	}
	if (len <= 1)
	{
		return (0);
	}
	return (1);
}
#include <stdio.h>
void	ft_putnbr_base(int nbr, char *base)
{
	printf("%d\n", validate_base(base));	
}
