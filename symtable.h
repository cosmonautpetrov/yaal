#ifndef _SYMTABLE_H_
#define _SYMTABLE_H_

#include "stdlib.h"
#include "string.h"
#include "stdio.h"

struct symlnk
{
	struct symlnk *next;
	char* name;
	int type;
	union
	{
		int ival;
		char* sval;
	}dat;
};
typedef struct symlnk symlnk;

struct symlnktab
{
	symlnk** slt;
	int num;
	char** fnt;//function names
};
typedef struct symlnktab symlnktab;

#define HEAD -1

int makesym();
//makes a symbol table, !NULL on success
void* getsym(char* name, void* vret);
//returns NULL if not in symbol_table,else returns void* to data
void* putsym(char* name, void* data, int type);
//adds symbol to table,else updates data at symbol table
symlnk* returnsym();
//returns main symtable
int makesymlocal();
//makes a table of local tables
int addsymlocal(char* name);
//adds a local symbol table
void* getsymlocal(char* fname, char* vname, void* vret);
//returns NULL if not in local table, else returns void* to data
void* putsymlocal(char* fname, char* vname, void* data, int type);
//adds symbol to local table
void* printsym();

#endif