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
	skiplist_t *head = NULL;
	skiplist_t *tail = NULL;
	int last_index;

	if (!list)
		return (NULL);

	head = list;
	tail = list->express;
	while (tail)
	{
		if (tail->n >= value)
		{
			printf("Value found between indexes [%zu] and [%zu]\n",head->index, tail->index);
                        break;
		}
		else
		{
			printf("Value checked at index [%zu] = [%d]\n", tail->index, tail->n);
			head = head->express;
                        tail = tail->express;
		}
	}
	
	if (!tail)
	{
		last_index = get_list_length(list) - 1;
		printf("Value found between indexes [%zu] and [%d]\n",head->index, last_index);
	}

	while (head)
	{
		if (head->n > value)
                        break;

		printf("Value checked at index [%zu] = [%d]\n", head->index, head->n);

		if (head->n == value)
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
