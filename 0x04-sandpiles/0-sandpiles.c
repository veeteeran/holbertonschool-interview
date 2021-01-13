#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: 3x3 grid added to and printed
 * @grid2: 3x3 grid adding to grid1
 *
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, temp[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	bool stable = false;

	/* Adds the two grids */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}

	while (!stable)
	{
		printf("=\n");
		print_grid(grid1);

		topple_all(grid1, temp);
		add_sand(grid1, temp);
		stable = is_stable(grid1, temp);
	}
}

/**
 * topple_all - topples every value greater than 3
 * @grid: 3x3 grid
 * @temp: 3x3 grid
 *
 * Return: void
 */
void topple_all(int grid[3][3], int temp[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			temp[i][j] = grid[i][j];
			if (temp[i][j] > 3)
				temp[i][j] -= 4;
		}
	}
}

/**
 * add_sand - add one grain of sand from grid to temp cells
 * @grid: 3x3 grid
 * @temp: 3x3 grid
 *
 * Return: void
 */
void add_sand(int grid[3][3], int temp[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				if (i - 1 >= 0)
					temp[i - 1][j] += 1;
				if (i + 1 < 3)
					temp[i + 1][j] += 1;
				if (j - 1 >= 0)
					temp[i][j - 1] += 1;
				if (j + 1 < 3)
					temp[i][j + 1] += 1;
			}
		}
	}
}

/**
 * is_stable - copy temp back to grid, check if grid is stable
 * @grid: 3x3 grid
 * @temp: 3x3 grid
 *
 * Return: true if stable false otherwise
 */
bool is_stable(int grid[3][3], int temp[3][3])
{
	int i, j;
	bool stable = true;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] = temp[i][j];

			if (temp[i][j] > 3)
				stable = false;

			temp[i][j] = 0;
		}
	}

	return (stable);
}

/**
 * print_grid - prints the grid
 * @grid: 3x3 grid
 *
 * Return: void
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
			printf(" ");
			printf("%d", grid[i][j]);
		}
			printf("\n");
	}
}
