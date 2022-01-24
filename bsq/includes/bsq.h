#ifndef BSQ_H
# define BSQ_H

typedef struct s_map {
	int		line;
	int		len;
	char	empty;
	char	obstacle;
	char	full;
	char	**field;
	int		allocated;
}			t_map;

#endif
