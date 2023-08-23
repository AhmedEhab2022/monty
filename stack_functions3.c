#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element of
 * the stack by the top element of the stack
 *
 * @stack: pointer to the top of the stack_t
 * @line_number: the line of the instruction
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		cleanup();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		cleanup();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n %= temp->n;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 *
 * @stack: pointer to the top of the stack_t
 * @line_number: the line of the instruction
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		cleanup();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		cleanup();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line
 *
 * @stack: pointer to the top of the stack_t
 * @line_number: the line of the instruction
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	while (temp && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top
 *
 * @stack: pointer to the top of the stack_t
 * @line_number: the line of the instruction
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack && (*stack)->next)
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;

		(*stack)->prev = temp;
		temp->next = *stack;
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = NULL;
	}
}

/**
 * rotr - rotates the stack to the bottom
 *
 * @stack: pointer to the top of the stack_t
 * @line_number: the line of the instruction
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;
	if (*stack && (*stack)->next)
	{
		temp = *stack;
		last = *stack;
		while (last->next)
			last = last->next;

		last->prev->next = NULL;
		last->prev = NULL;
		last->next = temp;
		temp->prev = last;
		*stack = last;
	}
}
