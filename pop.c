#include "monty.h"

/**
 * pop - removes top element of stack
 * @stack: head of stack
 * @l: line number
 */

void pop(stack_t **stack, unsigned int l)
{
	stack_t *t;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", l);
		exit(EXIT_FAILURE);
	}
	t = *stack;

	*stack = (*stack)->next;
	free(t);
}
