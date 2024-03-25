all:
	flex flex.lex
	gcc lex.yy.c -lfl