/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:40:58 by sgi               #+#    #+#             */
/*   Updated: 2022/07/08 15:16:36 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    int     i;
    int     count;
    va_list vlst;

	va_start(vlst, s);
    i = 0;
    count = 0;
    while (s[i] != 0)
    {
        if (s[i] != '%')
            count += ft_putchar(s[i]);
        else
        {
            
        }
    }
}
