#include "binary_trees.h"

bst_t *search(bst_t *root, int value)
{
	if (!root)
		return (NULL);
	while (root)
	{
		if (value > root->n)
			root = root->right;
		else if (value < root->n)
			root = root->left;
		break;
	}
	return (root);
}

/**
 * bst_remove - removes a node from a BST
 * @root: a pointer to the root node
 * @value: is the value to remove from the BST
 *
 * Return: a pointer to the new root node of the tree after
 * removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *minimum;

	if (!root)
		return (NULL);

	node = search(root, value);
	if (!node)
		return (NULL);
	minimum = node->right;
	while (minimum->left)
		minimum = minimum->left;

	minimum->parent->left = minimum->right;
	minimum->left = node->left;
	minimum->right = node->right;
	minimum->parent = node->parent;

	node->right->parent = minimum;
	node->left->parent = minimum;

	if (minimum->parent == NULL)
		root = minimum;
	free(node);

	return (root);
}
