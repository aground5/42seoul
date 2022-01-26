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

void	save_max_collide(int row, int col, t_square *square, int direction)
{
	if (direction == GARO)
	{
		if (square->obstacles.garo_obstacle_row < row)
			square->obstacles.garo_obstacle_row = row;
		if (square->obstacles.garo_obstacle_col < col)
			square->obstacles.garo_obstacle_col = col;
	}
	else
	{
		if (square->obstacles.sero_obstacle_row < row)
			square->obstacles.sero_obstacle_row = row;
		if (square->obstacles.sero_obstacle_col < col)
			square->obstacles.sero_obstacle_col = col;
	}
}

void	index_passing_zone(t_square square, char **index_field)
{
	int	i;
	int	j;

	i = square.row;
	j = square.col;
	while (i <= square.obstacles.garo_obstacle_row)
	{
		j = square.col;
		while (j <= square.obstacles.garo_obstacle_col)
			index_field[i][j++] = 'x';
		i++;
	}
	i = square.row;
	j = square.col;
	while (i <= square.obstacles.sero_obstacle_row)
	{
		j = square.col;
		while (j <= square.obstacles.sero_obstacle_col)
			index_field[i][j++] = 'x';
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
	ret[0] = (char *)malloc(sizeof(char) * (map->line) * (map->len));
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
	square->obstacles.garo_obstacle_col = 0;
	square->obstacles.garo_obstacle_row = 0;
	square->obstacles.sero_obstacle_col = 0;
	square->obstacles.sero_obstacle_row = 0;
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
