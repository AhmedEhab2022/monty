#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @stack: pointer to the top of the stack_t
 * @line_number: the line of the instruction
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *temp;
	int n = atoi(global.arg);

	temp = *stack;
	if (global.arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		cleanup();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	new_node->n = n;
	if (global.flag == 's')
	{
		if (temp)
			temp->prev = new_node;
		new_node->next = *stack;
		new_node->prev = NULL;
		*stack = new_node;
	}
	else if (global.flag == 'q')
	{
		while (temp && temp->next)
			temp = temp->next;
		if (temp != NULL)
			temp->next = new_node;
		else
			*stack = new_node;
		new_node->next = NULL;
		new_node->prev = temp;
	}
}

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack
 *
 * @stack: pointer to the top of the stack_t
 * @line_number: the line of the instruction
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;

	if (temp == NULL)
		return;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 *
 * @stack: pointer to the top of the stack_t
 * @line_number: the line of the instruction
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		cleanup();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 *
 * @stack: pointer to the top of the stack_t
 * @line_number: the line of the instruction
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop, stack empty\n", line_number);
		cleanup();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	temp->prev = NULL;
	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: pointer to the top of the stack_t
 * @line_number: the line of the instruction
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		cleanup();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	temp->prev = *stack;
}
