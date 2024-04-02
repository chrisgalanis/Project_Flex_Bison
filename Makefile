all:
	bison -t -d -v parser.y
	flex flex.lex
	gcc -o myParser.exe lex.yy.c parser.tab.c -lfl 