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
%token EMTPY

%start program

%%

program: %empty | class_identifier ;
// Class Identifier of Only One Class

class_identifier: PUBLIC CLASS CLASS_NAME CURLY_BRACKET_LEFT class_body CURLY_BRACKET_RIGHT {printf("\nClass is identified\n");} ;

class_body: %empty ;

//variables: 
//if_statement: 
//for_statement: 

%%

int main(void)
{
    yyparse();
}

void yyerror(const char *s)
{
    printf("Error: %s\n",s);
}