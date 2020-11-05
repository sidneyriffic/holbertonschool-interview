#include <stdlib.h>
#include <stdio.h>
#include "sort.h"


/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}


/**
 * merge_sort - use merge sort in place on an array of integers
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *left, *right, *start = array;
	size_t lsize = size / 2, rsize = size / 2 + size % 2;
	static int *buffer, idx, i;

	if (array == NULL || size <= 1)
		return;
	if (buffer == NULL)
		buffer = malloc(sizeof(int) * size);
	merge_sort(array, lsize);
	merge_sort(array + lsize, rsize);
	left = array;
	right = array + lsize;
	printf("Merging...\n[left]: ");
	print_array(left, lsize);
	printf("[right]: ");
	print_array(right, rsize);
	for (idx = 0; lsize > 0 && rsize > 0; idx++)
	{
		if (*left < *right)
		{
			buffer[idx] = *left;
			left++;
			lsize--;
		}
		else
		{
			buffer[idx] = *right;
			right++;
			rsize--;
		}
	}
	idx--;
	for (i = idx + 1; lsize; lsize--, left++, i++)
		array[i] = *left;
	for (i = idx + 1; rsize; rsize--, right++, i++)
		array[i] = *right;
	for (; idx >= 0; idx--)
		array[idx] = buffer[idx];
	printf("[Done]: ");
	print_array(start, size);
}
