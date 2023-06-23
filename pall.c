#include "monty.h"

/**
 * pall - print stack
 * @stack: adress
 * @l: number of line
 */

void pall(stack_t **stack, unsigned int l)
{
	stack_t *st = *stack;

	(void)l;
	if (*stack == NULL)
		return;
	while (st != NULL)
	{
		printf("%d\n", st->n);
		st = st->next;
	}
}
