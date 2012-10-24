#include "symtable.h"
#include "block.h"

symlnk *symbol_table;
symlnk *head;
char* currname;
int sym_num = 0;

int makesym(char* name_of_table)
{
	symbol_table = malloc(sizeof(symlnk)*1);
	head = symbol_table;
	currname=name_of_table;
	if(symbol_table)
		return 1;
	else
		return 0;
}

void* putsym(char* name, void* data, int type)
{
	head->name = name;
	if(type == TYPE_INT){
		head->dat.ival = (int)data;
		head->type = type;
		head->next = head++;}
	if(type == TYPE_STR){
		head->dat.sval = (char*)data;
		head->type = type;
		head->next = head++;}
	sym_num++;
	symbol_table = realloc(symbol_table, sizeof(symlnk)*(sym_num+1));
	head = &symbol_table[sym_num];
	return (void*)1;
}

void* getsym(char* name)
{
	symlnk* tmp = symbol_table;
	int i = 0;
	while(i++ < sym_num)
	{
		if(!strcmp(tmp->name, name)){
				return (void*)tmp;
		}
		else
			tmp++;
	}
	return 0;
}

void* printsym()
{
	int i;
	symlnk* tmp = symbol_table;
	printf("%s:\n", currname);
	for(i = 0; i < sym_num; i++)
		printf("%s\n", tmp[i].name);
}

symlnk* returnsym()
{
	return symbol_table;
}

int closesym()
{
	int i;
	symlnk* temp = symbol_table;
	for(i = 0; i < sym_num; i++)
	{
		free(temp[i].name);
		if(temp[i].type == TYPE_STR)
			free(temp[i].dat.sval);
	}
	free(symbol_table);
	sym_num=0;
	return 1;
}