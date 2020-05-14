#include "monty.h"

/**
 * opcode - interpreter operations
 * @file_line: content line
 * @stack: stack structure
 * @n_lines: number of line in file
 *
 * Return: 1 operation macth
 */
int opcode(char *file_line, stack_t **stack, unsigned int n_lines)
{
	char *command = NULL;
	char *push_number = NULL;
	unsigned int i = 0;

	instruction_t opcode_func[] = {
	    {"push", op_push},
	    {"pall", op_pall},
	    {NULL, NULL},
	};

	command = str_div(file_line);
	savior.command_struct = command;
	if (strcmp(command, "push") == 0)
	{
		push_number = get_number(file_line, n_lines);
		is_digit(push_number, n_lines);
		savior.node_data = atoi(push_number);
		free(push_number);
	}
	while (opcode_func[i].opcode != NULL)
	{
		if (strcmp(opcode_func[i].opcode, command) == 0)
		{
			opcode_func[i].f(stack, n_lines);
			return (1);
		}
		i++;
	}
	free(savior.getl_info);
	free_dlistint(savior.stack_head);
	fclose(savior.fp_struct);
	fprintf(stderr, "L'%u': unknown instruction '%s'\n", n_lines, command);
	free(command);
	exit(EXIT_FAILURE);
}
