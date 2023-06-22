#include "monty.h"

void mont_add(stack_t **stack, unsigned int line_number);
void mont_sub(stack_t **stack, unsigned int line_number);
void mont_div(stack_t **stack, unsigned int line_number);
void mont_mul(stack_t **stack, unsigned int line_number);
void mont_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - This adds the top two values of a stack_t linked list
 * @stack: a pointer to the top most node of stack_t linked list
 * @line_number: Ther current working line number of monty bytecodes file
 *
 * Description: THe result is stored in the second value node from the top
 *
 */

void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->nest == NULL)
		set_op_tok_error(shor_stack_error(line_number, "add"));
		return;
	
	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - This subtracts the top two values of a stack_t linked list
 * @stack: a pointer to the top most node of stack_t linked list
 * @line_number: Ther current working line number of monty bytecodes file
 * 
 * Description: THe result is stored in the second value node from the top
 */

void monty_sub(stack_t **stack, unsigned int line_number)
{
        if ((*stack)->next == NULL || (*stack)->next->nest == NULL)
                set_op_tok_error(shor_stack_error(line_number, "sub"));
                return;

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - This divides the top two values of a stack_t linked list
 * @stack: a pointer to the top most node of stack_t linked list
 * @line_number: Ther current working line number of monty bytecodes file
 *
 * Description: THe result is stored in the second value node from the top
 */


void monty_div(stack_t **stack, unsigned int line_number)
{
        if ((*stack)->next == NULL || (*stack)->next->nest == NULL)
                set_op_tok_error(shor_stack_error(line_number, "div"));
                return;

	if ((*stack)->next->n == 0)
		set_op_tok_error(div_error(line_number));
		return;
	
	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - This multiplies the top two values of a stack_t linked list
 * @stack: a pointer to the top most node of stack_t linked list
 * @line_number: Ther current working line number of monty bytecodes file
 *
 * Description: THe result is stored in the second value node from the top
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
        if ((*stack)->next == NULL || (*stack)->next->nest == NULL)
                set_op_tok_error(shor_stack_error(line_number, "mul"));
                return;

        (*stack)->next->next->n *= (*stack)->next->n;
        monty_pop(stack, line_number);
}

/**
 * monty_mod - This divides the top two values of a stack_t linked list
 * @stack: a pointer to the top most node of stack_t linked list
 * @line_number: Ther current working line number of monty bytecodes file
 *
 * Description: THe result is stored in the second value node from the top
 */


void monty_mod(stack_t **stack, unsigned int line_number)
{
        if ((*stack)->next == NULL || (*stack)->next->nest == NULL)
                set_op_tok_error(shor_stack_error(line_number, "mod"));
                return;

        if ((*stack)->next->n == 0)
                set_op_tok_error(div_error(line_number));
                return;
 
        (*stack)->next->next->n %= (*stack)->next->n;
        monty_pop(stack, line_number);
}
