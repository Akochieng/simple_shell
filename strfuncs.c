#include "main.h"
/**
  *_putchar - function to print a character to the stdout
  *@c: the character
  *
  *Return: ALways 1
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
  *_strlen - function to compute the length of a string
  *@s: the string
  *
  *Return: the length of the string
  */
size_t _strlen(char *s)
{
	size_t len = 0;

	if (s != NULL)
		for (len = 0; s[len] != '\0'; len++)
			;
	return (len);
}
/**
  *_strncmp - compares the first n characters in a string
  *@frst: the first string
  *@second: the second string
  *@num: the number of characters to be compared
  *
  *Return: -1 if false and 1 otherwise
  */
int _strncmp(char *frst, char *second, size_t num)
{
	size_t i = 0;

	for (i = 0; i < num; i++)
		if (!(frst[i] == second[i]))
			return (-1);
	return (1);
}
/**
  *_strdup - function that duplicates a string
  *@s: the string
  *Description: works similar to strdup of the string.h header
  *Return: the address to the newly created memory
  */
char *_strdup(char *s)
{
	size_t len, i;
	char *newstr = NULL;

	len = _strlen(s);
	newstr = malloc(len + 1);
	if (newstr == NULL)
		exit(12);
	for (i = 0; ((newstr[i] = s[i]) != '\0'); i++)
		;
	return (newstr);
}
/**
  *_strcat - function that concatanates two strings
  *@dest: the destination string
  *@sec: the second string to be added to the destination
  *
  *Return: address to the dest
  */
char *_strcat(char *dest, char *sec)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;
	while (sec[j] != '\0')
	{
		dest[i] = sec[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
