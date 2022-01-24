#include <unistd.h>

#include "bsq.h"

void	fill_map(t_map *map, t_square square)
{
	int	i;
	int	j;

	i = square.row;
	j = square.col;
	while (i < (square.dia + square.row))
	{
		j = square.col;
		while (j < (square.dia + square.col))
		{
			map->field[i][j++] = map->full;
		}
		i++;
	}
}

int	is_possible(t_map *map, int row, int col, int dia)
{
	int	i;

	i = col;
	while (i <= col + dia)
	{
		if (map->field[row + dia][i] == map->obstacle)
			return (0);
		i++;
	}
	i = row;
	while (i < row + dia)
	{
		if (map->field[i][col + dia] == map->obstacle)
			return (0);
		i++;
	}
	return (1);
}

int	dia_increase(t_map *map, int row, int col)
{
	int			i;

	i = 0;
	while (row + i < map->line && col + i < map->len)
	{
		if (is_possible(map, row, col, i) == 0)
			break ;
		i++;
	}
	return (i);
}

t_square	algorithm_start(t_map *map)
{
	int			i;
	int			j;
	int			tmp;
	t_square	max_square;

	max_square.dia = 0;
	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (j < map->len)
		{
			tmp = dia_increase(map, i, j);
			if (max_square.dia < tmp)
			{
				max_square.row = i;
				max_square.col = j;
				max_square.dia = tmp;
			}
			j++;
		}
		i++;
	}
	fill_map(map, max_square);
	return (max_square);
}
