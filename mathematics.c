#include "monty.h"


/**
 * add - adds the first two values in the stack
 *
 * @stack: double pointer to the stack
 *
 * @line_number: line number in the command file
 *
 * Return: none
 */

void add(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (!command->stack || !command->stack->next)
		error(CANT_ADD, NULL);

	/* adds first two values */
	command->stack->next->n += command->stack->n;

	/* removes pointer to first node */
	command->stack->next->prev = NULL;

	free_node(); /* removes first node */
}


/**
 * sub - subtracts the first two values in the stack
 *
 * @stack: double pointer to the stack
 *
 * @line_number: line number in the command file
 *
 * Return: none
 */

void sub(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (!command->stack || !command->stack->n)
		error(CANT_SUB, NULL);

	/* computes delta of first two values */
	command->stack->next->n -= command->stack->n;

	/* removes pointer to first node */
	command->stack->next->prev = NULL;

	free_node(); /* removes first node */
}


/**
 * _div - divides the first two values in the stack
 *
 * @stack: double pointer to the stack
 *
 * @line_number: line number in the command file
 *
 * Return: none
 */

void _div(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (!command->stack || !command->stack->n)
		error(CANT_DIV, NULL);

	if (command->stack->n == 0) /* checks if result would be undefined */
		error(UNDEFINED, NULL);

	/* computes quotient of first two values */
	command->stack->next->n /= command->stack->n;

	/* removes pointer to first node */
	command->stack->next->prev = NULL;

	free_node(); /* removes first node */
}


/**
 * mul - multiplies the first two values in the stack
 *
 * @stack: double pointer to the stack
 *
 * @line_number: line number in the command file
 *
 * Return: none
 */

void mul(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (!command->stack || !command->stack->n)
		error(CANT_DIV, NULL);

	/* computes product of first two nodes */
	command->stack->next->n *= command->stack->n;

	/* removes pointer to first node */
	command->stack->next->prev = NULL;

	free_node(); /* removes first node */
}


/**
 * mod - computes modulo of first two values in stack
 *
 * @stack: double pointer to the stack
 *
 * @line_number: line number in the command file
 *
 * Return: none
 */

void mod(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (!command->stack || !command->stack->n)
		error(CANT_MOD, NULL);

	if (command->stack->n == 0) /* checks if result would be undefined */
		error(UNDEFINED, NULL);

	/* computes modulus of first two nodes */
	command->stack->next->n %= command->stack->n;

	/* removes pointer to first node */
	command->stack->next->prev = NULL;

	free_node(); /* removes first node */
}
