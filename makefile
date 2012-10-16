all:
	yacc -d y.y
	lex l.lex
	gcc -g block.c symtable.c y.tab.c lex.yy.c main.c -lfl -o main