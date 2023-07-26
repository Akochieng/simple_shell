#include "main.h"
/**
  *gettheenv - returns a string with the environment variable requested
  *@name: the name of the environment variable
  *
  *Return: the environment variable described in the parameter
  */
char *gettheenv(char *name)
{
	int i = 0;
	size_t len = 0;
	int state = 0;

	if (name == NULL)
		return (NULL);
	len = _strlen(name);
	while (!(myenviron[i] == NULL))
	{
		state = _strncmp(name, myenviron[i], len);
		if (state == 1)
			return (myenviron[i]);
		i++;
	}
	return (NULL);
}
/**
  *printtheenv - prints the list of environment variables
  *@cmd: the array of commands and its variables
  *
  *Return: the number of printed variables
  */
int printtheenv(char **cmd __attribute__((unused)))
{
	int i = 0;
	int len = 0;

	while (!(myenviron[i] == NULL))
	{
		len = _puts(myenviron[i]) + _putchar('\n');
		i++;
	}
	return (len);
}
/**
  *genenvstr - generates a string of the environment
  *@name: the name of the variable
  *@value: the value of the variable
  *
  ;*Return: the generated name value string
  */
char *genenvstr(char *name, char *value)
{
	size_t len;
	char *dest;

	if (name == NULL || value == NULL)
	{
		theerr(22, 0);
		return (NULL);
	}
	len = _strlen(name) + _strlen(value) + 2;
	dest = malloc(len);
	if (dest == NULL)
	{
		theerr(12, 0);
		return (NULL);
	}
	_strcat(dest, name);
	_strcat(dest, "=");
	_strcat(dest, value);
	return (dest);
}

void populateenviron(void)
{
	size_t len = 0;
	size_t i = 0;

	len = len_ptrarr(environ);
	myenviron = malloc(sizeof(char **) * (len + 1));
	for (i = 0; i <= len; i++)
		myenviron[i] = _strdup(environ[i]);
}

void freeenviron(char **environment)
{
	size_t len = 0;
	size_t i = 0;

	len = len_ptrarr(environment);
	for (i = 0; i <= len; i++)
		free(environment[i]);
	free(environment);
}
