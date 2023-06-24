#include "monty.h"

/**
 * swap - swap the top two elements
 * @stack: adress of stack
 * @l: line number
 */

void swap(stack_t **stack, unsigned int l)
{
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = n;
}
