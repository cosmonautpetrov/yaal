#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "symtable.h"
#include "block.h"

extern int sym_num;
extern int numargs;

int codegen(char* filename);
//generates code, stores in file
char* straddmem(char* dest, char* source);
//adds to a string and allocates (string must be preallocated)

int codegen(char* filename)
{
	symlnk* syntmp = returnsym();
	codearg* codetmp = returnblock();
	FILE *f_ptr = fopen(filename, "w+b");
	char* data_buff = calloc(1, sizeof(char));
	char* code_buff = calloc(1, sizeof(char));

	//first lets put in all global variables
	data_buff=straddmem(data_buff, ".data\n");
	int i;
	for(i = 0; i < sym_num; i++)
	{
		printf("%s\n", syntmp[i].name);
		data_buff=straddmem(data_buff, syntmp[i].name);
		if(syntmp[i].type == TYPE_INT){//integer
			data_buff=straddmem(data_buff, ": .long 0\n");//makes a long
		}
		if(syntmp[i].type == TYPE_STR){//string
			data_buff=straddmem(data_buff, ": .asciz ");
			if(syntmp[i].dat.sval)
				data_buff=straddmem(data_buff, syntmp[i].dat.sval);
			else
				data_buff=straddmem(data_buff, "0");
			data_buff=straddmem(data_buff, "\n");
		}
	}
	code_buff=straddmem(code_buff, ".text\n");
	char* tmpint = malloc(sizeof(char)*33);
	int tmpchar;
	for(i = 0; i < numargs; i++)
	{
		switch(codetmp[i].typearg)
		{
			case TYPE_INT:
				code_buff=straddmem(code_buff, "pushl $");
				sprintf(tmpint, "%d", codetmp[i].val);
				code_buff=straddmem(code_buff, tmpint);
				code_buff=straddmem(code_buff, "\n");
				break;
			case TYPE_STR:
				syntmp = getsym(codetmp[i].name, 0);
				code_buff=straddmem(code_buff, "pushl ");
				if(syntmp->type == TYPE_STR){
					code_buff=straddmem(code_buff, "$");
					code_buff=straddmem(code_buff, codetmp[i].name);
					code_buff=straddmem(code_buff, "\n");}
				if(syntmp->type == TYPE_INT){
				code_buff=straddmem(code_buff, "(");
				code_buff=straddmem(code_buff, codetmp[i].name);
				code_buff=straddmem(code_buff, ")\n");}
				break;
			case TYPE_OP:
				switch(codetmp[i].val)
				{
					case TYPE_EMB:
						break;
					case TYPE_LV:
						break;
				}
				break;
			case TYPE_LOC:
				tmpchar = (codetmp[i].val - 97) * -4;//convert to addressing style
				sprintf(tmpint, "%d", tmpchar-4);
				code_buff=straddmem(code_buff, "pushl ");
				code_buff=straddmem(code_buff, tmpint);
				code_buff=straddmem(code_buff, "(%ebx)\n");
				break;
		}
	}
	fwrite(data_buff, 1 , strlen(data_buff), f_ptr);
	fwrite(code_buff, 1, strlen(code_buff), f_ptr);
	fclose(f_ptr);
}

char* straddmem(char* dest, char* source)
{
	dest = realloc(dest, strlen(dest) + strlen(source) + 1);
	strcat(dest, source);
	return dest;
}