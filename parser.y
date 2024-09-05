%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int yylex();
    void yyerror(const char *s);
    
    typedef struct variable
    {
        char *name;
        char *type;
        char *value;
        char* visibility;
        int inside_function;//bool value 
    } variable; 

    typedef struct function
    {
        char *name;
        char *return_type;
        char* visibility;  
        variable* arg[10];
        int top_arg;
    } function;

    typedef struct class
    {
        char *name;
        char* visibility;  
        variable * stack[100];
        int top_var;
        function * functions[100];
        int top_func;
        struct class * child[10];
        int count_child;
    } class;

    typedef struct object
    {
        char *name;
        class * c;
    } object;
   
    object * objects[100];
    int top_object=0;
    class* current_class;

    class * classes[100];
    int top_class=0;

    int var_counter = 0;
    int function_counter=0;
    int class_level=0;
    int parameter_count=0;

    
    class* find_current_class(class* c,int level_counter){
     if ( level_counter==class_level) return c;
    else find_current_class(c->child[c->count_child-1],level_counter++);
   }

     /* Variables Recognition */ 

    variable * create_variable(char* visibility, char *type, char *name)
    {
        variable *v = (variable *)malloc(sizeof(variable));
        v->name = name; // strdup is NOT used to copy the string BECAUSE OF SEGMENTATION ERROR
        v->type = type; 
        // v->value = value;
        v->visibility = visibility;
        v->inside_function = function_counter;
        return v;
    }

    void push_var(variable* stack[],int* top,variable *v)
    {
        stack[(*top)++] = v;
    }

    void pop_var(variable* stack[],int* top)
    {   
        (*top)--;
        free (stack[*top]);
    }

    void print_variable(variable *v)
    {
        printf("VARIABLE: %s %s %s Value: %s, in_function: %d\n", v->visibility, v->type, v->name, v->value,v->inside_function);
    }

    void print_stack_variable(variable* stack[],int top_var)
    {
        for(int i = 0; i < top_var; i++)
            print_variable(stack[i]);
    }

    variable* find_variable_access(variable* stack[],int top_var,char *name){
        for(int i = 0; i < top_var; i++)
            if(strcmp(stack[i]->name, name) == 0) return stack[i];
        return NULL;
    }

    variable* find_variable_initialize(variable* stack[],int top_var,char *name)
    {
        for(int i = 0; i < top_var; i++)
            if(strcmp(stack[i]->name, name) == 0 && stack[i]->inside_function == function_counter) return stack[i];
        return NULL;
    }

    void delete_function_vars()
    {
        class* c=find_current_class(classes[top_class-1],1);
        variable** vs=c->stack;
        int* top=& c->top_var;

        //printf("BEFORE FUNCTION VAR DELETION\n");
        //print_stack_variable( vs,*top);
        while(*top != 0  && vs[(*top)-1]->inside_function == function_counter ){
           pop_var(vs,top);
        }
        function_counter--;
        //printf("AFTER FUNCTION VAR DELETION\n");
         //print_stack_variable( vs,*top);
        return;
    }


    void variable_initiliazation(char* visibility , char *type, char *name)
    {
        class* c=find_current_class(classes[top_class-1],1);
        variable** vs=c->stack;
        int* top=& c->top_var;
        if (find_variable_initialize(vs,*top,name) != NULL)
        {   
            yyerror("Variable has been initialized");
            printf("!!! Variable: %s has been initialized with type: %s !!!\n", name, type);
            exit(0);
        }
        else
        {
            variable* var = create_variable(visibility, type, name); 
            push_var(vs,top,var);
           // print_stack_variable( c->stack,c->top_var);
        }
    }

    void arguement_initiliazation(char* visibility , char *type, char *name)
    {
        variable_initiliazation(visibility,type,name);
        class* c=find_current_class(classes[top_class-1],1);
        
        variable** vs=c->functions[c->top_func-1]->arg;
        int* top=&c->functions[c->top_func-1]->top_arg;
        variable* var = create_variable(visibility, type, name); 
        
        push_var(vs,top,var);
    }

    void fix_visibility(char* visibility)
    {   
        class* c=find_current_class(classes[top_class-1],1);
        while (var_counter != 0)
        {
            c->stack[c->top_var - 1 - var_counter]->visibility =  strdup(visibility);
            var_counter --;
        }
         var_counter= 0;
    }

    /* Functions Recognition */ 

    function * create_function(char* visibility, char *return_type, char *name)
    {
        function *v = (function *)malloc(sizeof(function));
        v->name = name; // strdup is NOT used to copy the string BECAUSE OF SEGMENTATION ERROR
        v->return_type = return_type; 
         v->visibility = visibility;
        return v;
    }

    void print_function(function *f)
    {
        printf("FUNCTION: %s %s, Return Type: %s\n",f->visibility, f->name, f->return_type);
        if(f->top_arg>0){
            printf("\t\tARGUEMENTS OF %s\n",f->name);
            print_stack_variable(f->arg,f->top_arg);
        }
    }

    void print_stack_function(function* functions[],int top_func)
    {
        for(int i = 0; i < top_func; i++)
            print_function(functions[i]);
    }

    function* find_function(function* functions[],int top_func,char *name)
    {
        for(int i = 0; i < top_func; i++)
            if(strcmp(functions[i]->name, name) == 0) return functions[i];
        return NULL;
    }

    void push_function(function* stack[],int* top,function *f)
    {   
        stack[(*top)++] = f;
    }


    void function_initiliazation( char* visibility , char *return_type, char *name)
    {
        class *c =find_current_class(classes[top_class-1],1);
        function** fs=c->functions;
        int* top=& c->top_func;

        if (find_function(fs,*top,name) != NULL)
        {   
            yyerror("Function has been initialized");
            printf("!!! Function: %s has been initialized with type: %s !!!\n", name, return_type);
            exit(0);
        }
        else
        {
            function* f = create_function(visibility, return_type, name); 
           push_function(fs,top,f);
        }
    }

    void check_parameter_type(char* name){
        class* c=find_current_class(classes[top_class-1],1);
        variable* v=find_variable_access(c->stack,c->top_var,name);
        if (v==NULL){
            yyerror("!!!Parameter has not been initialized!!!");
            exit(0);
        }
        function* f=c->functions[c->top_func-1];
         printf("skata 3tted%d\n",f->top_arg);
        if( parameter_count>=f->top_arg){
            yyerror("!!!Too many parameters!!!");
            exit(0);
        }
         printf("skata 4 spotted\n");
        if( strcmp(f->arg[parameter_count]->type, v->type) == 0){
            yyerror("Parameter type mismatch");
            printf("!!! Expected arguement type: %s instead of %s!!!\n",f->arg[parameter_count]->type,v-> type);
            exit(0);
        }
    }

    void check_parameter_count(){
        printf("skata spotted\n");
        class* c=find_current_class(classes[top_class-1],1);
        function* f=c->functions[c->top_func-1];
        printf("skata spotted\n");
        if( parameter_count != f->top_arg){
            yyerror("!!!Too few parameters!!!");
            exit(0);
        }
        printf("skata spotted\n");
    }


    /*Class Recognition*/
    class * create_class(char* visibility, char *name)
    {
         class* v = ( class *)malloc(sizeof( class));
        v->name = name; // strdup is NOT used BECAUSE SEGMENTATION ERROR
        v->visibility = visibility;
        v->top_var=0;
        v->top_func=0;
        v->count_child=0;
       // v->parent=NULL;
        return v;
    }
    //find_current_class(classes[top_class-1],1)

     void print_class(class *c)
    {
        printf("CLASS: %s %s\n",c->visibility, c->name);
        printf("\t\tVariable stack:\n");
        print_stack_variable(c->stack,c->top_var);
        printf("\t\tFunction stack:\n");
        print_stack_function(c->functions,c->top_func);
    }

    void print_inner_classes(class* c){
        if (c->count_child==0) return;
        printf("INNER CLASSES OF:%s\n",c->name);
            for(int i = 0; i < c->count_child; i++){
                print_class(c->child[i]);
                print_inner_classes(c->child[i]);
            }
        printf("END OF INNER CLASSES OF:%s\n",c->name);
    }

    void print_program(){
        printf("--------------PROGRAM--------------\n");
        for(int i=0;i<top_class;i++){
            print_class(classes[i]);
            print_inner_classes(classes[i]);
        }
 
    }

    class* find_class(char *name,class* c[],int top)
    {
        for(int i = 0; i < top; i++)
            if(strcmp(c[i]->name, name) == 0) return c[i];
        return NULL;
    }

    void push_class(class* stack[],int* top,class *c)
    {   
        stack[(*top)++] = c;
    }

    void class_initiliazation(char* visibility , char *name)
    {   class** cl=classes;
        int* top=&top_class;
        
        class** parent_stack=cl;
        int parent_top;
        if(class_level>0){
            for(int i=0;i<class_level;i++){
                cl=cl[(*top)-1]->child;//set child stack as current stack
                top=&(parent_stack[(*top)-1]->count_child);//set child counter as current counter
                parent_stack=cl;//copy current class stack
            }
        }

        if (find_class(name,cl,*top) != NULL)
        {   
            yyerror("Class has been initialized");
            printf("!!! Class: %s has been initialized with visibility: %s !!!\n", name, visibility);
            exit(0);
        }
        else
        {
            class* c = create_class(visibility, name);
            //if (class_level>0)c->parent=parent_stack[]
            
            push_class(cl,top,c);
        }
    }
    /*Object*/
    void print_objects(){
        for(int i=0;i<top_object;i++)
            printf("OBJECT: %s of class %s\n",objects[i]->name, objects[i]->c->name);
    }

     object * create_object(char *name,char* class_name)
    {
         object* o = ( object *)malloc(sizeof( object));
        o->name = name; // strdup is NOT used BECAUSE SEGMENTATION ERROR
        o->c=find_class(class_name,classes,top_class);
        if (o->c==NULL){
            yyerror("Class has not been declared\n");
            exit(0);
        }
        return o;
    }

    object* find_object(char* name){
        for(int i = 0; i < top_object; i++)
            if(strcmp(objects[i]->name, name) == 0) return objects[i];
        return NULL;
    }

    void object_initiliazation(char *name,char* class_name){
           if (find_object(name) != NULL)
        {   
            yyerror("Object has been initialized");
            printf("!!! Object: %s has been initialized !!!\n", name);
            exit(0);
        }
        else
        {
            object* o=create_object(name,class_name);
            objects[top_object++]=o;
            print_objects();
        }
    }

    

    void get_object_var(char* name,char* var){
        object* o=find_object(name);
        if (o== NULL){
            yyerror("Object has not been initialized");
            exit(0);
        }
        variable* v=find_variable_access(o->c->stack,o->c->top_var,var);
        if (v == NULL){
            yyerror("Variable has not been declared");
            printf("Variable %s has not been declared in class %s\n",var,o->c->name);
            exit(0);
        }
        if (strcmp(v->visibility,"private")==0){
            yyerror("Private Variable can not be accessed outside of class scope");
            exit(0);
        }
        printf("Successfull member access\n");
    }

    void get_object_func(char* name,char* func){
        object* o=find_object(name);
        if (o== NULL){
            yyerror("Object has not been initialized\n");
            exit(0);
        }
        function* f=find_function(o->c->functions,o->c->top_func,func);
        if (f == NULL){
            yyerror("Function has not been declared\n");
            exit(0);
        }
        if (strcmp(f->visibility,"private")==0){
            yyerror("Private function can not be accessed outside of class scope\n");
            exit(0);
        }
        printf("Successfull member access\n");
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
%token <sval>  PUBLIC
%token  <sval>PRIVATE
%type <sval> visibility

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

//data Types
%type <sval> int_init;
%type <sval> double_init;
%type <sval> char_init;
%type <sval> bool_init;
%type <sval> string_init;

%type <sval> data_assignment
%type <sval> data_type

%type <sval> VAR_NAME;
// Function Type
%type <sval> function_visibility;
%type <sval> function_call;

%token <sval> IDENT
%token <sval> VOID
%token <sval> INT
%token <sval> CHAR
%token <sval> DOUBLE
%token <sval> BOOLEAN
%token <sval> STRING
//%token EMTPY

//data Values
%token <ival> INT_VALUE 
%token <cval> CHAR_VALUE
%token <dval> DOUBLE_VALUE
%token <sval> BOOLEAN_VALUE
%token <sval> STRING_VALUE

%glr-parser


%start program

%%

program: %empty{print_program();} | class_identifier program ;

VAR_NAME: CLASS_NAME{$$=$1;} | IDENT{$$=$1;};

// Class Identifier of Only One Class
class_identifier: PUBLIC CLASS CLASS_NAME CURLY_BRACKET_LEFT {class_initiliazation($1,$3);class_level++;printf("CLASS %s IDENTIFIED\n",$3);}class_body CURLY_BRACKET_RIGHT { class_level--;printf("END OF CLASS %s\n",$3);}


// !! Double Check if class members before of functions
class_body: %empty |  functions class_body
	               |  class_members class_body // intitalisation class_body
                   |  class_identifier class_body ;
	        
class_members:   data_initialization SEMICOLON |   data_assignment SEMICOLON | member_access SEMICOLON | class_instance SEMICOLON;
// For the 2nd Version we need to recognise: int var = INT_Number exc.

//initialisation: data_init | function_init;
visibility:  %empty { $$ = "default"; } | PUBLIC { $$ = $1; } | PRIVATE { $$ = $1; } ;


data_initialization:  visibility  INT  int_init next_int {variable_initiliazation($1,$2,$3); fix_visibility($1);}|
                          visibility  DOUBLE  double_init next_double  {variable_initiliazation($1,$2,$3); fix_visibility($1);} |
                          visibility  CHAR char_init next_char    {variable_initiliazation($1,$2,$3); fix_visibility($1);} |
                          visibility  BOOLEAN  bool_init next_bool {variable_initiliazation($1,$2,$3); fix_visibility($1);} |
                          visibility  STRING  string_init next_string {variable_initiliazation($1,$2,$3); fix_visibility($1);};

next_int: %empty    | COMMA int_init next_int  {variable_initiliazation(0,"int",$2); var_counter ++; };
next_double: %empty | COMMA double_init next_double {variable_initiliazation(0,"double",$2); var_counter ++; };
next_char: %empty   | COMMA char_init next_char {variable_initiliazation(0,"char",$2); var_counter ++; };
next_bool: %empty   | COMMA bool_init next_bool    {variable_initiliazation(0,"boolean",$2); var_counter ++; };
next_string: %empty | COMMA string_init next_string    {variable_initiliazation(0,"string",$2); var_counter ++; };

int_init: VAR_NAME {$$ = $1;}   | VAR_NAME EQUAL_SIGN INT_VALUE {printf("int %s = %d",$1,$3); $$ = $1;};
double_init: VAR_NAME {$$ = $1;} | VAR_NAME EQUAL_SIGN DOUBLE_VALUE {printf("double %s = %f",$1,$3); $$ = $1;};
char_init: VAR_NAME  {$$ = $1;} | VAR_NAME EQUAL_SIGN CHAR_VALUE {printf("char %s = '%c'",$1,$3); $$ = $1;};
bool_init: VAR_NAME   {$$ = $1;}| VAR_NAME EQUAL_SIGN BOOLEAN_VALUE {printf("bool %s = %s",$1,$3); $$ = $1;};
string_init: VAR_NAME {$$ = $1;}| VAR_NAME EQUAL_SIGN STRING_VALUE {printf("char* %s = %s",$1,$3); $$ = $1;} ;

// This is NEW
data_assignment:  VAR_NAME EQUAL_SIGN expression { };

expression: expression PLUS term  { printf("\n addition \n");} |expression MINUS term |  BRACKET_LEFT expression  BRACKET_RIGHT | term  ;
term:  term MULTIPLY id  { printf("\nmul\n");} | term DIVIDE id | BRACKET_LEFT term BRACKET_RIGHT | BRACKET_LEFT expression BRACKET_RIGHT | id  ;
id: data_value  | VAR_NAME |  BRACKET_LEFT id  BRACKET_RIGHT | BRACKET_LEFT expression BRACKET_RIGHT;



data_type: INT { $$ = "int"; }  
              |DOUBLE { $$ = "double";}
              |CHAR { $$ = "char";}
              |BOOLEAN {$$ = "boolean";}
              |STRING {$$ = "String";};

data_value:  INT_VALUE | CHAR_VALUE | DOUBLE_VALUE | BOOLEAN_VALUE | STRING_VALUE ;

//Class Instance
class_instance: CLASS_NAME VAR_NAME EQUAL_SIGN NEW CLASS_NAME BRACKET_LEFT BRACKET_RIGHT {
    if(strcmp($1,$5)==0){
    object_initiliazation($2,$1);
    printf("instance %s of class %s\n",$2,$1);
    }else{
        printf("ERROR!!Invalid initiliazation of instance %s\n",$2);
    }
    };
member_access: VAR_NAME DOT VAR_NAME {get_object_var($1,$3);} | VAR_NAME DOT function_call {printf("func access\n");get_object_func($1,$3);}; //End Class Instance


// Functions
functions: function_visibility VOID VAR_NAME BRACKET_LEFT{function_counter++;function_initiliazation($1,"void",$3); printf("Function %s is identified\n",$3);} arguments_start BRACKET_RIGHT CURLY_BRACKET_LEFT inside_void_function CURLY_BRACKET_RIGHT  { delete_function_vars();printf("END OF function \n");}
         | function_visibility data_type VAR_NAME BRACKET_LEFT {function_counter++;function_initiliazation($1,$2,$3); printf("Function %s is identified\n",$3);}  arguments_start BRACKET_RIGHT CURLY_BRACKET_LEFT inside_function CURLY_BRACKET_RIGHT  { delete_function_vars();printf("END OF function \n");};
function_visibility: PRIVATE {$$ = $1;} | PUBLIC { $$ = $1;};

arguments_start : %empty| arguments
arguments: data_type VAR_NAME {arguement_initiliazation("default",$1,$2);} arguments_end
arguments_end : %empty | COMMA arguments 



inside_void_function: inside_brackets | inside_brackets RETURN SEMICOLON ;
inside_function: inside_brackets  RETURN VAR_NAME SEMICOLON{}  | inside_brackets RETURN data_value SEMICOLON ;

function_call:  VAR_NAME BRACKET_LEFT parameters_start BRACKET_RIGHT {$$=$1;};

parameters_start:%empty{printf("no parameter\n");}|parameters{check_parameter_count();parameter_count=0;} 
parameters: VAR_NAME parameters_end{printf("var name:%s\n",$1);check_parameter_type($1);parameter_count++;}|data_value parameters_end
parameters_end:%empty
|COMMA parameters

// End Functions

// !! Ambiguity !!
inside_brackets: %empty|function_call inside_brackets|functions inside_brackets | loops_n_condition inside_brackets | data_initialization  SEMICOLON inside_brackets | data_assignment SEMICOLON inside_brackets | class_instance SEMICOLON inside_brackets |member_access SEMICOLON inside_brackets ;

loops_n_condition: for_statement | switch | do_while | if  ; // + Δήλωση Μεταβλητών

// For Loop
for_statement:  FOR BRACKET_LEFT for_condition BRACKET_RIGHT CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT  {printf("\n For is identified\n");};
for_condition:  for_data SEMICOLON for_comparison SEMICOLON for_step ;

for_data: %empty | data_type VAR_NAME EQUAL_SIGN data_value  ;

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