#include <stdlib.h>
#include "binary_trees.h"

/**
 * get_last - get last level-order node in tree. Recursive.
 *
 * @tree: tree to get last node of
 *
 * Return: depth of node
 */
heap_t *get_last(heap_t *tree)
{
	static heap_t *last;
	static size_t this_depth;
	static size_t deepest;

	this_depth++;
	if (this_depth > deepest)
	{
		deepest = this_depth;
		last = tree;
	}
	if (tree->right != NULL)
		get_last(tree->right);
	if (tree->left != NULL)
		get_last(tree->left);
	this_depth--;
	if (this_depth == 0)
		deepest = 0;
	return (last);
}

/**
 * swap_down - swap two heap nodes one of which is a child
 *
 * @parent: first node
 * @child: second node
 */
void swap_down(heap_t *parent, heap_t *child)
{
	heap_t *temp;

	temp = parent->left;
	parent->left = child->left;
	child->left = temp;
	temp = parent->right;
	parent->right = child->right;
	child->right = temp;
	child->parent = parent->parent;
	parent->parent = child;
	if (child->left == child)
	{
		child->left = parent;
		if (child->right != NULL)
			child->right->parent = child;
	}
	else
	{
		child->right = parent;
		if (child->left != NULL)
			child->left->parent = child;
	}
	if (parent->left != NULL)
		parent->left->parent = parent;
	if (parent->right != NULL)
		parent->right->parent = parent;
	if (child->parent != NULL)
	{
		if (child->parent->left == parent)
			child->parent->left = child;
		else
			child->parent->right = child;
	}
}

/**
 * sift_down - Sift root node down to where it needs to go. Recursive.
 *
 * @tree: root node
 */
void sift_down(heap_t *tree)
{
	heap_t *comp;

	if (tree->left == NULL)
		return;
	if (tree->right == NULL)
	{
		if (tree->left->n > tree->n)
		{
			swap_down(tree, tree->left);
			sift_down(tree);
			return;
		}
		else
			return;
	}
	if (tree->left->n > tree->right->n)
		comp = tree->left;
	else
		comp = tree->right;
	if (tree->n < comp->n)
	{
		swap_down(tree, comp);
		sift_down(tree);
		return;
	}
}

/**
 * heap_extract - extra root node of a max binary heap
 *
 * @tree: tree to extract root from
 *
 * Return: value of root node
 */
int heap_extract(heap_t **tree)
{
	heap_t *last, *root = *tree;
	int retval;

	if (tree == NULL || *tree == NULL)
		return (0);
	retval = root->n;
	last = get_last(root);
	if (root == last)
	{
		free(root);
		*tree = NULL;
		return (retval);
	}
	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;
	last->parent = root->parent;
	last->right = root->right;
	last->left = root->left;
	if (last->right == last)
		last->right = NULL;
	else if (last->left == last)
		last->left = NULL;
	if (last->left != NULL)
		last->left->parent = last;
	if (last->right != NULL)
		last->right->parent = last;
	free(root);
	root = last->parent;
	sift_down(last);
	while (last->parent != root)
	{
		last = last->parent;
	}
	*tree = last;
	return (retval);
}
