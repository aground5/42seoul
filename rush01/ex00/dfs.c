/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <yjs@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:41:08 by junsyun           #+#    #+#             */
/*   Updated: 2022/01/16 19:15:01 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "dfs.h"
#include "check_view_fragment.h"
#include "check_duplicate.h"

int	***g_visit;

int	dfs_start(int **board, int len)
{
	g_visit = dfs_init(len);
	g_visit_zero_fill(len);
	return (dfs_process(board, len, 1, 1));
	free(g_visit[0][0]);
	free(g_visit[0]);
	free(g_visit);
}

int	dfs_process(int **board, int len, int row, int col)
{
	int	val;

	val = 1;
	if (row == len + 1)
		return (1);
	while (val <= len)
	{
		if (g_visit[row - 1][col - 1][val - 1] == 0)
		{
			g_visit[row - 1][col - 1][val - 1] = 1;
			board[row][col] = val;
			if (check_views(board, len, row, col)
				&& check_duplicate(board, len, row, col))
			{
				if (col == len && dfs_process(board, len, row + 1, 1))
					return (1);
				else if (col != len && dfs_process(board, len, row, col + 1))
					return (1);
			}
		}
		val++;
	}
	board[row][col] = 0;
	dfs_fail(len, row, col);
	return (0);
}

int	***dfs_init(int len)
{
	int	***visit;
	int	i;
	int	j;

	visit = (int ***)malloc(sizeof(int **) * len);
	visit[0] = (int **)malloc(sizeof(int *) * len * len);
	visit[0][0] = (int *)malloc(sizeof(int) * len * len * len);
	i = 0;
	while (++i < len)
		visit[i] = visit[i - 1] + len;
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (i == 0 && j == 0)
				continue ;
			if (j == 0)
				visit[i][j] = visit[i - 1][len - 1] + len;
			else
				visit[i][j] = visit[i][j - 1] + len;
		}
	}
	return (visit);
}

void	dfs_fail(int len, int row, int col)
{
	int	i;

	i = 0;
	while (i < len)
	{
		g_visit[row - 1][col - 1][i] = 0;
		i++;
	}
}

void	g_visit_zero_fill(int len)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			k = 0;
			while (k < len)
			{
				g_visit[i][j][k] = 0;
				k++;
			}
			j++;
		}
		i++;
	}
}
