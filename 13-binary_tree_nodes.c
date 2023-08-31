#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the node with at least 1 child
 * @tree: a pointer to the root node
 *
 * Return: the number of node with child, 0 otherwise
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->right || tree->left)
		return (binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right) + 1);
	return (0);
}
