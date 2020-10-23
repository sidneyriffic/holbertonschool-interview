#include "binary_trees.h"
#include <stdlib.h>


/**
 * sorted_array_to_avl - convert a sorted array to an AVL tree. Recursive.
 *
 * @array: the array to convert
 * @size: the size of the array
 *
 * Return: the new AVL tree root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *center;

	if (size == 0 || array == NULL)
		return (NULL);
	center = malloc(sizeof(avl_t));
	if (center == NULL)
		return (NULL);
	center->n = array[size / 2 + size % 2 - 1];
	center->left = sorted_array_to_avl(array, size / 2 + size % 2 - 1);
	if (size == 1)
		center->right = NULL;
	else
		center->right = sorted_array_to_avl(array + size / 2 + size % 2, size / 2);
	center->parent = NULL;
	if (center->left != NULL)
		center->left->parent = center;
	if (center->right != NULL)
		center->right->parent = center;
	return (center);
}
