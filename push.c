#include "monty.h"

char *s;

/**
 * push - push element at top of stack
 * @stack: adress of stack
 * @l: line number
 */

void push(stack_t **stack, unsigned int l)
{
	stack_t *t = malloc(sizeof(stack_t));
	int n = atoi(s);

	if (t == NULL)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (n == 0 && s[0] != '0')
	{
		printf("L%d: usage: push integer\n", l);
		exit(EXIT_FAILURE);
	}
	t->n = n;
	t->next = *stack;
	t->prev = NULL;
	if (*stack == NULL)
	{
		*stack = t;
		return;
	}
	(*stack)->prev = t;
	*stack = t;
}
