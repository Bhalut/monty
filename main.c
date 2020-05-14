#include "monty.h"

hero_t savior;

/**
 *  main -  interpreter for Monty ByteCodes files
 *  @argc: Number of paramethers
 *  @argv: Pointer to all the paramethers
 *
 *  Return: Always 0
 */
int main(int argc, char **argv)
{
	char *file_name = argv[1];
	size_t line_buf_size = 0;
	ssize_t line_size;
	unsigned int line_count = 0;
	FILE *fp = NULL;
	stack_t *main_stack = NULL;

	savior.stack_head = main_stack;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(file_name, "r");
	if (!fp)
	{
		fprintf(stderr, "Error opening file '%s'\n", file_name);
		exit(EXIT_FAILURE);
	}
	savior.fp_struct = fp;
	while ((line_size = getline(&savior.getl_info, &line_buf_size, fp)) != EOF)
	{
		line_count++;
		opcode(savior.getl_info, &savior.stack_head, line_count);
	}
	free(savior.getl_info);
	free(savior.command_struct);
	savior.getl_info = NULL;
	free_dlistint(savior.stack_head);
	fclose(fp);
	return (EXIT_SUCCESS);
}
