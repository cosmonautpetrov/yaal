#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20111219

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "y.y"
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
#line 24 "y.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int num;
	char* word;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 45 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#define YYERROR_DECL() yyerror(const char *s)
#define YYERROR_CALL(msg) yyerror(msg)

extern int YYPARSE_DECL();

#define INT 257
#define WORD 258
#define NUMBER 259
#define SENTENCE 260
#define NVAL 261
#define LOCALVAR 262
#define PSTRING 263
#define SUB 264
#define END 265
#define CHAIN 266
#define ROUTINE 267
#define NEXT 268
#define OP_ADD 269
#define OP_SUB 270
#define OP_MUL 271
#define OP_DIV 272
#define OPENP 273
#define CLOSEP 274
#define ENTER 275
#define EXIT 276
#define SETAT 277
#define GETAT 278
#define SETATN 279
#define GETATN 280
#define ARRAYS 281
#define ARRAYN 282
#define ASSIGN 283
#define PRINT 284
#define OP_IF 285
#define OP_EQUAL 286
#define OP_LOOP 287
#define OP_LESS 288
#define OP_GREATER 289
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    2,    0,    4,    3,    1,    1,    1,    7,   10,
    5,    6,    6,    8,    8,    8,    8,   11,   11,   11,
   11,   12,   12,   12,   12,   13,   13,   13,   13,   13,
   14,   14,   14,   14,   14,   15,   15,   15,   15,    9,
    9,   16,    9,
};
static const short yylen[] = {                            2,
    0,    0,    4,    0,    6,    0,    2,    2,    2,    0,
    4,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    0,
    2,    0,    5,
};
static const short yydefred[] = {                         0,
    2,    0,    6,    0,   14,   15,    0,   10,    3,   16,
   17,   13,    7,    8,   12,    0,    4,   40,    9,    0,
    0,    6,   18,   19,   20,   21,   22,   23,   24,   25,
   42,   11,   26,   27,   28,   29,   30,   31,   32,   33,
   34,   35,   37,   36,   38,   39,   41,    0,   40,    5,
    0,   43,
};
static const short yydgoto[] = {                          2,
    4,    3,   12,   20,   13,   14,   15,   16,   21,   18,
   43,   44,   45,   46,   47,   49,
};
static const short yysindex[] = {                      -273,
    0,    0,    0, -201,    0,    0, -255,    0,    0,    0,
    0,    0,    0,    0,    0, -254,    0,    0,    0, -268,
 -257,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -191,    0,    0,
 -224,    0,
};
static const short yyrindex[] = {                         8,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const short yygindex[] = {                         0,
  -13,    0,    0,    0,    0,    0,    0,    0,  -39,    0,
    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 91
static const short yytable[] = {                         23,
   24,    1,   17,   19,   25,   26,   22,    1,   48,   51,
    0,   27,   28,   29,   30,   31,   32,    0,    0,   33,
   34,   35,   36,    0,    0,    0,   37,   38,   39,   40,
   41,   42,   23,   24,    0,    0,    0,   25,   26,    0,
    0,    0,    0,    0,   27,   28,   29,   30,   31,   52,
    0,    0,   33,   34,   35,   36,    0,    5,    6,   37,
   38,   39,   40,   41,   42,    7,    0,    5,    6,    0,
    0,    8,    0,    0,    9,    7,    0,    0,    0,   10,
   11,    8,    0,    0,   50,    0,    0,    0,    0,   10,
   11,
};
static const short yycheck[] = {                        257,
  258,  275,  258,  258,  262,  263,  275,    0,   22,   49,
   -1,  269,  270,  271,  272,  273,  274,   -1,   -1,  277,
  278,  279,  280,   -1,   -1,   -1,  284,  285,  286,  287,
  288,  289,  257,  258,   -1,   -1,   -1,  262,  263,   -1,
   -1,   -1,   -1,   -1,  269,  270,  271,  272,  273,  274,
   -1,   -1,  277,  278,  279,  280,   -1,  259,  260,  284,
  285,  286,  287,  288,  289,  267,   -1,  259,  260,   -1,
   -1,  273,   -1,   -1,  276,  267,   -1,   -1,   -1,  281,
  282,  273,   -1,   -1,  276,   -1,   -1,   -1,   -1,  281,
  282,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 289
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","WORD","NUMBER","SENTENCE",
"NVAL","LOCALVAR","PSTRING","SUB","END","CHAIN","ROUTINE","NEXT","OP_ADD",
"OP_SUB","OP_MUL","OP_DIV","OPENP","CLOSEP","ENTER","EXIT","SETAT","GETAT",
"SETATN","GETATN","ARRAYS","ARRAYN","ASSIGN","PRINT","OP_IF","OP_EQUAL",
"OP_LOOP","OP_LESS","OP_GREATER",
};
static const char *yyrule[] = {
"$accept : program",
"program :",
"$$1 :",
"program : ENTER $$1 possiblestmt EXIT",
"$$2 :",
"varfunc : ROUTINE WORD $$2 ENTER possiblestmt EXIT",
"possiblestmt :",
"possiblestmt : possiblestmt codestmt",
"possiblestmt : possiblestmt declare",
"varstmt : vartype WORD",
"$$3 :",
"codestmt : OPENP $$3 opstmt CLOSEP",
"declare : varstmt",
"declare : varfunc",
"vartype : NUMBER",
"vartype : SENTENCE",
"vartype : ARRAYS",
"vartype : ARRAYN",
"varval : INT",
"varval : WORD",
"varval : LOCALVAR",
"varval : PSTRING",
"binop : OP_ADD",
"binop : OP_SUB",
"binop : OP_MUL",
"binop : OP_DIV",
"datop : SETAT",
"datop : GETAT",
"datop : SETATN",
"datop : GETATN",
"datop : PRINT",
"condop : OP_IF",
"condop : OP_EQUAL",
"condop : OP_LOOP",
"condop : OP_LESS",
"condop : OP_GREATER",
"possiblearg : binop",
"possiblearg : varval",
"possiblearg : datop",
"possiblearg : condop",
"opstmt :",
"opstmt : opstmt possiblearg",
"$$4 :",
"opstmt : opstmt OPENP $$4 opstmt CLOSEP",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 2:
#line 36 "y.y"
	{printf("ENTER\n");makefunction();}
break;
case 3:
#line 36 "y.y"
	{printf("EXIT\n");printfunction();if(!findfunction("main"))printf("main not found, terminating\n");else printf("returned: %i\n", eval(findfunction("main")));}
break;
case 4:
#line 38 "y.y"
	{printf("ROUTINE %s\n", yystack.l_mark[0].word);makesym(yystack.l_mark[0].word);makeblock(yystack.l_mark[0].word);}
break;
case 5:
#line 38 "y.y"
	{printsym();addfunction(returnfunction());closesym();closeblock();}
break;
case 9:
#line 45 "y.y"
	{printf("%s\n", yystack.l_mark[0].word);if(!getsym(yystack.l_mark[0].word))putsym(yystack.l_mark[0].word, 0, type_selector);else printf("symbol %s already registered\n", yystack.l_mark[0].word);}
break;
case 10:
#line 48 "y.y"
	{printf("OPENP\n");addline(TYPE_OP, (void*)'[');}
break;
case 11:
#line 48 "y.y"
	{printf("CLOSEP\n");addline(TYPE_OP, (void*)']');}
break;
case 14:
#line 53 "y.y"
	{printf("NUMBER\n");type_selector=TYPE_INT;}
break;
case 15:
#line 54 "y.y"
	{printf("SENTENCE\n");type_selector=TYPE_STR;}
break;
case 16:
#line 55 "y.y"
	{printf("ARRAYS\n");type_selector=TYPE_ARRC;}
break;
case 17:
#line 56 "y.y"
	{printf("ARRAYN\n");type_selector=TYPE_ARRI;}
break;
case 18:
#line 58 "y.y"
	{printf("INT %i\n", yystack.l_mark[0].num); addline(TYPE_INT, (void*)yystack.l_mark[0].num);}
break;
case 19:
#line 59 "y.y"
	{printf("WORD %s\n", yystack.l_mark[0].word); addline(TYPE_STR, (void*)yystack.l_mark[0].word);}
break;
case 20:
#line 60 "y.y"
	{printf("LOCAL %c\n", (char)yystack.l_mark[0].num); addline(TYPE_LOC, (void*)yystack.l_mark[0].num);}
break;
case 21:
#line 61 "y.y"
	{printf("PSTRING %s\n", yystack.l_mark[0].word); addline(TYPE_PSTRING, (void*)yystack.l_mark[0].word);}
break;
case 22:
#line 63 "y.y"
	{printf("OP_ADD\n"); addline(TYPE_OP, (void*)'+');}
break;
case 23:
#line 64 "y.y"
	{printf("OP_SUB\n"); addline(TYPE_OP, (void*)'-');}
break;
case 24:
#line 65 "y.y"
	{printf("OP_MUL\n"); addline(TYPE_OP, (void*)'*');}
break;
case 25:
#line 66 "y.y"
	{printf("OP_DIV\n"); addline(TYPE_OP, (void*)'/');}
break;
case 26:
#line 68 "y.y"
	{printf("SETAT\n"); addline(TYPE_OP, (void*)'=');}
break;
case 27:
#line 69 "y.y"
	{printf("GETAT\n"); addline(TYPE_OP, (void*)'$');}
break;
case 28:
#line 70 "y.y"
	{printf("SETN\n");  addline(TYPE_OP, (void*)'s');}
break;
case 29:
#line 71 "y.y"
	{printf("GETN\n");  addline(TYPE_OP, (void*)'g');}
break;
case 30:
#line 72 "y.y"
	{printf("PRINT\n"); addline(TYPE_OP, (void*)'^');}
break;
case 31:
#line 74 "y.y"
	{printf("OP_IF\n"); addline(TYPE_OP, (void*)'?');}
break;
case 32:
#line 75 "y.y"
	{printf("OP_EQUAL\n"); addline(TYPE_OP, (void*)'e');}
break;
case 33:
#line 76 "y.y"
	{printf("OP_LOOP\n"); addline(TYPE_OP, (void*)'l');}
break;
case 34:
#line 77 "y.y"
	{printf("OP_LESS\n"); addline(TYPE_OP, (void*)'L');}
break;
case 35:
#line 78 "y.y"
	{printf("OP_GREATER\n"); addline(TYPE_OP, (void*)'G');}
break;
case 42:
#line 87 "y.y"
	{printf("OPENP\n");addline(TYPE_OP, (void*)'[');}
break;
case 43:
#line 87 "y.y"
	{printf("CLOSEP\n");addline(TYPE_OP, (void*)']');}
break;
#line 610 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
