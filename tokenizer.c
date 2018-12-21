#include "monty.h"
#define DELIMS "\n \t"

data_t *command;

int main(int ac, char **av)
{
	char *token1;
	char *token2;
	size_t size = 0;
	int err;
	data_t arr = {0, NULL, NULL, NULL, 0};
	command = &arr;

	if (ac != 2)
		error(NO_ARGS, NULL);

	command->fp = fopen(av[1], "r");
	if (!command->fp)
		error(NO_FILE, av[1]);

	while (getline(&(command->line), &size, command->fp) != -1)
	{
		command->line_number++;

		token1 = strtok(command->line, DELIMS);
		token2 = strtok(NULL, DELIMS);

		if (token1 == NULL)
			err = SKIP_LINE;

		else
			err = search(token1);

		if (err == NULL_FUNC)
			error(INVAL_LINE, token1);

		if (err == NEED_ARGS)
		{
			/* copy the numerical data into the node */
			if (isint(token2))
				command->data = atoi(token2);

			else
				error(NO_DATA, NULL);
		}

		if (err != SKIP_LINE)
			exec(token1);
	}

	fclose(command->fp);
	free(command->line);

	while (command->stack)
		free_node();

	return (0);
}
