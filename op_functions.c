#include "monty.h"

/**
 * op_push - adds a new node at the stack
 * @stack: pointer to the head of the stack
 * @line_number: number of the current line
 *
 * Return: void.
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	stack_t *new = NULL;

	line_number = line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free(slayer.getl_info);
		fclose(slayer.fp_struct);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = slayer.node_data;
	if (*stack != NULL)
	{
		tmp = *stack;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		new->prev = tmp;
		tmp->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		new->next = NULL;
		new->prev = NULL;
	}
}

/**
 * op_pall - prints all the values on the stack
 * @stack: pointer to the head of the stack
 * @line_number: number of the current line
 *
 * Return: void.
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *printer_aux = *stack;

	line_number = line_number;
	if (printer_aux == NULL)
	{
		return;
	}
	while (printer_aux->next != NULL)
	{
		printer_aux = printer_aux->next;
	}
	while (printer_aux != NULL)
	{
		printf("%d\n", printer_aux->n);
		printer_aux = printer_aux->prev;
	}
}
