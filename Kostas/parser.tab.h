/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CURLY_BRACKET_LEFT = 258,      /* CURLY_BRACKET_LEFT  */
    CURLY_BRACKET_RIGHT = 259,     /* CURLY_BRACKET_RIGHT  */
    BRACKET_LEFT = 260,            /* BRACKET_LEFT  */
    BRACKET_RIGHT = 261,           /* BRACKET_RIGHT  */
    EQUAL_SIGN = 262,              /* EQUAL_SIGN  */
    SEMICOLON = 263,               /* SEMICOLON  */
    SINGLE_MARK = 264,             /* SINGLE_MARK  */
    COLON = 265,                   /* COLON  */
    COMMA = 266,                   /* COMMA  */
    DOT = 267,                     /* DOT  */
    PLUS = 268,                    /* PLUS  */
    MINUS = 269,                   /* MINUS  */
    MULTIPLY = 270,                /* MULTIPLY  */
    DIVIDE = 271,                  /* DIVIDE  */
    UMINUS = 272,                  /* UMINUS  */
    PUBLIC = 273,                  /* PUBLIC  */
    PRIVATE = 274,                 /* PRIVATE  */
    CLASS = 275,                   /* CLASS  */
    CLASS_NAME = 276,              /* CLASS_NAME  */
    NEW = 277,                     /* NEW  */
    IF = 278,                      /* IF  */
    ELSE = 279,                    /* ELSE  */
    FOR = 280,                     /* FOR  */
    DO = 281,                      /* DO  */
    WHILE = 282,                   /* WHILE  */
    CONDITION_SYMBOL = 283,        /* CONDITION_SYMBOL  */
    BOOL_SYMBOL = 284,             /* BOOL_SYMBOL  */
    INCREAMENT_DECREAMENT = 285,   /* INCREAMENT_DECREAMENT  */
    LOOP_STEP = 286,               /* LOOP_STEP  */
    SWITCH = 287,                  /* SWITCH  */
    CASE = 288,                    /* CASE  */
    DEFAULT = 289,                 /* DEFAULT  */
    BREAK = 290,                   /* BREAK  */
    RETURN = 291,                  /* RETURN  */
    IDENT = 292,                   /* IDENT  */
    VOID = 293,                    /* VOID  */
    INT = 294,                     /* INT  */
    CHAR = 295,                    /* CHAR  */
    DOUBLE = 296,                  /* DOUBLE  */
    BOOLEAN = 297,                 /* BOOLEAN  */
    STRING = 298,                  /* STRING  */
    INT_VALUE = 299,               /* INT_VALUE  */
    CHAR_VALUE = 300,              /* CHAR_VALUE  */
    DOUBLE_VALUE = 301,            /* DOUBLE_VALUE  */
    BOOLEAN_VALUE = 302,           /* BOOLEAN_VALUE  */
    STRING_VALUE = 303             /* STRING_VALUE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 449 "parser.y"

    int ival;
    char cval;
    double dval;
    char *sval;
    

#line 115 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
