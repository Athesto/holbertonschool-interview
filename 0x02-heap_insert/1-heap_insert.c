#include "binary_trees.h"

void get_level(int size, int *level, int *position);

/**
 * heap_insert - insert value into a Max Binary Heap
 * @root: a reference of a pointer to the root of the Heap
 * @value: the value to store in the node to be inserted
 *
 * Description: If the root is NULL. The created node becoma the root
 * The program respect the Max Heap
 * Return: a pointer to inserted node or NULL of failure
 */
heap_t *heap_insert(heap_t **root, int value)
{

	int level, r_pos, size;
	heap_t *runner = *root;

	if (*root == NULL)
		return (*root = binary_tree_node(*root, value));

	size = count_nodes(*root);
	get_level(size, &level, &r_pos);
	/* printf("counter=%d, level=%d, pos=%d\n", size, level, r_pos); */

	while (level > 1)
	{
		if (((r_pos >> (level - 1)) & 1) == 1)
			runner = runner->right;
		else
			runner = runner->left;
		level--;
	}
	if (((r_pos >> (level - 1)) & 1) == 1)
	{
		runner->right = binary_tree_node(runner, value);
		runner = runner->right;
	}
	else
	{
		runner->left = binary_tree_node(runner, value);
		runner = runner->left;
	}
	while (runner->parent && runner->parent->n < runner->n)
	{
		runner->parent->n =  runner->parent->n ^ runner->n;
		runner->n =  runner->n ^ runner->parent->n;
		runner->parent->n =  runner->parent->n ^ runner->n;
		runner = runner->parent;
	}


	return (runner);


}

/**
 * count_nodes - count number of nodes
 * @root: pointer to root of tree
 * Return: number of nodes
 */
int count_nodes(heap_t *root)
{

	if (root == NULL)
		return (0);
	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * get_level - get the level of and the position of a new element
 * @size: an int with the number of nodes
 * @level: an int reference for the level (every level is a new child)
 * @position: an int reference for the relative position in the level
 *
 * Example:
 * Level          index         position in the Level
 *   0              0                     0
 *   1          1       2             0       1
 *   2        3   4   5   6         0   1   2   3
 *   3       7 8 9 A B C D E       0 1 2 3 4 5 6 7
 */
void get_level(int size, int *level, int *position)
{
	int ref = 1;


	for (*level = 0; size >= ((ref * 2) - 1); ref = ref * 2)
	{
		(*level)++;
	}


	*position = size - (ref - 1);
}
