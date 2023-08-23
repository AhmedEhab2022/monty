#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: void
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, sum;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		cleanup();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*stack = temp->next;
	free(temp);
}

#include "monty.h"
/**
  *nop - nothing
  *@stack: stack head
  *@line_number: line_number
  *Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
