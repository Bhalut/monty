#include "monty.h"

int opcode(char *file_line, stack_t **stack, unsigned int n_lines)
{
	char *command = NULL;
	char *push_number = NULL;
	unsigned int i;

	/* printf("El conteo va en: %d\n", n_lines); */
	instruction_t opcode_func[] = {
	    {"push", op_push},
	    {"pall", op_pall},
	    {NULL, NULL}};

	command = str_div(file_line); /* ACA HAY UN MALLOC */
	savior.command_struct = command;
	printf("el string del cmod es : %s\n", savior.command_struct);
	printf("el string del dmos es : %s\n", command);
	/* printf("El key actual es: %s...\n", key[0]); */
	if (strcmp(command, "push") == 0)
	{
		push_number = get_number(file_line, n_lines); /* ACA HAY UN MALLOC --LISTO */
		printf("el string del no es : %s\n", push_number);
		is_digit(push_number, n_lines);
		printf("Despues de la func is digit\n");
		savior.node_data = atoi(push_number);
		printf("El numero en entero es %d\n", savior.node_data);
		free(push_number);
	}
	i = 0;
	while (opcode_func[i].opcode != NULL)
	{
		/* printf("%s\n", opcode_func[i].opcode); */
		if (strcmp(opcode_func[i].opcode, command) == 0)
		{
			/* printf("im inside if\n"); */
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
	return (1);
}
