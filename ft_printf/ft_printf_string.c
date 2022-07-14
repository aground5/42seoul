/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:55:59 by sgi               #+#    #+#             */
/*   Updated: 2022/07/13 14:06:36 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_putchar(int c)
{
	write(1, &c, sizeof(char));
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		s = "(null)";
	i = 0;
	while (s[i] != 0)
		i += ft_putchar(s[i]);
	return (i);
}
