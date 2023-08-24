#include "monty.h"
global_t global = {NULL, NULL, NULL, 's'};

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: arguments
* Return: 0 if success
*/
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	unsigned int line_count = 0;
	char *content;
	size_t size = 0;
	ssize_t read_line = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	global.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		global.content = content;
		line_count++;

		if (read_line > 0)
		{
			execute(content, &stack, line_count, file);
		}
		free(content);
	}

	free_stack(stack);
	fclose(file);

	return (0);
}
