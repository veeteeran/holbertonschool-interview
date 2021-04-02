#include "search.h"
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
	int skip_value, last_index;

	if (!list || list->n > value)
		return (NULL);
	h = list;
	t = list->express;
	skip_value = t->index - h->index;
	while (t)
	{
		printf("Value checked at index [%lu] = [%d]\n", t->index, t->n);
		if (t->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n", h->index, t->index);
			break;
		}
		else
		{
			h = h->express;
			t = t->express;
		}
	}
	if (!t)
	{
		last_index = h->index + (skip_value - 1);
		printf("Value found between indexes [%lu] and [%d]\n", h->index, last_index);
	}
	while (h)
	{
		printf("Value checked at index [%lu] = [%d]\n", h->index, h->n);
		if (h->n > value)
			break;
		if (h->n == value)
			return (h);
		h = h->next;
	}
	return (NULL);
}
