all:
	yacc -d y.y
	lex l.lex
	gcc -g symtable.c y.tab.c lex.yy.c main.c -lfl -o main