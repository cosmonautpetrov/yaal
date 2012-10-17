#ifndef _BLOCK_H_
#define _BLOCK_H_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define TYPE_INT -1 //integer
#define TYPE_STR -2 //string
#define TYPE_EMB '[' //embedded block- used for parentheses
#define TYPE_OP  -4 //operator
#define TYPE_LV  ']' //leave embedded block

#define TYPE_OP_ADD '+'
#define TYPE_OP_SUB '-'
#define TYPE_OP_MUL '*'
#define TYPE_OP_DIV '/'
#define TYPE_OP_SET '=' //=
#define TYPE_OP_GET '$' //$
#define TYPE_OP_ARR '#' //#

#define TYPE_LOC -13//local

struct codearg
{
	int typearg; //type of argument
	int embedlevel; //current embed level
	char* name; //variable (look up in symtable)
	int val; //int value if its a constant, operator value for opp
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
int chlevel(int level); //changes embed level
int closeblock(); //saves current block
int printblock();
codearg* returnblock();

#endif