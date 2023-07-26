#include "main.h"
/**
  *parsecmd - tokenises a string
  *@s: the string
  *
  *Return: the command
  */
char **parsecmd(char *s)
{
	char delim[] = {' ', '\n', '\0'};
	char *temp, *readbuf;
	char **delimited = NULL;
	size_t num = 0;
	size_t count = 0;

	num = checkdelims(s, delim) + 1;
	delimited = malloc(sizeof(char *) * num);
	readbuf = _strdup(s);
	if (delimited == NULL)
		theerr(12, EXITPROG);
	temp = strtok(readbuf, delim);
	if (!(temp == NULL))
	{
		for (count = 0; count < num - 1 && temp != NULL; count++)
		{
			delimited[count] = _strdup(temp);
			temp = strtok(NULL, delim);
		}
		delimited[count] = NULL;
	}
	else
	{
		free(delimited);
		delimited = NULL;
	}
	free(readbuf);
	return (delimited);
}
/**
  *runcmd - function to run the command
  *@readbuf: the read buffer
  *@pathhead: the head of the path singly linked list
  *
  *Return: 1 on success, -1 otherwise
  */
int runcmd(char *readbuf, paths *pathhead)
{
	char **cmd = NULL;
	char *fullpath = NULL;
	int found = -1;
	paths *cur;
	struct stat st;
	int (*internal)(char **) = NULL;

	cur = pathhead;
	cmd = parsecmd(readbuf);
	if (!(cmd == NULL))
	{
		internal = checkinternal(cmd);
		if (internal != NULL)
			internal(cmd);
		while (found == -1 && cur != NULL && internal == NULL)
		{
			fullpath = pathncmd(cur->path, cmd[0]);
			found = stat(fullpath, &st);
			if (found == 0)
				runexternal(fullpath, cmd);
			cur = cur->next;
			free(fullpath);
		}
	}
	if (cur == NULL)
		theerr(2, CONTPROG);
	if (cmd != NULL)
		free_pointerarr(cmd);
	return (0);
}
/**
  *pathncmd - creates a string consisting of the path and command
  *@path: the path
  *@cmd: the command
  *
  ;*Return: the fullpath and command combined
  */
char *pathncmd(char *path, char *cmd)
{
	char *temp = NULL;
	size_t len = 0;

	len = _strlen(path) + _strlen(cmd) + 2;
	temp = malloc(len);
	if (temp == NULL)
		theerr(12, EXITPROG);
	clear_mem(temp, len);
	_strcat(temp, path);
	_strcat(temp, "/");
	_strcat(temp, cmd);
	return (temp);
}
/**
  *checkinternal - function that checks whether the function is one
  *of the internally defined functions and returns it
  *@cmd: the array of arrays input into the command
  *
  *Return: 0 if function is not internal
  */
int (*checkinternal(char **cmd))(char **)
{
	intcmd funcs[] = {
		{"exit", exit_f},
		{"setenv", settheenv},
		{"unsetenv", unsettheenv},
		{"cd", changedir},
		{"alias", thealias},
		{"theevho", eecho},
		{"env", printtheenv},
		{NULL, NULL}
	};
	int i;

	for (i = 0; funcs[i].name != NULL; i++)
		if (_strcmp(funcs[i].name, cmd[0]) == 1)
			return (funcs[i].f);
	return (NULL);
}
/**
  *runexternal - runs external functions
  *@fullpath: the full path to the executable
  *@cmd: the command to be run and its parameters
  *
  *Return: the result of running the command
  */
int runexternal(char *fullpath, char **cmd)
{
	pid_t childpid;
	int state = 0;
	int status;

	childpid = fork();
	if (childpid == -1)
	{
		errno = 16;
		perror(progname);
	}
	else if (childpid == 0)
	{
		state = execve(fullpath, cmd, myenviron);
		if (state == -1)
			theerr(127, CONTPROG);
	}
	else
		wait(&status);
	return (state);
}
