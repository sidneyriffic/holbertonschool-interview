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
	int *left, *right, ltemp, rtemp, *buffer, bufsize, lsize, rsize;

	printf("size level %ld\n", size);
	if (array == NULL)
		return;
	if (size <= 1)
		return;
	lsize = size / 2;
	rsize = size / 2 + size % 2;
	merge_sort(array, lsize);
	merge_sort(array + lsize, rsize);
	printf("Bottom lsize %d rsize %d\n", lsize, rsize);
	left = array;
	right = array + lsize;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, lsize);
	printf("[right]: ");
	print_array(right, rsize);
	bufsize = 0;
	buffer = right + size % 2 + 1;
	ltemp = *left;
	left++;
	rtemp = *right;
	right++;
	while (rsize > 0 && lsize > 0)
	{
		printf("rtemp %d ltemp %d buffer %d\n", rtemp, ltemp, *buffer);
		if (rtemp < ltemp)
		{
			*array = rtemp;
			right++;
			rsize--;
			rtemp = *right;
			if (array >= left)
			{
				*(buffer + bufsize) = *array;
				bufsize++;
			}
		}
		else
		{
			*array = ltemp;
			left++;
			lsize--;
			if (bufsize)
			{
				ltemp = *buffer;
				buffer++;
				bufsize--;
			}
			else
				ltemp = *left;
		}
		array++;
	}
	printf("done with sorting\n");
	for (*array = ltemp; lsize > 0; array++, buffer++)
		*array = *buffer;
	printf("[Done]: ");
	print_array(array, size);
}
