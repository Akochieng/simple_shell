#include "main.h"

//make a function that loops through the list of environment
//variables and returns the requested environ

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
