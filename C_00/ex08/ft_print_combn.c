/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:44:03 by sgi               #+#    #+#             */
/*   Updated: 2022/01/12 17:35:02 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init(int n, char *d)
{
	int	i;

	i = 0;
	while (i < n)
	{
		d[i] = i + 0x30;
		i++;
	}
}

void	up_digit(int n, char *d)
{
	int	i;

	d[n - 1]++;
	i = n - 1;
	while (i > 0)
	{
		if (d[i] == '9' + 1 - (n - 1 - i))
		{
			d[i - 1]++;
		}
		else
		{
			break ;
		}
		i--;
	}
	i++;
	while (i < n)
	{
		d[i] = d[i - 1] + 1;
		i++;
	}
}

void	write_combn(int n, char *d)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &d[i], 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	d[9];

	if (n == 1)
	{
		write(1, "0, 1, 2, 3, 4, 5, 6, 7, 8, 9", 28);
		return ;
	}
	init(n, d);
	while (d[0] != 10 - n + 0x30)
	{
		write_combn(n, d);
		write(1, ", ", 2);
		up_digit(n, d);
	}
	write_combn(n, d);
}
