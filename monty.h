#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_s - holds the data read from monty file
 * @data: the opcode
 * @fp: pointer to the file from command line
 * @line: instruction set on the current line
 * @stack: references the stack linked list
 * @line_number: line number for error handling
 */
typedef struct data_s
{
	int data;
	FILE *fp;
	char *line;
	stack_t *stack;
	unsigned int line_number;
} data_t;

/* global variable */
extern data_t *command;

/* operators.c */
void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/* printing.c */
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);

/* mathematics.c */
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/* controller.c */
void exec(char *str);
int search(char *opcode);
int isint(char *data_n);

/* malloc_free.c */
stack_t *alloc(void);
void free_node(void);

/* failcases.c */
void error(int, char *info);

/* Function Checkers */
#define NEED_ARGS     2
#define NO_ARGS       1
#define NULL_FUNC     0
#define SKIP_LINE     3

/* Error Codes */
#define NO_ARGS        1
#define NO_FILE        2
#define NO_DATA        3
#define PINT_FAIL      4
#define POP_FAIL       5
#define PCHAR_FAIL     6
#define NO_TWO_NODES   7
#define CANT_ADD       8
#define CANT_SUB       9
#define CANT_MUL       10
#define CANT_DIV       11
#define CANT_MOD       12
#define NE_NODE_PCHAR  13
#define ZERO_DATA_MOD  14
#define UNDEFINED      15
#define UNDEFINEDD     16
#define RANGE_FAIL     17
#define INVAL_LINE     18
#define MALLOC_FAIL    19


#endif