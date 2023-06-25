#include "monty.h"

/**
 * divide - divide the top two elements
 * @stack: adress of stack
 * @l: line number
 */

void divide(stack_t **stack, unsigned int l)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", l);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, l);
}
