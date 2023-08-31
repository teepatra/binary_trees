#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestors
 * @first: a pointer to the first nodes
 * @second: a pointer to the second nodes
 *
 * Return: a pointer to the lowest common node, Null otherwises
 */
binary_tree_t
*binary_trees_ancestor(const binary_tree_t *first,
			const binary_tree_t *second)
{
	binary_tree_t *first_parent, *second_parent;

	if (!first || !second)
		return (NULL);
	else if (first == second->parent)
		return (second->parent);
	else if (second == first->parent)
		return (first->parent);

	first_parent = binary_trees_ancestor(first->parent, second);
	second_parent = binary_trees_ancestor(first, second->parent);
	return (first_parent && !second_parent ? first_parent : second_parent);
}
