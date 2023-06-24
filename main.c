#include "monty.h"

instruction_t ins[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop}
};
const int SIZE = 7;
/**
 * handleop - set the stack and handle instruction
 * @line: line in the file
 * @l: number of line
 * @stack: pointer to stack
 */
void handleop(char *line, unsigned int l, stack_t **stack)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	s = strtok(line, " ");
	if (s == NULL)
		return;
	while (j < SIZE)
	{
		if (strcmp(ins[j].opcode, s) == 0)
		{
			k = 1;
			ins[j].f(stack, l);
		}
		j++;
	}
	if (k == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", l, s);
		free(line);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
}
/**
 * main - Entry point
 * @argc: num of args
 * @argv: args vector
 * Return: 0 or error
 */

int main(int argc, char **argv)
{
	FILE *fp;
	size_t len = 0;
	unsigned int l = 1;
	ssize_t n;
	char *line = NULL;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((n = getline(&line, &len, fp)) != -1)
	{
		handleop(line, l, &stack);
		l++;
	}
	free(line);
	free_dlistint(stack);
	fclose(fp);
	return (0);
}
