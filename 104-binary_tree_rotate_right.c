#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right rotation
 * @tree: a pointer to the root node
 *
 * Return: a pointer to the new root node, null otherwise
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *first, *second;

	if (!tree)
		return (NULL);
	first = tree->left;
	second = first->right;
	tree->left = second;
	tree->parent = first;
	if (second)
		second->parent = tree;
	first->parent = NULL;
	first->right = tree;
	tree = first;
	return (tree);
}
