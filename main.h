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
void freepath(paths *pathhead);
int printpath(paths *pathhead);

extern char **environ;
char *gettheenv(char *name);

int _putchar(char c);
size_t _strlen(char *s);
int _strncmp(char *frst, char *second, size_t num);
char *_strdup(char *s);
char *_strcat(char *dest, char *sec);

size_t checkdelims(char *mem, char *del);

char **parsecmd(char *s);
char *pathncmd(char *path, char *cmd);
int runcmd(char *readbuf, paths *pathhead);

void free_pointerarr(char **s);
void clear_mem(char *mem, size_t len);
#endif
