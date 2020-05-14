#ifndef MONTY_H
#define MONTY_H

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct hero_s - funtional data for project
 * @command_struct: intruction
 * @stack_head: stack head
 * @fp_struct: file
 * @getl_info: line content
 * @node_data: data node number
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct hero_s
{
	char *command_struct;
	stack_t *stack_head;
	char *getl_info;
	FILE *fp_struct;
	int node_data;

} hero_t;

/* Global variable */
extern hero_t savior;

/* Prototypes */
int opcode(char *file_line, stack_t **stack, unsigned int n_lines);
char *get_number(char *str_to_div, unsigned int n_lines);
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void is_digit(char *number, unsigned int n_lines);
char **str_to_2d(char *buff_str, char del[]);
void free_dlistint(stack_t *head);
char *str_div(char *str_to_div);
void free_grid(char **grid);
void willy_malloc();

#endif /* MONTY_H */
