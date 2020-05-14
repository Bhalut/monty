#include "monty.h"
/**
 * free_grid - frees a 2 dimensional grid previously created.
 * @grid: bidimensional array.
 * @height: height array.
 *
 * Return: pointer with the address of the array created.
 */
void free_grid(char **grid)
{
	int index;

	for (index = 0; grid[index] != NULL; index++)
	{
		free(grid[index]);
	}
	free(grid);
}
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
	if (number[0] != '-' && (number[0] < 48 || number[0] > 57))
	{
		free_grid(savior.grid);
		free(savior.getl_info);
		free_dlistint(savior.stack_head);
		fprintf(stderr, "L'%u': usage: push integer\n", n_lines);
		exit(EXIT_FAILURE);
	}
	for (i = 1; number[i] != '\0'; i++)
	{

		if (number[i] < 48 || number[i] > 57)
		{
			free_grid(savior.grid);
			free(savior.getl_info);
			free_dlistint(savior.stack_head);
			fprintf(stderr, "L'%u': usage: push integer\n", n_lines);
			exit(EXIT_FAILURE);
		}
	}
}