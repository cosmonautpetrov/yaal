%{
#include "stdio.h"
#include "string.h"
#include "y.tab.h"
extern int lineno;
%}

%%
[ \t] /* white space, do nothing*/;
[\n]							{ lineno++;}
seta							{ return SETAT;}
geta							{ return GETAT;}
array							{ return ARRAY;}
print							{ return PRINT;}
null							{ return NVAL;}
number							{ return NUMBER;}
sentence						{ return SENTENCE;}
routine							{ return ROUTINE;}
add								{ return OP_ADD;}
sub								{ return OP_SUB;}
mul								{ return OP_MUL;}
div								{ return OP_DIV;}
[a-z]							{ yylval.num=(int)*yytext;return LOCALVAR;}
[a-z][a-zA-Z0-9]+				{ yylval.word=strdup(yytext);return WORD;}
[0-9]+							{ yylval.num=atoi(yytext);return INT;}
\".*\"							{ yylval.word=strdup(yytext);return PSTRING;}
[:]								{ return CHAIN;}
[,]								{ return NEXT;}
[;]								{ return END;}
[@]								{ return SUB;}
[(]								{ return ENTER;}
[)]								{ return EXIT;}
[\[]							{ return OPENP;}
[\]]							{ return CLOSEP;}
[=]								{ return ASSIGN;}
%%