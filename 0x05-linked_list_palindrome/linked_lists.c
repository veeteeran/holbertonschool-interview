#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - prints all elements of a listint_t list
 * @h: pointer to head of list
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	const listint_t *current;
	unsigned int n; /* number of nodes */

	current = h;
	n = 0;
	while (current != NULL)
	{
		printf("%i\n", current->n);
		current = current->next;
		n++;
	}

	return (n);
}

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @n: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *current;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}

	return (new);
}

/**
 * free_listint - frees a listint_t list
 * @head: pointer to list to be freed
 * Return: void
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

/**
 * list_length - counts nodes in list
 * @head: pointer to list
 * Return: length of list
 */
int list_length(listint_t *head)
{
	listint_t *mover;
	int nodes = 1;

	if (!head)
		return (0);

	mover = head;
	while (mover && mover->next)
	{
		mover = mover->next;
		nodes++;
	}

	return (nodes);
}

/**
 * check_nodes - loops through the list checking equality of nodes
 * @head: pointer to list
 * @first: length of first half of palindrome
 * @second: beginning of second half of palindrome
 * Return: 1 if palindrome, 0 if not
 */
int check_nodes(listint_t *head, int first, int second)
{
	int i, j;
	listint_t *first_mover, *second_mover;

	while (second_mover->next)
	{
		first_mover = head;
		for (i = 0; i < first; i++)
			first_mover = first_mover->next;

		second_mover = head;
		for (j = 0; j < second; j++)
			second_mover = second_mover->next;

		if (first_mover->n != second_mover->n)
			return (0);
	}

	if (!second_mover->next)
		return (1);
	return (check_nodes(head, first - 1, second + 1));
}
