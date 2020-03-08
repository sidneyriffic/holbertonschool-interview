#include <stdlib.h>
#include <string.h>
#include "list.h"


/**
 * add_node_end - add node to end of circular doubly linked list
 *
 * @list: list to add to (null list == new list)
 * @str: str to put into node
 *
 * Return: address of new list or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new, *end;

	if (list == NULL)
		return (NULL);
	if (*list != NULL)
	{
		end = (*list)->prev;
		if (end == NULL)
			return (NULL);
	}
	new = malloc(sizeof(list));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	if (new->str == NULL && str != NULL)
	{
		free(new);
		return (NULL);
	}
	if (*list == NULL)
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}
	new->next = *list;
	new->prev = end;
	end->next = new;
	(*list)->prev = new;
	return (new);
}

/**
 * add_node_begin - add node to end of circular doubly linked list
 *
 * @list: list to add to (null list == new list)
 * @str: str to put into node
 *
 * Return: address of new list or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new = add_node_end(list, str);

	if (new == NULL)
		return (NULL);
	*list = (*list)->prev;
	return (new);
}
