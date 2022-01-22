#ifndef DFS_H

# define DFS_H
int		dfs_start(int **board, int len);
int		dfs_process(int **board, int len, int i, int j);
int		***dfs_init(int len);
void	dfs_fail(int len, int row, int col);
void	g_visit_zero_fill(int len);

#endif
