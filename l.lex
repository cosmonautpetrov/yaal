%{
#include "stdio.h"
#include "string.h"
#include "y.tab.h"
%}

%%
[ \t\n] /* white space, do nothing*/;
[a-z][a-zA-Z0-9]+				{ yylval.word=strdup(yytext);return WORD;}
[0-9]+							{ yylval.num=atoi(yytext);return INT;}
[:]								{ return CHAIN;}
[;]								{ return END;}
[@]								{ return SUB;}
[(]								{ return ENTER;}
[)]								{ return EXIT;}
%%