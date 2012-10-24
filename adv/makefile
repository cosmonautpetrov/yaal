all:
	yacc -d y.y
	lex l.lex
	gcc -g codegen.c block.c symtable.c y.tab.c lex.yy.c main.c -lfl -o main