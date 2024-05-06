%{
#include <stdio.h>

int yylex();
void yyerror(const char *s);
%}
//CLASS DEC
%token PUBLIC
%token CLASS


//SYMBOLS
%token LCURLY
%token RCURLY
%token LPAR
%token RPAR
%token SEMICOLON

//MEMBER TYPE DEC
%token INT
%token DOUBLE
%token CHAR
%token BOOL
%token STRING
%token INTEGERNUM
%token REALNUM
//DATA TYPES
%token IDENT
%token SYMBOLS
%token SYMBOL




%%


program: classes
classes: class classes 
       | %empty  
class: PUBLIC CLASS IDENT LCURLY cl_content RCURLY
cl_content: cl_functions cl_content
	  | cl_members cl_content
	  | %empty
cl_functions: %empty
cl_members: type IDENT SEMICOLON
type: INT   
    |DOUBLE
    |CHAR
    |BOOL
    
	 

%%

int main(void){

yyparse();
}


void yyerror(const char *s){
printf("ekames lathos bro");
}

