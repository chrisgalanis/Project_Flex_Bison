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
%token BOOL_OP
%token INCREAMENT_DECREAMENT
%token LOOP_STEP

//Condition Identifiers
%token SWITCH
%token CASE
%token DEFAULT

%token BREAK 
%token RETURN
%token PRINT

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

program: %empty | class_identifier program ;

// Class Identifier of Only One Class
class_identifier: PUBLIC CLASS CLASS_NAME CURLY_BRACKET_LEFT class_body CURLY_BRACKET_RIGHT {printf("\nClass is identified : \n");};


// Double Check if class members before of functions
class_body: %empty |  functions class_body
	               |  class_members class_body
                   |  class_identifier class_body;
	        
class_members: variable_decleration SEMICOLON | variable_assignment SEMICOLON  | member_access SEMICOLON | class_instance SEMICOLON ;

VAR_NAME : IDENT  | CLASS_NAME ;

//Class Instance
class_instance: CLASS_NAME VAR_NAME EQUAL_SIGN NEW CLASS_NAME BRACKET_LEFT BRACKET_RIGHT ;
member_access: IDENT DOT IDENT parenthesis ; //End Class Instance
parenthesis: %empty  | BRACKET_LEFT BRACKET_RIGHT;


// Variable Decleration
visibility : %empty | PUBLIC | PRIVATE;
variable_decleration: visibility  variable_type VAR_NAME  ;
 
variable_type: INT   
              |DOUBLE
              |CHAR
              |BOOLEAN
              |STRING ;

// Variable Initilization
variable_assignment:  VAR_NAME EQUAL_SIGN expression;

expression: expression PLUS term |expression MINUS term  | term  ;
term:  term MULTIPLY par | term DIVIDE par | par ;
par : BRACKET_LEFT expression BRACKET_RIGHT | id;
id: variable_value  | VAR_NAME | BRACKET_LEFT id BRACKET_RIGHT;


variable_value:  INT_VALUE | CHAR_VALUE | DOUBLE_VALUE | BOOLEAN_VALUE | STRING_VALUE  ; 


// Functions
function_call:  VAR_NAME BRACKET_LEFT arguments_call BRACKET_RIGHT ;

arguments_call: %empty | expression arguments_call_end | VAR_NAME DOT VAR_NAME arguments_call_end;
arguments_call_end: %empty | COMMA expression arguments_call_end | COMMA VAR_NAME DOT VAR_NAME arguments_call_end;

functions: function_visibility VOID VAR_NAME BRACKET_LEFT arguments BRACKET_RIGHT CURLY_BRACKET_LEFT inside_void_function CURLY_BRACKET_RIGHT 
         | function_visibility variable_type VAR_NAME BRACKET_LEFT arguments BRACKET_RIGHT CURLY_BRACKET_LEFT inside_function CURLY_BRACKET_RIGHT  {printf("\n Function is identified\n");};
function_visibility: PRIVATE | PUBLIC 

arguments : %empty | parameters
parameters: variable_type VAR_NAME arguments_end
arguments_end : %empty | COMMA parameters 

inside_void_function: inside_brackets | inside_brackets RETURN SEMICOLON ;
inside_function: inside_brackets  RETURN expression SEMICOLON ;
// End Functions

inside_brackets: %empty | loops_n_condition inside_brackets | function_call SEMICOLON inside_brackets | print SEMICOLON inside_brackets | class_members inside_brackets;


loops_n_condition: for_statement | switch | do_while | if ; 

// For Loop
for_statement:  FOR BRACKET_LEFT for_condition BRACKET_RIGHT CURLY_BRACKET_LEFT inside_brackets_loop CURLY_BRACKET_RIGHT  {printf("\n For is identified\n");};
for_condition:  for_variable SEMICOLON condition SEMICOLON for_step ;

for_variable: %empty | variable_type variable_assignment  ;

condition: %empty | expression CONDITION_SYMBOL expression bool_operator | VAR_NAME bool_operator | BOOLEAN_VALUE bool_operator;
bool_operator:  %empty | BOOL_OP condition;

for_step : %empty | VAR_NAME step ;
step: INCREAMENT_DECREAMENT | LOOP_STEP expression;

inside_brackets_loop :inside_brackets | inside_brackets BREAK SEMICOLON inside_brackets;
// End For Loop

// DO While Loop 
do_while: DO CURLY_BRACKET_LEFT inside_brackets_loop CURLY_BRACKET_RIGHT  WHILE BRACKET_LEFT condition BRACKET_RIGHT SEMICOLON {printf("\n Do While is identified\n");};

// End While Loop


// Switch  
switch: SWITCH BRACKET_LEFT expression BRACKET_RIGHT CURLY_BRACKET_LEFT case default CURLY_BRACKET_RIGHT {printf("\n Switch is identified\n");};
case: CASE expression COLON switch_content case |%empty

switch_content: %empty | inside_brackets BREAK SEMICOLON;

default: DEFAULT COLON switch_content  |%empty ;
         
// End Switch

// IF 
if: IF BRACKET_LEFT condition BRACKET_RIGHT CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT else_if {printf("\n If is identified\n");};
else_if:  ELSE IF BRACKET_LEFT condition BRACKET_RIGHT CURLY_BRACKET_LEFT  inside_brackets CURLY_BRACKET_RIGHT else_if {printf("else if \n");} | else {printf("\n else \n");};
else: %empty  | ELSE CURLY_BRACKET_LEFT  inside_brackets CURLY_BRACKET_RIGHT {printf("\n Else is identified\n");};     

print : PRINT BRACKET_LEFT STRING_VALUE after_print BRACKET_RIGHT ;
after_print: %empty | COMMA VAR_NAME after_print;

%%

int main() {
    yyparse();
    printf("\n    Program has executed successfully.\n");
    return 0;
}

void yyerror(const char *s)
{
    printf("\n  Error: %s\n",s);
    exit(0);
}
