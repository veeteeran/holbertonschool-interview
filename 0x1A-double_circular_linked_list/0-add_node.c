#include "list.h"

int _strlen(char *s);
/**
 * add_node_end - add to end of circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 **/

List *add_node_end(List **list, char *str)
{
	List *new, *last;

	if (!list)
		return (NULL);

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);

	new->prev = NULL;
	new->next = NULL;
	new->str = strdup(str);
	if (!(*list))
	{
		new->next = new->prev = new;
		*list = new;
	}
	else
	{
		last = (*list)->prev;
		new->next = *list;
		(*list)->prev = new;
		new->prev = last;
		last->next = new;
	}
	return (new);
}

/**
 * add_node_begin - add to beginning of circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 **/
List *add_node_begin(List **list, char *str)
{
	List *new, *last;

	if (!list)
		return (NULL);

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);
        
	new->prev = NULL;
	new->next = NULL;
	new->str = strdup(str);
	if (!(*list))
	{
		new->prev = new->next = new;
		*list = new;
	}
	else
	{       
		last = (*list)->prev;
		last->next = new;
		new->prev = last;
		new->next = *list;
		(*list)->prev = new;
		last = *list;
		*list = new;
	}
	return (new);
}
