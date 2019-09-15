#include "lists.h"

/**
 * check_cycle - checks a linked list for a cycle
 *
 * @list: linked list to check for cycle
 *
 * Return: 0 if no cycle, 1 if cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *fast, *slow;

	if (list == NULL)
		return (0);
	fast = slow = list;
	do {
		fast = fast->next;
		if (fast == NULL)
			return (0);
		fast = fast->next;
		if (fast == NULL)
			return (0);
		slow = slow->next;
	} while (fast != slow);
	return (1);
}
