#ifndef GLOBAL_H
#define GLOBAL_H

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

#endif
