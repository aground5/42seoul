#ifndef BSQ_H
# define BSQ_H

typedef struct s_map {
	int		line;
	char	empty;
	char	obstacle;
	char	full;
	char	**field;
}			t_map;

#endif
