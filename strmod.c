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
