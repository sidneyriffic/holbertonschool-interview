#include <stdlib.h>
#include "substring.h"

/**
 * _strlen - find length of a string
 *
 * @s: string to get length of
 *
 * Return: length of string
 */
int _strlen(char const *s)
{
	int i = 0;

	while (s[i] != 0)
		i++;
	return (i);
}


/**
 * _strncmp - compare two strings up to n characters
 *
 * @s1: first string
 * @s2: second string
 * @n: maximum compare length
 *
 * Return: 0 if the same, 1 otherwise
 */
int _strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	while (i < n)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * find_substring - find a substring consisting of a concatenation of
 * a list of words in any order exactly once each.
 *
 * @s: string to search
 * @words: words to look for
 * @nb_words: number of words
 * @n: variable to return number of indices found
 *
 * Return: null on failure, or an array of indices substring is found at.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *found, *wordused;
	int len, i, j, k, wordcount, wordlen;

	if (nb_words == 0 || n == NULL || s == NULL || words == NULL)
		return (NULL);
	wordlen = _strlen(words[0]);
	len = _strlen(s);
	found = malloc(len * sizeof(int));
	if (found == NULL)
		return (NULL);
	wordused = malloc(nb_words * sizeof(int));
	if (wordused == NULL)
	{
		free(found);
		return (NULL);
	}
	*n = 0;
	for (i = 0; i < len - wordlen * nb_words + 1; i++)
	{
		for (k = 0; k < nb_words; k++)
			wordused[k] = 0;
		wordcount = nb_words;
		k = i;
		for (j = 0; j < nb_words; j++)
			if (!wordused[j] && !_strncmp(s + k, words[j], wordlen))
			{
				wordused[j] = 1;
				wordcount--;
				j = -1;
				k += wordlen;
			}
		if (wordcount == 0)
		{
			found[*n] = i;
			(*n)++;
		}
	}
	free(wordused);
	return (found);
}
