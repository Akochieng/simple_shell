#include "main.h"
/**
  *settheenv - sets an environment variable to the defined parameter
  *@cmd: pointer to the parameter
  *
  *Return: 1 on success, 0 otherwise
  */
int settheenv(char **cmd)
{
	int i, size, len, state, namelen;
	char *name, *value, *newpair, *found, **temp, **oldenviron;

	i = len = 0;
	name = value = NULL;
	len = len_ptrarr(cmd);
	if (len != 3)
	{
		theerr(22, 0);
		return (-1);
	}
	name = cmd[1];
	namelen = _strlen(name);
	found = gettheenv(name);
	newpair = genenvstr(name, cmd[2]);
	size = found == NULL ?  len_ptrarr(myenviron) + 2 : len_ptrarr(myenviron) + 1;
	temp = malloc(sizeof(char *) * size);
	if (temp == NULL)
	{
		theerr(12, 0);
		return (-1);
	}
	while (myenviron[i] != NULL)
	{
		state = _strncmp(name, myenviron[i], namelen);
		if (state == 1)
			temp[i] = newpair;
		else
			temp[i] = myenviron[i];
		i++;
	}
	if (found == NULL)
		temp[i++] = newpair;
	temp[i] = NULL;
	oldenviron = myenviron;
	myenviron = temp;
	free(oldenviron);
	return (0);
}
/**
  *unsettheenv - unsets an environment variable to the defined parameter
  *@cmd: pointer to the parameter
  *
  *Return: 1 on success, 0 otherwise
  */
int unsettheenv(char **cmd)
{
	char *name = NULL;
	char *envstr = NULL;
	char **temp = NULL;
	int state, i, j;
	size_t namelen = 0;
	size_t size = 0;
	char **oldenviron = NULL;

	i = j = 0;
	name = cmd[1];
	namelen = _strlen(name);
	envstr = gettheenv(name);
	size = len_ptrarr(myenviron);
	if (envstr == NULL)
		return (0);
	temp = malloc(sizeof(char *) * (size + 1));
	while (myenviron[i] != NULL)
	{
		state = _strncmp(name, myenviron[i], namelen);
		if (state == 1)
		{
			j++;
			continue;
		}
		temp[j++] = myenviron[i++];
	}
	oldenviron = myenviron;
	myenviron = temp;
	free(oldenviron);
	return (0);
}
/**
  *changedir - change the directory to the defined parameter
  *@cmd: pointer to the parameter
  *
  *Return: 1 on success, 0 otherwise
  */
int changedir(char **cmd __attribute__((unused)))
{
	return (0);
}
/**
  *thealias - sets an aliais to the defined parameter
  *@cmd: pointer to the parameter
  *
  *Return: 1 on success, 0 otherwise
  */
int thealias(char **cmd __attribute__((unused)))
{
	return (0);
}
/**
  *eecho - echo the parameter
  *@cmd: pointer to the parameter
  *
  *Return: 1 on success, 0 otherwise
  */
int eecho(char **cmd __attribute__((unused)))
{
	return (0);
}
