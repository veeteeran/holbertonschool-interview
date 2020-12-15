#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer of first node of listint_t list
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number) {
	/* declare new_node, current assign to NULL */
	listint_t *new;
	listint_t *current;

	/* NULL check **head */
	if (*head == NULL)
		return (NULL);

	/* malloc sizeof listint_t, NULL check new_node */
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	/* initialize new_node->n and new_node->next */
	new->n = number;
	new->next = NULL;

	/* NULL check *head insert */
	if (head == NULL) {
		*head = new;
		return (new);
	}

	/* Assign current to *head */
	current = *head;
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
