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

# define GARO 0
# define SERO 1

typedef struct s_map {
	int		line;
	int		len;
	char	empty;
	char	obstacle;
	char	full;
	char	**field;
}			t_map;

typedef struct s_obstacles {
	int	garo_obstacle_row;
	int	garo_obstacle_col;
	int	sero_obstacle_row;
	int	sero_obstacle_col;
}		t_obstacles;

typedef struct s_square {
	int			row;
	int			col;
	int			dia;
	t_obstacles	obstacles;
}				t_square;

int			ft_natoi_positive(char *str, int n);
char		*ft_string_realloc(char *src, int size, int n);
char		**map_field_maker(int line);

int			field_of_first(int fd, t_map *map);
int			field_of_remainder(int fd, t_map *map, int line_idx);
int			make_field(int fd, t_map *map);
int			get_field_information(int fd, t_map *map);
int			convert_files_to_map(int fd, t_map *map);

int			check_map_flood(int fd);

void		fill_map(t_map *map, t_square square);
int			is_empty_space(t_map *map, int dia, t_square *square);
int			dia_increase(t_map *map, t_square *square);
t_square	process_algorithm(t_map *map, char **index_field);
int			start_algorithm(t_map *map);

void		save_max_collide(int row, int col, t_square *square, int direction);
void		index_passing_zone(t_square square, char **index_field);
char		**malloc_index_field(t_map *map);
void		init_square(t_square *square, int row, int col);
void		init_index_field(char **index_field, t_map *map);

#endif
