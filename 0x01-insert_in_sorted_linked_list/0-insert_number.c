#include "lists.h"
/**
 * insert_node - insert node into position
 * @head: head of linked list
 * @number: value
 * Return: Pointer to the new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *runner;
	listint_t *node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->n = number;

	if (*head == NULL || (*head)->n > number)
	{
		node->next = *head;
		*head = node;
		return (node);
	}

	for (runner = *head; runner != NULL; runner = runner->next)
	{
		if (runner->next == NULL || runner->next->n > number)
		{
			node->next = runner->next;
			runner->next = node;
			break;
		}
	}
	return (node);
}
