#include "holberton.h"

/**
 * wildcmp - compares two strings
 * @s1: the regular string
 * @s2: string with wildcard chars
 *
 * Return: 1 if identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s2 == '*')
	{
		if (all_stars(s2))
		{
			return (1);
		}
		else
		{
			s2 = move_s2(s2);
			s1 = move_s1(s1, s2);
		}
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}

/**
 * move_s1 - moves through string
 * @s1: the string to move through
 * @s2: the string to compare against
 *
 * Return: pointer to location in the string
 */
char *move_s1(char *s1, char *s2)
{
	if (*s1 == '\0')
		return (s1);
	else if (*s1 != *s2)
		return (move_s1(s1 + 1, s2));
	return (s1);
}

/**
 * move_s2 - moves through the string
 * @s2: the string to move through
 *
 * Return: pointer to location in the string
 */
char *move_s2(char *s2)
{
	if (*s2 == '\0')
		return (s2);
	else if (*s2 == '*')
		return (move_s2(s2 + 1));
	return (s2);
}
/**
 * all_stars - checks to see is string is all asterisks
 * @s2: the string to check
 *
 * Return: 1 if true 0 otherwise
 */
int all_stars(char *s2)
{
	if (*s2 == '\0')
		return (1);
	else if (*s2 == '*')
		return (all_stars(s2 + 1));
	return (0);
}
