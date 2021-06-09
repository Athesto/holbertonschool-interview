#include <stdio.h>
#include <stdlib.h>
#include "../lists.h"

/**
 * print_listint - print linked list
 * @head: head of list
 * Return: size of list
 */
size_t print_listint(const listint_t *head)
{
	const listint_t *runner;
	size_t n;

	runner = head;
	for (n = 0; runner; n++)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
	return (n);
}

/**
 * add_nodeint - add node at list
 * @head: reference to  pointer of the head of list
 * @n: input int
 * Return: pointer to new node
 *
 */
listint_t *add_nodeint(listint_t **head, int n)
{
	listint_t *new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);

	new->next = *head;
	new->n = n;

	*head = new;

	return (new);
}

/**
 * free_listint - free list
 * @head: pointer to head of the list
 *
 */
void free_listint(listint_t *head)
{
	listint_t *killer = head;

	while (killer)
	{
		head = head->next;
		free(killer);
		killer = head;
	}

}
