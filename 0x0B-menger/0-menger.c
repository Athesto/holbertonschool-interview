#include "menger.h"
#define IMAGE '#'
#define EMPTY ' '
#define DEBUG 0

char **initSpace(int level);
void clearSpace(char **matrix, int level);
void printSpace(char **matrix, int level);
void freeSpace(char **matrix, int level);
/**
 * menger - draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
 * Notes:
 *  - If level is lower than 0, your function must do nothing
 *  -
 *
 */
void menger(int level)
{
	char **matrix;

	if (level < 0)
		return;

	matrix = initSpace(level);
	if (!matrix)
		return;

	clearSpace(matrix, level);
	printSpace(matrix, level);
	freeSpace(matrix, level);
}


/**
 * initSpace - create matrix for the level
 * @level: input value
 * Return: pointer to the matrix
 */
char **initSpace(int level)
{
	size_t i, j, size = pow(3, level);
	char **matrix;

	matrix = malloc(size * sizeof(*matrix));
	if (!matrix)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		matrix[i] = malloc(size * sizeof(**matrix));
		if (!matrix[i])
		{
			for (j = 0; j < i; j++)
				free(matrix[j]);
			free(matrix);
			return (NULL);
		}
		memset(matrix[i], IMAGE, size);
	}
	return (matrix);

}

/**
 * clearSpace - run throught the matrix and clear the [1][1] for each level
 * @matrix: reference to matrix
 * @level: input level
 */
void clearSpace(char **matrix, int level)
{
	size_t i, j, k, size = pow(3, level);
	int valid_i = 1, valid_j;

	for (k = 0; k < (size_t)level; k++)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				valid_i = ((int)(j / pow(3, k))) % 3 == 1;
				valid_j = ((int)(i / pow(3, k))) % 3 == 1;
				if (valid_i && valid_j)
					matrix[i][j] = EMPTY;
			}
		}
	}
}

/**
 * printSpace - print matrix
 * @matrix: pointer to matrix
 * @level: input level
 */
void printSpace(char **matrix, int level)
{
	size_t i, j, size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (DEBUG && !(j == 0))
				printf(", ");
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}
}

/**
 * freeSpace - take matrix and free pointers
 * @matrix: double pointer for the matrix of the output
 * @level: level of the sponge
 */
void freeSpace(char **matrix, int level)
{
	size_t i, size = pow(3, level);

	for (i = 0; i < size; i++)
		free(matrix[i]);
	free(matrix);
}
