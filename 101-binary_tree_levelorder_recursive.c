#include "binary_trees.h"

/**
 * struct node_s - singly linked list
 * @node: binary tree node
 * @next: next node
 */
typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} ll;

ll *append(ll *head, const binary_tree_t *btnode);
void free_list(ll *head);
ll *get_children(ll *head, const binary_tree_t *parent);
void levels_rec(ll *head, void (*func)(int));

/**
 * binary_tree_levelorder - goes through a binary tree; level-order traversal
 * @tree: ptr to the root node of the tree to traverse
 * @func: ptr to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	ll *children = NULL;

	func(tree->n);
	children = get_children(children, tree);
	levels_rec(children, func);

	free_list(children);
}

/**
 * levels_rec - calls func on all nodes at each level
 * @head: ptr to head of linked list with nodes at one level
 * @func: ptr to a function to call for each node
 */
void levels_rec(ll *head, void (*func)(int))
{
	ll *children = NULL, *curr = NULL;

	if (!head)
		return;
	for (curr = head; curr != NULL; curr = curr->next)
	{
		func(curr->node->n);
		children = get_children(children, curr->node);
	}
	levels_rec(children, func);
	free_list(children);
}

/**
 * get_children - appends children of parent to linked list
 * @head: ptr to head of linked list where children will be appended
 * @parent: ptr to node whose children we want to append
 * Return: ptr to head of linked list of children
 */
ll *get_children(ll *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = append(head, parent->left);
	if (parent->right)
		head = append(head, parent->right);
	return (head);
}

/**
 * append - adds new node at the end of a linkedlist
 * @head: ptr to head of linked list
 * @btnode: const binary tree node to append
 * Return: ptr to head, NULL - failure
 */
ll *append(ll *head, const binary_tree_t *btnode)
{
	ll *new = NULL, *last = NULL;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->node = btnode;
		new->next = NULL;
		if (!head)
			head = new;
		else
		{
			last = head;
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
	return (head);
}

/**
 * free_list - frees all the nodes in a linked list
 * @head: ptr to the head of list_t linked list
 */
void free_list(ll *head)
{
	ll *ptr = NULL;

	while (head)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
