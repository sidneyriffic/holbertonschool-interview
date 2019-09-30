#include "lists.h"
#include <stdlib.h>

/**
 * is_palindrome - returns if a singly linked list is a palindrome
 * @head: head of linked list
 * Return: 1 if palindrome otherwise 0
 */
int is_palindrome(listint_t **head)
{
	size_t x, size;
	listint_t *ptr, **reverse;
	int odd;

	if (head == NULL || *head == NULL || (**head).next == NULL)
		return (1);
	for (ptr = *head, size = 0; ptr != NULL; size++)
		ptr = ptr->next;
	if (size % 2)
		odd = 1;
	else
		odd = 0;
	size = size / 2;
	reverse = malloc(sizeof(*reverse) * size);
	for (ptr = *head, x = size; x > 0; x--)
		ptr = ptr->next;
	if (odd)
		ptr = ptr->next;
	for (x = size; x > 0; x--, ptr = ptr->next)
		reverse[x - 1] = ptr;
	for (ptr = *head, x = 0; x < size; x++, ptr = ptr->next)
		if (ptr->n != reverse[x]->n)
			return (0);
	return (1);
}
