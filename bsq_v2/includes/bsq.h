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
	int	row_collide;
	int	col_collide;
}		t_square;

typedef struct s_list {
	t_square		*square;
	struct s_list	*next;
}					t_list;

int			ft_natoi_positive(char *str, int n);
char		*ft_string_realloc(char *src, int size, int n);

int			field_of_first(int fd, t_map *map);
int			field_of_remainder(int fd, t_map *map, int line_idx);
int			make_field(int fd, t_map *map);
int			get_field_information(int fd, t_map *map);
int			convert_files_to_map(int fd, t_map *map);

int			check_map_flood(int fd);

void		fill_map(t_map *map, t_list **list);
int			is_empty_space(t_map *map, int dia, t_square *square);
int			dia_increase(t_map *map, t_square *square);
int			is_passable(int	row, int col, t_list **list, t_map *map);
int			algorithm_start(t_map *map);

void		save_max_collide(int row, int col, t_square *square);

void		free_list(t_list **list);
t_square	*make_square(int row, int col);
int			append_list(t_square *square, t_list **list);
t_square	*find_max_square(t_list **list);

#endif