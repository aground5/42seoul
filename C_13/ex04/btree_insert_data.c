#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (*root == 0)
	{
		*root = (t_btree *)malloc(sizeof(t_btree));
		if (*root == 0)
			return ;
		(*root)->item = item;
		return ;
	}
}

int	cmpf(void *s1, void *s2)
{

}