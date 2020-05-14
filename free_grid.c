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
void is_digit(char *number, unsigned int n_lines)
{
	unsigned int i;

	/* printf("el numero actual es: %s\n", number);
	printf("n_lines es: %u\n", n_lines); */
	printf("Estoy en is digit\n");
	printf("El no es : %s\n", number);
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
		printf("Diferente de digito\n");
		printf("Libero number %s\n", number);
		free(number);
		printf("Libero el comando %s\n", savior.command_struct);
		free(savior.command_struct);
		printf("Libero el getline %s\n", savior.getl_info);
		free(savior.getl_info);
		printf("Libero el stack\n");
		free_dlistint(savior.stack_head);
		printf("Cierro el file \n");
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