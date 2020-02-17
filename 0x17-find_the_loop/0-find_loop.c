#include "lists.h"

/**
 * find_listint_loop - checks a linked list for a cycle
 *
 * @head: linked list to check for cycle
 *
 * Return: 0 if no cycle, 1 if cycle
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast, *slow;

	if (head == NULL)
		return (0);
	fast = slow = head;
	do {
		fast = fast->next;
		if (fast == NULL)
			return (NULL);
		fast = fast->next;
		if (fast == NULL)
			return (NULL);
		slow = slow->next;
	} while (fast != slow);
	for (fast = head; fast != slow; fast = fast->next)
		slow = slow->next;
	return (fast);
}
