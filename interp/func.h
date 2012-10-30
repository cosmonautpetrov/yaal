#ifndef _FUNC_H_
#define _FUNC_H_
#include "block.h"
#include "symtable.h"

struct function
{
	char* funcname;
	symlnk* funcdata;
	codearg* functext;
	int textnum;
	int datanum;
};
typedef struct function function;

function* returnfunction();

void* addfunction(function*);
void* makefunction();
void* printfunction();
function* findfunction(char* name);

#endif