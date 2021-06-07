#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - print linked list
 * @head: head of list
 */
void print_listint(listint_t *head)
{
	listint_t *runner;

	runner = head;
	while (runner)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
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
