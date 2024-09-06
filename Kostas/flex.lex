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
"=" {return EQUAL_SIGN;}
";" {printf("\n ; \n");return SEMICOLON;}
"'" {return SINGLE_MARK;}
":" {return COLON;}
"," {return COMMA;}
"." {return DOT;}

"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MULTIPLY;}
"/" {return DIVIDE;}


{FOR} {printf("\n FOR \n"); return FOR;}
{DO} {printf("\n DO \n"); return DO;}
{WHILE} {return WHILE;}
{IF} { return IF;}
{ELSE} {return ELSE;}

{SWITCH}  {return SWITCH;}
{CASE}    {return CASE; }
{DEFAULT} {return DEFAULT;}

{BREAK}  {return BREAK;}
{RETURN} {return RETURN;}

"=="|"!="|">="|"<="|">"|"<" { return CONDITION_SYMBOL; }
"&&"|"||" {return BOOL_SYMBOL;}
"++"|"--" {return INCREAMENT_DECREAMENT;}
"+="|"-="|"*="|"/=" {return LOOP_STEP;}

{VOID} {return VOID;}
{INT} {return INT;}
{CHAR} {return CHAR;}
{STRING} {return STRING;}
{DOUBLE} {return DOUBLE;}
{BOOLEAN} {return BOOLEAN;}

{PUBLIC} {printf("\nPUBLIC\n"); return PUBLIC;}
{PRIVATE} {printf("\nPRIVATE\n"); return PRIVATE;}
{CLASS} {printf("\nCLASS\n");return CLASS;}
{NEW} {return NEW;}
[A-Z][a-z]* {printf("\nCLASS NAME\n"); return CLASS_NAME;}


[+|-]?[0-9]+ { yylval.ival = atoi(yytext); return INT_VALUE;}
[+|-]?[0-9]+[.][0-9]+[d] { yytext[yyleng - 1] = '\0'; yylval.dval = strtod(yytext, NULL); return DOUBLE_VALUE;}
['](([ -~]?)|([\\][nt]?))['] { yylval.cval = strdup(yytext); return CHAR_VALUE;}
["][ -~]+["] { yylval.sval = strdup(yytext); return STRING_VALUE;}
{TRUE}|{FALSE} { yylval.sval = strdup(yytext); return BOOLEAN_VALUE;}
[A-Za-z][A-Za-z0-9_]* { yylval.sval = strdup(yytext); printf("\nVAR NAME\n");return IDENT;}

"//"([ -~	]+) {printf("\nCOMMENT\n");}
"/*"([ -~   \n]+)"*/" {printf("\nCOMMENTS\n");}
[ \t\n] {}
%%


