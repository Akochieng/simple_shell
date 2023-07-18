#include "main.h"
/**
  *main - this is the main function of the simple shell program
  *
  *Return: 0 on success
  */
int main(void)
{
	char *readbuf = NULL;
	paths *pathhead = NULL;
	size_t size = 1024;
	int numread = 0;
	int numwrite = 0;
	char *command = NULL;

	pathhead = pathify();
	readbuf = malloc(size);
	while (1)
	{
		_putchar('$');
		numread = getline(&readbuf, &size, stdin);
		if (numread == -1)
			break;
		command = parsecmd(readbuf);
		runcmd(&readbuf);
		numwrite = write(STDOUT_FILENO, readbuf, numread);
	}
	free(readbuf);
	freepath(pathhead);
	_putchar('\n');
	return (0);
}

