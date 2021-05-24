#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
int _strlen(char *s);
int _isdigit(int c);
int _atoi(char *s);

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: array of arguements
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	int i, j, num1, num2;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 0; i < _strlen(argv[1]); i++)
	{
		if (!_isdigit(argv[1][i]))
		{
			printf("Error\n");
			exit(98);
		}
	}

	for (j = 0; j < _strlen(argv[2]); j++)
	{
		if (!_isdigit(argv[2][j]))
		{
			printf("Error\n");
			exit(98);
		}
	}
	num1 = _atoi(argv[1]);
	num2 = _atoi(argv[2]);
	printf("%d\n", num1 * num2);

	return (0);
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

/**
 * _isdigit - Check for a digit 0-9
 * @c: The int to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	if ((c >= 0 && c <= 9) || (c >= 48 && c <= 57))
		return (1);
	return (0);
}

/**
 * _atoi - convert a string to an int
 * @s: the string to convert
 *
 * Return: an int representation of the string
 */
int _atoi(char *s)
{
	int digit = 0, num = 0, b_10 = 1;
	int start, end, ndx = 0, negative = 0;

	if (s[ndx] == '\0')
		return (0);
	while (s[ndx] && !(digit))
	{
		if (s[ndx] == '-')
			negative++;
		else if (s[ndx] >= '0' && s[ndx] <= '9')
			digit = 1;
		ndx++;
	}
	start = ndx - 1;
	while (s[ndx] && digit)
	{
		if (s[ndx] < '0' || s[ndx] > '9')
		{
			digit = 0;
			ndx--;
		}
		ndx++;
	}
	end = ndx - 1;
	while (end >= start)
	{
		num += ((s[end] - '0') * b_10);
		b_10 *= 10;
		end--;
	}
	if (negative != 0 && negative % 2 != 0)
		num *= -1;
	return (0 + num);
}
