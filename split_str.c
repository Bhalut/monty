#include "monty.h"

/**
 * split_str - divition by string
 * @str_to_split: string to check
 *
 * Return: split string
 */
char *split_str(char *str_to_split)
{
	char *token = NULL;
	char *command = NULL;

	token = strtok(str_to_split, " \n\t\r");
	command = token;
	if (strcmp(command, "push") == 0)
	{
		token = strtok(NULL, " \n\t\r");
		is_digit(token);
		slayer.node_data = atoi(token);
	}
	return (command);
}

/**
 * is_digit - check is digit
 * @number: character for check
 *
 * Return: void
 */
void is_digit(char *number)
{
	unsigned int i = 0;

	if (number == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", slayer.n_lines);
		free(slayer.getl_info);
		slayer_list(slayer.stack_head);
		fclose(slayer.fp_struct);
		exit(EXIT_FAILURE);
	}
	else if (number[0] != '-' && (number[0] < 48 || number[0] > 57))
	{
		fprintf(stderr, "L%u: usage: push integer\n", slayer.n_lines);
		free(slayer.getl_info);
		slayer_list(slayer.stack_head);
		fclose(slayer.fp_struct);
		exit(EXIT_FAILURE);
	}
	for (i = 1; number[i] != '\0'; i++)
	{
		if (number[i] < 48 || number[i] > 57)
		{
			fprintf(stderr, "L%u: usage: push integer\n", slayer.n_lines);
			free(slayer.getl_info);
			slayer_list(slayer.stack_head);
			fclose(slayer.fp_struct);
			exit(EXIT_FAILURE);
		}
	}
}
