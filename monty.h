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
 * @n_lines: lines counter
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
	FILE *fp_struct;
	stack_t *stack_head;
	char *getl_info;

	int node_data;
	unsigned int n_lines;

} hero_t;

extern hero_t slayer;

/* Aux Functions */
char *split_str(char *str_to_split);
void is_digit(char *number);
void opcode(char *command);
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void slayer_list(stack_t *head);

#endif /* MONTY_H */
