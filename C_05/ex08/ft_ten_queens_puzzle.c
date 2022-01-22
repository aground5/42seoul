/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:51:05 by sgi               #+#    #+#             */
/*   Updated: 2022/01/19 17:58:28 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_reachable(int row, int col, int board[10][10])
{
	int	index;

	index = -1;
	while (++index < 10)
	{
		if (index != col && board[row][index] == 1)
			return (1);
	}
	index = -1;
	while (++index < 10)
	{
		if (col - row + index >= 0 && col - row + index < 10
			&& index != row && board[index][col - row + index] == 1)
			return (1);
	}
	index = -1;
	while (++index < 10)
	{
		if (col + row - index >= 0 && col + row - index < 10
			&& index != row && board[index][col + row - index] == 1)
			return (1);
	}
	return (0);
}

void	ft_write_debug(int debug[10])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = debug[i];
		c += '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	solve_puzzle(int col, int board[10][10], int debug[10], int ans)
{
	int	row;

	if (col == 10)
	{
		ans++;
		ft_write_debug(debug);
		return (ans);
	}
	row = 0;
	while (row < 10)
	{
		board[row][col] = 1;
		if (is_reachable(row, col, board) == 0)
		{
			debug[col] = row;
			ans = solve_puzzle(col + 1, board, debug, ans);
		}
		debug[col] = 0;
		board[row][col] = 0;
		row++;
	}
	return (ans);
}

void	init_array(int board[10][10], int debug[10])
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 10)
	{
		debug[i] = 0;
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10][10];
	int	debug[10];
	int	ans;

	init_array(board, debug);
	ans = solve_puzzle(0, board, debug, 0);
	return (ans);
}
