#ifndef BSQ_H
# define BSQ_H

# define NORMEX 0
# define FILERR 1
# define MALOFL 2
# define MAPERR 3

typedef struct s_map {
	int		line;
	int		len;
	char	empty;
	char	obstacle;
	char	full;
	char	**field;
}			t_map;

int		ft_natoi_positive(char *str, int n);
char	*ft_string_realloc(char *src, int size);

int	field_of_first(int fd, t_map *map);
int	field_of_remainder(int fd, t_map *map, int line_idx);
int	make_field(int fd, t_map *map);
int	get_board_information(int fd, t_map *map);
int	convert_files_to_map(int fd, t_map *map);

#endif
