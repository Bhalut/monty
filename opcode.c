#include "monty.h"

int opcode(char *file_line, stack_t **stack, unsigned int n_lines)
{
	char **key = NULL;
	unsigned int i;

	/* printf("El conteo va en: %d\n", n_lines); */
	instruction_t opcode_func[] = {
	    {"push", op_push},
	    {"pall", op_pall},
	    {NULL, NULL}};

	key = str_to_2d(file_line, " \n");
	savior.grid = key;
	/* printf("El key actual es: %s...\n", key[0]); */
	if (strcmp(key[0], "push") == 0)
	{
		is_digit(key[1], n_lines);
		savior.node_data = atoi(key[1]);
	}
	i = 0;
	while (opcode_func[i].opcode != NULL)
	{
		/* printf("%s\n", opcode_func[i].opcode); */
		if (strcmp(opcode_func[i].opcode, key[0]) == 0)
		{
			/* printf("im inside if\n"); */
			opcode_func[i].f(stack, n_lines);
			free_grid(key);
			return (1);
		}
		i++;
	}
	free_grid(savior.grid);
	free(savior.getl_info);
	free_dlistint(savior.stack_head);
	fprintf(stderr, "L'%u': unknown instruction '%s'\n", n_lines, key[0]);
	exit(EXIT_FAILURE);
	return (1);
}
