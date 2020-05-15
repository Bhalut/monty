#include "monty.h"

/**
 * opcode - interpreter operations
 * @command: content line
 *
 * Return: void
 */
void opcode(char *command)
{
	unsigned int i = 0;
	instruction_t opcode_func[] = {
	    {"push", op_push},
	    {"pall", op_pall},
	    {NULL, NULL},
	};

	i = 0;
	while ((opcode_func[i].opcode != NULL))
	{
		if (strcmp(opcode_func[i].opcode, command) == 0)
		{
			opcode_func[i].f(&slayer.stack_head, slayer.n_lines);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", slayer.n_lines, command);
	free(slayer.getl_info);
	slayer_list(slayer.stack_head);
	fclose(slayer.fp_struct);
	exit(EXIT_FAILURE);
}
