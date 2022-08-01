/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:55:59 by sgi               #+#    #+#             */
/*   Updated: 2022/07/15 18:28:48 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_ptf_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_ptf_putchar(int c)
{
	write(1, &c, sizeof(char));
	return (1);
}

int	ft_ptf_putstr(char *s)
{
	int	i;

	if (s == NULL)
		s = "(null)";
	i = 0;
	while (s[i] != 0)
		i += ft_ptf_putchar(s[i]);
	return (i);
}
