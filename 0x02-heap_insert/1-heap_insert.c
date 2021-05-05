#include "binary_trees.h"
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
	if (*root == NULL)
		return (*root = binary_tree_node(*root, value));

	if ((*root)->left && (*root)->right)
	{
		return (heap_insert(&(*root)->left, value));
	}

	if ((*root)->left && (*root)->right == NULL)
		return ((*root)->right = binary_tree_node(*root, value));

	return ((*root)->left = binary_tree_node(*root, value));
}

