int repeatmode(char *s1, char *s2, char subject);

/**
 * exactmode - Goes to end of a found substring. Matches '.' to
 * any character.
 *
 * @s1: non-regex string we're checking for matches
 * @s2: regex string we're checking the substring from
 *
 * Return: repeat mode at end of substring if
 * substring found, 0 otherwise. 1 if done/end of both strings.
 */
int exactmode(char *s1, char *s2)
{
	if (*s1 == 0 && *s2 == 0)
		return (1);
	if (*s2 == 0)
		return (0);
	if (*s2 == '.' && *(s2 + 1) == '*')
		return (repeatmode(s1, s2 + 2, 0));
	if (*(s2 + 1) == '*')
		return (repeatmode(s1, s2 + 1, *s1));
	if (*s2 == '.' || *s1 == *s2)
		return (exactmode(s1 + 1, s2 + 1));
	return (0);
}

/**
 * repeatmode - Repeat a single character (or dot)
 *
 * @s1: string we're trying to match
 * @s2: regex string
 * @subject: the character we are repeating (or 0 for wild)
 *
 * Return: 1 if we finish the regex and string, 0 if not
 */
int repeatmode(char *s1, char *s2, char subject)
{
	if (*s2 == '*')
		return (repeatmode(s1, s2 + 1, subject));
	if (subject == 0 && *s2 == 0)
		return (1);
	if (*s2 == 0 && *s1 == 0)
		return (1);
	if (*s1 == 0)
		return (0);
	if (!(exactmode(s1, s2)))
		return (repeatmode(s1 + 1, s2, subject));
	return (1);
}


/**
 * regex_match - Compares two strings, the second with . and *
 * in regex fashion. Sets initial search mode.
 *
 * @s1: first string, does not have . or *
 * @s2: second string, may have . or *
 *
 * Return: 1 if identical, otherwise 0. 0 if * at start of regex
 * (invalid regex).
 */
int regex_match(char *s1, char *s2)
{
	if (*s2 == '*')
		return (0);
	return (exactmode(s1, s2));
}
