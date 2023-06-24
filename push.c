#include "monty.h"

/**
 * push - push element at top of stack
 * @stack: adress of stack
 * @l: line number
 */

void push(stack_t **stack, unsigned int l)
{
	stack_t *t = malloc(sizeof(stack_t));
	int n;
	int i = 0;

	if (t == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (s[i])
	{
		if ((s[i] < 48 || s[i] > 57) && (s[i] != '+' && s[i] != '-'))
		{
			fprintf(stderr, "L%d: usage: push integer\n", l);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	n = atoi(s);
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
