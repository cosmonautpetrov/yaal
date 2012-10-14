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
