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
		*list = new;
		new->prev = new->next;
		new->next = new->prev;
	}	
	else
	{
		last = *list;
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
        if (!*list)
        {
                *list = new;
                new->prev = new->next;
                new->next = new->prev;
        }      
	else
        {       
                last = *list;
                new->next = *list;
                new->prev = last;
                last->next = (*list)->prev = new;
		*list = new;
        }
        return (new);
}

/**
 * _strlen - returns the length of a string
 * @s: the string to check
 *
 * Return: the length of a string as an int
 */
int _strlen(char *s)
{
	int counter;

	for (counter = 0; s[counter] != '\0'; counter++)
	{
		continue;
	}
	return (counter);
}
