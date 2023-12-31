#include "monty.h"

/**
* execute - executes the opcode
* @content: line content
* @stack: head linked list - stack
* @line_count: line_counter
* @f: poiner to monty file
* Return: 0 if success 1 ohterwise
*/
int execute(char *content, stack_t **stack, unsigned int line_count, FILE *f)
{
	instruction_t operations[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", _div},
		{"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
		{"stack", nop}, {"queue", nop},
		{NULL, NULL}
	};
	int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);

	if (strcmp(op, "queue") == 0)
		global.flag = 'q';
	else if (strcmp(op, "stack") == 0)
		global.flag = 's';

	global.arg = strtok(NULL, " \n\t");
	while (operations[i].opcode && op)
	{
		if (strcmp(op, operations[i].opcode) == 0)
		{
			operations[i].f(stack, line_count);
			return (0);
		}
		i++;
	}
	if (op && operations[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_count, op);
		fclose(f);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
