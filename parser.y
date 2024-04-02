%{

#include <stdio.h>

int yylex();
void yyerror(const char *s);

%}

// Class Identifier
%token PUBLIC
%token CLASS
%token CLASS_NAME
%token CURLY_BRACKET_LEFT
%token CURLY_BRACKET_RIGHT

//Variable Types
%token INT

%start program

%%
program: %empty | class_identifier

class_identifier: PUBLIC CLASS CLASS_NAME CURLY_BRACKET_LEFT CURLY_BRACKET_RIGHT {printf("Class is identified");}

%%

int main(void)
{
    yyparse();
}

void yyerror(const char *s)
{
    printf("Error: %s\n",s);
}