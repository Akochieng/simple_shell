#include "main.h"
/**
  *main - this is the main function of the simple shell program
  *@ac: the number of parameters passed in
  *@argv: the parameters themselves
  *
  *Return: 0 on success
  */
int main(int ac __attribute__((unused)), char **argv)
{
	char *readbuf = NULL;
	paths *pathhead = NULL;
	size_t size = 1024;
	int numread = 0;

	exitnow = 0;
	progname = argv[0];
	populateenviron();
	pathhead = pathify();
	readbuf = malloc(size);
	signal(SIGINT, _theexit);
	while (!exitnow)
	{
		if (isatty(fileno(stdin)))
			_putchar('$');
		numread = getline(&readbuf, &size, stdin);
		if (numread == -1)
			break;
		runcmd(readbuf, pathhead);
	}
	fflush(stdin);
	free(readbuf);
	freepath(pathhead);
	freeenviron(myenviron);
	_putchar('\n');
	return (0);
}
/**
  *_theexit - call back function to handle signal SIGINT
  *@sig: the signal
  *
  *Return: void
  */
void _theexit(int sig)
{
	if (sig == SIGINT)
		exitnow = 1;
}
/**
  *theerr - handles the error raised
  *@err: the error
  *@stop: defines whether the program exits or not
  *
  *Return: void
  */
void theerr(int err, int stop)
{
	errno = err;
	perror(progname);
	if (stop == 1)
		raise(SIGINT);
}
/**
  *exit_f - function to handle the exit command
  *@cmd: pointer to the command and parameters
  *
  *Return: 1 on success
  */
int exit_f(char **cmd)
{
	size_t len = 0;
	int err = 0;

	len = len_ptrarr(cmd);
	if (len > 2)
		err = 1;
	else if (len == 2)
		err = _atoi(cmd[1]);
	errno = err;
	raise(SIGINT);
	return (1);
}
