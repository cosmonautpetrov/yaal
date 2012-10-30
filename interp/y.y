%{
	#include "stdio.h"
	#include "block.h"
	#include "string.h"
	#include "func.h"

	extern void* getsym(char* name);
	extern void* putsym(char* name, void* data, int type);
	extern int closesym();
	extern int funcgen();
	extern int eval(function* feval);

	int type_selector;
	void* sym_return;
%}

%token INT WORD NUMBER SENTENCE NVAL LOCALVAR PSTRING
%token SUB END CHAIN ROUTINE NEXT
%token OP_ADD OP_SUB OP_MUL OP_DIV
%token OPENP CLOSEP ENTER EXIT
%token SETAT GETAT ARRAY ASSIGN PRINT

%union {
	int num;
	char* word;
}

%token <num> LOCALVAR
%token <num> INT
%token <word> WORD
%token <word> PSTRING

%%
program:
	|ENTER {printf("ENTER\n");makefunction();} possiblestmt EXIT {printf("EXIT\n");printfunction();if(!findfunction("main"))printf("main not found, terminating\n");else printf("returned: %i\n", eval(findfunction("main")));}

varfunc: ROUTINE WORD {printf("ROUTINE %s\n", $2);makesym($2);makeblock($2);} ENTER possiblestmt EXIT {printsym();addfunction(returnfunction());closesym();closeblock();}

possiblestmt:
	|possiblestmt codestmt
	|possiblestmt declare

varstmt:
	vartype WORD {printf("%s\n", $2);if(!getsym($2))putsym($2, 0, type_selector);else printf("symbol %s already registered\n", $2);}

codestmt: 
	OPENP {printf("OPENP\n");addline(TYPE_OP, (void*)'[');} opstmt CLOSEP {printf("CLOSEP\n");addline(TYPE_OP, (void*)']');}

declare: varstmt
	|varfunc

vartype: NUMBER {printf("NUMBER\n");type_selector=TYPE_INT;}
	|SENTENCE	{printf("SENTENCE\n");type_selector=TYPE_STR;}

varval: INT 	{printf("INT %i\n", $1); addline(TYPE_INT, (void*)$1);}
	|WORD 		{printf("WORD %s\n", $1); addline(TYPE_STR, (void*)$1);}
	|LOCALVAR   {printf("LOCAL %c\n", (char)$1); addline(TYPE_LOC, (void*)$1);}
	|PSTRING    {printf("PSTRING %s\n", $1); addline(TYPE_PSTRING, (void*)$1);}

binop: OP_ADD	{printf("OP_ADD\n"); addline(TYPE_OP, (void*)'+');}
	| OP_SUB	{printf("OP_SUB\n"); addline(TYPE_OP, (void*)'-');}
	| OP_MUL	{printf("OP_MUL\n"); addline(TYPE_OP, (void*)'*');}
	| OP_DIV	{printf("OP_DIV\n"); addline(TYPE_OP, (void*)'/');}

datop: SETAT 	{printf("SETAT\n"); addline(TYPE_OP, (void*)'=');}
	| GETAT 	{printf("GETAT\n"); addline(TYPE_OP, (void*)'$');}
	| ARRAY		{printf("ARRAY\n"); addline(TYPE_OP, (void*)'#');}
	| PRINT     {printf("PRINT\n"); addline(TYPE_OP, (void*)'^');}

possiblearg: binop
	| varval
	| datop

opstmt: 
	|opstmt possiblearg
	|opstmt OPENP {printf("OPENP\n");chlevel(TYPE_EMB);addline(TYPE_OP, (void*)'[');} opstmt CLOSEP {printf("CLOSEP\n");chlevel(TYPE_LV);addline(TYPE_OP, (void*)']');}
%%