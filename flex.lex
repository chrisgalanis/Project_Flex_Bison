%{
#include<stdio.h>
%}

INT "int"
CLASS "class"
VISSTATUS "public"
WHILELOOP "while"
%%
{VISSTATUS} {printf("VISSTATUS: %s\n", yytext);}
{CLASS} {printf("CLASS : %s\n", yytext);}
[a-z]+ {printf("NAME: %s\n", yytext);}
"{" {printf("CURLY BRAKET LEFT");}
"}" {printf("CURLY BRAKET RIGHT");}

{WHILELOOP} {printf("WHILELOOP: %s\n", yytext);}
"(" {printf("BRAKET LEFT");}
[A-Za-z0-9]+\?\!\<\>\=[A-Za-z0-9]+ {printf("CONDITION: %s\n", yytext);}
")" {printf("BRAKET RIGHT");}



{INT} {printf("DataType : %s\n",yytext);}
[0-9]+ {printf("%s\n", yytext);}
[a-z]+ {printf("%s\n", yytext);}
[ \t\n] {}
%%

int main(void)
{
    yylex();
}
