#include "main.h"

size_t checkdelims(char *mem, char *del)
{
	size_t m, d, count;

	count = 0;
	for (m = 0; mem[m] != '\0'; m++)
		for (d = 0; del[d] != '\0'; d++)
			if (mem[m] == del[d])
				count++;
	return (count);
}
