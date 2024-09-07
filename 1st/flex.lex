%{
#include<stdio.h>
#include "parser.tab.h"

%}

INT "int"
CHAR "char"
DOUBLE "double"
BOOLEAN "boolean"
STRING "String"
CLASS "class"
NEW "new"
RETURN "return"
VOID "void"
IF "if"
ELSE "else"
WHILE "while"
DO "do"
FOR "for"
SWITCH "switch"
CASE "case"
DEFAULT "default"
BREAK "break"
TRUE "true"
FALSE "false"
PUBLIC "public"
PRIVATE "private"

%%
"{" {printf("\n { \n"); return CURLY_BRACKET_LEFT;}
"}" {printf("\n } \n");return CURLY_BRACKET_RIGHT;}
"(" {printf("\n ( \n");return BRACKET_LEFT;}
")" {printf("\n ) \n");return BRACKET_RIGHT;}
"=" {printf("\n = \n");return EQUAL_SIGN;}
";" {printf("\n ; \n");return SEMICOLON;}

":" {return COLON;}
"," {return COMMA;}
"." {return DOT;}

"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MULTIPLY;}
"/" {return DIVIDE;}

"out.println"|"out.print" {printf("\n PRINT \n"); return PRINT;}
{FOR} {printf("\n FOR \n"); return FOR;}
{DO} {printf("\n DO \n"); return DO;}
{WHILE} {printf("\n WHILE \n");return WHILE;}
{IF} { printf("\n IF \n");return IF;}
{ELSE} {printf("\n ELSE \n");return ELSE;}

{SWITCH}  {return SWITCH;}
{CASE}    {return CASE; }
{DEFAULT} {return DEFAULT;}

{BREAK}  {printf("\n BREAK \n"); return BREAK;}
{RETURN} {printf("\n RETURN \n"); return RETURN;}

"=="|"!="|">="|"<="|">"|"<" { return CONDITION_SYMBOL; }
"&&"|"||" {return BOOL_OP;}
"++"|"--" {return INCREAMENT_DECREAMENT;}
"+="|"-="|"*="|"/=" {return LOOP_STEP;}

{VOID} {return VOID;}
{INT} { printf("\n INT \n") ; return INT;}
{CHAR} { printf("\n CHAR \n") ;return CHAR;}
{STRING} { printf("\n STRING \n") ;return STRING;}
{DOUBLE} { printf("\n DOUBLE \n") ;return DOUBLE;}
{BOOLEAN} { printf("\n BOOLEAN \n") ; return BOOLEAN;}

{PUBLIC} {printf("\nPUBLIC\n"); return PUBLIC;}
{PRIVATE} {printf("\nPRIVATE\n"); return PRIVATE;}
{CLASS} {printf("\nCLASS\n");return CLASS;}
{NEW} {return NEW;}
[A-Z][A-Za-z0-9_]* {printf("\nCLASS NAME\n"); return CLASS_NAME;}


[+|-]?[0-9]+ {return INT_VALUE;}
[+|-]?[0-9]+[.][0-9]+[d] {return DOUBLE_VALUE;}
['](([ -~]?)|([\\][nts]?))['] {return CHAR_VALUE;}
["][ -~]*["] {return STRING_VALUE;}
{TRUE}|{FALSE} {return BOOLEAN_VALUE;}
[A-Za-z_][A-Za-z0-9_]* {printf("\nIDENT\n");return IDENT;}

"//"([ -~	]+) {printf("\nCOMMENT\n");}
"/*"([ -~   \n]+)"*/" {printf("\nCOMMENTS\n");}
[ \t\n] {}
%%


