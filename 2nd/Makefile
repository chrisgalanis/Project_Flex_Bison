tests = TestCases/class_objects.txt  TestCases/functions.txt TestCases/variables.txt TestCases/inside_brackets.txt

all : myParser
	./myParser.exe < test.txt

myParser:
	bison -t -d -v parser.y
	flex flex.lex
	gcc -o myParser.exe lex.yy.c parser.tab.c -lfl
	

test: myParser
	@for testfile in $(tests); do \
		echo "Running test with $$testfile..."; \
		./myParser.exe < $$testfile; \
		echo "---------------------------------"; \
	done