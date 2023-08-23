#include "monty.h"

/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: 0 if success 1 ohterwise
*/
int execute(char *content, stack_t **stack, unsigned int line_count, FILE *file)
{
	instruction_t operations[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");

	/* handling comments */
	if (op && op[0] == '#')
		return (0);

	global.arg = strtok(NULL, " \n\t");
	/* find matching operation in table */
	while (operations[i].opcode && op)
	{
		if (strcmp(op, operations[i].opcode) == 0)
		{
			operations[i].f(stack, line_count);
			return (0);
		}

		i++;
	}
	/* handle unknown operation */

	if (op && operations[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_count, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
