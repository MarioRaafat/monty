#include "monty.h"
#include <stdio.h>
#define _GNU_SOURCE
#include <stdlib.h>

bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - function for monty code interpreter
* @argc: argument count
* @argv: argument value
*
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *mm;
	FILE *file;
	size_t size = 0;
	ssize_t readline = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readline > 0)
	{
		mm = NULL;
		readline = getline(&mm, &size, file);
		bus.content = mm;
		counter++;
		if (readline > 0)
		{
			execute(mm, &stack, counter, file);
		}
		free(mm);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
