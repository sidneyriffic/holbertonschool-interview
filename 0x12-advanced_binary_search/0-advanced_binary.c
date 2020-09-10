#include <stdio.h>

/**
 * _recur_binary_search - recursive binary search an integer array and
 * return the address of first value.
 *
 * @array: array to search
 * @size: size of array
 * @value: value to find
 *
 * Return: first address of value in array
 */
int *_recur_binary_search(int *array, size_t size, int value)
{
	size_t i;

	if (size == 1 && array[0] == value)
		return (array);
	printf("Searching in array: %d", array[0]);
	for (i = 1; i < size; i++)
		printf(", %d", array[i]);
	printf("\n");
	if (size == 1)
		return (NULL);
	if (array[size / 2 - 1] >= value)
		return (_recur_binary_search(array, size / 2 + size % 2,
					     value));
	else
		return (_recur_binary_search(array + size / 2 + size % 2,
					     size / 2, value));
}

/**
 * advanced_binary - check array existence and start recursive binary search
 * function to return first instance of a value in an array.
 *
 * @array: array to search
 * @size: size of array
 * @value: value to find
 *
 * Return: index of element in array
 */
int advanced_binary(int *array, size_t size, int value)
{
	int *value_addr;

	if (array == NULL || size == 0)
		return (-1);
	value_addr = _recur_binary_search(array, size, value);
	if (value_addr == NULL)
		return (-1);
	return (value_addr - array);
}
