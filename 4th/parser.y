%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    int yylex();
    void yyerror(const char *s);

      typedef struct var_value
    {
        int itemp;
        double dtemp;
        char *stemp;
    } var_value;

   typedef struct var
    {
        char *name;
        char *type;
        var_value value;
        char* visibility;
        int inside_function;//bool value 
    } var; 

    typedef struct function
    {
        char *name;
        char *return_type;
        char* visibility;  
        var* arg[10];
        int top_arg;
    } function;

    typedef struct class
    {
        char *name;
        char* visibility;  
        var* stack[100];
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
   /*PROGRAM VARIABLES*/
    object * objects[100];
    int top_object=0;

    class* current;
    function* function_called;
    var* instance_variable;

    class * classes[100];
    int top_class=0;

    char * visibility;
    char* data_type;
    char* value_type;
    var_value value;

    int function_counter=0;
    int class_level=0;
    int parameter_count=0;

    int class_error=0;
  /*PROGRAM FUNCTIONS*/  
    class* find_current(class* c,int level_counter){
     if ( c->count_child==0 || level_counter==class_level) return c;
    else find_current(c->child[c->count_child-1],level_counter++);
   }

     /* Variables Recognition */ 

    var* create_variable(char* visibility, char *type, char *name)
    {
        var*v = (var*)malloc(sizeof(var));
        v->name = name; // strdup is NOT used to copy the string BECAUSE OF SEGMENTATION ERROR
        v->type = type; 
        //v->value = NULL;
        v->visibility = visibility;
        v->inside_function = function_counter;
        return v;
    }

    void push_var(var* stack[],int* top,var*v)
    {
        stack[(*top)++] = v;
    }

    void pop_var(var* stack[],int* top)
    {   
        (*top)--;
        free (stack[*top]);
    }

    void print_variable(var*v)
    {
        if (strcmp(v->type, "int") == 0) printf("VARIABLE: %s %s %s Value: %d, in_function: %d\n", v->visibility, v->type, v->name, v->value.itemp,v->inside_function);
        else if (strcmp(v->type, "double") == 0) printf("VARIABLE: %s %s %s Value: %f, in_function: %d\n", v->visibility, v->type, v->name, v->value.dtemp,v->inside_function);              
        else printf("VARIABLE: %s %s %s Value: %s, in_function: %d\n", v->visibility, v->type, v->name, v->value.stemp,v->inside_function);
    }

    void print_stack_variable(var* stack[],int top_var)
    {
        for(int i = 0; i < top_var; i++)
            print_variable(stack[i]);
    }

    var* find_variable(var* stack[],int top_var,char *name){
        for(int i = 0; i < top_var; i++)
            if(strcmp(stack[top_var-1-i]->name, name) == 0) return stack[top_var-1-i];
        return NULL;
    }

    var* find_variable_initialize(var* stack[],int top_var,char *name)
    {
        for(int i = 0; i < top_var; i++)
            if(strcmp(stack[top_var-1-i]->name, name) == 0 && stack[top_var-1-i]->inside_function == function_counter) return stack[top_var-1-i];
        return NULL;
    }

    void delete_function_vars()
    {
        class* c=current;
        var** vs=c->stack;
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


    void var_initialize(char* visibility , char *type, char *name)
    {
        class* c=current;
        var** vs=c->stack;
        int* top=& c->top_var;
        var* temp;
        if ((temp = find_variable_initialize(vs,*top,name)) != NULL)
        {   
            yyerror("Variable has been initialized");
            printf("!!! Variable: %s has been initialized with type: %s !!!\n", name, temp->type);
        }
        else
        {
            var* var = create_variable(visibility, type, name); 
            push_var(vs,top,var);
           // print_stack_variable( c->stack,c->top_var);
        }
    }
     
     void fix_value( var*v,var_value value,char* value_type){
            if ( v == NULL ){
                yyerror("Variable has not been initialized");
                return;
            }
            if (strcmp(v->type, "int") == 0|| strcmp(v->type, "double") == 0 ) {
                v->value.itemp = value.itemp;
                v->value.dtemp = value.dtemp;   
            }              
            else if(strcmp(v->type,value_type)==0) v->value.stemp = value.stemp;
            else{
                yyerror("Variable type and value type mismatch");
                return;
            }
            print_variable(v);
    }

    void var_initialize_value(char* visibility , char *type, char *name,var_value value,char* value_type)
    {
        var_initialize(visibility,type,name);
        fix_value(find_variable(current->stack,current->top_var,name),value,value_type);
    }


   

    void arguement_initialization(char* visibility , char *type, char *name)
    {
        var_initialize(visibility,type,name);
        class* c=current;
        
        var** vs=c->functions[c->top_func-1]->arg;
        int* top=&c->functions[c->top_func-1]->top_arg;
        var* var = create_variable(visibility, type, name); 
        
        push_var(vs,top,var);
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
        class *c =current;
        function** fs=c->functions;
        int* top=& c->top_func;

        if (find_function(fs,*top,name) != NULL)
        {   
            yyerror("Function has been initialized");
            printf("!!! Function: %s has been initialized with type: %s !!!\n", name, return_type);
        }
        else
        {
            function* f = create_function(visibility, return_type, name); 
           push_function(fs,top,f);
        }
    }

    void check_parameter_type(function* f,var* v,char* name){
        if (f==NULL){
            yyerror("Function can not be accessed");
            return;
        }
        if (v==NULL){
            yyerror("!!!Parameter can not be accessed!!!");
           printf("!!! Parameter %s has not been initialized in this scope!!!\n",name);
           return;
        }
        if( parameter_count>=f->top_arg){
            yyerror("!!!Too many parameters!!!");
            return;
        }
        if( strcmp(f->arg[parameter_count]->type, v->type) != 0){
            yyerror("Parameter type mismatch");
            printf("!!! Expected arguement type: %s instead of %s!!!\n",f->arg[parameter_count]->type,v-> type);
            return;
        }
        printf("PARAMETER %s matched\n",name);
    }

    void check_parameter_count(function* f){
        if (f==NULL){
            yyerror("Function can not be accessed");
            return;
        }
        if( parameter_count != f->top_arg){
            yyerror("!!!Too few parameters!!!");
            return;
        }
    }

    /*Class Recognition*/
    class * create_class(char* visibility, char *name)
    {
         class* v = ( class *)malloc(sizeof( class));
        v->name = strdup(name); 
        v->visibility = visibility;
        v->top_var=0;
        v->top_func=0;
        v->count_child=0;
       // v->parent=NULL;
        return v;
    }

     void print_class(class *c){
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
            return;
        }
        else
        {
            class* c = create_class(visibility, name);
            //if (class_level>0)c->parent=parent_stack[]
            
            push_class(cl,top,c);
            class_level++;
            current=find_current(classes[top_class-1],1);
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
            return NULL;
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
            return;
        }
        else
        {
            object* o=create_object(name,class_name);
            if (o!=NULL) objects[top_object++]=o;
            print_objects();
        }
    }

    var* get_object_var(char* name,char* var_name){
        object* o=find_object(name);
        printf("object name %s\n",o->name);
        if (o== NULL){
            yyerror("Object has not been initialized");
            return NULL;
        }
        var* v=find_variable(o->c->stack,o->c->top_var,var_name);
        if (v == NULL){
            yyerror("Variable has not been declared");
            printf("Variable %s has not been declared in class %s\n",var_name,o->c->name);
            return NULL;
        }
        if (strcmp(v->visibility,"private")==0){
            yyerror("Private Variable can not be accessed outside of class scope");
            printf("Variable %s is private \n",var_name);
            return NULL;
        }
        printf("Successfull variable access\n");
        return v;
    }

    function* get_object_func(char* name,char* func_name){
        object* o=find_object(name);

        if (o== NULL){
            yyerror("Object has not been initialized\n");
            return NULL;
        }
        function* f=find_function(o->c->functions,o->c->top_func,func_name);
        if (f == NULL){
            yyerror("Function has not been declared\n");
            return NULL;
        }
        if (strcmp(f->visibility,"private")==0){
            yyerror("Private function can not be accessed outside of class scope\n");
            return NULL;
        }
        printf("Successfull function access\n");
        return f;
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
%token COLON
%token COMMA
%token DOT  

//Operations
%left  PLUS
%left MINUS
%left MULTIPLY
%left DIVIDE
%nonassoc UMINUS // Unary Minus , recognizing  negative numbers

// Class Identifier
%token <sval>  PUBLIC
%token <sval> PRIVATE
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

%token PRINT
%token TRASH
//data Types

%type <sval> variable_assignment
%type <sval> data_type
%type <dval> expression
%type <sval> VAR_NAME


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
%token <sval> CHAR_VALUE
%token <dval> DOUBLE_VALUE
%token <sval> BOOLEAN_VALUE
%token <sval> STRING_VALUE

%locations

%glr-parser


%start program

%%

program: class_identifier  program
        |%empty{print_program();} 
        |error {} program
        ;

VAR_NAME: CLASS_NAME{$$=$1;} | IDENT{$$=$1;};

class_identifier: 
PUBLIC CLASS CLASS_NAME CURLY_BRACKET_LEFT {class_initiliazation($1,$3);printf("CLASS %s IDENTIFIED\n",$3);}class_body CURLY_BRACKET_RIGHT { class_level--;current=find_current(classes[top_class-1],1);printf("END OF CLASS %s\n",$3);} 
|error CURLY_BRACKET_LEFT{char name[4];sprintf(name,"%d",class_error++);class_initiliazation("ERROR",name);yyerror("Error in class declaration");}class_body CURLY_BRACKET_RIGHT { class_level--;current=find_current(classes[top_class-1],1);printf("END OF CLASS ERROR\n");}

;
class_body: 
    %empty 
    |  functions class_body 
    |  class_members_semicolon class_body //error handled
    |  class_identifier class_body 
    
    ;
	        
class_members:  
    variable_declaration  //error handled
    | variable_initialization  //error handled
    ;

class_members_semicolon: class_members SEMICOLON |class_members error {yyerror("Missing semicolon");}



visibility:  %empty { $$ = "default"; } | PUBLIC { $$ = $1; } | PRIVATE { $$ = $1; } ;

variable_declaration: 
    visibility data_type VAR_NAME {visibility=$1; data_type=$2;var_initialize($1,$2,$3);} next_declaration
  //  | error {yyerror("Error in variable declaration");}

next_declaration:
    %empty    
    | COMMA VAR_NAME { var_initialize(visibility,data_type,$2);} next_declaration
    | error {yyerror("Error in initiliasation multiple variables"); yyerrok;}
    ;

variable_initialization: 
    visibility  data_type  VAR_NAME EQUAL_SIGN expression  {visibility=$1;data_type=$2;value.itemp=$5;value.dtemp=$5;var_initialize_value($1,$2,$3,value,value_type);}next_initialization
    | error {yyerror("Error in variable initialization/decleration"); yyerrok; }
    ;

next_initialization:
    %empty    
    | COMMA VAR_NAME EQUAL_SIGN expression  {value.itemp=$4;value.dtemp=$4;var_initialize_value(visibility,data_type,$2,value,value_type); }next_initialization
    ;

variable_assignment:  
    VAR_NAME EQUAL_SIGN expression{value.itemp=$3;value.dtemp=$3;fix_value(find_variable(current->stack,current->top_var,$1),value,value_type); }
    | VAR_NAME step
    | error {yyerror("Error in variable assignment"); yyerrok; }
    ;

expression: INT_VALUE { $$ = $1 ;} 
            |DOUBLE_VALUE   { $$ = $1; }
            |CHAR_VALUE { $$=0; value_type="char";value.stemp=$1;} 
            |BOOLEAN_VALUE { $$ = 0;value_type="boolean";value.stemp=$1;} 
            |STRING_VALUE { $$ = 0;value_type="string";value.stemp=$1;} 
            |VAR_NAME{var* v = find_variable(current->stack,current->top_var,$1); 
                if( v != NULL){  
                    value_type=v->type;
                    value.stemp=v->value.stemp;
                    if(strcmp(v->type,"int") == 0 ||strcmp(v->type,"double") == 0 ) {
                        $$= v->value.itemp;
                        $$= v->value.dtemp;
                        value_type="int/double";
                    }
                }
                else  yyerror("Variable inside expression has not been initialised!");
                }  
            |member_access{ var* v=instance_variable;
                if( v != NULL){  
                    value_type=v->type;
                    value.stemp=v->value.stemp;
                    if(strcmp(v->type,"int") == 0 ||strcmp(v->type,"double") == 0 ) {
                        $$= v->value.itemp;
                        $$= v->value.dtemp;
                        value_type="int/double";
                    }
                }
                else yyerror("Variable inside expression has not been initialised!"); 
                }
            | expression PLUS expression { $$ = $1 + $3 ; } 
            | expression MINUS expression { $$ = $1 - $3; }
            | expression MULTIPLY expression { $$ = $1 * $3; }
            | expression DIVIDE expression	{ if ($3==0) yyerror("Cannot divide by zero"); else $$ = $1 / (float)$3;}
            | BRACKET_LEFT expression BRACKET_RIGHT { $$ = $2; }
            | MINUS expression %prec UMINUS { $$ = -$2; } 
            | PLUS expression %prec UMINUS {$$ = $2;}
            ;


data_type: INT { $$ = "int"; } | DOUBLE { $$ = "double";} | CHAR { $$ = "char";}|BOOLEAN {$$ = "boolean";}|STRING {$$ = "String";};
              
//Class Instance
class_instance: 
    CLASS_NAME VAR_NAME EQUAL_SIGN NEW CLASS_NAME BRACKET_LEFT BRACKET_RIGHT {if(strcmp($1,$5)==0)object_initiliazation($2,$1);else  yyerror("ERROR!!Invalid initiliazation of instance");}
    |error {yyerror("ERROR!!Invalid initiliazation of instance"); yyerrok; }
    ;

member_access: 
    VAR_NAME DOT VAR_NAME {instance_variable=get_object_var($1,$3);} 
    | VAR_NAME DOT VAR_NAME BRACKET_LEFT {function_called=get_object_func($1,$3);} parameters_start BRACKET_RIGHT
    | error{yyerror("Error in class member access");yyerrok; }
    ;
    
// Functions
functions:
     function_visibility VOID VAR_NAME BRACKET_LEFT{function_counter++;function_initiliazation($1,"void",$3); printf("Function %s IDENTIFIED\n",$3);} arguments_start BRACKET_RIGHT CURLY_BRACKET_LEFT inside_void_function CURLY_BRACKET_RIGHT  { delete_function_vars();printf("END OF function \n");}
    |function_visibility data_type VAR_NAME BRACKET_LEFT {function_counter++;function_initiliazation($1,$2,$3); printf("Function %s IDENTIFIED\n",$3);}  arguments_start BRACKET_RIGHT CURLY_BRACKET_LEFT inside_function  CURLY_BRACKET_RIGHT  { delete_function_vars();printf("END OF function \n");};
    | VOID error{yyerror("Error in function declaratiob");yyerrok; } CURLY_BRACKET_LEFT CURLY_BRACKET_RIGHT 
    ;

function_visibility: PRIVATE {$$ = $1;} | PUBLIC { $$ = $1;};

arguments_start : %empty| arguments 
arguments: data_type VAR_NAME {arguement_initialization("default",$1,$2);} arguments_end 
arguments_end : %empty | COMMA arguments 



inside_void_function: inside_brackets | inside_brackets RETURN SEMICOLON ;
inside_function: inside_brackets  RETURN VAR_NAME SEMICOLON  | inside_brackets RETURN expression SEMICOLON ;


function_call:  VAR_NAME BRACKET_LEFT{function_called=find_function(current->functions,current->top_func,$1);} parameters_start BRACKET_RIGHT {$$=$1;}
                | error{yyerror("Error in function call");yyerrok; } ;

parameters_start:%empty{printf("no parameter\n");}|parameters{check_parameter_count(function_called);parameter_count=0;} 

parameters:
    VAR_NAME {check_parameter_type(function_called,find_variable(current->stack,current->top_var,$1),$1);parameter_count++;} parameters_end
    |VAR_NAME DOT VAR_NAME{check_parameter_type(function_called,get_object_var($1,$3),$3);parameter_count++;} parameters_end  
    |expression {parameter_count++;}parameters_end;

parameters_end:%empty|COMMA parameters

statement: function_call  
        | variable_declaration   
        | variable_initialization    
        | variable_assignment  
        | class_instance 
        |member_access 
        |print     
        ;

statement_semicolon: statement SEMICOLON | statement error{ yyerror("Error missing semicolon");yyerrok; };

// !! Ambiguity !!
inside_brackets: %empty
                |statement_semicolon inside_brackets
                |functions inside_brackets 
                | loops_n_condition inside_brackets 
                ;

loops_n_condition: for_statement | switch | do_while | if ; 

// For Loop
for_statement:  
    FOR BRACKET_LEFT{function_counter++;printf("FOR LOOP IDENTIFIED\n");} for_condition BRACKET_RIGHT CURLY_BRACKET_LEFT inside_brackets_break CURLY_BRACKET_RIGHT  {delete_function_vars();printf("END OF FOR \n");}
    | error CURLY_BRACKET_LEFT {yyerror("Error in FOR lLOOP statement");function_counter++;yyerrok; }  inside_brackets_break CURLY_BRACKET_RIGHT  {delete_function_vars(); }
    ;

for_condition:  for_variable SEMICOLON condition SEMICOLON for_step ;

for_variable: %empty |  variable_initialization  | variable_assignment ;

condition: %empty | expression CONDITION_SYMBOL expression bool_operator | VAR_NAME bool_operator | BOOLEAN_VALUE bool_operator; // remove var_name and boolean value,already included in expression
bool_operator:  %empty | BOOL_SYMBOL condition;

for_step : %empty | VAR_NAME step ;

step: INCREAMENT_DECREAMENT | LOOP_STEP expression;

inside_brackets_break :inside_brackets | inside_brackets BREAK SEMICOLON inside_brackets ;

// DO While Loop 
do_while: DO CURLY_BRACKET_LEFT {function_counter++;printf("DO WHILE IDENTIFIED\n");} inside_brackets_break CURLY_BRACKET_RIGHT  WHILE BRACKET_LEFT condition BRACKET_RIGHT SEMICOLON {delete_function_vars();printf("END of Do While \n");}
        |error CURLY_BRACKET_LEFT {yyerror("Error in DO WHILE LOOP");function_counter++;yyerrok; }  inside_brackets_break CURLY_BRACKET_RIGHT error SEMICOLON {delete_function_vars(); }
        ;

// Switch  
switch: SWITCH BRACKET_LEFT  expression BRACKET_RIGHT CURLY_BRACKET_LEFT {function_counter++;printf("SWITCH IDENTIFIED\n");}  case default CURLY_BRACKET_RIGHT {delete_function_vars();printf("END of Switch \n");}
        |error CURLY_BRACKET_LEFT {yyerror("Error in SWITCH statement");function_counter++;yyerrok; }  inside_brackets CURLY_BRACKET_RIGHT  {delete_function_vars(); }
        ;

case: CASE expression COLON inside_brackets_break case |%empty


default: DEFAULT COLON inside_brackets_break  |%empty ;

// IF 
if: IF BRACKET_LEFT condition BRACKET_RIGHT CURLY_BRACKET_LEFT {function_counter++;printf("IF IDENTIFIED\n");}  inside_brackets CURLY_BRACKET_RIGHT  {delete_function_vars();printf(" End of If is identified\n");} else_if 
    |IF BRACKET_LEFT error CURLY_BRACKET_LEFT {yyerror("Error in IF statement");function_counter++;yyerrok; }  inside_brackets CURLY_BRACKET_RIGHT  {delete_function_vars(); } else_if
    ;

else_if:ELSE IF BRACKET_LEFT condition BRACKET_RIGHT CURLY_BRACKET_LEFT{function_counter++;printf("ELSE IF IDENTIFIED\n");}   inside_brackets CURLY_BRACKET_RIGHT {delete_function_vars();printf("End of else if \n");} else_if 
        |ELSE IF BRACKET_LEFT error CURLY_BRACKET_LEFT {yyerror("Error in IF ELSE statement");function_counter++;printf("ELSE IDENTIFIED\n");yyerrok; }  inside_brackets CURLY_BRACKET_RIGHT  {delete_function_vars(); }else_if
        | else 
        ;

else: %empty  
    | ELSE CURLY_BRACKET_LEFT {function_counter++;} inside_brackets CURLY_BRACKET_RIGHT {delete_function_vars();printf("End of Else is identified\n");}   
    |error CURLY_BRACKET_LEFT {yyerror("Error in ELSE statement");function_counter++;yyerrok; }  inside_brackets CURLY_BRACKET_RIGHT  {delete_function_vars(); }
    ;

//PRINT
print : PRINT BRACKET_LEFT STRING_VALUE after_print BRACKET_RIGHT {printf("PRINT IDENTIFIED\n");}
        |PRINT error {yyerror("Error in PRINT statement");yyerrok; }
        ;

after_print: %empty | COMMA VAR_NAME after_print;
            
%%

int main(void)
{
    yyparse();
}


void yyerror(const char *msg)
{
    printf("** Line %d: %s\n", yylloc.first_line, msg);
}