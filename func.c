#include "func.h"
#include "string.h"

extern int sym_num;
extern int numargs;
extern char* currname;

function* function_table;
function* function_head;
int func_num = 0;

function* returnfunction()
{
	function* temp = (void*)malloc(sizeof(function));
	temp->funcname = (char*)malloc(strlen(currname)+1);
	strcpy(temp->funcname, currname);//allocate func name

	temp->functext = (void*)malloc(sizeof(codearg)*numargs);
	temp->funcdata = (void*)malloc(sizeof(symlnk)*sym_num);

	memcpy(temp->functext, returnblock(), sizeof(codearg)*numargs);
	memcpy(temp->funcdata, returnsym(), sizeof(symlnk)*sym_num); //copy over our data

	temp->textnum = numargs;
	temp->datanum = sym_num;

	printf("%s: datanum: %i textnum: %i\n", temp->funcname, temp->datanum, temp->textnum);

	return temp;
}

void* makefunction()
{
	function_table = malloc(sizeof(function)*1);
	function_head = function_table;
}

void* addfunction(function* source)
{
	memcpy(function_head, source, sizeof(function));
	func_num++;
	function_table = realloc(function_table, sizeof(function)*(func_num+1));
	function_head = &function_table[func_num];
}

void* printfunction()
{
	function* temp = function_table;
	int i;
	for(i = 0; i < func_num; i++)
	{
		printf("%s: datanum: %i textnum: %i\n", temp[i].funcname, temp[i].datanum, temp[i].textnum);
	}
}

function* findfunction(char* name)
{
	function* temp;
	int i;
	for(i = 0; i < func_num; i++)
	{
		if(!strcmp(function_table[i].funcname, name))
			return &function_table[i];
	}
	return 0;
}
