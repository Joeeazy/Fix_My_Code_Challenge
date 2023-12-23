#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *prev, *next;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	current = *head;

	/* Special case: index is 0 */
	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	/* Traverse the list to find the node at the specified index */
	for (i = 0; i < index && current != NULL; i++)
		current = current->next;

	/* If the index is greater than the number of nodes */
	if (current == NULL)
		return (-1);

	prev = current->prev;
	next = current->next;

	/* Update the previous node's next pointer */
	if (prev != NULL)
		prev->next = next;

	/* Update the next node's previous pointer */
	if (next != NULL)
		next->prev = prev;

	free(current);

	return (1);
}
