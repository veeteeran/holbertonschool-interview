#include "sandpiles.h"

void corner_check(int grid[3][3]);
void edge_check(int grid[3][3]);
void middle_check(int grid[3][3]);
static void print_grid(int grid[3][3]);

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, row = 3, col = 3;
	int corner, edge, middle;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}
	
/*	printf("=\n");
	print_grid(grid1);
*/
	while (true)
	{
		corner = grid1[0][0];
		edge = grid1[0][1];
		middle = grid1[1][1];
		if (corner <= 3 && edge <= 3 && middle <= 3)
			break;
		else
		{
			printf("=\n");
                	print_grid(grid1);
		}

		corner_check(grid1);
		edge_check(grid1);
		middle_check(grid1);

/*		printf("=\n");
		print_grid(grid1);
*/
	}
}

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

void  edge_check(int grid[3][3])
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
/*
static void print_grid_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid1[i][j]);
        }

        printf(" %c ", (i == 1 ? '+' : ' '));

        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid2[i][j]);
        }
        printf("\n");
    }
}
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
