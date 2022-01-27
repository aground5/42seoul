#include <stdlib.h>

#include "ft_btree.h"

t_btree	*btree_create_note(void *item)
{
	t_btree	*btree;

	btree = (t_btree *)malloc(sizeof(t_btree));
	btree->item = item;
	btree->left = NULL;
	btree->right = NULL;
	return (btree);
}