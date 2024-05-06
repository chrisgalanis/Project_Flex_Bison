
%{

#include <stdio.h>
#include "parser.tab.h"
%}
INT "int"
CHAR "char"
DOUBLE "double"
BOOL "boolean"
STRING "String"
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
CLASS "class"
SEMICOLON ";"

%%
{PUBLIC} { return PUBLIC; }
{CLASS} { return CLASS; }
{INT} { return INT;}
{CHAR} { return CHAR;}
{BOOL} {  return BOOL;}
{SEMICOLON} { return SEMICOLON; }
[A-Za-z][A-Za-z0-9_]* { return IDENT;}
[ 	/n]+ { }
"(" { return LPAR; }
")" { return RPAR; }
"{" { return LCURLY; }
"}" { return RCURLY;}
0|[1-9][0-9]* { return INTEGERNUM; }
(0|[1-9][0-9]*)(\.[0-9]+)? { return REALNUM; }

%%

