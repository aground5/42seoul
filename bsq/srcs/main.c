/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:32:38 by sgi               #+#    #+#             */
/*   Updated: 2022/01/25 20:10:26 by chanbpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "bsq.h"

void	print_error_msg(int errno, int isLast)
{
	if (errno == NORMEX)
		return ;
	else
		write(1, "map error\n", 10);
	if (!isLast)
		write(1, "\n", 1);
}

void	print_field(t_map *map, int isLast)
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
	if (!isLast)
		write(1, "\n", 1);
}

int	multi_argv_start(char *fileName, int isLast)
{
	int		fd;
	int		errno;
	t_map	map;

	fd = open(fileName, O_RDONLY);
	if (fd < 0)
	{
		print_error_msg(FILERR, isLast);
		return (FILERR);
	}
	errno = convert_files_to_map(fd, &map);
	if (errno == NORMEX)
	{
		errno = start_algorithm(&map);
		if (errno == NORMEX)
			print_field(&map, isLast);
		free(map.field[0]);
		free(map.field);
	}
	print_error_msg(errno, isLast);
	close(fd);
	return (errno);
}

int	main(int argc, char **argv)
{
	int		i;
	int		errno;
	t_map	map;

	if (argc == 1)
	{
		errno = convert_files_to_map(0, &map);
		if (errno == NORMEX)
		{
			errno = start_algorithm(&map);
			if (errno == NORMEX)
				print_field(&map, 1);
			free(map.field[0]);
			free(map.field);
		}
		print_error_msg(errno, 1);
		return (errno);
	}
	i = 0;
	errno = 0;
	while (++i < argc)
		errno += multi_argv_start(argv[i], i == argc - 1);
	return (errno);
}
