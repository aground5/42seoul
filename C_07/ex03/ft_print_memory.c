/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:23:17 by sgi               #+#    #+#             */
/*   Updated: 2022/01/12 22:00:18 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char_to_hexstring(unsigned char x)
{
	char	hexstring[2];
	int		i;

	hexstring[1] = x % 0x10;
	hexstring[0] = x / 0x10;
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

void	put_addr(void *addr)
{
	char					hexaddr[16];
	unsigned long long int	int_addr;
	int						i;

	int_addr = (unsigned long long int)addr;
	i = 0;
	while (i < 16)
	{
		hexaddr[i] = int_addr % 0x10;
		int_addr /= 0x10;
		i++;
	}
	i = 15;
	while (i >= 0)
	{
		if (hexaddr[i] >= 0 && hexaddr[i] <= 9)
			hexaddr[i] += '0';
		else
			hexaddr[i] = hexaddr[i] - 10 + 'a';
		write(1, &hexaddr[i], 1);
		i--;
	}
	write(1, ": ", 2);
}

void	ft_putstr_printable(unsigned char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (*str >= 0x20 && *str <= 0x7e)
			write(1, str, 1);
		else
			write(1, ".", 1);
		str++;
		i++;
	}
	write(1, "\n", 1);
}

void	ft_handle_leftover(void *addr, unsigned int size)
{
	unsigned int	i;

	if (size % 2 == 1)
		write(1, "   ", 3);
	i = 0;
	while (i++ < (16 - (size % 16)) / 2)
		write(1, "     ", 5);
	ft_putstr_printable((unsigned char *)(addr - (size % 16)), size % 16);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void			*ret;
	unsigned int	i;

	ret = addr;
	i = 0;
	while (i < size)
	{
		if (i % 16 == 0)
			put_addr(addr);
		put_char_to_hexstring(*(unsigned char *)addr);
		if (i % 2 == 1)
			write(1, " ", 1);
		if (i % 16 == 15)
			ft_putstr_printable((unsigned char *)(addr - 15), 16);
		addr++;
		i++;
	}
	if (size % 16 != 0)
		ft_handle_leftover(addr, size);
	return (ret);
}
