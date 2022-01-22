/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suschoi <suschoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:11:50 by suschoi           #+#    #+#             */
/*   Updated: 2022/01/08 13:53:54 by suschoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	select_char(int x, int y, int i, int j)
{
	if (i == 1 && j == 1 || i == 1 && j == y)
	{
		ft_putchar('A');
	}
	else if (i == x && j == 1 || i == x && j == y)
	{
		ft_putchar('C');
	}
	else if (i == x && 1 < j && j < y || i == 1 && 1 < j && j < y
		|| 1 < i && i < x && j == 1 || 1 < i && i < x && j == y)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i <= x && j <= y)
	{
		select_char(x, y, i, j);
		if (i == x)
		{
			i = 1;
			j++;
			ft_putchar('\n');
		}
		else
		{
			i++;
		}
	}
}
