#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestors
 * @first: a pointer to the first nodes
 * @second: a pointer to the second nodes
 *
 * Return: a pointer to the lowest common node, Null otherwises
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *tmp;

	if (first == NULL || second == NULL)
		return (NULL);
	tmp = (binary_tree_t *)second;
	while (first)
	{
		while (second)
		{
			if (first == second)
				return ((binary_tree_t *)first);
			second = second->parent;
		}
		second = tmp;
		first = first->parent;
	}
	return (NULL);
}
