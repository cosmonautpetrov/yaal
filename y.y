%{
	#include "stdio.h"

	extern void* getsym(char* name);
	extern void* putsym(char* name, void* data, int type);
	
%}

%token INT WORD SUB END ENTER EXIT CHAIN NUMBER SENTENCE ASSIGN ROUTINE NVAL NEXT
%token OP_ADD OP_SUB OP_MUL OP_DIV

%union {
	int num;
	char* word;
}

%token <num> INT
%token <word> WORD

%%
start: 
  program

program:
	|program func
	|program declare

func:
	SUB WORD {printf("function %s\n", $2);} ENTER varstmt CHAIN codestmt CHAIN retstmt EXIT 

varstmt:
	vartype WORD varassign
	|NVAL

varassign:
	|ASSIGN varval

codestmt: 
	codestmt opstmt 
	|NVAL
	
retstmt: WORD
	|INT
	|NVAL

declare: varstmt
	|varfunc
	;

vartype: NUMBER
	|SENTENCE
	;

varfunc: ROUTINE vartype WORD
	;

varval: INT
	|WORD
	;

binop: OP_ADD
	| OP_SUB
	| OP_MUL
	| OP_DIV

opstmt:
	varval binop varval cntopstmt

cntopstmt:
	|cntopstmt binop varval
	|cntopstmt ASSIGN varval 
%%