#include "regex.h"
#include <stdio.h>

int get_len(const char *str);

/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: can be empty, may contain any ASCII character except of . and *
 * @pattern: can be empty, may contain any ASCII character, including . and *
 *
 * Return: 1 if there's a match, 0 if not
 **/

int regex_match(char const *str, char const *pattern)
{
	int i = 0, j = 0;
	int str_len = get_len(str);
	int p_len = get_len(pattern);
	/* !str and !pattern ? return 1 */
	if ((!str && !pattern) || (str[0] == ' ' && pattern[0] == ' '))
		return (1);
	/* !str and pattern ? return 0 */
	/* str and !pattern ? return 1(not sure here) */
	if ((!str && pattern) || (str && !pattern))
		return (0);
	/* Loop through each string */
	while (str[i] || pattern[j])
	{
		/* str[i] == pattern[j] ? increment both continue */
		if (str[i] == pattern[j])
		{
			i++;
			j++;
		}
		else if (str[i] != pattern[j])
		{
		/* pattern[j] == '.' ? increment both */
			if (pattern[j] == '.')
			{
				i++;
				j++;
			}
		/* pattern[j] == '*' ? check prev char */
			else if (pattern[j] == '*')
			{
			/* prev char == '.' ? return 1 */
				if (pattern[j - 1] == '.')
					if (str[str_len - 1] ==
					    pattern[p_len - 1] ||
					    pattern[p_len - 1] == '.' ||
					    pattern[p_len - 1] == '*')
						return (1);
			/*   else while str[i] == pattern[j - 1] */
				while (str[i] == pattern[j - 1])
					i++;
				j++;
			}
			else if (pattern[j + 1] == '*')
				j += 2;
			else
				return (0);
		}
	}
	return (1);
}

/**
 * get_len - gets the length of a string
 * @str: string to process
 *
 * Return: length of string
 **/
int get_len(const char *str)
{
	int i = 0;

	while (str[i])
		i++;

	return (i);
}
