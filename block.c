#include "block.h"

codeblock* current_block;
codearg*   current_head;
int numargs = 0;
int embedlevel = 0;

int makeblock(char* routine)
{
	current_block = malloc(sizeof(codeblock));
	current_block->codelist = malloc(sizeof(codearg)*2);
	current_head = current_block->codelist;
}

int addline(int typearg, void* argitself)
{
	current_block->codelist = realloc(current_block->codelist, sizeof(codearg)*numargs + sizeof(codearg)*2);
	current_head = &current_block->codelist[numargs];
	current_head->typearg = typearg;
	current_head->embedlevel = embedlevel;
	if(typearg == TYPE_STR)
		current_head->name = argitself;
	if(typearg == TYPE_INT)
		current_head->val = (int)argitself;
	if(typearg == TYPE_OP)
		current_head->val = (int)argitself;
	numargs++;
	current_head++;
	return 0;
}

int closeblock()
{
	int i;
	codearg* temp = current_block->codelist;
	for(i = 0; i < numargs; i++)
	{
		if(&temp[i])
			free(&temp[i]);
	}
	free(current_block);
	return 0;
}

int printblock()
{
	int i = 0;
	int y = 0;
	int tmplevel = 0;
	int tmplevelold = 0;
	codearg *temp = current_block->codelist;
	while(i++ < numargs)
	{
		tmplevelold = tmplevel;
		tmplevel = temp->embedlevel;
		if(tmplevel != tmplevelold)
		{
			printf("\n");
			for(y = 0; y < tmplevel; y++)
				printf(" ");
		}
		if(temp->typearg == TYPE_INT)
			printf("%i ", temp->val);
		if(temp->typearg == TYPE_STR)
			printf("%s ", temp->name);
		if(temp->typearg == TYPE_OP)
			printf("%c ", temp->val);
		temp++;

	}
	printf("\n");
}

int chlevel(int level)
{
	if(level == TYPE_EMB)
		embedlevel++;
	if(level == TYPE_LV)
		embedlevel--;
}