#include <fcntl.h>
#include <stdlib.h>

#include "bsq.h"


int make_field(int fd, t_map *map)
{
	int	i;
	
	map->field = (char **)malloc(sizeof(char *) * map->line);
	if (map->field == NULL)
		return (-1);
	map->field[0] = (char *)malloc(sizeof(char));
	if (map->field[0] == NULL)	// -1이면 NULL까지 free하기
		return (-1);
	map->allocated = 1;
	map->len = field_of_first(fd, map)
	if (map->len == -1 || map->len == 0)	// 0이면 allocated 참고
		return (map->len);
	i = 1;
	while (i < map->len)
	{
		map->field[i] = (char *)malloc(sizeof(char) * len);
		if (map->field[i] == NULL)
			return (-1);
		map->allocated = i + 1;
		field_of_remainder(fd, map);
		i++;
	}
}

int	get_board_information(int fd, t_map *map)
{
	int		len;
	char	first_line[14];

	len = 0;
	while (read(fd, &first_line[len], 1) != 0 && len < 14)
	{
		if (first_line[len] == '\n')
			break;
		len++;
	}
	if (len == 14)
		return (0);	// line too long
	len = i;
	map->line = ft_natoi_positive(first_line, len - 3);
	if (map->line == -1)
		return (0);	// map error
	map->empty = first_line[len - 3];
	map->obstacle = first_line[len - 2];
	map->full = first_line[len - 1];
	if (map->empty == map.obstacle
		|| map->obstacle == map.full
		|| map->empty == map.full)
		return (0);	// map error
	return (1);	// normal exit
}

char	*convert_files_to_map(int fd)
{
	t_map	map;

	if (get_board_information(fd, &map) == 0)
	{
		// TODO: map error
	}
	make_field(fd, &map);
}
