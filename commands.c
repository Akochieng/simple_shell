#include "main.h"
/**
  *parsecmd - tokenises a string
  *@s: the string
  *
  *Return: the command
  */
char *parsecmd(char *s)
{
	char *delim = " /n";
	char *temp = NULL;
	char *command = NULL;

	temp = strtok(s, delim);
	command = temp;
	while (!(temp == NULL))
		temp = strtok(NULL, delim);
	return (command);
}
/**
  *runcmd - function to run the command
  *@readbuf: the read buffer
  *
  *Return: 1 on success, -1 otherwise
  */
int runcmd(char **readbuf)
{
	extern char **environ;
	int state = 1;
	char *const *thebuf;

	thebuf = (char *const *)readbuf;
	state = execve("\\bin", thebuf, environ);
	if (state == -1)
		_putchar('1');
}
