#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - insert a node in a sorted singly linked list
 * @head: head of list
 * @number: number to insert
 *
 * Return: address of new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *ptr;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(new_node));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number;
	if (*head == NULL || number < (**head).n)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	ptr = *head;
	while (ptr->next != NULL && number > ptr->next->n)
		ptr = ptr->next;
	new_node->next = ptr->next;
	ptr->next = new_node;
	return (new_node);
}
