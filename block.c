#include "block.h"
#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define ASI '='

#define LABEL -1
#define NUM -2

codeline* intermcode;
codeline* code_head;
int num = 1;

int addline(codeline*);
int makline();
int printline(codeline*);

int makline()
{
	intermcode = (void*)malloc(sizeof(codeline)*2);
	code_head = intermcode;
	return 0;
}

int addline(codeline* input)
{
	memcpy(code_head, input, sizeof(codeline));
	intermcode = (void*)realloc(intermcode, (sizeof(codeline)*(num+1)));
	num++;
	code_head++;
	return 0;	
}

int printline(codeline* input)
{
	if(input->typearg1 == LABEL)
		printf("%s", input->arg1.name);
	if(input->typearg1 == NUM)
		printf("%i", input->arg1.val);
	printf("%c", input->op1);
	if(input->typearg2 == LABEL)
		printf("%s", input->arg1.name);
	if(input->typearg2 == NUM)
		printf("%i", input->arg1.val);
	printf("%c", input->op2);
	if(input->typearg3 == LABEL)
		printf("%s", input->arg1.name);
	if(input->typearg3 == NUM)
		printf("%i", input->arg1.val);
	return 0;
}