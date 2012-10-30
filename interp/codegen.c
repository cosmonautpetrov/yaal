#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "symtable.h"
#include "block.h"
#include "func.h"

extern int sym_num;
extern int numargs;
extern char* currname;

int funcgen();
//generate current function
char* straddmem(char* dest, char* source);
//adds to a string and allocates (string must be preallocated)
int eval(function* feval);
//evals a function using function table, returns output of function
symlnk* getlocsym(char* name, function* feval);
//returns a pointer to a local functions symbol

int eval(function* feval)
{
	int* fstack = (int*)calloc(1, 4096);
	int sp=0;
	function* tempf;
	symlnk* temps;


	int* rstack=(int*)malloc(sizeof(int)*1);//restoration stack
	int rp=0;//restoration stack pointer

	int y;
	int i;
	for(i = 0; i < feval->textnum; i++)
	{
		switch(feval->functext[i].typearg)
		{
			case TYPE_INT:
				//simply push the value on top of the stack
				fstack[sp++]=(int)feval->functext[i].val;
				break;
			case TYPE_STR:
				//if its a string, first check if its a function
				if(tempf=findfunction(feval->functext[i].name)){
					fstack[sp++]=eval(tempf);//push evaluation of the function
					if(feval->functext[i+1].val != ']'){
						printf("Expected ']' after operation.\n");
						free(fstack);
						exit(0);
					}
				}
				else
					if(getlocsym(feval->functext[i].name, feval)){
						fstack[sp++]=(int)feval->functext[i].name;
					}
					else{
						printf("Undefined symbol %s\n", feval->functext[i].name);
						free(fstack);
						exit(0);
					}
				break;
			case TYPE_PSTRING:
				//push a string
				fstack[sp++]=(int)feval->functext[i].name;
				break;
			case TYPE_OP:
				//first we go through operators that aren't "finishing ops"
				if(feval->functext[i].val==TYPE_EMB){
					rstack=realloc(rstack, sizeof(int)*(rp+1));
					rstack[rp++]=sp;
					continue;
				}
				if(feval->functext[i].val==TYPE_LV){
					if(sp)
						y=fstack[sp-1];
					else
						y=fstack[sp];
						sp=rstack[--rp];
						fstack[sp++]=y;
					continue;
				}
				switch(feval->functext[i].val)
				{
					case TYPE_OP_ADD:
						fstack[sp-2]+=fstack[sp-1];//add top two, push
						sp--;
						break;
					case TYPE_OP_SUB:
						fstack[sp-2]-=fstack[sp-1];//sub top two, push
						sp--;
						break;
					case TYPE_OP_MUL:
						fstack[sp-2]*=fstack[sp-1];//mul top two, push
						sp--;
						break;
					case TYPE_OP_DIV:
						fstack[sp-2]/=fstack[sp-1];//mul top two, push
						sp--;
						break;
					case TYPE_OP_SET:
						temps=getlocsym((char*)fstack[sp-2], feval);
						if(temps->type == TYPE_INT)
							temps->dat.ival = fstack[sp-1];
						fstack[sp-2]=fstack[sp-1]; //set variable to stack val, return stack val
						sp-=2;
						break;
					case TYPE_OP_GET:
						temps=getlocsym((char*)fstack[sp-1], feval);
						if(temps->type == TYPE_INT)
							fstack[sp-1]=temps->dat.ival;
						break;
					case TYPE_OP_PNT:
						printf("%s", (char*)fstack[--sp]);
						break;
				}
				if(feval->functext[i+1].val != ']'){
					printf("Expected ']' after operation.\n");
					free(fstack);
					exit(0);
				}
				break;
		}
	}
	if(sp)
		i=fstack[sp-1];
	else
		i=fstack[sp];
	free(fstack);
	return i;
}

char* straddmem(char* dest, char* source)
{
	dest = realloc(dest, strlen(dest) + strlen(source) + 1);
	strcat(dest, source);
	return dest;
}

symlnk* getlocsym(char* name,function* feval)
{
	symlnk* tmp = feval->funcdata;
	int i;
	for(i = 0; i < feval->datanum; i++)
	{
		if(!strcmp(tmp[i].name, name))
			return &tmp[i];
	}
	return 0;
}