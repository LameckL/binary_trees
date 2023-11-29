#include "binary_trees.h"

/**
 * binary_tree_insert_right - func inserting a node as the right-child
 * of another one in a binary tree.
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: NULL - if parent is NULL or an error occurs
 *         Otherwise - pointer to the new node
 *
 * Description: If parent already has a right-child, the new node replace
 * it and the old right-child set as the right-child of the new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
