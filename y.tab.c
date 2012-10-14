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

	extern void* getsym(char* name);
	extern void* putsym(char* name, void* data, int type);

	int type_selector;
	void* sym_return;
#line 19 "y.y"
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
#line 41 "y.tab.c"

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
#define SUB 262
#define END 263
#define CHAIN 264
#define ROUTINE 265
#define NEXT 266
#define OP_ADD 267
#define OP_SUB 268
#define OP_MUL 269
#define OP_DIV 270
#define OPENP 271
#define CLOSEP 272
#define ENTER 273
#define EXIT 274
#define SETAT 275
#define GETAT 276
#define ARRAY 277
#define ASSIGN 278
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    3,    1,    6,    1,    2,
    2,    4,    4,    7,    8,    8,    9,    9,    9,    9,
   10,   10,   10,   11,   11,   11,    5,    5,   12,    5,
};
static const short yylen[] = {                            2,
    0,    2,    2,    2,    2,    2,    0,    0,    4,    1,
    1,    1,    1,    3,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    0,    2,    0,    5,
};
static const short yydefred[] = {                         1,
    0,   12,   13,    0,    8,    4,    5,    2,    3,   10,
    0,   11,    0,   27,    6,   14,    0,   15,   16,   17,
   18,   19,   20,   29,    9,   21,   22,   23,   25,   24,
   26,   28,   27,    0,   30,
};
static const short yydgoto[] = {                          1,
    8,    9,   10,   11,   17,   14,   12,   29,   30,   31,
   32,   33,
};
static const short yysindex[] = {                         0,
 -227,    0,    0, -256,    0,    0,    0,    0,    0,    0,
 -253,    0, -252,    0,    0,    0, -257,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -241,    0,
};
static const short yyrindex[] = {                         0,
    2,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,    3,  -25,    0,    0,    0,    0,    0,
    0,    0,
};
#define YYTABLESIZE 47
static const short yytable[] = {                         18,
   19,    7,    2,    3,   15,   16,   13,   34,    0,   20,
   21,   22,   23,   24,   25,   18,   19,   26,   27,   28,
    0,    0,    0,    0,    0,   20,   21,   22,   23,   24,
   35,    2,    3,   26,   27,   28,    0,    4,    0,    0,
    0,    0,    0,    5,    0,    6,    7,
};
static const short yycheck[] = {                        257,
  258,    0,  259,  260,  258,  258,    4,   33,   -1,  267,
  268,  269,  270,  271,  272,  257,  258,  275,  276,  277,
   -1,   -1,   -1,   -1,   -1,  267,  268,  269,  270,  271,
  272,  259,  260,  275,  276,  277,   -1,  265,   -1,   -1,
   -1,   -1,   -1,  271,   -1,  273,  274,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 278
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","WORD","NUMBER","SENTENCE",
"NVAL","SUB","END","CHAIN","ROUTINE","NEXT","OP_ADD","OP_SUB","OP_MUL","OP_DIV",
"OPENP","CLOSEP","ENTER","EXIT","SETAT","GETAT","ARRAY","ASSIGN",
};
static const char *yyrule[] = {
"$accept : program",
"program :",
"program : program codestmt",
"program : program declare",
"program : program ENTER",
"program : program EXIT",
"varstmt : vartype WORD",
"codestmt :",
"$$1 :",
"codestmt : OPENP $$1 opstmt CLOSEP",
"declare : varstmt",
"declare : varfunc",
"vartype : NUMBER",
"vartype : SENTENCE",
"varfunc : ROUTINE vartype WORD",
"varval : INT",
"varval : WORD",
"binop : OP_ADD",
"binop : OP_SUB",
"binop : OP_MUL",
"binop : OP_DIV",
"datop : SETAT",
"datop : GETAT",
"datop : ARRAY",
"possiblearg : binop",
"possiblearg : varval",
"possiblearg : datop",
"opstmt :",
"opstmt : opstmt possiblearg",
"$$2 :",
"opstmt : opstmt OPENP $$2 opstmt CLOSEP",

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
case 4:
#line 31 "y.y"
	{makesym();makeblock(NULL);printf("ENTER\n");}
break;
case 5:
#line 32 "y.y"
	{printblock();printsym();printf("EXIT\n");}
break;
case 6:
#line 35 "y.y"
	{printf("%s\n", yystack.l_mark[0].word);if(!getsym(yystack.l_mark[0].word))putsym(yystack.l_mark[0].word, 0, TYPE_INT);else printf("symbol %s already registered\n", yystack.l_mark[0].word);}
break;
case 8:
#line 38 "y.y"
	{printf("OPENP\n");}
break;
case 9:
#line 38 "y.y"
	{printf("CLOSEP\n");}
break;
case 12:
#line 43 "y.y"
	{printf("NUMBER\n");type_selector=TYPE_INT;}
break;
case 13:
#line 44 "y.y"
	{printf("SENTENCE\n");type_selector=TYPE_STR;}
break;
case 15:
#line 48 "y.y"
	{printf("INT %i\n", yystack.l_mark[0].num); addline(TYPE_INT, (void*)yystack.l_mark[0].num);}
break;
case 16:
#line 49 "y.y"
	{printf("WORD %s\n", yystack.l_mark[0].word); addline(TYPE_STR, (void*)yystack.l_mark[0].word);}
break;
case 17:
#line 51 "y.y"
	{printf("OP_ADD\n"); addline(TYPE_OP_ADD, (void*)'+');}
break;
case 18:
#line 52 "y.y"
	{printf("OP_SUB\n"); addline(TYPE_OP_SUB, (void*)'-');}
break;
case 19:
#line 53 "y.y"
	{printf("OP_MUL\n"); addline(TYPE_OP_MUL, (void*)'*');}
break;
case 20:
#line 54 "y.y"
	{printf("OP_DIV\n"); addline(TYPE_OP_DIV, (void*)'/');}
break;
case 21:
#line 56 "y.y"
	{printf("SETAT\n"); addline(TYPE_OP_SET, (void*)'=');}
break;
case 22:
#line 57 "y.y"
	{printf("GETAT\n"); addline(TYPE_OP_GET, (void*)'$');}
break;
case 23:
#line 58 "y.y"
	{printf("ARRAY\n"); addline(TYPE_OP_ARR, (void*)'#');}
break;
case 29:
#line 66 "y.y"
	{printf("OPENP\n");}
break;
case 30:
#line 66 "y.y"
	{printf("CLOSEP\n");}
break;
#line 508 "y.tab.c"
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
