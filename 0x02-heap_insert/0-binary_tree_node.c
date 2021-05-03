#include "binary_trees.h"
/**
 * binary_tree_node - Creates a binary tree node
 * @parent: pointer to the parent of the node
 * @value: value of the new node
 *
 * Description: When you create a node, it does no have any children
 * Return: A pointer to the new node or NULL if it fails
 *
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{

	binary_tree_t *node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
