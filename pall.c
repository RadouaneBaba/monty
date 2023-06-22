#include "monty.h"

/**
 * pall - print stack
 * @stack: adress
 * @l: number of line
 */

void pall(stack_t **stack, unsigned int l)
{
	(void)l;
	stack_t s = *stack;

	if (*stack == NULL)
		return;
	while (s != NULL)
	{
		printf("%d\n", s->n);
		s = s->next;
	}
}
