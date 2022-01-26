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

#include <stdio.h>
void	debug_all_list(t_list **list)
{
	t_list		*curList;

	curList = *list;
	while (curList != NULL)
	{
		printf("<--%p-->\n", curList->square);
		printf("row: %d\n", curList->square->row);
		printf("col: %d\n", curList->square->col);
		printf("dia: %d\n", curList->square->dia);
		printf("row_collide: %d\n", curList->square->row_collide);
		printf("col_collide: %d\n", curList->square->col_collide);
		curList = curList->next;
	}
}

void	fill_map(t_map *map, t_list **list)
{
	int			i;
	int			j;
	t_square	*square;

	//debug_all_list(list);	//
	square = find_max_square(list);
	i = square->row;
	j = square->col;
	while (i < (square->dia + square->row))
	{
		j = square->col;
		while (j < (square->dia + square->col))
		{
			map->field[i][j++] = map->full;
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
			save_max_collide(square->row + dia, i, square);
		}
		i++;
	}
	i = square->row;
	while (i < square->row + dia)
	{
		if (map->field[i][square->col + dia] == map->obstacle)
		{
			ret = 0;
			save_max_collide(i, square->col + dia, square);
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

int	is_passable(int	row, int col, t_list **list, t_map *map)
{
	t_list		*curList;

	curList = *list;
	while (curList != NULL)
	{
		if (row >= curList->square->row
			&& row <= curList->square->row_collide
			&& col >= curList->square->row
			&& col <= curList->square->col_collide)
			return (1);
		if (row + curList->square->dia - 1 > map->line
			|| col + curList->square->dia - 1 > map->len)
			return (1);
		curList = curList->next;
	}
	return (0);
}

int	algorithm_start(t_map *map)
{
	int			i;
	int			j;
	int			errno;
	t_list		**list;
	t_square	*square;

	list = (t_list **)malloc(sizeof(t_list *));
	if (list == NULL)
		return (MALOFL);
	*list = NULL;
	i = -1;
	while (++i < map->line)
	{
		j = -1;
		while (++j < map->len)
		{
			if (is_passable(i, j, list, map) == 1)
				continue ;		// TODO: edit
			square = make_square(i, j);
			if (square == NULL)
				free_list(list);
			dia_increase(map, square);
			errno = append_list(square, list);
			if (errno != NORMEX)
				return (errno);
		}
	}
	fill_map(map, list);
	free_list(list);
	return (NORMEX);
}
