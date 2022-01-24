#include <stdlib.h>
#include "bsq.h"

int	field_of_first(int fd, t_map *map)
{
	int	i;
	
	i = 0;
	while (read(fd, &field[0][i], 1) != 0)
	{
		if (field[0][i] != '\n')
		{
			field[0] = ft_string_realloc(field[0], i + 2);
			if (field[0] == NULL)
				return (-1);
		}
		else
			break ;
		if (field[0][i] != map->empty
			&& field[0][i] != map->obstacle)
			return (0);
		i++;
	}
	return (i);
}

void free_field(t_map *map, int line)
{
	
}

int	field_of_remainder(int fd, t_map *map)
{
	int		i;
	int		j;
	char	c;
	
	while (j < map->len
			&& read(fd, &field[map->allocated - 1][j], 1) != 0)
	{
		if (field[map->allocated - 1][j] == '\n')
			break ;
		if (field[][i] != map->empty
			&& field[][i] != map->obstacle)
		{
			free(field[]);
			return (0);
		}
	}
	if (j != len - 1 && read(fd, &c, 1) == 0
		&& c != '\n')
	{
		free_field(map, i);
		return (0);
	}
}
