#include "binary_trees.h"

/**
 * array_to_bst - Converts an array to a BST
 * @array: a pointer to the first element of the array
 * @size: the number of element in the array
 *
 * Return: a pointer to the root node of BST, null otherwise
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *tree;

	tree = NULL;
	for (i = 0; i < size; i++)
	{
		bst_insert(&tree, array[i]);
	}
	return (tree);
}
