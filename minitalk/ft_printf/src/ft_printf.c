/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:40:58 by sgi               #+#    #+#             */
/*   Updated: 2022/07/15 17:59:39 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	vlst;

	va_start(vlst, s);
	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (s[i] != '%')
			count += ft_ptf_putchar(s[i]);
		else
		{
			count += ft_ptf_judge((char *)s + i + 1, &vlst);
			i++;
		}
		i++;
	}
	return (count);
}

int	ft_ptf_judge(char *s, va_list *vlst)
{
	int	count;

	count = 0;
	if (*s == 'c')
		count += ft_ptf_putchar(va_arg(*vlst, int));
	else if (*s == 's')
		count += ft_ptf_putstr(va_arg(*vlst, char *));
	else if (*s == 'p')
	{
		count += ft_ptf_putstr("0x");
		ft_ptf_putpnt(va_arg(*vlst, uint64_t), &count);
	}
	else if (*s == 'd')
		ft_ptf_putnbr(va_arg(*vlst, int32_t), &count);
	else if (*s == 'i')
		ft_ptf_putnbr(va_arg(*vlst, int32_t), &count);
	else if (*s == 'u')
		ft_ptf_putnbr_ub("0123456789", va_arg(*vlst, uint32_t), &count);
	else if (*s == 'x')
		ft_ptf_putnbr_ub("0123456789abcdef", va_arg(*vlst, uint32_t), &count);
	else if (*s == 'X')
		ft_ptf_putnbr_ub("0123456789ABCDEF", va_arg(*vlst, uint32_t), &count);
	else if (*s == '%')
		count += ft_ptf_putchar('%');
	return (count);
}
