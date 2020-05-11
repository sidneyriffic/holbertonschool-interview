int wildmode(char const *s1, char const *s2);
int repeatmode(char const *s1, char const *s2, const char repeat);

/**
 * exactmode - Goes to end of found substring
 *
 * @s1: non-wildcarded string we're checking for matches
 * @s2: wildcarded string we're checking the substring from
 *
 * Return: continue wild mode at end of substring if
 * substring found, 0 otherwise
 */
int exactmode(char const *s1, char const *s2)
{
	if (*s1 == 0 && *s2 == 0)
		return (1);
	if (*s2 == '.')
	{
		if (*(s2 + 1) == '*')
			return (wildmode(s1, s2 + 2));
		if (*s1 == 0)
			return (0);
		return (exactmode(s1 + 1, s2 + 1));
	}
	if (*(s2 + 1) == '*')
		return (repeatmode(s1, s2 + 2, *s2));
	if (*s1 == *s2)
		return (exactmode(s1 + 1, s2 + 1));
	return (0);
}

/**
 * wildmode - Processes wildcards from s2 and handles backtracking
 * to match multiple instances of wildcarded substrings. '.*' operator.
 *
 * @s1: string we're trying to match
 * @s2: wildcarded string containing search pattern
 *
 * Return: 1 if valid match, 0 if not
 */
int wildmode(char const *s1, char const *s2)
{
	if (*s2 == '*')
		return (wildmode(s1, s2 + 1));
	if (*s2 == 0)
		return (1);
	if (*s1 == 0)
		return (0);
	if (*s1 != *s2)
		return (wildmode(s1 + 1, s2));
	if (!(exactmode(s1 + 1, s2 + 1)))
		return (wildmode(s1 + 1, s2));
	return (1);
}

/**
 * repeatmode - checks for repeated instances of a character. '*' operator.
 *
 * @s1: string to check
 * @s2: pattern to match
 * @repeat: character being repeated
 *
 * Return: 0 if no match
 */
int repeatmode(char const *s1, char const *s2, const char repeat)
{
	if (*s2 == '*')
		return (repeatmode(s1, s2 + 1, repeat));
	if (*s1 == repeat)
	{
		if (!(exactmode(s1 + 1, s2)))
			return (repeatmode(s1 + 1, s2, repeat));
		return (1);
	}
	return (exactmode(s1, s2));
}

/**
 * regex_match - Compares two strings with '.', '*' and '.*' operators.
 * Sets initial search mode.
 *
 * @str: first string, does not have regex operators
 * @pattern: second string, has regex operators
 *
 * Return: 1 if identical, otherwise 0
 */
int regex_match(char const *str, char *pattern)
{
	if (*pattern == '*')
		return (wildmode(str, pattern));
	return (exactmode(str, pattern));
}
