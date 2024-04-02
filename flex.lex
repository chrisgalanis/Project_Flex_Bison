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
{INT} {return INT;}
{PUBLIC} {return PUBLIC;}
{CLASS} {return CLASS;}
"{" {return CURLY_BRACKET_LEFT;}
"}" {return CURLY_BRACKET_RIGHT;}
[0-9]+ {printf("%s\n", yytext);}
[A-Z]+[a-z]* {printf("%s\n", yytext); return CLASS_NAME;}
[ \t\n] {}
%%


