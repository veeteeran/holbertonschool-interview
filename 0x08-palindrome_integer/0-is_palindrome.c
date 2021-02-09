#include "palindrome.h"
/*
 * is_palindrome - checks if unsigned integer is a palindrome
 * @n: number to check
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(unsigned long n)
{
	unsigned long divisor = 1000000000000000000;
	unsigned long first_digit = n / divisor;
	unsigned long mod = 10, last_digit;

	if (n < 10)
		return (1);

	/* Find tens place */
	while (first_digit == 0)
	{
		divisor /= 10;
		first_digit = n / divisor;
	}

	last_digit =  n % mod;
	while (first_digit == last_digit)
	{
		first_digit = n / divisor;
		last_digit =  n % mod;

		/* Get rid of first digit */
		n -= divisor * first_digit;
		/* Get rid of first digit */
		n /= 10;
		/* Reduce divisor by two tens places */
		divisor /= 100;
		if (divisor < mod)
			return (1);
	}
	return (0);
}
