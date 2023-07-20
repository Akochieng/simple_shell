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

	num = checkdelims(s, delim);
	delimited = malloc(sizeof(char *) * num);
	readbuf = _strdup(s);
	if (delimited == NULL)
		exit(12);
	delimited[count++] = strtok(readbuf, delim);
	for (; count < num; count++)
		delimited[count] = strtok(NULL, delim);
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

	cmd = parsecmd(readbuf);
	cur = pathhead;
	while (found == -1)
	{
		fullpath = pathncmd(cur->path, cmd[0]);
		found = stat(fullpath, &st);
		if (found == 0)
			printf("%s\n", fullpath);
		cur = cur->next;
		free(fullpath);
		if (cur == NULL)
		{	
			perror("stat");
			break;
		}
	}
	return (0);
}
/**
int checkcmd(char *cmd, path *pathhead)
{
}
*/
char *pathncmd(char *path, char *cmd)
{
	char *temp = NULL;
	size_t len = 0;

	len = _strlen(path) + _strlen(cmd) + 2;
	temp = malloc(len);
	if (temp == NULL)
		exit(12);
	_strcat(temp, path);
	_strcat(temp, "/");
	_strcat(temp, cmd);
	return (temp);
}
