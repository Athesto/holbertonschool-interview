#include "lists.h"
/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: reference of a list
 * Return: 1 if is a linked, 0 Otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *runner_a, *runner_b;
	int i, j, len = 0;

	if (*head == NULL)
	{
		return (1);
	}


	runner_a = *head;
	while (runner_a->next)
	{
		len++;
		runner_a = runner_a->next;
	}

	runner_a = *head;
	for (i = 0; i <= len / 2; i++)
	{
		runner_b = *head;
		for (j = 0 ; j < len - i; j++)
			runner_b = runner_b->next;

		if (runner_a->n != runner_b->n)
			return (0);

		runner_a = runner_a->next;
	}
	return (1);

}
