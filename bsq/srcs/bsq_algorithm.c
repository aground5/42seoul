#include <unistd.h>

#include "bsq.h"

int	is_possible(t_map *map, int row, int col, int dia)
{
	int	i;

	i = col;
	while (i < col + dia)
	{
		if (map->field[row + dia][i] == map->obstacle)
			return (0);
	}
	i = row;
	while (i < row + dia)
	{
		if (map->field[i][col + dia] == map->obstacle)
			return (0);
	}
	return (1);
}

int	dia_increase(t_map *map, int row, int col)
{
	int	i;

	i = 0;
	while (row + i < map->line && col + i < map->len)
	{
		if (is_possible(map, row, col, i) == 0)
			break ;
		i++;
	}
	return (i);
}

void	algorithm_start(t_map *map)
{
	int	i;
	int	j;
	int	max_dia;

	i = 0;
	while (i < map->line)
	{
		j = 0;
		while(j < map->len)
		{
			dia_increase(map, i, j);
			j++;
		}
		i++;
	}
}