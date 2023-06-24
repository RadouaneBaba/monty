#include "monty.h"

/**
 * add - add the top two elements
 * @stack: adress of stack
 * @l: line number
 */

void add(stack_t **stack, unsigned int l)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, l);
}
