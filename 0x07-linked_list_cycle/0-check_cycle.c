#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to linked list
 * Return: 1 if cycle exist, 0 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *tortoise, *hare;

	if (!list)
		return (0);

	tortoise = hare = list;
	while (1)
	{
		/* tortoise moves one node, hare moves two*/
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (tortoise == hare)
			return (1);
		/* Pointer to null means no cycle */
		if (!tortoise || (!hare || !hare->next))
			break;
	}
	return (0);
}
