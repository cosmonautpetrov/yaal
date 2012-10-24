#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "symtable.h"
#include "block.h"

extern int sym_num;
extern int numargs;
extern char* currname;
int curr_max_char=0;
int curr_chr_embl=0;

FILE *out_fptr;

int codegen(char* filename);
//generates code, stores in file
int funcgen();
//generate current function
char* straddmem(char* dest, char* source);
//adds to a string and allocates (string must be preallocated)

int funcgen()
{
	//buffers
	char* data=calloc(1, sizeof(char));
	char* text=calloc(1, sizeof(char));

	//get the current function tables
	symlnk* stemp = returnsym();
	codearg* btemp = returnblock();

	//create data
	data=straddmem(data, ".data\n");
	int i;
	for(i = 0; i < sym_num; i++)
	{
		data=straddmem(data, currname);
		data=straddmem(data, stemp[i].name);
		switch(stemp[i].type){
			case TYPE_INT:
				data=straddmem(data, ": .long 0\n");
				break;
			case TYPE_STR:
				data=straddmem(data, ": .asciz \"\"\n");
				break;
		}
	}

	//generate code
	text=straddmem(text, ".text\n.globl ");
	text=straddmem(text, currname);
	text=straddmem(text, "\n");
	text=straddmem(text, currname);
	text=straddmem(text, ":\n");
	char tempstr[32];
	for(i = 0; i < numargs; i++)
	{
		switch(btemp[i].typearg){
			case TYPE_INT: //constant
				text=straddmem(text, "pushl $");
				sprintf(tempstr, "%d", btemp[i].val);
				text=straddmem(text, tempstr);
				text=straddmem(text, "\n");
				break;
			case TYPE_STR: //variable
				stemp = getsym(btemp[i].name);
				text=straddmem(text, "pushl ");
				if(stemp->type == TYPE_STR){
					text=straddmem(text, "$");
					text=straddmem(text, currname);
					text=straddmem(text, stemp->name);
					text=straddmem(text, "\n");}
				if(stemp->type == TYPE_INT){
				text=straddmem(text, "(");
				text=straddmem(text, currname);
				text=straddmem(text, stemp->name);
				text=straddmem(text, ")\n");}
				break;
			case TYPE_OP:
				break;
		}
	}
	fwrite(data, 1 , strlen(data), out_fptr);
	fwrite(text, 1,  strlen(text), out_fptr);
	return 0;
}

int codegen(char* filename)
{
	symlnk* syntmp = returnsym();
	codearg* codetmp = returnblock();
	codearg* codefwr = codetmp;
	FILE *f_ptr = fopen(filename, "w+b");
	char* data_buff = calloc(1, sizeof(char));
	char* code_buff = calloc(1, sizeof(char));

	//first lets put in all global variables
	data_buff=straddmem(data_buff, ".data\n");
	int i;
	for(i = 0; i < sym_num; i++)
	{
		if(syntmp[i].type == TYPE_ROUT){//function
			data_buff=straddmem(data_buff, ".globl ");
		}
		printf("%s\n", syntmp[i].name);
		data_buff=straddmem(data_buff, syntmp[i].name);
		if(syntmp[i].type == TYPE_INT){//integer
			data_buff=straddmem(data_buff, ": .long 0");//makes a long
		}
		if(syntmp[i].type == TYPE_STR){//string
			data_buff=straddmem(data_buff, ": .asciz ");
			if(syntmp[i].dat.sval)
				data_buff=straddmem(data_buff, syntmp[i].dat.sval);
			else
				data_buff=straddmem(data_buff, "0");
		}
		data_buff=straddmem(data_buff, "\n");
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
				syntmp = getsym(codetmp[i].name);
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
						code_buff=straddmem(code_buff, "popl %eax\nmovl %ebp, %esp\npopl %ebp\npushl %eax\n");
						break;
					case TYPE_OP_ADD:
						code_buff=straddmem(code_buff, "popl %eax\naddl %eax, (%esp)\n");
						break;
					case TYPE_OP_SUB:
						code_buff=straddmem(code_buff, "popl %eax\nsubl %eax, (%esp)\n");
						break;
					case TYPE_OP_MUL:
						code_buff=straddmem(code_buff, "popl %eax\npopl %edx\nmull %edx\npushl %eax\n");
						break;
					case TYPE_OP_DIV:
						code_buff=straddmem(code_buff, "popl %edx\npopl %eax\ndivl %edx\npushl %eax\n");
						break;
					case TYPE_ROUT:
						code_buff=straddmem(code_buff, codetmp[i].name);
						code_buff=straddmem(code_buff, ":\n");
						codefwr = &codetmp[i];
						codefwr++;
						do
						{
							if(codefwr->typearg == TYPE_LOC)
							{
								if(codefwr->val > curr_max_char)
									curr_max_char = codefwr->val;
							}
							if(codefwr->val == TYPE_EMB)
								curr_chr_embl++;
							if(codefwr->val == TYPE_LV)
								curr_chr_embl--;
							codefwr++;
						}
						while(curr_chr_embl);
						curr_chr_embl=0;
						if(curr_max_char){
							tmpchar=(curr_max_char - 97) * 4;
							sprintf(tmpint, "%d", tmpchar+4);}
						else
							sprintf(tmpint, "%d", 0);
						code_buff=straddmem(code_buff, "pushl %ebp\nmovl %esp, %ebp\nmovl %ebp, %edi\n");
						code_buff=straddmem(code_buff, "subl $");
						code_buff=straddmem(code_buff, tmpint);
						code_buff=straddmem(code_buff, ", %esp\npushl $0\n");
						curr_max_char=0;
						break;
				}
				break;
			case TYPE_LOC:
				tmpchar = (codetmp[i].val - 97) * -4;//convert to addressing style
				sprintf(tmpint, "%d", tmpchar-4);
				code_buff=straddmem(code_buff, "pushl ");
				code_buff=straddmem(code_buff, tmpint);
				code_buff=straddmem(code_buff, "(%edi)\n");
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