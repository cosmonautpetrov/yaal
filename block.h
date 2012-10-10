#ifndef _BLOCK_H_
#define _BLOCK_H_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct codeline
{
	int op1;
	int op2;
	int typearg1;
	int typearg2;
	int typearg3;
	union
	{
		char* name;
		int val;
	}arg1;
	union
	{
		char* name;
		int val;
	}arg2;
	union
	{
		char* name;
		int val;
	}arg3;
};
typedef struct codeline codeline;

int addline(codeline*);
int makline();
int printline(codeline*);

#endif