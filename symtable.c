#include "symtable.h"
#include "block.h"

symlnk *symbol_table;
symlnk *head;
char* currname;
int sym_num = 0;

int makesym(char* name_of_table)
{
	symbol_table = malloc(sizeof(symlnk));
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
	head->type=type;
	head->next=head++;
	if(type == TYPE_INT){
		head->dat.ival = (int)data;
	}
	if(type == TYPE_STR){
		head->dat.sval = (char*)data;
	}
	if(type == TYPE_ARRC){
		head->dat.sval = malloc(sizeof(arrstruct));
		arrstruct* temp = head->dat.sval;
		temp->type = TYPE_ARRC;
		temp->max = 0;
		temp->buffer = malloc(sizeof(char));
	}
	if(type == TYPE_ARRI){
		head->dat.sval = malloc(sizeof(arrstruct));
		arrstruct* temp = head->dat.sval;
		temp->type = TYPE_ARRI;
		temp->max = 0;
		temp->buffer = malloc(sizeof(char));
	}
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
	}
	free(symbol_table);
	sym_num=0;
	return 1;
}

arrstruct* makearr(int type)
{
	arrstruct* temp = malloc(sizeof(arrstruct));
	temp->type = type;
	if(type == TYPE_ARRI)
		temp->buffer = malloc(sizeof(int));
	if(type == TYPE_ARRC)
		temp->buffer = malloc(sizeof(char));
	return temp;
}

int writearr(arrstruct* source, int val, int n)
{
	if(source->type == TYPE_ARRI){
		if(source->max < n){
			source->max = n;
			source->buffer = realloc(source->buffer, sizeof(int)*(n+1));
		}
		((int*)source->buffer)[n] = val;
	}
	if(source->type == TYPE_ARRC){
		if(source->max < n){
		source->max = n;
		source->buffer = realloc(source->buffer, sizeof(char)*(n+1));
		}
		((char*)source->buffer)[n] = (char)val;
	}
	return 0;
}

int getarr(arrstruct* source, int n)
{
	if(source->type == TYPE_ARRI)
		return ((int*)source->buffer)[n];
	if(source->type == TYPE_ARRC)
		return (int)((char*)source->buffer)[n];
}