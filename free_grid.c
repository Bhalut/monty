#include "monty.h"

/**
 * free_dlistint - Frees a double linked list
 * @head: Address of the head of the linked list
 *
 * Return: Free list.
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp_1 = NULL, *tmp_2 = NULL;

	if (head == NULL)
	{
		return;
	}
	tmp_1 = head->next;
	while (tmp_1 != NULL)
	{
		tmp_2 = tmp_1->next;
		free(tmp_1);
		tmp_1 = tmp_2;
	}

	free(head);
}

/**
 * is_digit - check is digit
 * @number: character for check
 * @n_lines: number of line in file
 *
 * Return: void
 */
void is_digit(char *number, unsigned int n_lines)
{
	unsigned int i = 0;

	if (number == NULL)
	{
		free(number);
		free(savior.command_struct);
		free(savior.getl_info);
		free_dlistint(savior.stack_head); /* verificar */
		fclose(savior.fp_struct);
		fprintf(stderr, "L'%u': usage: push integer\n", n_lines);
		exit(EXIT_FAILURE);
	}
	if (number[0] != '-' && (number[0] < 48 || number[0] > 57))
	{
		free(number);
		free(savior.command_struct);
		free(savior.getl_info);
		free_dlistint(savior.stack_head);
		fclose(savior.fp_struct);
		fprintf(stderr, "L'%u': usage: push integer\n", n_lines);
		exit(EXIT_FAILURE);
	}
	for (i = 1; number[i] != '\0'; i++)
	{
		if (number[i] < 48 || number[i] > 57)
		{
			free(number);
			free(savior.command_struct);
			free(savior.getl_info);
			free_dlistint(savior.stack_head); /* verificar */
			fclose(savior.fp_struct);
			fprintf(stderr, "L'%u': usage: push integer\n", n_lines);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * str_div - divition by string
 * @str_to_div: string to check
 *
 * Return: split string
 */
char *str_div(char *str_to_div)
{
	char *str_aux = NULL;
	char *token = NULL;

	str_aux = strdup(str_to_div);
	if (str_aux == NULL)
	{
		return (NULL);
	}
	token = strtok(str_aux, " \n\t\r");

	return (token);
}
