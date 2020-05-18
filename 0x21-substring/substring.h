#ifndef SUBSTRING_H
#define SUBSTRING_H

int *find_substring(char const *s, char const **words,
		    int nb_words, int *n);

/**
 * struct IndexList - singly linked list to hold indexes before compiling
 * into an array.
 * @index: the index found
 * @next: next node in list
 */
typedef struct IndexList
{
	int index;
	struct IndexList *next;
} IndexList;

#endif
