#include "main.h"
/**
  *checkdelims - function that checks whether any of the characters in del
  *are in mem
  *@mem: the array of characters
  *@del: the delimiter characters
  *
  *Return: the number of delimiters counted
  */
size_t checkdelims(char *mem, char *del)
{
	size_t m, d, count;

	count = 0;
	for (m = 0; mem[m] != '\0'; m++)
		for (d = 0; del[d] != '\0'; d++)
			if (mem[m] == del[d])
				count++;
	return (count);
}
/**
  *_strcmp - function that compares two strings
  *@first: the first string
  *@second: the second string
  *
  *Return: 0 if equal, -1 otherwise
  */
int _strcmp(char *first, char *second)
{
	size_t i;
	size_t firstlen;
	size_t secondlen;

	if (first == NULL || second == NULL)
		return (-1);
	firstlen = _strlen(first);
	secondlen = _strlen(second);
	if (!(firstlen == secondlen))
		return (-1);
	for (i = 0; i < firstlen; i++)
		if (!(first[i] == second[i]))
			return (-1);
	return (1);
}
