#include <limits.h>
#include <stddef.h>
#include "binary_trees.h"

/**
 * _test_avl_recur - the recursive test for AVL treeness
 *
 * @t: tree to check
 * @min: minimum allowed value
 * @max: maximum allowed value
 *
 * Return: height of tree, or -1 for early exit if non-AVLness confirmed
 */
long int _test_avl_recur(const binary_tree_t *t, const int min, const int max)
{
	long int left, right;

	if (t == NULL)
		return  (1);
	if (t->n < min || t->n > max)
		return (-1);
	left = _test_avl_recur(t->left, min, t->n);
	if (left == -1)
		return (-1);
	right = _test_avl_recur(t->right, t->n, max);
	if (right == -1)
		return (-1);
	if (left > right + 1 || right > left + 1)
		return (-1);
	return (left > right ? left + 1 : right + 1);
}

/**
 * binary_tree_is_avl - determine if a binary tree is an avl tree
 *
 * @tree: tree to check if AVL
 *
 * Return: 1 if AVL, 0 if not
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	long int result;

	if (tree == NULL)
		return (0);
	result = _test_avl_recur(tree, INT_MIN, INT_MAX);
	if (result == -1)
		return (0);
	return (1);
}
