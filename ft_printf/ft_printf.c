/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:40:58 by sgi               #+#    #+#             */
/*   Updated: 2022/07/13 14:21:12 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			count += ft_putchar(s[i]);
		else
		{
			count += ft_printf_judge((char *)s + i + 1, vlst);
			i++;
		}
		i++;
	}
	return (count);
}

int	ft_printf_judge(char *s, va_list vlst)
{
	int	count;

	count = 0;
	if (*s == 'c')
		count += ft_putchar(va_arg(vlst, int));
	else if (*s == 's')
		count += ft_putstr(va_arg(vlst, char *));
	else if (*s == 'p')
	{
		count += ft_putstr("0x");
		ft_putpnt(va_arg(vlst, uint64_t), &count);
	}
	else if (*s == 'd')
		ft_putnbr(va_arg(vlst, int32_t), &count);
	else if (*s == 'i')
		ft_putnbr(va_arg(vlst, int32_t), &count);
	else if (*s == 'u')
		ft_putnbr_base_u("0123456789", va_arg(vlst, uint32_t), &count);
	else if (*s == 'x')
		ft_putnbr_base_u("0123456789abcdef", va_arg(vlst, uint32_t), &count);
	else if (*s == 'X')
		ft_putnbr_base_u("0123456789ABCDEF", va_arg(vlst, uint32_t), &count);
	else if (*s == '%')
		count += ft_putchar('%');
	return (count);
}
