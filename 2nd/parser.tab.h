/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
    PUBLIC = 272,                  /* PUBLIC  */
    PRIVATE = 273,                 /* PRIVATE  */
    CLASS = 274,                   /* CLASS  */
    CLASS_NAME = 275,              /* CLASS_NAME  */
    NEW = 276,                     /* NEW  */
    IF = 277,                      /* IF  */
    ELSE = 278,                    /* ELSE  */
    FOR = 279,                     /* FOR  */
    DO = 280,                      /* DO  */
    WHILE = 281,                   /* WHILE  */
    CONDITION_SYMBOL = 282,        /* CONDITION_SYMBOL  */
    BOOL_SYMBOL = 283,             /* BOOL_SYMBOL  */
    INCREAMENT_DECREAMENT = 284,   /* INCREAMENT_DECREAMENT  */
    LOOP_STEP = 285,               /* LOOP_STEP  */
    SWITCH = 286,                  /* SWITCH  */
    CASE = 287,                    /* CASE  */
    DEFAULT = 288,                 /* DEFAULT  */
    BREAK = 289,                   /* BREAK  */
    RETURN = 290,                  /* RETURN  */
    VAR_NAME = 291,                /* VAR_NAME  */
    VOID = 292,                    /* VOID  */
    INT = 293,                     /* INT  */
    CHAR = 294,                    /* CHAR  */
    DOUBLE = 295,                  /* DOUBLE  */
    BOOLEAN = 296,                 /* BOOLEAN  */
    STRING = 297,                  /* STRING  */
    INT_VALUE = 298,               /* INT_VALUE  */
    CHAR_VALUE = 299,              /* CHAR_VALUE  */
    DOUBLE_VALUE = 300,            /* DOUBLE_VALUE  */
    BOOLEAN_VALUE = 301,           /* BOOLEAN_VALUE  */
    STRING_VALUE = 302             /* STRING_VALUE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "parser.y"

    int ival;
    char cval;
    double dval;
    char *sval;


#line 119 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
