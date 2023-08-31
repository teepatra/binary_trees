#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of binary tree
 * @tree: a pointer to the root node
 *
 * Return: the size of the binary tree, O otherwise
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
