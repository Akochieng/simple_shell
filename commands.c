#include "main.h"
/**
  *parsecmd - tokenises a string
  *@s: the string
  *
  *Return: void
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
