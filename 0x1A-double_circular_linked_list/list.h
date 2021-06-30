#ifndef _LIST_H_
#define _LIST_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/**
 * struct List - doubly linked list
 * @str: string - (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

#endif /* _LIST_H_ */
