#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - radix sort an integer array
 *
 * @array: array to sort
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int *buffer, *temp, divisor, digit, early;
	size_t i, idx, bufidx;

	if (size == 0)
		return;
	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;
	for (i = 0, divisor = 1; ; i++)
	{
		bufidx = 0;
		for (early = 1, digit = 0; bufidx < size && digit < 10; digit++)
			for (idx = 0; idx < size; idx++)
			{
				if (array[idx] >= divisor)
					early = 0;
				if (array[idx] / divisor % 10 == digit)
					buffer[bufidx++] = array[idx];
			}
		temp = buffer;
		buffer = array;
		array = temp;
		divisor *= 10;
		if ((early == 1 && divisor > 10) || divisor < 0 || divisor % 10)
			break;
		print_array(array, size);
	}
	if (!(i % 2))
	{
		temp = buffer;
		buffer = array;
		array = temp;
		for (i = 0; i < size; i++)
			array[i] = buffer[i];
	}
	free(buffer);
}
