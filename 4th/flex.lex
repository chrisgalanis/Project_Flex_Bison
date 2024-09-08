%{
#include<stdio.h>
#include "parser.tab.h"

extern int yylineno;
#define YY_USER_ACTION yylloc.first_line = yylineno;


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
"{" { return CURLY_BRACKET_LEFT;}
"}" {return CURLY_BRACKET_RIGHT;}
"(" {return BRACKET_LEFT;}
")" {return BRACKET_RIGHT;}
"=" {return EQUAL_SIGN;}
";" {return SEMICOLON;}
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
{INT} {yylval.sval = "int";return INT;}
{CHAR} {yylval.sval = "char";return CHAR;}
{STRING} {yylval.sval = "string";return STRING;}
{DOUBLE} {yylval.sval = "double";return DOUBLE;}
{BOOLEAN} {yylval.sval = "boolean";return BOOLEAN;}

{PUBLIC} {yylval.sval = "public" ;return PUBLIC;}
{PRIVATE} {yylval.sval = "private";return PRIVATE;}
{CLASS} {return CLASS;}
{NEW} {return NEW;}
[A-Z][A-Za-z0-9_]* {yylval.sval = strdup(yytext);return CLASS_NAME;}


[0-9]+ { yylval.ival = atoi(yytext); return INT_VALUE;}
[0-9]+[.][0-9]+[d] { yytext[yyleng - 1] = '\0'; yylval.dval = strtod(yytext, NULL); return DOUBLE_VALUE;}
['](([ -~]?)|([\\][nts]?))['] { yylval.sval = strdup(yytext); return CHAR_VALUE;}
["][ -~]+["] { yylval.sval = strdup(yytext); return STRING_VALUE;}
{TRUE}|{FALSE} { yylval.sval = strdup(yytext); return BOOLEAN_VALUE;}
[A-Za-z_][A-Za-z0-9_]* { yylval.sval = strdup(yytext); return IDENT;}

"//"([ -~	]+) {}
"/*"([ -~   \n]+)"*/" {}
[ \t] {}
[\n] {yylineno++;}
. {return TRASH;}
%%