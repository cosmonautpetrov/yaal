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
		void* sval;
	}dat;
};
typedef struct symlnk symlnk;
#define HEAD -1

struct arrstruct
{
	void* buffer;
	int type;
	int max;
};
typedef struct arrstruct arrstruct;

int makesym(char*);
//makes a symbol table, !NULL on success
int closesym();
void* getsym(char* name);
//returns NULL if not in symbol_table,else returns void* to data
void* putsym(char* name, void* data, int type);
//adds symbol to table,else updates data at symbol table
symlnk* returnsym();
//returns main symtable
void* printsym();

//arrstruct functions
arrstruct* makearr(int type);
int writearr(arrstruct*, int val, int n);
int getarr(arrstruct*, int n);

#endif