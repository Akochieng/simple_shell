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
		exit(12);
	temp = strtok(readbuf, delim);
	delimited[count++] = _strdup(temp);
	for (; count < num - 1 ; count++)
	{
		temp = strtok(NULL, delim);
		delimited[count] = _strdup(temp);
	}
	delimited[count] = NULL;
	free(readbuf);
	return (delimited);
}
/**
  *runcmd - function to run the command
  *@readbuf: the read buffer
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
	pid_t childpid;
	int state = 0;
	int status;

	cur = pathhead;
	cmd = parsecmd(readbuf);
	if (!(cmd == NULL))
		while (found == -1 && cur != NULL)
		{
			fullpath = pathncmd(cur->path, cmd[0]);
			found = stat(fullpath, &st);
			if (found == 0)
			{
				childpid = fork();
				if (childpid == -1)
					perror("fork");
				else if (childpid == 0)
				{
					state = execve(fullpath, cmd, environ);
					if (state == -1)
						perror("execve");
				}
				else
					wait(&status);
			}
			cur = cur->next;
			free(fullpath);
		}
	if (cur == NULL)
		perror("stat");
	free_pointerarr(cmd);
	return (0);
}
/**
  *pathncmd - creates a string consisting of the path and command
  *@path: the path
  *@cmd: the command
  *
  *Return: the fullpath and command combined
  */
char *pathncmd(char *path, char *cmd)
{
	char *temp = NULL;
	size_t len = 0;

	len = _strlen(path) + _strlen(cmd) + 2;
	temp = malloc(len);
	if (temp == NULL)
		exit(12);
	clear_mem(temp, len);
	_strcat(temp, path);
	_strcat(temp, "/");
	_strcat(temp, cmd);
	return (temp);
}
