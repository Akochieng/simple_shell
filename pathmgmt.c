#include "main.h"

//make a function that goes through the path environment
//and creates a linked list of the paths
//the function should return the head of the list.

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

int main(void)
{
	paths *pathhead = NULL;
	paths *cur;

	pathhead = pathify();
	if (pathhead == NULL)
	{
		printf("Error generating the paths\n");
		exit(1);
	}
	cur = pathhead;
	while (cur)
	{
		printf("%s\n", cur->path);
		cur = cur->next;
		if (cur == NULL)
			break;
	}
	return (0);
}
//create a function that frees up the linked list created
//for the path
