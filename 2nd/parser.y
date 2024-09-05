%{

#include <stdio.h>

int yylex();
void yyerror(const char *s);

%}

// Declare the types oftokens that will be used in the grammar
%union
{
    int ival;
    char cval;
    double dval;
    char *sval;

}

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
%token <sval> PUBLIC
%token <sval> PRIVATE
%token  CLASS
%token <sval> CLASS_NAME
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
%type <sval> VAR_NAME

%token <sval> IDENT
%token VOID
%token INT
%token CHAR
%token DOUBLE
%token BOOLEAN
%token STRING


//Variable Values
%token <ival> INT_VALUE 
%token <cval> CHAR_VALUE
%token <dval> DOUBLE_VALUE
%token <sval> BOOLEAN_VALUE 
%token <sval> STRING_VALUE



%start program

%%

program: %empty | class_identifier program;

// Class Identifier of Only One Class
class_identifier: PUBLIC CLASS CLASS_NAME CURLY_BRACKET_LEFT class_body CURLY_BRACKET_RIGHT {printf("\nClass is identified\n");};


// !! Double Check if class members before of functions
class_body: %empty |  functions class_body
	               |  class_members class_body
                   |  class_identifier class_body;
	        
class_members:  visibility  variable_initialization SEMICOLON |   variable_assignment SEMICOLON | member_access SEMICOLON | class_instance SEMICOLON ;

VAR_NAME : IDENT | CLASS_NAME;

// For the 2nd Version we need to recognise: int var = INT_Number exc.
/* variable_declaration: variable_type VAR_NAME next;
next: %empty | COMMA VAR_NAME next; */


variable_declaration:     visibility  INT  VAR_NAME dnext_int  |
                          visibility  DOUBLE  VAR_NAME dnext_double |
                          visibility  CHAR VAR_NAME dnext_char     |
                          visibility  BOOLEAN  VAR_NAME dnext_bool  |
                          visibility  STRING  VAR_NAME dnext_string ;

dnext_int: %empty    | COMMA VAR_NAME dnext_int ; 
dnext_double: %empty | COMMA VAR_NAME dnext_double ;
dnext_char: %empty   | COMMA VAR_NAME dnext_char ;
dnext_bool: %empty   | COMMA VAR_NAME dnext_bool;
dnext_string: %empty | COMMA VAR_NAME dnext_string;




variable_initialization:  visibility  INT  int_init next_int  |
                          visibility  DOUBLE  double_init next_double |
                          visibility  CHAR char_init next_char     |
                          visibility  BOOLEAN  bool_init next_bool  |
                          visibility  STRING  string_init next_string ;

next_int: %empty    | COMMA int_init next_int 
next_double: %empty | COMMA double_init next_double 
next_char: %empty   | COMMA char_init next_char 
next_bool: %empty   | COMMA bool_init next_bool 
next_string: %empty | COMMA string_init next_string 

int_init: VAR_NAME EQUAL_SIGN INT_VALUE/* printf("int %s = %d",$1,$3); $$ = $1; temp[top_value].itemp = $3; top_value++; };*/
double_init:  VAR_NAME EQUAL_SIGN DOUBLE_VALUE 
char_init:  VAR_NAME EQUAL_SIGN CHAR_VALUE 
bool_init: VAR_NAME EQUAL_SIGN BOOLEAN_VALUE  
string_init:  VAR_NAME EQUAL_SIGN STRING_VALUE  


variable_assignment:  VAR_NAME EQUAL_SIGN expression;
expression: expression PLUS term |expression MINUS term |  BRACKET_LEFT expression  BRACKET_RIGHT | term  ;
term:  term MULTIPLY id | term DIVIDE id | BRACKET_LEFT term BRACKET_RIGHT | BRACKET_LEFT expression BRACKET_RIGHT | id  ;
id: variable_value  | VAR_NAME |  BRACKET_LEFT id  BRACKET_RIGHT | BRACKET_LEFT expression BRACKET_RIGHT;


visibility: PUBLIC | PRIVATE  | %empty ;
variable_value:  INT_VALUE | CHAR_VALUE | DOUBLE_VALUE | BOOLEAN_VALUE | STRING_VALUE ;
variable_type: INT   
              |DOUBLE
              |CHAR
              |BOOLEAN
              |STRING ;
//Class Instance
class_instance: CLASS_NAME VAR_NAME EQUAL_SIGN NEW CLASS_NAME BRACKET_LEFT BRACKET_RIGHT ;
member_access: VAR_NAME DOT VAR_NAME parenthesis; //End Class Instance
parenthesis: %empty  | BRACKET_LEFT BRACKET_RIGHT;
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