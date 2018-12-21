#include "monty.h"

/**
 * pall - prints all values in the stack
 *
 * @stack: double pointer to the stack
 *
 * @line_number: line number in the command file
 *
 * Return: none
 */


void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void) stack;
	(void) line_number;

	node = command->stack; /* sets to top of LL */

	while (node) /* loop and print */
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}


/**
 * pint - prints the member of the first node
 *
 * @stack: double pointer to the stack
 *
 * @line_number: line number in the command file
 *
 * Return: none
 */

void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (!command->stack)
		error(PINT_FAIL, NULL);

	printf("%d\n", command->stack->n); /* prints first value */
}


/**
 * pchar - prints the character representation of first member value
 *
 * @stack: double pointer to the stack
 *
 * @line_number: line number in the command file
 *
 * Return: none
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (!command->stack)
		error(PCHAR_FAIL, NULL);

	/* check ASCII upper/lower bound */
	if (command->stack->n <= 127 && command->stack->n >= 0)
		error(RANGE_FAIL, NULL);

	putchar(command->stack->n);
	printf("\n");
}
