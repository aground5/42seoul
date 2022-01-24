#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "bsq.h"

int	field_of_first(int fd, t_map *map)
{
	int	i;

	i = 0;
	while (read(fd, &map->field[0][i], 1) != 0)
	{
		if (map->field[0][i] != '\n')
		{
			map->field[0] = ft_string_realloc(map->field[0], i + 2);
			if (map->field[0] == NULL)
				return (-1);
		}
		else
			break ;
		if (map->field[0][i] != map->empty
			&& map->field[0][i] != map->obstacle)
			return (0);
		i++;
	}
	return (i);
}

int	field_of_remainder(int fd, t_map *map, int line_idx)
{
	int		i;
	char	c;

	i = 0;
	while (i < map->len 
		&& read(fd, &(map->field[line_idx ][i]), 1) != 0)
	{
		if (map->field[line_idx][i] == '\n')
			return (0);
		if (map->field[line_idx][i] != map->empty
			&& map->field[line_idx][i] != map->obstacle)
			return (0);
		i++;
	}
	if (read(fd, &c, 1) == 0)
		return (0);
	if (c != '\n')
		return (0);
	return (1);
}

int	make_field(int fd, t_map *map)
{
	int	i;
	
	map->field = (char **)malloc(sizeof(char *) * map->line);
	if (map->field == NULL)
		return (-1);	// -1이면 field만 free
	map->field[0] = (char *)malloc(sizeof(char));
	if (map->field[0] == NULL)
		return (-1);	// -1이면 field만 free
	map->len = field_of_first(fd, map);
	if (map->len == -1 || map->len == 0)	// 0이면 field[0], field만 free
		return (map->len);
	map->field[0] = ft_string_realloc(map->field[0], (map->line) * (map->len));
	if (map->field[0] == NULL)
		return (-1);	// -1이면 field만 free
	i = 1;
	while (i < map->line)
	{
		map->field[i] = map->field[i - 1] + map->len;
		if (field_of_remainder(fd, map, i) == 0)
			return (0);	// 0이면 field[0], field만 free
		i++;
	}
	return (1);
}

int	get_board_information(int fd, t_map *map)
{
	int		len;
	char	first_line[14];

	len = 0;
	while (len < 14)
	{
		if (read(fd, &first_line[len], 1) == 0)
			return (0);
		if (first_line[len] == '\n')
			break ;
		len++;
	}
	if (len == 14)
		return (0);	// line too long
	map->line = ft_natoi_positive(first_line, len - 3);
	if (map->line == -1)
		return (0);	// map error
	map->empty = first_line[len - 3];
	map->obstacle = first_line[len - 2];
	map->full = first_line[len - 1];
	if (map->empty == map->obstacle
		|| map->obstacle == map->full
		|| map->empty == map->full)
		return (0);	// map error
	return (1);	// normal exit
}

int	convert_files_to_map(int fd, t_map *map)
{
	int		result;

	if (get_board_information(fd, map) == 0)
		return (MAPERR);
	result = make_field(fd, map);
	if (result == 0)
	{
		free(map->field[0]);
		free(map->field);
		return (MAPERR);
	}
	if (result == -1)
	{
		free(map->field);
		return (MALOFL);
	}
	return (NORMEX);
}
