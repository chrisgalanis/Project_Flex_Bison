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
%token IF
%token ELSE
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
%token IDENT
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

%glr-parser // For handling the problem of LR(1) grammar

%start program

%%

program: %empty | class_identifier program;

// Class Identifier of Only One Class
class_identifier: PUBLIC CLASS CLASS_NAME CURLY_BRACKET_LEFT class_body CURLY_BRACKET_RIGHT {printf("\nClass is identified : \n");};


// Double Check if class members before of functions
class_body: %empty |  functions class_body
	               |  class_members class_body
                   |  class_identifier class_body;
	        
class_members: variable_initialization SEMICOLON | variable_assignment SEMICOLON  | member_access SEMICOLON | class_instance SEMICOLON ;

VAR_NAME : IDENT {printf("I");} | CLASS_NAME {printf("C");};

//Class Instance
class_instance: CLASS_NAME VAR_NAME EQUAL_SIGN NEW CLASS_NAME BRACKET_LEFT BRACKET_RIGHT ;
member_access: IDENT DOT IDENT parenthesis ; //End Class Instance
parenthesis: %empty  | BRACKET_LEFT BRACKET_RIGHT;

variable_type: INT   
              |DOUBLE
              |CHAR
              |BOOLEAN
              |STRING ;



// Note Fix Visibility
// !! Assignement Επιπλέον, η σύνθετη παράσταση μπορεί να είναι οποιαδήποτε αριθμητική παράσταση που περιλαμβάνει τις πράξεις +, -, *, /.  
//expressions

variable_assignment:  VAR_NAME EQUAL_SIGN expression;
expression: expression PLUS term |expression MINUS term |  BRACKET_LEFT expression  BRACKET_RIGHT | term  ;
term:  term MULTIPLY id | term DIVIDE id | BRACKET_LEFT term BRACKET_RIGHT | BRACKET_LEFT expression BRACKET_RIGHT | id  ;
id: variable_value  | VAR_NAME |  BRACKET_LEFT id  BRACKET_RIGHT | BRACKET_LEFT expression BRACKET_RIGHT;

//My kostas branch
/*variable_assignment:  VAR_NAME EQUAL_SIGN variable_value {printf("\nVariable  assign is identified\n");};
variable_value:  expression|INT_VALUE | CHAR_VALUE | DOUBLE_VALUE | BOOLEAN_VALUE | STRING_VALUE|VAR_NAME ;
expression:  variable_value operation variable_value {printf("\nexpression is identified\n");}
| BRACKET_LEFT expression BRACKET_RIGHT ;
operation: PLUS |MINUS|MULTIPLY|DIVIDE;
variable_type: INT   
              |DOUBLE
              |CHAR
              |BOOLEAN
              |STRING ;
*/


/* variable_action: other | other expression_operation  other ;
other: number | BRACKET_LEFT number expression_operation other BRACKET_RIGHT | BRACKET_LEFT number BRACKET_RIGHT; 
expression_operation: PLUS | MINUS | DIVIDE | MULTIPLY;
number: INT_VALUE | DOUBLE_VALUE | CHAR_VALUE | VAR_NAME; */


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

inside_brackets: %empty | loops_n_condition inside_brackets | variable_assignment SEMICOLON ;



loops_n_condition: for_statement | switch | do_while | if | variable_initialization  SEMICOLON | variable_assignment SEMICOLON | class_instance SEMICOLON  |member_access SEMICOLON ; // + Δήλωση Μεταβλητών

// For Loop
for_statement:  FOR BRACKET_LEFT for_condition BRACKET_RIGHT CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT  {printf("\n For is identified\n");};
for_condition:  for_variable SEMICOLON for_comparison SEMICOLON for_step ;

for_variable: %empty | variable_type VAR_NAME EQUAL_SIGN variable_value  ;

for_comparison: %empty | VAR_NAME CONDITION_SYMBOL comparison_value for_bool_operator;
comparison_value: INT_VALUE | DOUBLE_VALUE | CHAR_VALUE | BOOLEAN_VALUE | VAR_NAME ;
for_bool_operator:  %empty | BOOL_SYMBOL for_comparison;

for_step : %empty | VAR_NAME step ;
step: INCREAMENT_DECREAMENT | LOOP_STEP step_value;
step_value: INT_VALUE | DOUBLE_VALUE ;
// End For Loop

// DO While Loop 
do_while: DO CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT  WHILE BRACKET_LEFT do_condition BRACKET_RIGHT SEMICOLON {printf("\n Do While is identified\n");};
do_condition: operand CONDITION_SYMBOL operand do_bool_operator| BOOLEAN_VALUE | VAR_NAME;
do_bool_operator: %empty | BOOL_SYMBOL do_condition;
operand: VAR_NAME | INT_VALUE | DOUBLE_VALUE | CHAR_VALUE | BOOLEAN_VALUE ;
// End While Loopo

// For the 2nd Version we need to recognise: int var = INT_Number exc.
variable_initialization:  variable_type VAR_NAME  ;
 

variable_value:  INT_VALUE | CHAR_VALUE | DOUBLE_VALUE | BOOLEAN_VALUE | STRING_VALUE  ; 

// Switch  
switch: SWITCH BRACKET_LEFT VAR_NAME BRACKET_RIGHT CURLY_BRACKET_LEFT case default CURLY_BRACKET_RIGHT {printf("\n Switch\n");};
case: CASE switch_value COLON switch_content case
      |%empty

switch_value: INT_VALUE | CHAR_VALUE ;
switch_content: %empty | /*ACTUAL CONTENT*/ BREAK SEMICOLON;

default: DEFAULT COLON switch_content ;
         |%empty
         
// End Switch

// IF 
if: IF BRACKET_LEFT if_condition BRACKET_RIGHT CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT else_if{printf("\n If is identified\n");};
else_if: %empty | ELSE IF BRACKET_LEFT if_condition BRACKET_RIGHT CURLY_BRACKET_LEFT  inside_brackets CURLY_BRACKET_RIGHT else_if {printf("else if \n");} | else {printf("\n If is identified\n");};
else: ELSE CURLY_BRACKET_LEFT  inside_brackets CURLY_BRACKET_RIGHT {printf("\n Else is identified\n");};     
if_condition: operand  CONDITION_SYMBOL operand if_bool_operator| BOOLEAN_VALUE | VAR_NAME {printf("\n If Condition is identified\n");};
if_bool_operator: %empty | BOOL_SYMBOL if_condition;

%%

int main(void)
{
    yyparse();
}

void yyerror(const char *s)
{
    printf("Error: %s\n",s);
}