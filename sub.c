#include "monty.h"

/**
 * sub - add the top two elements
 * @stack: adress of stack
 * @l: line number
 */

void sub(stack_t **stack, unsigned int l)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", l);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, l);
}
