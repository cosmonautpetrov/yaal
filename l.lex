%{
#include "stdio.h"
#include "string.h"
#include "y.tab.h"
extern int lineno;
%}

%%
[ \t] /* white space, do nothing*/;
[\n]							{ lineno++;}
null							{ return NVAL;}
number							{ return NUMBER;}
sentence						{ return SENTENCE;}
routine							{ return ROUTINE;}
[a-z][a-zA-Z0-9]+				{ yylval.word=strdup(yytext);return WORD;}
[0-9]+							{ yylval.num=atoi(yytext);return INT;}
[:]								{ return CHAIN;}
[,]								{ return NEXT;}
[;]								{ return END;}
[@]								{ return SUB;}
[(]								{ return ENTER;}
[)]								{ return EXIT;}
[=]								{ return ASSIGN;}
[+]								{ return OP_ADD;}
[-]								{ return OP_SUB;}
[*]								{ return OP_MUL;}
[/]								{ return OP_DIV;}
%%