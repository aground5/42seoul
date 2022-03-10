#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void(*applyf)(void *))
{
	applyf(root->item);
	if (root->left != 0)
		btree_apply_prefix(root->left, applyf);
	if (root->right != 0)
		btree_apply_prefix(root->right, applyf);
}