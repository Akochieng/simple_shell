#include "main.h"
/**
  *pathify - function that makes a singly linked list from struct paths
  *
  *Return: the head of the path
  */
paths *pathify(void)
{
	char *temp;
	char *mixpath;
	paths *pathhead = NULL;
	paths *cur, *new;

	temp = gettheenv("PATH");
	mixpath = _strdup(temp);
	temp = strtok(mixpath, "=");
	while (temp)
	{
		temp = strtok(NULL, ":");
		if (temp == NULL)
			break;
		new = malloc(sizeof(paths));
		new->path = _strdup(temp);
		new->next = NULL;
		if (pathhead == NULL)
		{
			pathhead = new;
			cur = pathhead;
		}
		else
		{
			cur->next = new;
			cur = cur->next;
		}
	}
	free(mixpath);
	return (pathhead);
}
/**
  *printpath - prints the path variable in a singly linked list
  *@pathhead: the head of the singly linked list
  *
  *Return: 0 on success, -1 otherwise
  */
int printpath(paths *pathhead)
{
	paths *cur;

	if (pathhead == NULL)
	{
		_puts("Error generating the paths\n");
		exit(1);
	}
	cur = pathhead;
	while (cur)
	{
		_puts(cur->path);
		_putchar('\n');
		cur = cur->next;
		if (cur == NULL)
			break;
	}
	return (0);
}
/**
  *freepath - function that frees the path singly linked list
  *@pathhead: the head of the singly linked list
  *
  *Return: void
  */
void freepath(paths *pathhead)
{
	paths *cur;
	paths *next;

	if (!(pathhead == NULL))
	{
		cur = pathhead;
		while (cur)
		{
			next = cur->next;
			free(cur->path);
			free(cur);
			cur = next;
		}
	}
	pathhead = NULL;
}
