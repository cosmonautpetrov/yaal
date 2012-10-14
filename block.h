#ifndef _BLOCK_H_
#define _BLOCK_H_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define TYPE_INT -1 //integer
#define TYPE_STR -2 //string
#define TYPE_EMB -3 //embedded block- used for parentheses
#define TYPE_OP  -4 //operator

#define TYPE_OP_ADD -5
#define TYPE_OP_SUB -6
#define TYPE_OP_MUL -7
#define TYPE_OP_DIV -8
#define TYPE_OP_SET -9 //=
#define TYPE_OP_GET -10 //$
#define TYPE_OP_ARR -11 //#

struct codearg
{
	int typearg; //type of argument

	char* name; //variable (look up in symtable)
	int val; //int value if its a constant, operator value for opp
	struct codearg* p_codearg; //pointer to a pointer below
};
typedef struct codearg codearg;

struct codeblock
{
	char* routname; //name of the routine
	codearg* codelist;
};
typedef struct codeblock codeblock;

int makeblock(char* routine); //makes block
int addline(int typearg, void* argitself); //adds to current block
int closeblock(); //saves current block
int printblock();

#endif