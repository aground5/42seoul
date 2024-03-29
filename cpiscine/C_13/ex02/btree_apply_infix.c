#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root->left != 0)
		btree_apply_infix(root->left, applyf);
	applyf(root->item);
	if (root->right != 0)
		btree_apply_infix(root->right, applyf);
}