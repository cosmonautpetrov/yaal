#include "stdio.h"
#include "stdlib.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern codegen(char* filename);

int lineno=1;

int main(int argc, char** argv)
{
	if(argc < 3){
		printf("not enough args\n");
		return 0;
	}
	FILE* fptr = fopen(argv[1], "r");
  	yyin = fptr;
  	while(!(feof(yyin)))
  		yyparse();

  	codegen(argv[2]);
}

void yyerror(char* s)
{
	printf("syntax error at %i\n", lineno);
	exit(-1);
}