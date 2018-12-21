#include "monty.h"

/**
 * push - adds a node to the stack
 *
 * @stack: double pointer to the stack
 *
 * @line_number: line number in the command file
 *
 * Return: none
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	(void) line_number;
	(void) stack;

	new_node = alloc();

	new_node->n = command->data;
	new_node->prev = NULL;

	if (!command->stack) /* case: one node */
	{
		new_node->next = NULL;
		command->stack = new_node;
	}
	else /* case: many nodes */
	{
		new_node->next = command->stack; /* sets to bottom of LL */
		command->stack->prev = new_node; /* sets bottom to newnode */
		command->stack = new_node; /* moves head ref up one spot */
	}
}


/**
 * pop - removes the first node from the stack
 *
 * @stack: double pointer to the stack
 *
 * @line_number: line number in the command file
 *
 * Return: none
 */

void pop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	if (!command->stack) /* if no node to pop */
		error(POP_FAIL, NULL);

	free_node(); /* removes first node */

}


/**
 * swap - swaps the first two elements in the stack
 *
 * @stack: double pointer to the stack
 *
 * @line_number: line number in the command file
 *
 * Return: none
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *second;
	(void) stack;
	(void) line_number;

	if (!command->stack || !command->stack->next)
		error(NO_TWO_NODES, NULL);

	second = command->stack->next; /* set first+1 node */

	command->stack->next = second->next; /* set bottom stack next to top */
	command->stack->prev = second;

	second->next = command->stack;
	second->prev = NULL;

	command->stack = second; /* reset reference to top */
}


/**
 * nop - literally does nothing
 *
 * @stack: double pointer to the stack
 *
 * @line_number: line number in the command file
 *
 * Return: none
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack; /* this function literally does nothing */
	(void) line_number;
}
