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
%token COLON
%token COMMA
%token DOT 

//arithmetic expressions
%token PLUS
%token MINUS
%token MULTIPLY
%token DIVIDE

// Class Identifier
%token PUBLIC
%token PRIVATE
%token CLASS
%token CLASS_NAME
%token NEW

// Loop Identifiers
%token FOR
%token DO
%token WHILE
%token CONDITION_SYMBOL
%token BOOL_SYMBOL
%token INCREAMENT_DECREAMENT
%token LOOP_STEP

//Condition Identifiers
%token SWITCH
%token CASE
%token DEFAULT

%token BREAK 
%token RETURN

//Variable Types
%token VAR_NAME
%token VOID
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


// Double Check if class members before of functions
class_body: %empty |  functions class_body
	               |  class_members class_body ;
	        
class_members: variable_initialization SEMICOLON | variable_assignment SEMICOLON | variable_expression SEMICOLON;

variable_type: INT   
              |DOUBLE
              |CHAR
              |BOOLEAN
              |STRING ;
//Class Instance
class_instance: CLASS_NAME VAR_NAME EQUAL_SIGN NEW CLASS_NAME BRACKET_LEFT BRACKET_RIGHT ;
member_access: VAR_NAME DOT VAR_NAME ; //End Class Instance

// Functions
functions: function_visibility VOID VAR_NAME BRACKET_LEFT arguments BRACKET_RIGHT CURLY_BRACKET_LEFT inside_void_function CURLY_BRACKET_RIGHT 
         | function_visibility variable_type VAR_NAME BRACKET_LEFT arguments BRACKET_RIGHT CURLY_BRACKET_LEFT inside_function CURLY_BRACKET_RIGHT  {printf("\n Function is identified\n");};
function_visibility: PRIVATE | PUBLIC 

arguments : %empty | parameters
parameters: variable_type VAR_NAME arguments_end
arguments_end : %empty | COMMA parameters 

inside_void_function: inside_brackets | inside_brackets RETURN SEMICOLON ;
inside_function: inside_brackets  RETURN VAR_NAME SEMICOLON  | inside_brackets RETURN variable_value SEMICOLON ;
// End Functions

inside_brackets: %empty | loops_n_condition inside_brackets ;
loops_n_condition: for_statement | switch | do_while | variable_initialization  SEMICOLON | variable_assignment SEMICOLON | class_instance SEMICOLON  |member_access SEMICOLON ; // + Δήλωση Μεταβλητών

// For Loop
for_statement:  FOR BRACKET_LEFT for_condition BRACKET_RIGHT CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT  {printf("\n For is identified\n");};
for_condition:  for_variable SEMICOLON for_comparison SEMICOLON for_step ;

for_variable: %empty | variable_assignment ;

for_comparison: %empty | VAR_NAME CONDITION_SYMBOL comparison_value bool_operator;
comparison_value: INT_VALUE | DOUBLE_VALUE | CHAR_VALUE | BOOLEAN_VALUE | VAR_NAME ;
bool_operator:  %empty | BOOL_SYMBOL for_comparison;

for_step : %empty | VAR_NAME step ;
step: INCREAMENT_DECREAMENT | LOOP_STEP step_value;
step_value: INT_VALUE | DOUBLE_VALUE ;
// End For Loop

// DO While Loop 
do_while: DO CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT  WHILE BRACKET_LEFT do_condition BRACKET_RIGHT SEMICOLON {printf("\n Do While is identified\n");};
do_condition: operand CONDITION_SYMBOL operand | BOOLEAN_VALUE;
operand: VAR_NAME | INT_VALUE | DOUBLE_VALUE | CHAR_VALUE | BOOLEAN_VALUE | VAR_NAME;
// End While Loopo

// For the 2nd Version we need to recognise: int var = INT_Number exc.
variable_initialization:  variable_type VAR_NAME  ;
variable_assignment: variable_type VAR_NAME EQUAL_SIGN variable_value ;
variable_value:  INT_VALUE | CHAR_VALUE | DOUBLE_VALUE | BOOLEAN_VALUE | STRING_VALUE ;

//expressions
variable_expression:  VAR_NAME EQUAL_SIGN variable_action;
variable_action: other | other expression_operation  other ;
other: number | BRACKET_LEFT number expression_operation other BRACKET_RIGHT | BRACKET_LEFT number BRACKET_RIGHT; 
expression_operation: PLUS | MINUS | DIVIDE | MULTIPLY;
number: INT_VALUE | DOUBLE_VALUE | CHAR_VALUE | VAR_NAME;


//end_expressions

// Switch  
switch: SWITCH BRACKET_LEFT VAR_NAME BRACKET_RIGHT CURLY_BRACKET_LEFT case default CURLY_BRACKET_RIGHT {printf("\n Switch\n");};
case: CASE switch_value COLON switch_content case
      |%empty

switch_value: INT_VALUE | CHAR_VALUE ;
switch_content: %empty | /*ACTUAL CONTENT*/ BREAK;

default: DEFAULT COLON switch_content ;
         |%empty
         
// End Switch
            
%%

int main(void)
{
    yyparse();
}

void yyerror(const char *s)
{
    printf("Error: %s\n",s);
}
