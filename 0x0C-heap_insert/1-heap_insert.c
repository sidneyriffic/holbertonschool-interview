#include <stdlib.h>
#include "binary_trees.h"

/**
 * _find_insert_parent - find parent where to insert heap node
 *
 * @node: node being examined
 * @depth: depth node is at
 *
 * Return: address of new parent
 */
node_depth _find_insert_parent(heap_t *node, size_t depth)
{
	node_depth ret, ret2;

	if (node->left == NULL || node->right == NULL)
	{
		ret.node = node;
		ret.depth = depth;
		return (ret);
	}

	ret = _find_insert_parent(node->left, depth + 1);
	ret2 = _find_insert_parent(node->right, depth + 1);
	if (ret.depth != ret2.depth)
		return (ret2);
	else
		return (ret);
}

/**
 * _swap - swap a node with its parent
 *
 * @node: node to swap with its parent
 */
void _swap(heap_t *node)
{
	heap_t *swap, *parent;

	parent = node->parent;
	if (node->left != NULL)
		node->left->parent = parent;
	if (node->right != NULL)
		node->right->parent = parent;
	if (parent->left != NULL)
		parent->left->parent = node;
	if (parent->right != NULL)
		parent->right->parent = node;
	swap = node->left;
	node->left = parent->left;
	parent->left = swap;
	swap = node->right;
	node->right = parent->right;
	parent->right = swap;
	if (node == node->left)
		node->left = parent;
	if (node == node->right)
		node->right = parent;
	if (parent->parent != NULL)
	{
		if (parent->parent->left == parent)
			parent->parent->left = node;
		if (parent->parent->right == parent)
			parent->parent->right = node;
	}
	node->parent = parent->parent;
	parent->parent = node;
}

/**
 * heap_insert - insert a value into a max heap. Reallocates nodes by address
 * instead of swapping values.
 *
 * @root: root of heap
 * @value: value to insert
 *
 * Return: address of new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent;

	if (root == NULL)
		return (NULL);
	new = malloc(sizeof(heap_t));
	if (new == NULL)
		return (NULL);
	if (*root == NULL)
	{
		parent = NULL;
		*root = new;
	}
	else
		parent = _find_insert_parent(*root, 0).node;
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	new->n = value;
	if (parent != NULL)
	{
		if (parent->left == NULL)
			parent->left = new;
		else
			parent->right = new;
	}
	while (new->parent != NULL && new->n > new->parent->n)
		_swap(new);
	if (new->parent == NULL)
		*root = new;
	return (new);
}
