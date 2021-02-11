#include "palindrome.h"
/*
 * is_palindrome - checks if unsigned integer is a palindrome
 * @n: number to check
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(unsigned long n)
{
	unsigned long bizzaro = 0, superboy;

	/* Clone of n so we don't mutate the original */
	superboy = n;
	while (superboy)
	{
		/* Create a backwards version of n */
		bizzaro = (bizzaro * 10) + (superboy % 10);
		superboy /= 10;
	}
	/* Compare the original with the backwards copy */
	return (bizzaro == n);
}
