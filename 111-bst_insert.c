#include "binary_trees.h"

/**
 * bst_insert - inserts a value in BST
 * @tree: a double pointer to the root node
 * @value: the value to store in the node
 *
 * Return: a pointer to the newly created node, null otherwise
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current;

	if (!(*tree))
	{
		(*tree) = (binary_tree_node(NULL, value));
		return (*tree);
	}
	current = *tree;
	while (1)
	{
		if (value < current->n)
		{
			if (current->left)
				current = current->left;
			else
			{
				current->left = (binary_tree_node(current, value));
				current = current->left;
				break;
			}
		}
		else if (value > current->n)
		{
			if (current->right)
				current = current->right;
			else
			{
				current->right = (binary_tree_node(current, value));
				current = current->right;
				break;
			}
		}
		else
			return (NULL);
	}
	return (current);
}
