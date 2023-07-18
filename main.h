#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
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

extern char **environ;
char *gettheenv(char *name);

int _putchar(char c);
size_t _strlen(char *s);
int _strncmp(char *frst, char *second, size_t num);
char *_strdup(char *s);

char *parsecmd(char *s);
int runcmd(char **readbuf);
#endif
