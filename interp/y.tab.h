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
#define ARRAY 279
#define ASSIGN 280
#define PRINT 281
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
extern YYSTYPE yylval;
