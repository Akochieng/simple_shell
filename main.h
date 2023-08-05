#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#define EXITPROG 1
#define CONTPROG 0
/**
  *struct pathlist - struct consisting of paths
  *@path: instance of a path
  *@next: addres of the next path
  */
typedef struct pathlist
{
	char *path;
	struct pathlist *next;
} paths;
paths *pathify(void);
paths *pathhead;
void freepath(paths *pathhead);
int printpath(paths *pathhead);
/**
  *struct commands - struct with a list of internal commands
  *@name: the name of the command to reference the function pointer
  *@f: the function to be returned
  */
typedef struct commands
{
	char *name;
	int (*f)(char **);
} intcmd;
int (*checkinternal(char **cmd))(char **);

extern char **environ;
char **myenviron;
char **cmd;
char *progname;
int exitnow;
int exitstate;
char *gettheenv(char *name);
void populateenviron(void);
void freeenviron(char **environment);

int _putchar(char c);
int _puts(char *s);
size_t _strlen(char *s);
size_t len_ptrarr(char **s);
int _strncmp(char *frst, char *second, size_t num);
char *_strdup(char *s);
char *_strcat(char *dest, char *sec);
int _strcmp(char *first, char *second);

size_t checkdelims(char *mem, char *del);

int _atoi(char *s);

int exit_f(char **cmd);
int settheenv(char **cmd);
int unsettheenv(char **cmd);
int changedir(char **cmd);
int thealias(char **cmd);
int eecho(char **cmd);
int printtheenv(char **cmd __attribute__((unused)));
char *genenvstr(char *name, char *value);

char **parsecmd(char *s);
char *readbuf;
char *pathncmd(char *path, char *cmd);
int runcmd(char *readbuf, paths *pathhead);
int runexternal(char *fullpath, char **cmd);

void free_pointerarr(char **s);
void clear_mem(char *mem, size_t len);
void _theexit(int sig);
void theerr(int err, int stop);
void freeresources(void);
#endif
