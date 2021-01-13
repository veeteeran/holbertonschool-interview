#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void print_grid(int grid[3][3]);
void topple_all(int grid[3][3], int temp[3][3]);
void add_sand(int grid[3][3], int temp[3][3]);
bool is_stable(int grid[3][3], int temp[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /* SANDPILES_H */
