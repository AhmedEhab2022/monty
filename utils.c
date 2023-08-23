#include "monty.h"

/**
 * cleanup - frees memory and closes file
 *
 * Return: void
 */
void cleanup(void)
{
	fclose(global.file);
	free(global.content);
}

/**
* free_stack - frees a doubly linked list
* @head: head of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
