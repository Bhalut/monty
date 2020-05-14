#include "monty.h"
hero savior;
/**
 *  main -  interpreter for Monty ByteCodes files
 *  @argc: Number of paramethers
 *  @argv: Pointer to all the paramethers
 * 
 *  Return: Always 0
 */
int main(int argc, char **argv)
{
	/* Open the file for reading */
	char *line_buf = NULL, *file_name = argv[1];
	size_t line_buf_size = 0;
	ssize_t line_size;
	unsigned int line_count = 0;
	FILE *fp;
	stack_t *main_stack = NULL;

	main_stack = NULL;
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
	/* Get the first line of the file. */
	line_size = getline(&line_buf, &line_buf_size, fp);
	savior.getl_info = line_buf;
	/* Loop through until we are done with the file. */
	while (line_size >= 0)
	{
		/* Increment our line count */
		line_count++;
		/* Function Call to identity the op */
		opcode(line_buf, &main_stack, line_count);
		/* Show the line details */
		/* printf("line[%06d]: contents: %s", line_count, line_buf); */
		/* Get the next line */
		line_size = getline(&line_buf, &line_buf_size, fp);
		savior.getl_info = line_buf;
	}
	/* Free the allocated line buffer */
	free(line_buf);
	line_buf = NULL;
	free_grid(savior.grid);
	free_dlistint(savior.stack_head);
	/* Close the file now that we are done with it */
	fclose(fp);
	return (EXIT_SUCCESS);
}
