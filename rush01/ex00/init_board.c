/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:15:56 by sgi               #+#    #+#             */
/*   Updated: 2022/01/16 20:15:58 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "init_board.h"

int	**init_board(int len, char *raw_input)
{
	int	**board;
	int	i;

	board = (int **)malloc(sizeof(int *) * (len + 2));
	board[0] = (int *)malloc(sizeof(int) * (len + 2) * (len + 2));
	i = 1;
	while (i < len + 2)
	{
		board[i] = board[i - 1] + len + 2;
		i++;
	}
	zero_fill(board, len);
	process_input(board, len, raw_input);
	return (board);
}

void	process_input(int **board, int len, char *raw_input)
{
	int	i;

	i = 0;
	while (i < len * 4)
	{
		if (i < len)
			board[0][i + 1] = raw_input[i * 2] - '0';
		else if (i < len * 2)
			board[len + 1][i + 1 - len] = raw_input[i * 2] - '0';
		else if (i < len * 3)
			board[i + 1 - (len * 2)][0] = raw_input[i * 2] - '0';
		else
			board[i + 1 - (len * 3)][len + 1] = raw_input[i * 2] - '0';
		i++;
	}
}

void	zero_fill(int **board, int len)
{
	int	i;
	int	j;

	i = 1;
	while (i <= len)
	{
		j = 1;
		while (j <= len)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	free_board(int **board)
{
	free(board[0]);
	free(board);
}
