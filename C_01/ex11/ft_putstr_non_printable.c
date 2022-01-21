/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:21:01 by sgi               #+#    #+#             */
/*   Updated: 2022/01/11 15:17:44 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char_to_hexstring(char x)
{
	char	hexstring[2];
	int		i;

	hexstring[1] = x % 16;
	hexstring[0] = x / 16;
	i = 0;
	while (i < 2)
	{
		if (hexstring[i] >= 0 && hexstring [i] <= 9)
			hexstring[i] += '0';
		else
			hexstring [i] = hexstring[i] - 10 + 'a';
		i++;
	}
	write(1, hexstring, 2);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\x00')
	{
		if (*str >= 0x20)
		{
			write(1, str, 1);
		}
		else
		{
			write(1, "\\", 1);
			put_char_to_hexstring(*str);
		}
		str++;
	}
}
