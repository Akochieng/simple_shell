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
	size_t len;
	extern char **environ;
	int state;

	if (name == NULL)
		return (NULL);
	len = _strlen(name);
	while (!(environ[i] == NULL))
	{
		state = _strncmp(name, environ[i], len);
		if (state == 1)
			return (environ[i]);
		i++;
	}
	return (NULL);
}
