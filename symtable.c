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

symlnk *symbol_table;
symlnk *head;

int makesym();
//makes a symbol table, !NULL on success
void* getsym(char* name, void* vret);
//returns NULL if not in symbol_table,else returns void* to data
void* putsym(char* name, void* data, int type);
//adds symbol to table,else updates data at symbol table

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