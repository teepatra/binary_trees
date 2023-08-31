#include "binary_trees.h"

/**
 * is_bst - checks if a tree is a valid BST
 * @tree: a pointer to the root node
 * @min: the minimumm left possible
 * @max: the maximum right possible
 *
 * Return: 1 if the tree is a BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n > min
		&& tree->n < max
		&& is_bst(tree->left, min, tree->n)
		&& is_bst(tree->right, tree->n, max))
		return (1);
	else
		return (0);
}

/**
 * binary_tree_is_bst - checks if a tree is a valid BST
 * @tree: a pointer to the root node
 *
 * Return: 1 if the tree is a BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst(tree, INT_MIN, INT_MAX));
}
