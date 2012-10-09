%{
	#include "stdio.h"

	extern void* getsym(char* name);
	extern void* putsym(char* name, void* data, int type);
	
%}

%token INT WORD SUB END ENTER EXIT CHAIN

%union {
	int num;
	char* word;
}

%token <num> INT
%token <word> WORD

%%
start:
	func
	;

stmt: INT stmt 	{printf("int %i\n", $1);}	
	| WORD stmt	{printf("word %s\n", $1);}
	| END  stmt 
	|;

func:
	SUB WORD ENTER stmt EXIT {printf("function %s\n", $2);}
%%