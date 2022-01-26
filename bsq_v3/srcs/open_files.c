/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:32:44 by sgi               #+#    #+#             */
/*   Updated: 2022/01/24 21:32:49 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "bsq.h"

int	field_of_first(int fd, t_map *map)
{
	int	i;

	i = 0;
	while (read(fd, &map->field[0][i], 1) > 0)
	{
		if (map->field[0][i] != '\n')
		{
			map->field[0] = ft_string_realloc(map->field[0], i + 2, i + 1);
			if (map->field[0] == NULL)
				return (BCLRLNMF);
		}
		else
			break ;
		if (map->field[0][i] != map->empty
			&& map->field[0][i] != map->obstacle)
			return (MERRBFCLR);
		i++;
	}
	map->len = i;
	if (map->len <= 0)
		return (MAPERR);
	return (NORMEX);
}

int	field_of_remainder(int fd, t_map *map, int line_idx)
{
	int		i;
	char	c;

	i = 0;
	while (i < map->len
		&& read(fd, &(map->field[line_idx][i]), 1) > 0)
	{
		if (map->field[line_idx][i] == '\n')
			return (MAPERR);
		if (map->field[line_idx][i] != map->empty
			&& map->field[line_idx][i] != map->obstacle)
			return (MERRBFCLR);
		i++;
	}
	if (read(fd, &c, 1) <= 0)
		return (MAPERR);
	if (c != '\n')
		return (MERRBFCLR);
	return (NORMEX);
}

int	make_field(int fd, t_map *map)
{
	int		i;
	int		errno;

	map->field = map_field_maker(map->line);
	if (map->field == NULL)
		return (FIELDMF);
	errno = field_of_first(fd, map);
	if (errno != NORMEX)
		return (errno);
	map->field[0] = ft_string_realloc(map->field[0],
			(map->line) * (map->len), (map->len));
	if (map->field[0] == NULL)
		return (FDLNMF);
	i = 1;
	while (i < map->line)
	{
		map->field[i] = map->field[i - 1] + map->len;
		errno = field_of_remainder(fd, map, i++);
		if (errno != NORMEX)
			return (errno);
	}
	errno = check_map_flood(fd);
	return (errno);
}

int	get_field_information(int fd, t_map *map)
{
	int		len;
	char	first_line[14];

	len = 0;
	while (len < 14)
	{
		if (read(fd, &first_line[len], 1) <= 0)
			return (MAPERR);
		if (first_line[len] == '\n')
			break ;
		len++;
	}
	if (len == 14)
		return (MERRBFCLR);
	map->line = ft_natoi_positive(first_line, len - 3);
	if (map->line <= 0 || len < 4)
		return (MAPERR);
	map->empty = first_line[len - 3];
	map->obstacle = first_line[len - 2];
	map->full = first_line[len - 1];
	if (map->empty == map->obstacle
		|| map->obstacle == map->full
		|| map->empty == map->full)
		return (MAPERR);
	return (NORMEX);
}

int	convert_files_to_map(int fd, t_map *map)
{
	int		errno;
	char	c;

	errno = get_field_information(fd, map);
	if (errno == MERRBFCLR)
		while (read(fd, &c, 1) > 0 && c != '\n')
			continue ;
	if (errno == MAPERR || errno == MERRBFCLR)
		return (MAPERR);
	errno = make_field(fd, map);
	if (errno == MERRBFCLR || errno == BCLRLNMF)
		while (read(fd, &c, 1) > 0 && c != '\n')
			continue ;
	if (errno == MAPERR || errno == MERRBFCLR)
	{
		free(map->field[0]);
		free(map->field);
		return (MAPERR);
	}
	if (errno == FDLNMF || errno == FIELDMF || errno == BCLRLNMF)
		free(map->field);
	if (errno == FIELDMF || errno == BCLRLNMF)
		return (MALOFL);
	return (NORMEX);
}
