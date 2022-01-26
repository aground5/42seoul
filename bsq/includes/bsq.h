/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:32:14 by sgi               #+#    #+#             */
/*   Updated: 2022/01/24 21:32:16 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define NORMEX 0
# define FILERR 1
# define MALOFL 2
# define MAPERR 3

# define MERRBFCLR -1
# define BCLRLNMF -2
# define FIELDMF -3
# define FDLNMF -4

typedef struct s_map {
	int		line;
	int		len;
	char	empty;
	char	obstacle;
	char	full;
	char	**field;
}			t_map;

typedef struct s_square {
	int	row;
	int	col;
	int	dia;
}		t_square;

int		ft_natoi_positive(char *str, int n);
char	*ft_string_realloc(char *src, int size, int n);

int		field_of_first(int fd, t_map *map);
int		field_of_remainder(int fd, t_map *map, int line_idx);
int		make_field(int fd, t_map *map);
int		get_field_information(int fd, t_map *map);
int		convert_files_to_map(int fd, t_map *map);

int		check_map_flood(int fd);

int		is_possible(t_map *map, int row, int col, int dia);
int		dia_increase(t_map *map, int row, int col);
void	algorithm_start(t_map *map);

#endif
