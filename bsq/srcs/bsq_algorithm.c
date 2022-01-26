/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:32:27 by sgi               #+#    #+#             */
/*   Updated: 2022/01/24 21:32:28 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "bsq.h"

void	fill_map(t_map *map, t_square square)
{
	int			i;
	int			j;

	i = square.row;
	j = square.col;
	while (i < (square.dia + square.row))
	{
		j = square.col;
		while (j < (square.dia + square.col))
		{
			map->field[i][j] = map->full;
			j++;
		}
		i++;
	}
}

int	is_empty_space(t_map *map, int dia, t_square *square)
{
	int	i;
	int	ret;

	ret = 1;
	i = square->col;
	while (i <= square->col + dia)
	{
		if (map->field[square->row + dia][i] == map->obstacle)
		{
			ret = 0;
			save_max_collide(square->row + dia, i, square, GARO);
		}
		i++;
	}
	i = square->row;
	while (i < square->row + dia)
	{
		if (map->field[i][square->col + dia] == map->obstacle)
		{
			ret = 0;
			save_max_collide(i, square->col + dia, square, SERO);
		}
		i++;
	}
	return (ret);
}

int	dia_increase(t_map *map, t_square *square)
{
	int			i;

	i = 0;
	while (square->row + i < map->line && square->col + i < map->len)
	{
		if (is_empty_space(map, i, square) == 0)
			break ;
		i++;
	}
	square->dia = i;
	return (i);
}

t_square	process_algorithm(t_map *map, char **index_field)
{
	int			i;
	int			j;
	t_square	square;
	t_square	max_square;

	max_square.dia = 0;
	i = -1;
	while (++i < map->line - max_square.dia)
	{
		j = -1;
		while (++j < map->len - max_square.dia)
		{
			if (index_field[i][j] == 'x')
				continue ;
			init_square(&square, i, j);
			dia_increase(map, &square);
			if (square.dia > max_square.dia)
				max_square = square;
			index_passing_zone(square, index_field);
		}
	}
	return (max_square);
}

int	start_algorithm(t_map *map)
{
	t_square	max_square;
	char		**index_field;

	index_field = malloc_index_field(map);
	if (index_field == NULL)
		return (MALOFL);
	init_index_field(index_field, map);
	max_square = process_algorithm(map, index_field);
	free(index_field[0]);
	free(index_field);
	fill_map(map, max_square);
	return (NORMEX);
}
