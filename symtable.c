#include "symtable.h"

symlnk *symbol_table;
symlnk *head;
int sym_num = 0;

symlnktab *symbol_tables_local;
symlnk *head_local;

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
	if(type == -1){
		head->dat.ival = (int)data;
		head->type = type;
		head->next = head++;}
	if(type == -2){
		head->dat.sval = (char*)data;
		head->type = type;
		head->next = head++;}
	sym_num++;
	return (void*)1;
}

void* getsym(char* name, void* vret)
{
	symlnk* tmp = symbol_table;
	int i = 0;
	while(i++ < sym_num)
	{
		if(!strcmp(tmp->name, name)){
			if(tmp->type == -1){
				if(vret)
					vret = (void*)tmp->dat.ival;
				return (void*)tmp;}
			if(tmp->type == -2){
				if(vret)
					vret = (void*)tmp->dat.sval;
				return (void*)tmp;}
		}
		else
			tmp++;
	}
	return 0;
}

void* printsym()
{
	symlnk* tmp = symbol_table;
	int i = 0;
	while(i++ < sym_num)
	{
		printf("%s %i\n", tmp->name, tmp->type);
		tmp++;
	}
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

symlnk* returnsym()
{
	return symbol_table;
}