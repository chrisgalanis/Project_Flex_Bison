%{
#include<stdio.h>


%}


%%
[0-9]+ {printf("%s\n", yytext);}
[a-z]+ {printf("%s\n", yytext);}
[ \t\n] {}
%%

int main(void)
{
    yylex();
}