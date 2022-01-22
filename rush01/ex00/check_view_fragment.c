/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_view_fragment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:15:34 by sgi               #+#    #+#             */
/*   Updated: 2022/01/16 20:15:36 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_view_fragment.h"
#include "ft_util.h"

int	check_views(int **board, int len, int row, int col)
{
	if (row < len && col < len)
		return (check_left(board, row, col)
			&& check_up(board, row, col));
	if (row < len && col == len)
		return (check_row(board, len, row)
			&& check_up(board, row, col));
	if (row == len && col < len)
		return (check_left(board, row, col)
			&& check_col(board, len, col));
	if (row == len && col == len)
		return (check_row(board, len, row)
			&& check_col(board, len, col));
	return (0);
}

int	check_row(int **board, int len, int row)
{
	int	col;
	int	l_max;
	int	r_max;
	int	left;
	int	right;

	ft_set_zero(&l_max, &r_max);
	ft_set_zero(&left, &right);
	col = 1;
	while (col <= len)
	{
		if (board[row][col] > l_max)
		{
			l_max = board[row][col];
			left++;
		}
		if (board[row][len + 1 - col] > r_max)
		{
			r_max = board[row][len + 1 - col];
			right++;
		}
		col++;
	}
	return (left == board[row][0] && right == board[row][len + 1]);
}

int	check_col(int **board, int len, int col)
{
	int	row;
	int	u_max;
	int	d_max;
	int	up;
	int	down;

	ft_set_zero(&u_max, &d_max);
	ft_set_zero(&up, &down);
	row = 1;
	while (row <= len)
	{
		if (board[row][col] > u_max)
		{
			u_max = board[row][col];
			up++;
		}
		if (board[len + 1 - row][col] > d_max)
		{
			d_max = board[len + 1 - row][col];
			down++;
		}
		row++;
	}
	return (up == board[0][col] && down == board[len + 1][col]);
}

int	check_left(int **board, int row, int now_col)
{
	int	col;
	int	max;
	int	left;

	col = 1;
	left = 0;
	max = 0;
	while (col <= now_col)
	{
		if (board[row][col] > max)
		{
			max = board[row][col];
			left++;
		}
		if (left > board[row][0])
			return (0);
		col++;
	}
	return (1);
}

int	check_up(int **board, int now_row, int col)
{
	int	row;
	int	max;
	int	up;

	row = 1;
	max = 0;
	up = 0;
	while (row <= now_row)
	{
		if (board[row][col] > max)
		{
			max = board[row][col];
			up++;
		}
		if (up > board[0][col])
			return (0);
		row++;
	}
	return (1);
}
