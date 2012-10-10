#include "stdio.h"
#include "stdlib.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

extern int makesym();
extern void* getsym(char* name, void* vret);
extern void* putsym(char* name, void* data, int type);

int lineno=1;

int main(int argc, char** argv)
{
	if(argc == 1){
		printf("not enough args\n");
		return 0;
	}
	FILE* fptr = fopen(argv[1], "r");
  	yyin = fptr;
  	while(!(feof(yyin)))
  		yyparse();
}

void yyerror(char* s)
{
	printf("syntax error at %i\n", lineno);
	exit(-1);
}