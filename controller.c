#include "monty.h"


/**
 * exec - array of function pointers to execute
 *
 * @str: string parsed that is the command to execute
 *
 * Return: none
 */

void exec(char *str)
{
	int i;
	stack_t **node = NULL;

	instruction_t controller[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pchar", pchar},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"nop", nop},
		{"#", nop},
		{NULL, NULL}
	};

	/* iterates array of function pointers */
	for (i = 0; controller[i].opcode != NULL; i++)
	{
		/* execute if match is found */
		if (strcmp(str, controller[i].opcode) == 0)
			controller[i].f(node, command->line_number);
	}
}


/**
 * search - returns error code from iterating array of commands
 *
 * @opcode: opcode taken in from file
 *
 * Return: see error codes
 */

int search(char *opcode)
{
	int i;

	instruction_t controller[] = {
		{"push", NULL},
		{"pall", NULL},
		{"pint", NULL},
		{"pchar", NULL},
		{"pop", NULL},
		{"swap", NULL},
		{"add", NULL},
		{"sub", NULL},
		{"div", NULL},
		{"mul", NULL},
		{"mod", NULL},
		{"nop", NULL},
		{"#", NULL},
		{NULL, NULL}
	};

	for (i = 0; controller[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, controller[i].opcode) == 0)
		{
			/* checks for valid arguments */
			if (strcmp(opcode, controller[0].opcode) == 0)
				return (NEED_ARGS);
			else
				return (NO_ARGS);
		}
	}
	return (NULL_FUNC);
}


/**
 * isint - checks if the command in the .m file has ints
 *
 * @str: command stream
 *
 * Return: 0 (not int) 1 (is int)
 */

int isint(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (isdigit(str[i]) == 0 && str[i] != '-')
			return (0);
	}
	return (1);
}
