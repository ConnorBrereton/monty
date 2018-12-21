#include "monty.h"

/**
 * error - handles error codes and prints out the approriate failure
 *
 * @error: integer that correlates to a specific error type
 *
 * @info: file name
 *
 * Return: none
 */

void error(int error, char *info)
{
	(void) info;

	switch (error)
	{
		case NO_ARGS:
			printf("USAGE: monty file\n");
			break;
		case NO_FILE:
			printf("Error: Can't open file %s\n", info);
			break;
		case NO_DATA:
			printf("L%d: usage: push integer\n", command->line_number);
			break;
		case PINT_FAIL:
			printf("L%d: can't pint, stack empty\n", command->line_number);
			break;
		case POP_FAIL:
			printf("L%d: can't pop an empty stack\n", command->line_number);
			break;
		case NO_TWO_NODES:
			printf("L%d: can't swap, stack too short\n", command->line_number);
			break;
		case CANT_ADD:
			printf("L%d: can't add, stack too short\n", command->line_number);
			break;
		case CANT_SUB:
			printf("L%d: can't sub, stack too short\n", command->line_number);
			break;
		case CANT_DIV:
			printf("L%d: can't div, stack too short\n", command->line_number);
			break;
		case CANT_MUL:
			printf("L%d: can't mul, stack too short\n", command->line_number);
			break;
		case CANT_MOD:
			printf("L%d: can't mod, stack too short\n", command->line_number);
			break;
		case PCHAR_FAIL:
			printf("L%d: can't pchar, stack empty\n", command->line_number);
			break;
		case UNDEFINED:
		case UNDEFINEDD:
			printf("L%d: division by zero\n", command->line_number);
			break;
		case RANGE_FAIL:
			printf("L%d: can't pchar, value out of range\n", command->line_number);
			break;
		case INVAL_LINE:
			printf("L%d: unknown instruction %s\n", command->line_number, info);
			break;
		case MALLOC_FAIL:
			printf("Error: malloc failed\n");
			break;
		default:
			printf("code works!\n");
	}
	if (command->fp)
		fclose(command->fp);

	if (command->line)
		free(command->line);

	while (command->stack)
		free_node();

	exit(EXIT_FAILURE);
}
