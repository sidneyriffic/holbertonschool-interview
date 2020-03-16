#include "sort.h"
#include <stdlib.h>


/**
 * radix_sort - radix sort a given array
 *
 * @array: array to size
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int *buff, *from, *to, *tmp, digit, place, end;
	size_t idx, toidx;

	buff = malloc(size * sizeof(int));
	if (buff == NULL)
		return;
	for (place = 1, from = array, to = buff, end = 0; place > 0 && !end;)
	{
		toidx = 0;
		end = 1;
		for (digit = 0; digit < 10; digit++)
			for (idx = 0; idx < size; idx++)
				if (from[idx] / place % 10 == digit)
				{
					if (digit > 0)
						end = 0;
					to[toidx++] = from[idx];
				}
		if (place == 1000000000)
			end = 1;
		if (!end)
		{
			tmp = to;
			to = from;
			from = tmp;
			place *= 10;
			print_array(from, size);
		}
	}
	if (to != array)
		for (idx = 0; idx < size; idx++)
			from[idx] = to[idx];
	free(buff);
}
