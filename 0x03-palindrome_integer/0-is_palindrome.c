/**
 * is_palindrome - returns if an integer's digits are a palindrome.
 * @n: integer to check
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(unsigned long n)
{
	unsigned int x, size, reverse[20];
	unsigned long temp;

	for (size = 0, temp = n; temp != 0; size++, temp = temp / 10)
		reverse[size] = temp % 10;
	for (x = size - 1, temp = n; x > size / 2 - 1; x--, temp = temp / 10)
		if (reverse[x] != temp % 10)
			return (0);
	return (1);
}
