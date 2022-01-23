#include <fcntl.h>
#include <stdlib.h>

#include "bsq.h"

int	ft_natoi_positive(char *str, int n)
{
	int				i;
	int				result;

	i = 0;
	result = 0;
	while (i < n)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += str[i] - '0';
		}
		else
			return (-1)
		i++;
	}
	return (result);
}

int	is_printable(char c)
{
	if (c >= 0x20 && c <= 0xfe)
		return (1);
	return (0);
}

char	*ft_string_realloc(char *src, int size)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * size);
	if (dest == NULL)
	{
		free(src);
		return (NULL);
	}
	i = 0;
	while (i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	free(src);
	return (NULL);
}

char	**make_field(int fd, t_map *map)
{
	char	**field;
	int		i;
	int		j;

	field = (char **)malloc(sizeof(char *) * map->line);
	if (field == NULL)
		return (NULL);
	field[0] = (char *)malloc(sizeof(char));
	if (field[0] == NULL)
	{
		free(field);
		return (NULL);
	}
	i = 0;
	while (read(fd, &field[0][i], 1) != 0)
	{
		if (field[0][i] != '\n')
		{
			field[0] = ft_string_realloc(field[0], i + 2);
			if (field[0] == NULL)
			{
				free(field);
				return (NULL);
			}
		}
		else
			break ;
		if (field[0][i] != map->empty
			&& field[0][i] != map->obstacle)
		{
			
			return (NULL);
		}
		i++;
	}
}

char	*convert_files_to_map(int fd)
{
	int		i;
	int		len;
	char	first_line[13];
	t_map	map;

	i = 0;
	while (read(fd, &first_line[i], 1) != 0 && i < 13)
	{
		if (first_line[i] == '\n')
			break;
		i++;
	}
	if (i == 13)
		return (NULL);
	len = i;
	map.line = ft_natoi_positive(first_line, len - 3);
	if (map.line == -1)
		return (NULL);
	map.empty = first_line[len - 3];
	map.obstacle = first_line[len - 2];
	map.full = first_line[len - 1];
	if (map.empty == map.obstacle
		|| map.obstacle == map.full
		|| map.empty == map.full)
		return (NULL);
	map.field = make_field(fd, &map);
}
