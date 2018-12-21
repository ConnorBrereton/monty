#include "monty.h"


/**
 * alloc - creates a new node to add to the stack
 *
 * Return: new node
 */

stack_t *alloc(void)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		error(MALLOC_FAIL, NULL);

	return (new);
}


/**
 * free_node - deletes the first node in the stack
 *
 * Return: none
 */

void free_node(void)
{
	stack_t *node;

	node = command->stack;

	if (command->stack->next == NULL)
		command->stack = NULL;

	else
	{
		command->stack = command->stack->next;
		command->stack->prev = NULL;
	}

	free(node);
}
