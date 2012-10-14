%{
	#include "stdio.h"
	#include "block.h"
	#include "string.h"

	extern void* getsym(char* name);
	extern void* putsym(char* name, void* data, int type);

	int type_selector;
	void* sym_return;
%}

%token INT WORD NUMBER SENTENCE NVAL
%token SUB END CHAIN ROUTINE NEXT
%token OP_ADD OP_SUB OP_MUL OP_DIV
%token OPENP CLOSEP ENTER EXIT
%token SETAT GETAT ARRAY ASSIGN

%union {
	int num;
	char* word;
}

%token <num> INT
%token <word> WORD

%%
program:
	|program codestmt
	|program declare
	|program ENTER {makesym();makeblock(NULL);printf("ENTER\n");}
	|program EXIT {printblock();printsym();printf("EXIT\n");}

varstmt:
	vartype WORD {printf("%s\n", $2);if(!getsym($2))putsym($2, 0, TYPE_INT);else printf("symbol %s already registered\n", $2);}

codestmt: 
	|OPENP {printf("OPENP\n");} opstmt CLOSEP {printf("CLOSEP\n");}

declare: varstmt
	|varfunc

vartype: NUMBER {printf("NUMBER\n");type_selector=TYPE_INT;}
	|SENTENCE	{printf("SENTENCE\n");type_selector=TYPE_STR;}

varfunc: ROUTINE vartype WORD

varval: INT 	{printf("INT %i\n", $1); addline(TYPE_INT, (void*)$1);}
	|WORD 		{printf("WORD %s\n", $1); addline(TYPE_STR, (void*)$1);}

binop: OP_ADD	{printf("OP_ADD\n"); addline(TYPE_OP_ADD, (void*)'+');}
	| OP_SUB	{printf("OP_SUB\n"); addline(TYPE_OP_SUB, (void*)'-');}
	| OP_MUL	{printf("OP_MUL\n"); addline(TYPE_OP_MUL, (void*)'*');}
	| OP_DIV	{printf("OP_DIV\n"); addline(TYPE_OP_DIV, (void*)'/');}

datop: SETAT 	{printf("SETAT\n"); addline(TYPE_OP_SET, (void*)'=');}
	| GETAT 	{printf("GETAT\n"); addline(TYPE_OP_GET, (void*)'$');}
	| ARRAY		{printf("ARRAY\n"); addline(TYPE_OP_ARR, (void*)'#');}

possiblearg: binop
	| varval
	| datop

opstmt: 
	|opstmt possiblearg
	|opstmt OPENP {printf("OPENP\n");} opstmt CLOSEP {printf("CLOSEP\n");}
%%