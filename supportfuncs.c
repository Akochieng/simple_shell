#include "main.h"
/**
  *_atoi - converts a number in a string to interger
  *@s: the string
  *
  *Return: the number
  */
int _atoi(char *s)
{
	int result = 0;
	int sign = 1;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			result = result * 10 + (*s - '0');
		else
			return (-1);
		s++;
	}
	return (result * sign);
}
/**
  *_puts - prints a string of characters to the standard output
  *@s: the string
  *
  *Return: the number of characters printed
  */
int _puts(char *s)
{
	int len = 0;

	if (s == NULL)
		return (0);
	len = _strlen(s);
	return (write(1, s, len));
}
