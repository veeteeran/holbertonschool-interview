#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: number to insert
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	if (*head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (head == NULL)
	{
		*head = new;
		return (new);
	}

	current = *head;
	if (new->n < current->n)
	{
		*head = new;
		new->next = current;
		return (new);
	}	
	/* loop while current->next != NULL and number > current->next->n */
	while (current->next != NULL && number > current->next->n)
		/* update current to current->next */
		current = current->next;

	/* connect new_node->next to current->next */
	new->next = current->next;
	/* current->next = new_node */
	current->next = new;

	/* Return new */
	return (new);
}
