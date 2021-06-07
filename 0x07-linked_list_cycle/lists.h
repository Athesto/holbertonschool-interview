#ifndef _LIST_H_
#define _LIST_H_

/**
 * struct listint_s - linked list
 * @n: val
 * @next: next node
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;

} listint_t;

listint_t *add_nodeint(listint_t **, int);
void print_listint(listint_t *);
void free_listint(listint_t *);
int check_cycle(listint_t *);

#endif /* _LIST_H_ */
