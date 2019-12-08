#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - add a node to a max heap
 *
 * @parent: parent of node to be added
 * @value: value of node to add
 *
 * Return: address of new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent != NULL && parent->left != NULL && parent->right != NULL)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	new->n = value;
	if (parent != NULL)
	{
		if (parent->left == NULL)
			parent->left = new;
		else
			parent->right = new;
	}
	return (new);
}
