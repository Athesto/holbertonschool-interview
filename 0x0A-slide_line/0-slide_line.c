#include "slide_line.h"
#define pos(i) (line[(direction == SLIDE_LEFT) ? (i) : ((int) size - 1 - (i))])

/**
 * slide_line - reproduce the 2048 game(NSFW !!) mechanics
 * on a single horizontal line.
 * @line: points to an array of integers
 * @size: size of array
 * @direction: merged direction, SLIDE_LEFT or SLIDE_RIGHT
 * Return: return 1 upon success, or 0 upon failure
 *
 */
int slide_line(int *line, size_t size, int direction)
{
	int fwd, bwd, wasAdded;

	wasAdded = 0;
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	for (fwd = 1; fwd < (int)size; fwd++)
	{

		if (fwd < (int) size && pos(fwd) == 0)
			continue;

		bwd = fwd - 1;
		if (pos(bwd) == 0 || pos(bwd) == pos(fwd))
		{
			while (bwd > 0 && pos(bwd) == 0)
				bwd--;
			if (pos(bwd) == pos(fwd) && wasAdded == 0)
			{
				pos(bwd) += pos(fwd);
				wasAdded = 1;
			}
			else
			{
				if (pos(bwd) == 0)
					pos(bwd) += pos(fwd);
				else
					pos(bwd + 1) += pos(fwd);
				wasAdded = 0;
			}
			pos(fwd) = 0;
		}
	}
	return (1);
}
