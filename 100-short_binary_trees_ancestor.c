#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds lowest common ancestor of two nodes
 * @first: ptr to the first node
 * @second: ptr to the second node
 * Return: NULL - no common ancestors, else - common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mom, *pop;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mom = first->parent, pop = second->parent;
	if (first == pop || !mom || (!mom->parent && pop))
		return (binary_trees_ancestor(first, pop));
	else if (mom == second || !pop || (!pop->parent && mom))
		return (binary_trees_ancestor(mom, second));
	return (binary_trees_ancestor(mom, pop));
}
