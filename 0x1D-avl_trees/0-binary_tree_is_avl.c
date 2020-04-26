#include "binary_trees.h"
#include <limits.h>
#include <stddef.h>

/**
 * _is_avl_recur - check if binary tree is avl tree
 *
 * @node: subtree to check
 * @max: parent's max holder for this child
 * @min: parent's min holder for this child
 *
 * Return: depth from node if bst, -1 otherwise
 */
int _is_avl_recur(const binary_tree_t *node,
		  int *max, int *min)
{
	int left_max = INT_MIN, left_min = INT_MAX,
		right_max = INT_MIN, right_min = INT_MAX,
		left_depth, right_depth;

	if (node->left == NULL && node->right == NULL)
		*max = *min = node->n;
	if (node->left != NULL)
		left_depth = _is_avl_recur(node->left,
					   &left_max,
					   &left_min);
	else
		left_depth = 0;
	if (node->right != NULL)
		right_depth = _is_avl_recur(node->right,
					    &right_max,
					    &right_min);
	else
		right_depth = 0;
	if (left_depth == -1 || right_depth == -1)
		return (-1);
	if (left_depth > right_depth + 1 ||
	    right_depth > left_depth + 1 ||
	    left_max >= node->n || right_min <= node->n)
		return (-1);
	*max = node->n > right_max ? node->n : right_max;
	*min = node->n > left_min ? node->n : left_min;
	return (left_depth > right_depth ?
		left_depth + 1 : right_depth + 1);
}

/**
 * binary_tree_is_avl - check if binary tree is avl tree
 *
 * @tree: tree to check
 *
 * Return: 1 if avl tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int unused, nothing;

	if (tree == NULL)
		return (0);
	return (_is_avl_recur(tree, &unused,
			      &nothing) != -1 ? 1 : 0);
}
