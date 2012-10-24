#define INT 257
#define WORD 258
#define NUMBER 259
#define SENTENCE 260
#define NVAL 261
#define LOCALVAR 262
#define SUB 263
#define END 264
#define CHAIN 265
#define ROUTINE 266
#define NEXT 267
#define OP_ADD 268
#define OP_SUB 269
#define OP_MUL 270
#define OP_DIV 271
#define OPENP 272
#define CLOSEP 273
#define ENTER 274
#define EXIT 275
#define SETAT 276
#define GETAT 277
#define ARRAY 278
#define ASSIGN 279
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
