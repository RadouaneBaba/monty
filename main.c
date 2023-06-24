#include "monty.h"

/**
 * handleop - set the stack and handle instruction
 * @line: line in the file
 * @l: number of line
 * @cmd: instruction pointer
 * @stack: pointer to stack
 */
void handleop(char *line, unsigned int l, instruction_t *cmd, stack_t **stack)
{
	int i = 0;

	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	cmd->opcode = strtok(line, " ");

	if (strcmp(cmd->opcode, "push") == 0)
	{
		s = strtok(NULL, " ");
		cmd->f = push;
		cmd->f(stack, l);
	}
	else if (strcmp(cmd->opcode, "pall") == 0)
	{
		cmd->f = pall;
		cmd->f(stack, l);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", l, cmd->opcode);
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
	instruction_t *cmd = malloc(sizeof(instruction_t));

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
	if (cmd == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while ((n = getline(&line, &len, fp)) != -1)
	{
		if (line[0] == '\n')
		{
			l++;
			continue;
		}
		handleop(line, l, cmd, &stack);
		l++;
	}
	free(cmd);
	free(line);
	free_dlistint(stack);
	fclose(fp);
	return (0);
}
