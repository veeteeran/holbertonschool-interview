#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 1 if palindrom, 0 if not
 */
int is_palindrome(listint_t **head)
{
	int length;

	/* There is no list */
	if (!head)
		return (0);

	length = list_length(*head);
	/* Empty or list length of 1 is a palindrome */
	if (length <  2)
		return (1);

	if (length == 2)
	{
		/* Compare the two nodes */
		if ((*head)->n == (*head)->next->n)
			return (1);
		return (0);
	}

	return (check_nodes(*head, length));
}
