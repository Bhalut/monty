#include "monty.h"

/**
 * willy_malloc - free memory for malloc
 *
 * Return: void
 */
void willy_malloc(void)
{
	free(savior.getl_info);
	free(savior.command_struct);
	free_dlistint(savior.stack_head);
	fprintf(stderr, "Error: malloc failed\n");
	fclose(savior.fp_struct);
	exit(EXIT_FAILURE);
}
