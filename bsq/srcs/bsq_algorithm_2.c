/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_algorithm_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 00:57:59 by sgi               #+#    #+#             */
/*   Updated: 2022/01/26 00:58:00 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "bsq.h"

void	save_max_collide(int row, int col, t_square *square)
{
	if (square->row_collide < row)
		square->row_collide = row;
	if (square->col_collide < col)
		square->col_collide = col;
}

void	index_passing_zone(t_square square, char **index_field)
{
	int			i;
	int			j;

	i = square.row;
	j = square.col;
	while (i < square.row_collide)
	{
		j = square.col;
		while (j < square.col_collide)
		{
			index_field[i][j++] = 'x';
		}
		i++;
	}
}

char	**malloc_index_field(t_map *map)
{
	int		i;
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * map->line);
	if (ret == NULL)
		return (NULL);
	ret[0] = (char *)malloc(sizeof(char) * (map->line) * (map -> len));
	if (ret[0] == NULL)
	{
		free(ret);
		return (NULL);
	}
	i = 1;
	while (i < map->line)
	{
		ret[i] = ret[i - 1] + map->len;
		i++;
	}
	return (ret);
}

void	init_square(t_square *square, int row, int col)
{
	square->row = row;
	square->col = col;
	square->dia = 0;
	square->row_collide = 0;
	square->col_collide = 0;
}

void	init_index_field(char **index_field, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (j < map->len)
		{
			index_field[i][j] = 'o';
			j++;
		}
		i++;
	}
}
