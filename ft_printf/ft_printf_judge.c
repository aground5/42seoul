/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_judge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:11:46 by sgi               #+#    #+#             */
/*   Updated: 2022/07/08 15:20:54 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_judge(char *s, va_list vlst)
{
    int count;

    if (*s == 'c')
        count = ft_putchar(va_args(vlst, char));
    else if (*s == 's')
        count = ft_putstr(va_args(vlst, char *))
    else if (*s == 'p')
    {
        
    }
    else if (*s == 'd')
    {
        
    }
    else if (*s == 'i')
    {
        
    }
    else if (*s == 'u')
    {
        
    }
    else if (*s == 'x')
    {
        
    }
    else if (*s == 'X')
    {
        
    }
    else if (*s == '%')
    {
        f
    }
}