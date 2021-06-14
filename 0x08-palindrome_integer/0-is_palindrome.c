static int recursive_check(unsigned long, unsigned long *);

/**
 * is_palindrome - check is a int is palindrome
 * @n: input number
 * Return: 1 if is palindrome, 0 otherwhise
 */
int is_palindrome(unsigned long n)
{
	return (recursive_check(n, &n));
}

/**
 * recursive_check - recurson check
 * @forward: number reduced to forward
 * @backward: number reduced to backward
 * Return: 1 recursive, 0 otherwiswe
 */
static int recursive_check(unsigned long forward, unsigned long *backward)
{
	int is_pal = 1;

	if (forward > 10)
		is_pal = recursive_check(forward / 10, backward);

	is_pal = is_pal && (forward % 10 == *backward % 10);
	*backward /= 10;

	return (is_pal);
}
