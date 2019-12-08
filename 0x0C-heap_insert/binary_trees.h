#ifndef BINARY_TREES_H
#define BINARY_TREES_H


/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

/**
 * struct node_depth - a heap_t node and how deep in a tree it is. Used for a
 * pair value return in _swap in 1-heap_insert.c. Style checker requires
 * it in header even though this isn't intended for anywhere else.
 *
 * @node: the node
 * @depth: how deep it is
 */
typedef struct node_depth
{
	heap_t *node;
	size_t depth;
} node_depth;


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);

void binary_tree_print(const binary_tree_t *tree);

#endif
