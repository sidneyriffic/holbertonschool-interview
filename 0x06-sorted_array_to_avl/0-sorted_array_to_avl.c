#include <stdlib.h>
#include "binary_trees.h"


/**
 * _add_branch_recur - adds an avl branch from sorted array
 * @array: array to convert
 * @size: size of array
 * @parent: parent node in tree
 *
 * Return: address of new tree on success, NULL on failure
 */
binary_tree_t *_add_branch_recur(int *array, size_t size, avl_t *parent)
{
	binary_tree_t *new;

	new = malloc(sizeof(avl_t));
	if (new == NULL)
		return (NULL);

	new->n = array[(size - 1) / 2];
	new->parent = parent;
	new->right = NULL;
	new->left = NULL;
	if (size > 1)
	{
		new->right = _add_branch_recur(array + (size + 1) / 2,
					       size / 2, new);
		if (new->right == NULL)
			return (NULL);
	}
	if (size > 2)
	{
		new->left = _add_branch_recur(array, (size - 1) / 2, new);
		if (new->right == NULL)
			return (NULL);
	}

	return (new);
}

/**
 * sorted_array_to_avl - puts numbers stored in an array into an avl tree
 * @array: array to convert
 * @size: size of array
 *
 * Return: root AVL tree node address on success, NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (size == 0 || array == NULL)
		return (NULL);
	return ((avl_t *) _add_branch_recur(array, size, NULL));
}
