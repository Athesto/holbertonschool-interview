#include "lists.h"
#include <stddef.h> /* NULL */

/**
 * check_cycle - check if linkedlist is cyclic
 * @head: pointer to head of the list
 *
 * Return: 1 if is cyclic or 0 Otherwise
 */
int check_cycle(listint_t *head)
{
	listint_t *turtle, *rabbit;

	if (head == NULL)
		return (1);

	turtle = rabbit = head;
	while (rabbit && rabbit->next)
	{
		turtle = turtle->next;
		rabbit = rabbit->next->next;
		if (rabbit == turtle)
			return (1);
	}
	return (0);

}
