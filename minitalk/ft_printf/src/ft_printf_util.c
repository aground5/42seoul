/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:45:35 by sgi               #+#    #+#             */
/*   Updated: 2022/07/15 17:59:40 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	ft_ptf_putnbr_ub(char *base, uint32_t nb, int *count)
{
	uint32_t	base_num;

	base_num = ft_ptf_strlen(base);
	if (nb >= base_num)
	{
		ft_ptf_putnbr_ub(base, nb / base_num, count);
		nb = nb % base_num;
	}
	if (nb < base_num)
		*count += ft_ptf_putchar(base[nb]);
}

void	ft_ptf_putnbr(int32_t nb, int *count)
{
	if (nb < 0 && *count == 0)
		*count += ft_ptf_putchar('-');
	if (nb <= -10 || nb >= 10)
	{
		ft_ptf_putnbr(nb / 10, count);
		nb = nb % 10;
	}
	if (nb > -10 && nb < 10)
	{
		if (nb < 0)
			nb = -nb;
		*count += ft_ptf_putchar(nb + 48);
	}
}

void	ft_ptf_putpnt(uint64_t nb, int *count)
{
	if (nb >= 16)
	{
		ft_ptf_putpnt(nb / 16, count);
		nb = nb % 16;
	}
	if (nb < 16)
		*count += ft_ptf_putchar("0123456789abcdef"[nb]);
}
