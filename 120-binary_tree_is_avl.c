#include "binary_trees.h"

/**
 * maximum - returns the maximum of two integers
 * @first: the first integer
 * @second: the second integer
 *
 * Return: the maximum between the two integer
 */
size_t maximum(size_t first, size_t second)
{
	if (first > second)
		return (first);
	else
		return (second);
}
/**
 * binary_tree_height - measures the hieght of binary tree
 * @tree: a pointer to the root node
 *
 * Return: the eight of the tree, 0 otherwise
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->left || tree->right)
		return (maximum(binary_tree_height(tree->left),
				binary_tree_height(tree->right)) + 1);
	return (0);
}
/**
 * is_avl - checks if a binary tree is AVL
 * @tree: a pointer to the root node of the tree
 *
 * Return: 1 if the tree is AVL, 0 otherwise
 */
int is_avl(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (1);
	left_height = binary_tree_height(tree->left) + 1;
	right_height = binary_tree_height(tree->right) + 1;
	if (abs(left_height - right_height) <= 1
		&& is_avl(tree->left)
		&& is_avl(tree->right))
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - checks if a binary tree is AVL
 * @tree: a pointer to the root node of the tree
 *
 * Return: 1 if the tree is AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_avl(tree));
}
