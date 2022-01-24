#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

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
	int	i;
	int	j;

	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (j < map->len)
		{
			write(1, &(map->field[i][j]), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	multi_argv_start(char *fileName)
{
	int		fd;
	int		errno;
	t_map	map;

	fd = open(fileName, O_RDONLY);
	if (fd < 0)
	{
		print_error_msg(FILERR);
		return (-1);
	}
	errno = convert_files_to_map(fd, &map);
	print_error_msg(errno);
	if (errno == NORMEX)
	{
		algorithm_start(&map);
		print_field(&map);
		free(map.field[0]);
		free(map.field);
	}
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		errno;
	t_map	map;

	if (argc == 1)
	{
		errno = convert_files_to_map(0, &map);
		print_error_msg(errno);
		if (errno == NORMEX)
		{
			algorithm_start(&map);
			print_field(&map);
			free(map.field[0]);
			free(map.field);
		}
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		multi_argv_start(argv[i]);
	}
	return (errno);
}
