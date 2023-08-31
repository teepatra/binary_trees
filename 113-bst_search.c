#include "binary_trees.h"

/**
 * bst_search - searches for a value in a BST
 * @tree: a pointer to the root node
 * @value: the value to search in the tree
 *
 * Return: a pointer to the node containing the value,
 * returns null otherwise
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	while (tree)
	{
		if (value > tree->n)
			tree = tree->right;
		else if (value < tree->n)
			tree = tree->left;
		else if (tree->n == value)
			return ((bst_t *) tree);
	}
	return ((bst_t *) tree);
}
