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
	int i, j, row = 3, col = 3;
	int corner, edge, middle;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}

	while (true)
	{
		corner = grid1[0][0];
		edge = grid1[0][1];
		middle = grid1[1][1];
		if (corner <= 3 && edge <= 3 && middle <= 3)
			break;

		printf("=\n");
		print_grid(grid1);
		/* Only run functions when original assignments are true */
		if (corner > 3)
			corner_check(grid1);
		if (edge > 3)
			edge_check(grid1);
		if (middle > 3)
			middle_check(grid1);

	}
}

/**
 * corner_check - topples each corner, adds to edge
 * @grid: 3x3 grid
 *
 * Return: void
 */
void corner_check(int grid[3][3])
{
	int corner = grid[0][0];

	if (corner > 3)
	{
		/* Corners */
		grid[0][0] -= 4;
		grid[0][2] -= 4;
		grid[2][0] -= 4;
		grid[2][2] -= 4;
		/* Edges */
		grid[0][1] += 2;
		grid[1][0] += 2;
		grid[1][2] += 2;
		grid[2][1] += 2;
	}
}

/**
 * edge_check - topples each edge, adds to corners and middle
 * @grid: 3x3 grid
 *
 * Return: void
 */
void edge_check(int grid[3][3])
{
	int edge = grid[0][1];

	if (edge > 3)
	{
		/* Edges */
		grid[0][1] -= 4;
		grid[1][0] -= 4;
		grid[1][2] -= 4;
		grid[2][1] -= 4;
		/* Corners */
		grid[0][0] += 2;
		grid[0][2] += 2;
		grid[2][0] += 2;
		grid[2][2] += 2;
		/* Middle */
		grid[1][1] += 4;
	}
}

/**
 * middle_check - topples the middle, adds to edges
 * @grid: 3x3 grid
 *
 * Return: void
 */
void middle_check(int grid[3][3])
{
	int middle = grid[1][1];

	if (middle > 3)
	{
		/* Middle */
		grid[1][1] -= 4;
		/* Edges */
		grid[0][1] += 1;
		grid[1][0] += 1;
		grid[1][2] += 1;
		grid[2][1] += 1;
	}
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
