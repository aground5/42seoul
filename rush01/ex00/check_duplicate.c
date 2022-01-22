/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:15:14 by sgi               #+#    #+#             */
/*   Updated: 2022/01/16 20:15:17 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "check_duplicate.h"

int	check_duplicate(int **board, int len, int row, int col)
{
	if (check_duplicate_row(board, len, row)
		&& check_duplicate_col(board, len, col))
	{
		return (1);
	}
	return (0);
}

int	check_duplicate_row(int **board, int len, int row)
{
	int	col;
	int	list[9];

	init_check_duplicate_list(list);
	col = 1;
	while (col <= len)
	{
		if (board[row][col] == 0)
			break ;
		if (list[board[row][col] - 1] == 0)
			list[board[row][col] - 1] = 1;
		else
			return (0);
		col++;
	}
	return (1);
}

int	check_duplicate_col(int **board, int len, int col)
{
	int	row;
	int	list[9];

	init_check_duplicate_list(list);
	row = 1;
	while (row <= len)
	{
		if (board[row][col] == 0)
			break ;
		if (list[board[row][col] - 1] == 0)
			list[board[row][col] - 1] = 1;
		else
			return (0);
		row++;
	}
	return (1);
}

void	init_check_duplicate_list(int *list)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		list[i] = 0;
		i++;
	}
}
