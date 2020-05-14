#include "monty.h"
char *get_number(char *str_to_div, unsigned int n_lines)
{
	char *str_aux = NULL;
	char *token = NULL;

	str_aux = strdup(str_to_div);
	if (str_aux == NULL)
	{
		return (NULL);
	}
	token = strtok(str_aux, " \n\t\r");
	token = strtok(NULL, " \n\t\r");
	if (token == NULL)
	{
		free(str_aux);
		free(savior.command_struct);
		free(savior.getl_info);
		free_dlistint(savior.stack_head); /* verificar */
		fclose(savior.fp_struct);
		fprintf(stderr, "L'%u': usage: push integer\n", n_lines);
		exit(EXIT_FAILURE);
	}
	token = strdup(token);
	if (str_aux == NULL)
	{
		return (NULL);
	}
	free(str_aux);
	return (token);
}