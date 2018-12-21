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
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case NO_FILE:
			fprintf(stderr, "Error: Can't open file %s\n", info);
			break;
		case NO_DATA:
			fprintf(stderr, "L%d: usage: push integer\n", command->line_number);
			break;
		case PINT_FAIL:
			fprintf(stderr, "L%d: can't pint, stack empty\n", command->line_number);
			break;
		case POP_FAIL:
			fprintf(stderr, "L%d: can't pop an empty stack\n", command->line_number);
			break;
		case NO_TWO_NODES:
			fprintf(stderr, "L%d: can't swap, stack too short\n", command->line_number);
			break;
		case CANT_ADD:
			fprintf(stderr, "L%d: can't add, stack too short\n", command->line_number);
			break;
		case CANT_SUB:
			fprintf(stderr, "L%d: can't sub, stack too short\n", command->line_number);
			break;
		case CANT_DIV:
			fprintf(stderr, "L%d: can't div, stack too short\n", command->line_number);
			break;
		case CANT_MUL:
			fprintf(stderr, "L%d: can't mul, stack too short\n", command->line_number);
			break;
		case CANT_MOD:
			fprintf(stderr, "L%d: can't mod, stack too short\n", command->line_number);
			break;
		case PCHAR_FAIL:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", command->line_number);
			break;
		case UNDEFINED:
		case UNDEFINEDD:
			fprintf(stderr, "L%d: division by zero\n", command->line_number);
			break;
		case RANGE_FAIL:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", command->line_number);
			break;
		case INVAL_LINE:
			fprintf(stderr, "L%d: unknown instruction %s\n", command->line_number, info);
			break;
		case MALLOC_FAIL:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			fprintf(stdout, "code works!\n");
	}
	if (command->fp)
		fclose(command->fp);

	if (command->line)
		free(command->line);

	while (command->stack)
		free_node();

	exit(EXIT_FAILURE);
}
