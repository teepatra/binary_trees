#include "binary_trees.h"

/**
 * push - pushs a node in the front of a queue
 * @head: a pointer to the head of the queue
 * @tail: a pointer to the tail of the queue
 * @node: a pointer to the binary tree node
 *
 * Return: void
 */
void push(queue_t **head, queue_t **tail, const binary_tree_t *node)
{
	queue_t *new_node;

	new_node = malloc(sizeof(queue_t));
	if (!new_node)
		return;
	new_node->node = node;
	if (*head == NULL)
	{
		(*head) = new_node;
		(*tail) = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		new_node->next = (*head);
		new_node->prev = NULL;
		(*head)->prev = new_node;
		(*head) = new_node;
	}
}

/**
 * pop - pops a node from the tail of the queue
 * @tail: a pointer to the tail of the queue
 *
 * Return: void
 */
void pop(queue_t **tail)
{
	queue_t *tmp;

	tmp = (*tail);
	(*tail) = (*tail)->prev;
	free(tmp);
}

/**
 * binary_tree_is_complete - checks if the binary tree is complete
 * @tree: a pointer to the root node
 *
 * Return: 1 if a binary tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int finish = 0;
	queue_t *head = NULL, *tail = NULL;
	const binary_tree_t *current;

	if (!tree)
		return (0);
	push(&head, &tail, tree);
	while (tail)
	{
		current = tail->node;
		if (current == NULL)
			finish = 1;
		else
		{
			if (finish)
				return (0);
			push(&head, &tail, current->left);
			push(&head, &tail, current->right);
		}
		pop(&tail);
	}
	return (1);
}
