/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:45:35 by sgi               #+#    #+#             */
/*   Updated: 2022/07/13 14:16:58 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_u(char *base, uint32_t nb, int *count)
{
	uint32_t	base_num;

	base_num = ft_strlen(base);
	if (nb >= base_num)
	{
		ft_putnbr_base_u(base, nb / base_num, count);
		nb = nb % base_num;
	}
	if (nb < base_num)
		*count += ft_putchar(base[nb]);
}

void	ft_putnbr(int32_t nb, int *count)
{
	if (nb < 0 && *count == 0)
		*count += ft_putchar('-');
	if (nb <= -10 || nb >= 10)
	{
		ft_putnbr(nb / 10, count);
		nb = nb % 10;
	}
	if (nb > -10 && nb < 10)
	{
		if (nb < 0)
			nb = -nb;
		*count += ft_putchar(nb + 48);
	}
}

void	ft_putpnt(uint64_t nb, int *count)
{
	if (nb >= 16)
	{
		ft_putpnt(nb / 16, count);
		nb = nb % 16;
	}
	if (nb < 16)
		*count += ft_putchar("0123456789abcdef"[nb]);
}
