#include "monty.h"

/**
 * push - push element into the stack
 *
 * @stack: stack given by main
 *
 * @line_cnt: amount of lines
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_cnt)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.argument)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.argument)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}
}

/**
 * pall - prints the stack
 *
 * @stack: stack given by main
 *
 * @line_cnt: amount of lines
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	print_stack(*stack);
}

/**
 * pint - print the top data
 *
 * @stack: stack given by main
 *
 * @line_cnt: amount of lines
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	printf("%d\n", (*stack)->n);
}

/**
* pop - pops the very top

* @stack: stack given by main

* @line_cnt: line number for error messages
*
* Return: void
*/

void pop(stack_t **stack, unsigned int line_cnt)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return; /* prevents errors because next line might assign a NULL */
	(*stack)->prev = NULL;
}
