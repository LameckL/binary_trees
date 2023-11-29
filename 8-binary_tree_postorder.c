#include "binary_trees.h"

/**
 * binary_tree_postorder - traverses a binary tree, uses post-order traversal
 * @tree: ptr to the root node of the tree to traverse
 * @func: ptr to a function to call for each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
