#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "bsq.h"

void	print_error_msg(int errno)
{
	if (errno == NORMEX)
		return ;
	else if (errno == FILERR)
		write(1, "File not found.\n", 16);
	else if (errno == MALOFL)
		write(1, "Malloc failed.\n", 15);
	else if (errno == MAPERR)
		write(1, "map error\n", 10);
}

void	print_field(t_map	*map)
{
	for (int i = 0; i < map->line; i++)
	{
		for (int j = 0; j < map->len; j++)
		{
			printf("%c", map->field[i][j]);
		}
		printf("\n");
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	int		errno;
	t_map	map;

	if (argc == 1)
	{
		fd = 0;
		errno = convert_files_to_map(fd, &map);
		print_error_msg(errno);
		if (errno == NORMEX)
		{
			print_field(&map);
			free(map.field[0]);
			free(map.field);
		}
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			print_error_msg(FILERR);
			return (-1);
		}
		errno = convert_files_to_map(fd, &map);
		print_error_msg(errno);
		if (errno == NORMEX)
		{
			print_field(&map);
			free(map.field[0]);
			free(map.field);
		}
		close(fd);
		i++;
	}
}
