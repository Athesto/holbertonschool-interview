#include "sandpiles.h"
#include <stdio.h>

/**
 * copy_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void copy_grid(int grid1[3][3], int grid2[3][3])
{
	int i,j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid2[i][j];
}

/**
 * copy_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static int is_stable(int grid[3][3])
{
	int i,j, stable = 1;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			stable = stable && grid[i][j] <= 3;
	return (stable);
}


/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
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

/**
 * sandpiles_sum - sum of elements
 * grid1 - input
 * grid2 - sum element
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, stable = 0, *cell;

	/* sum  */
	stable = 1;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cell =  &grid1[i][j];
			*cell =  grid1[i][j] + grid2[i][j];
			grid1[i][j] = *cell;
			grid2[i][j] = *cell;
			if (*cell > 4)
				stable = 0;
		}
	}
	stable = is_stable(grid1);
	while (!stable)
	{
		stable = 1;
		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				cell =  &grid1[i][j];

				if (grid2[i][j] >= 4)
				{
					*cell =  *cell - 4;
					if (i < 2)
					{
						cell = &grid1[i + 1][j];
						(*cell)++;
					}
					if (j < 2)
					{
						cell = &grid1[i][j + 1];
						(*cell)++;
					}
					if (i > 0)
					{
						cell = &grid1[i - 1][j];
						(*cell)++;
					}
					if (j > 0)
					{
						cell = &grid1[i][j - 1];
						(*cell)++;
					}
				}
			}
		stable = is_stable(grid1);
		copy_grid(grid2, grid1);
	}

}

