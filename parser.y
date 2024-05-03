%{

#include <stdio.h>

int yylex();
void yyerror(const char *s);

%}

// Brackets
%token CURLY_BRACKET_LEFT
%token CURLY_BRACKET_RIGHT
%token BRACKET_LEFT 
%token BRACKET_RIGHT
%token EQUAL_SIGN
%token SEMICOLON
%token SINGLE_MARK

// Class Identifier
%token PUBLIC
%token CLASS
%token CLASS_NAME
%token NEW

// Loop Identifiers
%token FOR
%token WHILE
%token CONDITION_SYMBOL
%token BOOL_SYMBOL
%token INCREAMENT_DECREAMENT
%token LOOP_STEP

//Variable Types
%token VAR_NAME
%token INT
%token CHAR
%token DOUBLE
%token BOOLEAN
%token STRING
//%token EMTPY

//Variable Values
%token INT_VALUE 
%token CHAR_VALUE
%token DOUBLE_VALUE
%token BOOLEAN_VALUE
%token STRING_VALUE

%start program

%%

program: %empty | class_identifier ;

// Class Identifier of Only One Class
class_identifier: PUBLIC CLASS CLASS_NAME CURLY_BRACKET_LEFT class_body CURLY_BRACKET_RIGHT {printf("\nClass is identified\n");};

class_body: %empty |  functions 
	               |  class_members;
	        
class_members: variable_type VAR_NAME SEMICOLON ;
variable_type: INT   
              |DOUBLE
              |CHAR
              |BOOLEAN
              |STRING ;

functions: CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT {printf("\n Function is identified\n");};

inside_brackets: %empty | for_statement;

for_statement:  FOR BRACKET_LEFT for_condition BRACKET_RIGHT CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT  {printf("\n For is identified\n");};
for_condition:  for_variable SEMICOLON for_comparison SEMICOLON for_step ;

for_variable: %empty | variable_assignment ;

for_comparison: %empty | VAR_NAME CONDITION_SYMBOL comparison_value bool_operator;
comparison_value: INT_VALUE | DOUBLE_VALUE | BOOLEAN_VALUE ;
bool_operator:  %empty | BOOL_SYMBOL for_comparison;

for_step : %empty | VAR_NAME step ;
step: INCREAMENT_DECREAMENT | LOOP_STEP step_value;
step_value: INT_VALUE | DOUBLE_VALUE ;

// For the 2nd Version we need to recognise: int var = INT_Number exc.
variable_assignment: variable_type VAR_NAME EQUAL_SIGN variable_value ;
variable_value:  INT_VALUE | CHAR_VALUE | DOUBLE_VALUE | BOOLEAN_VALUE | STRING_VALUE ;

            
%%

int main(void)
{
    yyparse();
}

void yyerror(const char *s)
{
    printf("Error: %s\n",s);
}