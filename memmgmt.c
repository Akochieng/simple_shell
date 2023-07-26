#include "main.h"
/**
  *free_pointerarr - clears an array of pointers
  *@s: the array of strings to be cleared
  *
  *Return: void
  */
void free_pointerarr(char **s)
{
	int i = 0;

	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
}
/**
  *clear_mem - sets the contents of a memory location to '\0'
  *@mem: the memory location
  *@len: the length of the memory
  *
  *Return: void
  */
void clear_mem(char *mem, size_t len)
{
	size_t i;

	for (i = 0; i < len; i++)
		mem[i] = '\0';
}
/**
  *len_ptrarr - compute the length of an array of pointers
  *@s: pointers to strings
  *
  *Return: number of elements in the array
  */
size_t len_ptrarr(char **s)
{
	size_t len = 0;

	while (s[len] != NULL)
		len++;
	return (len);
}
/**
  *freeresources - frees up resources allocated using malloc
  *
  *Return: void
  */
void freeresources(void)
{
	fflush(stdin);
	free(readbuf);
	freepath(pathhead);
	free_pointerarr(myenviron);
}
