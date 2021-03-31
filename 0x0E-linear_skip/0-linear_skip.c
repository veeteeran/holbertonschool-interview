#include "search.h"
int get_list_length(skiplist_t *list);

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located or NULL
 **/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *h = NULL;
	skiplist_t *t = NULL;
	int last_index;

	if (!list)
		return (NULL);

	h = list;
	t = list->express;
	while (t)
	{
		if (t->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n", h->index, t->index);
			break;
		}
		else
		{
			printf("Value checked at index [%lu] = [%d]\n", t->index, t->n);
			h = h->express;
			t = t->express;
		}
	}

	if (!t)
	{
		last_index = get_list_length(list) - 1;
		printf("Value found between indexes [%lu] and [%d]\n", h->index, last_index);
	}

	while (h)
	{
		if (h->n > value)
			break;

		printf("Value checked at index [%lu] = [%d]\n", h->index, h->n);

		if (h->n == value)
			return (head);

		head = head->next;
	}
	return (NULL);
}

/**
 * get_list_length - gets lenght of the list
 * @list: pointer to head of the skip_list
 *
 * Return: list length
 **/
int get_list_length(skiplist_t *list)
{
	int length;
	skiplist_t *mover;

	for (mover = list, length = 0; mover; mover = mover->next, length++)
		continue;

	return (length);
}
