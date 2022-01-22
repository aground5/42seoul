/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:53:02 by sgi               #+#    #+#             */
/*   Updated: 2022/01/12 17:34:02 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_nbr(int nb, char *d)
{
	int	i;
	int	len;

	len = 0;
	while (nb != 0)
	{
		d[len] = nb % 10 + 0x30;
		nb /= 10;
		len++;
	}	
	i = len - 1;
	while (i >= 0)
	{
		write(1, &d[i], 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	char	d[10];

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			write(1, "-", 1);
		}
		else if (nb == 0)
		{
			write(1, "0", 1);
		}
		write_nbr(nb, d);
	}
}
