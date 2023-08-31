#include "binary_trees.h"
int find_depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (!tree)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}
int is_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (!tree)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect(tree->left, depth, level + 1) &&
		is_perfect(tree->right, depth, level + 1));
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to root node
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;
	int level = 0;

	depth = find_depth(tree);
	return (is_perfect(tree, depth, level));
}
