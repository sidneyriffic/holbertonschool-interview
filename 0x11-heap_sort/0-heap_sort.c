#include "sort.h"
#include <stddef.h>
#include <unistd.h>

/**
 * _sift_down - sift down on a heap node
 *
 * @array: array to sift
 * @size: size of array
 * @node: node we're sifting on, 1 indexed
 * @full_size: hack for printing full array for assignment
 */
void _sift_down(int *array, size_t size, size_t node, size_t full_size)
{
	/* swapidx is 0 indexed */
	int tmp, swapidx = 0;

	if (node * 2 <= size && array[node - 1] < array[node * 2 - 1])
		swapidx = node * 2 - 1;
	if (node * 2 + 1 <= size &&
	    array[node - 1] < array[node * 2] &&
	    array[node * 2 - 1] < array[node * 2])
		swapidx = node * 2;
	if (swapidx)
	{
		tmp = array[swapidx];
		array[swapidx] = array[node - 1];
		array[node - 1] = tmp;
		print_array(array, full_size);
		_sift_down(array, size, swapidx + 1, full_size);
	}
}

/**
 * heap_sort - in place heap sort an integer array. Parent/child relations
 * are managed by multiplying or dividing a 1 indexed node index by 2.
 *
 * @array: array to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	size_t node; /*the node we are looking at. 1 indexed*/
	int tmp;
	size_t full_size = size;

	for (node = size; node > 0; node--)
		_sift_down(array, size, node, full_size);
	while (size > 1)
	{
		tmp = array[0];
		array[0] = array[size - 1];
		array[size - 1] = tmp;
		size--;
		print_array(array, full_size);
		_sift_down(array, size, 1, full_size);
	}
}
