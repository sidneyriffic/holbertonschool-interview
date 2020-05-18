#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * _words_strcmp - compare words against front of current string
 * @s: string to search front of
 * @words: words to search for
 * @nb_words: number of words in array
 * @mask: words to not search because they've been used already
 * @wordlen: length of words
 *
 * Return: 1 for found, 0 for not found
 */
int _words_strcmp(char const *s, char const **words, int nb_words,
		  char mask[], int wordlen)
{
	int word;

	for (word = 0; word < nb_words; word++)
	{
		if (mask[word] == 1)
			continue;
		if (!strncmp(words[word], s, wordlen))
		{
			mask[word] = 1;
			return (_words_strcmp(s + wordlen, words,
					      nb_words, mask, wordlen));
		}
	}
	for (word = 0; word < nb_words; word++)
		if (mask[word] == 0)
			return (0);
	return (1);
}


/**
 * _free_alloc - frees allocated index list
 * @list: list to free
 */
void _free_alloc(IndexList *list)
{
	IndexList *current = list, *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/**
 * find_substring - find substrings that are concatenations of the
 *  words given.
 * @s: string to search
 * @words: words to check for
 * @nb_words: number of words in the words array
 * @n: address to hold number of substrings found
 *
 * Return: NULL on error or not found, address of index array
 * if successful
 */
int *find_substring(char const *s, char const **words,
		    int nb_words, int *n)
{
	int word, wordlen, stridx, stringlen;
	int numindices = 0, *idxarray = NULL;
	char *wordmask;
	IndexList *indices = NULL, *current = NULL, *new;

	*n = 0;
	if (words == NULL || *words == NULL || n == NULL || s == NULL)
		return (NULL);
	wordlen = strlen(words[0]);
	if (wordlen == 0 || *s == 0)
		return (NULL);
	wordmask = malloc(nb_words);
	if (wordmask == NULL)
		return (NULL);
	stringlen = strlen(s) - wordlen * nb_words + 1;
	for (stridx = 0; stridx < stringlen; stridx++)
	{
		for (word = 0; word < nb_words; word++)
			wordmask[word] = 0;
		if (_words_strcmp(s + stridx, words, nb_words,
				  wordmask, wordlen))
		{
			numindices += 1;
			*n += 1;
			new = malloc(sizeof(IndexList));
			if (new == NULL)
			{
				free(wordmask);
				_free_alloc(indices);
				*n = 0;
				return (NULL);
			}
			new->index = stridx;
			new->next = NULL;
			if (indices == NULL)
				indices = current = new;
			else
			{
				current->next = new;
				current = new;
			}
		}
	}
	idxarray = malloc(sizeof(int) * numindices);
	if (idxarray)
		for (stridx = 0, current = indices; stridx < numindices;
		     stridx++, current = current->next)
			idxarray[stridx] = current->index;
	_free_alloc(indices);
	free(wordmask);
	return (idxarray);
}
