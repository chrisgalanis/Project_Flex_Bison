%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int yylex();
    void yyerror(const char *s);

    int var_counter = 0;


    typedef struct variable
    {
        char *name;
        char *type;
        char *value;
        int visibility;
    } variable; 

    typedef struct function
    {
        char *name;
        char *return_type;
        int visibility;  
    } function;

    variable * stack[100];
    function * functions[100];

    int top_var = 0;
    int top_func = 0;
    
    
    /* Functions Recognition */ 

    function * create_function(int visibility, char *return_type, char *name)
    {
        function *v = (function *)malloc(sizeof(function));
        v->name = strdup(name); // strdup is used to copy the string
        v->return_type = return_type; 
        v->visibility = visibility;
        return v;
    }

    void print_function(function *f)
    {
        printf("Name: %s, Return Type: %s, Visibility: %d\n", f->name, f->return_type, f->visibility);
    }

    void print_stack_functions()
    {
        for(int i = 0; i < top_func; i++)
        {
        printf("Name: %s, Return Type: %s, Visibility: %d\n", functions[i]->name, functions[i]->return_type,  functions[i]->visibility);
        }
    }

    int find_functions(char *name)
    {
        for(int i = 0; i < top_func; i++)
        {
            if(strcmp(functions[i]->name, name) == 0)
            {
                print_function(functions[i]);
                return i;
            }
        }
        return -1;
    }

    void push_function(function *v)
    {
        functions[top_func++] = v;
    }

    function * pop_function()
    {
        return functions[--top_func];
    }
    

    void function_initiliazation(int visibility , char *return_type, char *name)
    {
        if (find_functions(name) > 0)
        {   
            char *msg;
            yyerror("Variable has been initialized");
            printf("!!! Variable: %s has been initialized with type: %s !!!\n", name, return_type);
            exit(0);
        }
        else
        {
            function* var = create_function(visibility, return_type, name); 
            print_function(var);
            push_function(var);
            print_stack_functions();
        }
    }
    
   
    
     /* Variables Recognition */ 

    variable * create_variable(int visibility, char *type, char *name)
    {
        printf("Creating variable:: ");
        variable *v = (variable *)malloc(sizeof(variable));
        v->name = strdup(name); // strdup is used to copy the string
        v->type = type; 
        // v->value = value;
        v->visibility = visibility;
        return v;
    }

    void push_var(variable *v)
    {
        stack[top_var++] = v;
    }

    variable *pop_var()
    {
        return stack[--top_var];
    }

    void print_stack_variable()
    {
        printf("Stack:\n");
        for(int i = 0; i < top_var; i++)
        {
            printf("Name: %s, Type: %s, Value: %s, Visibility: %d\n", stack[i]->name, stack[i]->type, stack[i]->value, stack[i]->visibility);
        }
    }


    void print_variable(variable *v)
    {
        printf("Name: %s, Type: %s, Value: %s, Visibility: %d\n", v->name, v->type, v->value, v->visibility);
    }



    
    int find_variable(char *name)
    {
        for(int i = 0; i < top_var; i++)
        {
            if(strcmp(stack[i]->name, name) == 0)
            {
                print_variable(stack[i]);
                return i;
            }
        }
        return -1;
    }


    void variable_initiliazation(int visibility , char *type, char *name)
    {
        if (find_variable(name) > 0)
        {   
            char *msg;
            yyerror("Variable has been initialized");
            printf("!!! Variable: %s has been initialized with type: %s !!!\n", name, type);
            exit(0);
        }
        else
        {
            variable* var = create_variable(visibility, type, name); 
            print_variable(var);
            push_var(var);
            print_stack_variable();
        }
    }

    void fix_visibility(int count, int visibility)
    {
        while (count != 0)
        {
            stack[top_var - 1 - count]->visibility = visibility;
            count --;
        }
        print_stack_variable();
        count = 0;
    }

%}

// Declare the types of tokens that will be used in the grammar
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
%type <ival> visibility

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
%type <sval> int_init;
%type <sval> double_init;
%type <sval> char_init;
%type <sval> bool_init;
%type <sval> string_init;

%type <sval> variable_assignment
%type <sval> variable_type


// Function Type
%type <ival> function_visibility;

%token <sval> VAR_NAME
%token <sval> VOID
%token <sval> INT
%token <sval> CHAR
%token <sval> DOUBLE
%token <sval> BOOLEAN
%token <sval> STRING
//%token EMTPY

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
	               |  class_members class_body // intitalisation class_body
                   |  class_identifier class_body;
	        
class_members:   variable_initialization SEMICOLON |   variable_assignment SEMICOLON | member_access SEMICOLON;
// For the 2nd Version we need to recognise: int var = INT_Number exc.

//initialisation: variable_init | function_init;
visibility:  %empty { $$ = 0; } | PUBLIC { $$ = 1; } | PRIVATE { $$ = 0; } ;


variable_initialization:  visibility  INT  int_init next_int {variable_initiliazation($1,"int",$3); fix_visibility(var_counter, $1);} |
                          visibility  DOUBLE  double_init next_double { variable_initiliazation($1,"double",$3);  fix_visibility(var_counter, $1); }|
                          visibility  CHAR char_init next_char   { variable_initiliazation($1,"char",$3);  fix_visibility(var_counter, $1);}   |
                          visibility  BOOLEAN  bool_init next_bool  { variable_initiliazation($1,"boolean",$3);  fix_visibility(var_counter, $1);} |
                          visibility  STRING  string_init next_string { variable_initiliazation($1,"String",$3);  fix_visibility(var_counter, $1);};

next_int: %empty    | COMMA int_init next_int {variable_initiliazation(0,"int",$2); var_counter ++; };
next_double: %empty | COMMA double_init next_double;
next_char: %empty   | COMMA char_init next_char;
next_bool: %empty   | COMMA bool_init next_bool;
next_string: %empty | COMMA string_init next_string;

int_init: VAR_NAME {$$ = $1;}   | VAR_NAME EQUAL_SIGN INT_VALUE {printf("int %s = %d",$1,$3); $$ = $1;};
double_init: VAR_NAME {$$ = $1;} | VAR_NAME EQUAL_SIGN DOUBLE_VALUE {printf("double %s = %f",$1,$3); $$ = $1;};
char_init: VAR_NAME  {$$ = $1;} | VAR_NAME EQUAL_SIGN CHAR_VALUE {printf("char %s = '%c'",$1,$3); $$ = $1;};
bool_init: VAR_NAME   {$$ = $1;}| VAR_NAME EQUAL_SIGN BOOLEAN_VALUE {printf("bool %s = %s",$1,$3); $$ = $1;};
string_init: VAR_NAME {$$ = $1;}| VAR_NAME EQUAL_SIGN STRING_VALUE {printf("char* %s = %s",$1,$3); $$ = $1;} ;

// This is NEW
variable_assignment:  VAR_NAME EQUAL_SIGN expression ;
expression: expression PLUS term |expression MINUS term |  BRACKET_LEFT expression  BRACKET_RIGHT | term  ;
term:  term MULTIPLY id | term DIVIDE id | BRACKET_LEFT term BRACKET_RIGHT | BRACKET_LEFT expression BRACKET_RIGHT | id  ;
id: variable_value  | VAR_NAME |  BRACKET_LEFT id  BRACKET_RIGHT | BRACKET_LEFT expression BRACKET_RIGHT;



variable_type: INT { $$ = "int"; }  
              |DOUBLE { $$ = "double";}
              |CHAR { $$ = "char";}
              |BOOLEAN {$$ = "boolean";}
              |STRING {$$ = "String";};

variable_value:  INT_VALUE | CHAR_VALUE | DOUBLE_VALUE | BOOLEAN_VALUE | STRING_VALUE ;

//Class Instance
class_instance: CLASS_NAME VAR_NAME EQUAL_SIGN NEW CLASS_NAME BRACKET_LEFT BRACKET_RIGHT ;
member_access: VAR_NAME DOT VAR_NAME ; //End Class Instance


// Functions
functions: function_visibility VOID VAR_NAME BRACKET_LEFT arguments BRACKET_RIGHT CURLY_BRACKET_LEFT inside_void_function CURLY_BRACKET_RIGHT  {function_initiliazation($1,"void",$3);}
         | function_visibility variable_type VAR_NAME BRACKET_LEFT arguments BRACKET_RIGHT CURLY_BRACKET_LEFT inside_function CURLY_BRACKET_RIGHT  {function_initiliazation($1,$2,$3); printf("\n Function is identified\n");};
function_visibility: PRIVATE {$$ = 0;} | PUBLIC { $$ = 1;};

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