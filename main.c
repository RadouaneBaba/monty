#include "monty.h"

char *s;

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
		if (line[i] == '\n' || line[i] == '$')
			line[i] = ' ';
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
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		perror("Error: Can't open file ");
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	if (cmd == NULL)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while ((n = getline(&line, &len, fp)) != -1)
	{
		handleop(line, l, cmd, &stack);
		l++;
	}
	free(cmd);
	free(line);
	fclose(fp);
	exit(EXIT_SUCCESS);


}
