#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if the binary tree node is root
 * @node: a pointer to node to check
 *
 * Return: 1 if the node is root, 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return ((!node || node->parent) ? 0 : 1);
}
