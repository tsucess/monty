#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - frees a stack
 * @stack: pointer to the top stack or bottom queue
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;
	
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * int_stack - initializes a stack with ethe beginning
 *
 * @stack: a pointer to an stack
 *
 * Return: EXIT_FAILURE for error or EXIT_SUCCESS
 */

int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);

}

/**
 * check_mode - checks if a stackis or queue a linked list
 * @stack: pointer to the top of stack
 *
 * Return: if stack mode - STACK (0)
 * 	if queue mod - QUEUE (1) 
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);

}
