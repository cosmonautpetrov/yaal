#include "stdlib.h"
#include "string.h"

#define HEAD -1

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

symlnk *symbol_table;
symlnk *head;

symlnktab *symbol_tables_local;
symlnk *head_local;

int makesym();
//makes a symbol table, !NULL on success
void* getsym(char* name, void* vret);
//returns NULL if not in symbol_table,else returns void* to data
void* putsym(char* name, void* data, int type);
//adds symbol to table,else updates data at symbol table
int makesymlocal();
//makes a table of local tables
int addsymlocal(char* name);
//adds a local symbol table
void* getsymlocal(char* fname, char* vname, void* vret);
//returns NULL if not in local table, else returns void* to data
void* putsymlocal(char* fname, char* vname, void* data, int type);
//adds symbol to local table

int makesym()
{
	symbol_table = calloc(101, sizeof(symlnk));
	head = symbol_table;
	if(symbol_table)
		return 1;
	else
		return 0;
}

void* putsym(char* name, void* data, int type)
{
	head->name = (char*)malloc(strlen(name)+1);
	strcpy(head->name, name);
	if(type == -2){
		head->dat.ival = (int)data;
		head->type = type;
		head->next = head++;}
	return (void*)1;
}

void* getsym(char* name, void* vret)
{
	symlnk* tmp = symbol_table;
	while(tmp)
	{
		if(!strcmp(tmp->name, name)){
			if(tmp->type == -2){
				if(vret)
					vret = (void*)tmp->dat.ival;
				return (void*)1;
			}
		}
		else
			tmp++;
	}
	return 0;
}

int makesymlocal()
{
	symbol_tables_local->num = 0;
	symbol_tables_local->slt = (void*)calloc(101, sizeof(void*));
	head_local = symbol_tables_local->slt[0];
	if(symbol_tables_local->slt)
		return 1;
	else
		return 0;
}

int addsymlocal(char* name)
{
}

void* getsymlocal(char* fname, char* vname, void* vret)
{
}

void* putsymlocal(char* fname, char* vname, void* data, int type)
{
}
