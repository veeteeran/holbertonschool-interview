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

	if (!list || list->n > value)
		return (NULL);
	h = list;
	t = list->express;
	while (t)
	{
		printf("Value checked at index [%lu] = [%d]\n", t->index, t->n);
		if (t->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n", h->index, t->index);
			break;
		}
		h = h->express;
		t = t->express;
	}
	if (!t)
	{
		for (t = h; t->next; t = t->next)
			continue;
		printf("Value found between indexes [%lu] and [%lu]\n", h->index,t->index);
	}
	while (h)
	{
		printf("Value checked at index [%lu] = [%d]\n", h->index, h->n);
		if (h->n == value)
			return (h);
		h = h->next;
	}
	return (NULL);
}
