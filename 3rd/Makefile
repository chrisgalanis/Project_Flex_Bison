all:
	bison -t -d -v parser.y
	flex flex.lex
	gcc -o myParser.exe lex.yy.c parser.tab.c functions.c -lfl
	./myParser.exe < test.txt

debug: 
	bison -t -d -v parser.y
	flex flex.lex
	gcc -g -o  myParser.exe lex.yy.c parser.tab.c -lfl
	./myParser.exe < test.txt
