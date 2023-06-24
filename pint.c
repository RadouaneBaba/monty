#include "monty.h"

/**
 * pint - print the value at top
 * @stack: adress of stack
 * @l: line number
 */

void pint(stack_t **stack, unsigned int l)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", l);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
