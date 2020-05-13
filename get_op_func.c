#include "monty.h"

void (*get_func(char *operation))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t instructions[] = {
	    {"push", op_push},
	    {"pall", op_pall},
	    {"pint", op_pint},
	    {NULL, NULL},
	};

	while (strcmp(instructions[i].opcode, operation) != 0 && instructions[i].f != NULL)
		i++;

	return (instructions[i].f);
}

void op_push()
{
}

void op_pall()
{
}

void op_pint()
{
}
