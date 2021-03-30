#include "search.h"
int get_skip_index(skiplist_t *list);
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
	skiplist_t *mover = NULL;
	int skip_index;
	int i, last_index;

	if (!list)
		return (NULL);

	skip_index = get_skip_index(list);
	i = skip_index;
	mover = list;
	last_index = get_list_length(list) - 1;
	while (mover->express)
	{
		printf("Value checked at index [%d] = [%d]\n", i, mover->express->n);
		if (mover->express->n <= value)
		{
			mover = mover->express;
			i += skip_index;
		}
		else
		{
			i -= skip_index;
			printf("Value found between indexes [%d] and [%d]\n", i, i + 4);
			break;
		}

	}
	if (!mover->express)
	{
		printf("Value found between indexes [%d] and [%d]\n", i - 4, last_index);
		i -= skip_index;
	}

	while (mover)
	{
		printf("Value checked at index [%d] = [%d]\n", i, mover->n);
		if (mover->n == value)
			return (mover);

		mover = mover->next;
		i++;
	}

	return (NULL);
}

/**
 * get_skip_index - gets the skip value
 * @list: pointer to head of the skip_list
 *
 * Return: skip value
 **/
int get_skip_index(skiplist_t *list)
{
	int skip_value = 0;
	int exp_n;
	skiplist_t *mover;

	mover = list;
	exp_n = list->express->n;
	while (mover)
	{
		if (mover->n == exp_n)
			return (skip_value);

		skip_value++;
		mover = mover->next;
	}

	return (-1);
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
