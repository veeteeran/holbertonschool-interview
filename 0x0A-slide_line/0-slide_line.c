#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers based on 2048 game
 * @line: array of integers
 * @size: soze of array
 * @direction: direction of slide
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (size < 1 || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else
		slide_right(line, size);

	return (1);
}

/**
 * slide_left - helper function to slide left
 * @line: array of integers
 * @size: size of array
 *
 * Return: void
 */
void slide_left(int *line, size_t size)
{
	int i, j;

	for (i = 0, j = i + 1; j < (int)size; j++)
	{
		if (line[j] == 0)
			continue;
		if (line[i] == line[j])
		{
			line[i] += line[j];
			line[j] = 0;
			i++;
		}
		if (line[i] != line[j])
		{
			if (line[i] == 0)
			{
				line[i] += line[j];
				line[j] = 0;
			}
			else
			{
				i++;
				if (i != j)
				{
					line[i] += line[j];
					line[j] = 0;
				}
			}
		}
	}
}

/**
 * slide_right - helper function to slide right
 * @line: array of integers
 * @size: soze of array
 *
 * Return: void
 */
void slide_right(int *line, size_t size)
{
	int i, j;

	for (i = (int)size - 1, j = i - 1; j >= 0; j--)
	{
		if (line[j] == 0)
			continue;
		if (line[i] == line[j])
		{
			line[i] += line[j];
			line[j] = 0;
			i--;
		}
		if (line[i] != line[j])
		{
			if (line[i] == 0)
			{
				line[i] += line[j];
				line[j] = 0;
			}
			else
			{
				i--;
				if (i != j)
				{
					line[i] += line[j];
					line[j] = 0;
				}
			}
		}
	}
}
