#include "main.h"
/**
  *main - this is the main function of the simple shell program
  *
  *Return: 0 on success
  */
int main(void)
{
	char *readbuf = NULL;
	size_t size = 1024;
	int numread = 0;
	int numwrite = 0;
	char *command = NULL;

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
	_putchar('\n');
	return (0);
}

