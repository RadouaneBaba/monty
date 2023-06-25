#ifndef GLOBAL_H
#define GLOBAL_H

instruction_t ins[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{"div", divide},
	{"mul", mul},
	{"mod", mod}
};
const int SIZE = 11;

#endif
