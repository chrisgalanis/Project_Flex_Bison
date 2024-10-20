/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"


#include <stdio.h>

int yylex();
void yyerror(const char *s);


#line 80 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CURLY_BRACKET_LEFT = 3,         /* CURLY_BRACKET_LEFT  */
  YYSYMBOL_CURLY_BRACKET_RIGHT = 4,        /* CURLY_BRACKET_RIGHT  */
  YYSYMBOL_BRACKET_LEFT = 5,               /* BRACKET_LEFT  */
  YYSYMBOL_BRACKET_RIGHT = 6,              /* BRACKET_RIGHT  */
  YYSYMBOL_EQUAL_SIGN = 7,                 /* EQUAL_SIGN  */
  YYSYMBOL_SEMICOLON = 8,                  /* SEMICOLON  */
  YYSYMBOL_COLON = 9,                      /* COLON  */
  YYSYMBOL_COMMA = 10,                     /* COMMA  */
  YYSYMBOL_DOT = 11,                       /* DOT  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_MINUS = 13,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 14,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 15,                    /* DIVIDE  */
  YYSYMBOL_PUBLIC = 16,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 17,                   /* PRIVATE  */
  YYSYMBOL_CLASS = 18,                     /* CLASS  */
  YYSYMBOL_CLASS_NAME = 19,                /* CLASS_NAME  */
  YYSYMBOL_NEW = 20,                       /* NEW  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_DO = 24,                        /* DO  */
  YYSYMBOL_WHILE = 25,                     /* WHILE  */
  YYSYMBOL_CONDITION_SYMBOL = 26,          /* CONDITION_SYMBOL  */
  YYSYMBOL_BOOL_OP = 27,                   /* BOOL_OP  */
  YYSYMBOL_INCREAMENT_DECREAMENT = 28,     /* INCREAMENT_DECREAMENT  */
  YYSYMBOL_LOOP_STEP = 29,                 /* LOOP_STEP  */
  YYSYMBOL_SWITCH = 30,                    /* SWITCH  */
  YYSYMBOL_CASE = 31,                      /* CASE  */
  YYSYMBOL_DEFAULT = 32,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 33,                     /* BREAK  */
  YYSYMBOL_RETURN = 34,                    /* RETURN  */
  YYSYMBOL_IDENT = 35,                     /* IDENT  */
  YYSYMBOL_VOID = 36,                      /* VOID  */
  YYSYMBOL_INT = 37,                       /* INT  */
  YYSYMBOL_CHAR = 38,                      /* CHAR  */
  YYSYMBOL_DOUBLE = 39,                    /* DOUBLE  */
  YYSYMBOL_BOOLEAN = 40,                   /* BOOLEAN  */
  YYSYMBOL_STRING = 41,                    /* STRING  */
  YYSYMBOL_INT_VALUE = 42,                 /* INT_VALUE  */
  YYSYMBOL_CHAR_VALUE = 43,                /* CHAR_VALUE  */
  YYSYMBOL_DOUBLE_VALUE = 44,              /* DOUBLE_VALUE  */
  YYSYMBOL_BOOLEAN_VALUE = 45,             /* BOOLEAN_VALUE  */
  YYSYMBOL_STRING_VALUE = 46,              /* STRING_VALUE  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_class_identifier = 49,          /* class_identifier  */
  YYSYMBOL_class_body = 50,                /* class_body  */
  YYSYMBOL_class_members = 51,             /* class_members  */
  YYSYMBOL_VAR_NAME = 52,                  /* VAR_NAME  */
  YYSYMBOL_variable_initialization = 53,   /* variable_initialization  */
  YYSYMBOL_next_int = 54,                  /* next_int  */
  YYSYMBOL_next_double = 55,               /* next_double  */
  YYSYMBOL_next_char = 56,                 /* next_char  */
  YYSYMBOL_next_bool = 57,                 /* next_bool  */
  YYSYMBOL_next_string = 58,               /* next_string  */
  YYSYMBOL_int_init = 59,                  /* int_init  */
  YYSYMBOL_double_init = 60,               /* double_init  */
  YYSYMBOL_char_init = 61,                 /* char_init  */
  YYSYMBOL_bool_init = 62,                 /* bool_init  */
  YYSYMBOL_string_init = 63,               /* string_init  */
  YYSYMBOL_variable_assignment = 64,       /* variable_assignment  */
  YYSYMBOL_expression = 65,                /* expression  */
  YYSYMBOL_term = 66,                      /* term  */
  YYSYMBOL_par = 67,                       /* par  */
  YYSYMBOL_id = 68,                        /* id  */
  YYSYMBOL_visibility = 69,                /* visibility  */
  YYSYMBOL_variable_value = 70,            /* variable_value  */
  YYSYMBOL_variable_type = 71,             /* variable_type  */
  YYSYMBOL_class_instance = 72,            /* class_instance  */
  YYSYMBOL_member_access = 73,             /* member_access  */
  YYSYMBOL_parenthesis = 74,               /* parenthesis  */
  YYSYMBOL_functions = 75,                 /* functions  */
  YYSYMBOL_function_visibility = 76,       /* function_visibility  */
  YYSYMBOL_arguments = 77,                 /* arguments  */
  YYSYMBOL_parameters = 78,                /* parameters  */
  YYSYMBOL_arguments_end = 79,             /* arguments_end  */
  YYSYMBOL_inside_void_function = 80,      /* inside_void_function  */
  YYSYMBOL_inside_function = 81,           /* inside_function  */
  YYSYMBOL_inside_brackets = 82,           /* inside_brackets  */
  YYSYMBOL_loops_n_condition = 83,         /* loops_n_condition  */
  YYSYMBOL_for_statement = 84,             /* for_statement  */
  YYSYMBOL_for_condition = 85,             /* for_condition  */
  YYSYMBOL_for_variable = 86,              /* for_variable  */
  YYSYMBOL_for_comparison = 87,            /* for_comparison  */
  YYSYMBOL_comparison_value = 88,          /* comparison_value  */
  YYSYMBOL_for_bool_operator = 89,         /* for_bool_operator  */
  YYSYMBOL_for_step = 90,                  /* for_step  */
  YYSYMBOL_step = 91,                      /* step  */
  YYSYMBOL_step_value = 92,                /* step_value  */
  YYSYMBOL_do_while = 93,                  /* do_while  */
  YYSYMBOL_do_condition = 94,              /* do_condition  */
  YYSYMBOL_do_bool_operator = 95,          /* do_bool_operator  */
  YYSYMBOL_operand = 96,                   /* operand  */
  YYSYMBOL_switch = 97,                    /* switch  */
  YYSYMBOL_case = 98,                      /* case  */
  YYSYMBOL_switch_value = 99,              /* switch_value  */
  YYSYMBOL_switch_content = 100,           /* switch_content  */
  YYSYMBOL_default = 101,                  /* default  */
  YYSYMBOL_if = 102,                       /* if  */
  YYSYMBOL_else_if = 103,                  /* else_if  */
  YYSYMBOL_else = 104,                     /* else  */
  YYSYMBOL_if_condition = 105,             /* if_condition  */
  YYSYMBOL_if_bool_operator = 106          /* if_bool_operator  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   324

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  272

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    87,    87,    87,    90,    94,    94,    95,    96,    98,
      98,    98,    98,   100,   100,   122,   123,   124,   125,   126,
     128,   128,   129,   129,   130,   130,   131,   131,   132,   132,
     134,   135,   136,   137,   138,   141,   143,   143,   143,   144,
     144,   144,   145,   145,   146,   146,   146,   148,   148,   148,
     149,   149,   149,   149,   149,   150,   151,   152,   153,   154,
     156,   157,   158,   158,   160,   161,   162,   162,   164,   164,
     165,   166,   166,   168,   168,   169,   169,   172,   172,   172,
     176,   176,   176,   176,   176,   176,   176,   176,   179,   180,
     182,   182,   184,   184,   185,   185,   185,   185,   185,   186,
     186,   188,   188,   189,   189,   190,   190,   194,   195,   195,
     195,   196,   196,   197,   197,   197,   197,   197,   202,   203,
     204,   206,   206,   207,   207,   209,   210,   215,   216,   216,
     216,   217,   218,   218,   218,   219,   219
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CURLY_BRACKET_LEFT",
  "CURLY_BRACKET_RIGHT", "BRACKET_LEFT", "BRACKET_RIGHT", "EQUAL_SIGN",
  "SEMICOLON", "COLON", "COMMA", "DOT", "PLUS", "MINUS", "MULTIPLY",
  "DIVIDE", "PUBLIC", "PRIVATE", "CLASS", "CLASS_NAME", "NEW", "IF",
  "ELSE", "FOR", "DO", "WHILE", "CONDITION_SYMBOL", "BOOL_OP",
  "INCREAMENT_DECREAMENT", "LOOP_STEP", "SWITCH", "CASE", "DEFAULT",
  "BREAK", "RETURN", "IDENT", "VOID", "INT", "CHAR", "DOUBLE", "BOOLEAN",
  "STRING", "INT_VALUE", "CHAR_VALUE", "DOUBLE_VALUE", "BOOLEAN_VALUE",
  "STRING_VALUE", "$accept", "program", "class_identifier", "class_body",
  "class_members", "VAR_NAME", "variable_initialization", "next_int",
  "next_double", "next_char", "next_bool", "next_string", "int_init",
  "double_init", "char_init", "bool_init", "string_init",
  "variable_assignment", "expression", "term", "par", "id", "visibility",
  "variable_value", "variable_type", "class_instance", "member_access",
  "parenthesis", "functions", "function_visibility", "arguments",
  "parameters", "arguments_end", "inside_void_function", "inside_function",
  "inside_brackets", "loops_n_condition", "for_statement", "for_condition",
  "for_variable", "for_comparison", "comparison_value",
  "for_bool_operator", "for_step", "step", "step_value", "do_while",
  "do_condition", "do_bool_operator", "operand", "switch", "case",
  "switch_value", "switch_content", "default", "if", "else_if", "else",
  "if_condition", "if_bool_operator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-203)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-135)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,    -4,    20,    -7,     3,  -203,  -203,    26,     7,    -8,
      -5,   -16,  -203,     7,    35,     7,    29,    33,    71,    48,
      60,     7,   165,  -203,    36,  -203,  -203,  -203,     2,   -16,
    -203,  -203,  -203,    74,   170,  -203,  -203,  -203,   -16,  -203,
    -203,  -203,  -203,  -203,   -16,    56,     2,  -203,  -203,  -203,
    -203,  -203,  -203,    81,    82,  -203,  -203,  -203,   127,  -203,
     -16,   -16,   -16,   -16,   -16,   130,   143,   131,    66,   145,
       2,     2,     2,     2,   147,  -203,    84,   153,   157,   155,
     160,   171,   163,   174,   173,   182,   177,   177,   189,  -203,
    -203,    82,    82,  -203,  -203,  -203,   183,   -16,  -203,   169,
     -16,  -203,   151,   -16,  -203,   168,   -16,  -203,   181,   -16,
    -203,   -16,   213,  -203,   222,   223,  -203,   153,  -203,   155,
    -203,   171,  -203,   174,  -203,   182,   220,   228,   230,  -203,
    -203,  -203,  -203,  -203,  -203,   177,  -203,    50,   152,  -203,
     229,   231,   232,   233,   234,   235,   236,   237,   242,   203,
      50,  -203,  -203,  -203,  -203,   243,   205,    85,   177,    86,
     -16,  -203,     4,  -203,  -203,  -203,   244,  -203,  -203,    80,
    -203,  -203,  -203,   245,   247,   214,   248,   -16,   249,   250,
     246,   251,  -203,   252,   253,    98,   238,   255,   256,   -16,
     239,   260,  -203,  -203,  -203,  -203,   240,    86,   178,    86,
     254,   257,   261,   225,    85,  -203,   264,  -203,   265,   112,
     -16,   117,    69,   241,  -203,   259,  -203,  -203,  -203,  -203,
    -203,  -203,   258,    90,  -203,   262,   263,   266,   267,  -203,
    -203,   268,   269,   270,     9,  -203,  -203,   -16,  -203,  -203,
     -29,  -203,   271,    98,   272,   272,  -203,    86,   277,  -203,
    -203,  -203,  -203,  -203,   273,   275,   225,  -203,   280,    85,
     117,  -203,  -203,  -203,  -203,   281,  -203,   283,    86,   286,
     259,  -203
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     2,     0,     1,     3,     0,    49,    47,
      48,    14,    13,    49,     0,    49,     0,     0,    49,     0,
       0,    49,     0,    14,     0,     8,     4,     7,     0,     0,
      10,    47,    48,     0,     0,    12,    11,     6,     0,    55,
      57,    56,    58,    59,     0,     0,     0,    50,    51,    52,
      53,    54,    45,    35,    38,    41,    43,    44,    62,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
       0,     0,     0,     0,     0,    61,     0,    20,     0,    24,
       0,    22,     0,    26,     0,    28,    68,    68,     0,    42,
      46,    36,    37,    39,    40,    63,     0,     0,    15,     0,
       0,    17,     0,     0,    16,     0,     0,    18,     0,     0,
      19,     0,     0,    69,     0,     0,    30,    20,    32,    24,
      31,    22,    33,    26,    34,    28,    71,     0,     0,    60,
      21,    25,    23,    27,    29,     0,    70,    49,    49,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      49,    80,    82,    81,    83,     0,     0,     0,    90,    49,
       0,    84,    85,    86,    87,    64,     0,    78,    65,     0,
     114,   116,   115,   117,   113,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,     0,    92,
       0,     0,    75,    76,   117,   113,   135,    49,     0,    49,
       0,     0,     0,   120,     0,   132,     0,    91,     0,     0,
     101,     0,     0,   126,   136,   128,    88,    94,    96,    95,
      97,    98,    99,     0,    89,   109,   110,     0,     0,   121,
     122,     0,     0,     0,     0,   127,   130,    92,    93,   103,
       0,   102,     0,     0,   123,   123,   118,    49,     0,   100,
     105,   106,   104,   107,   111,     0,   120,   125,     0,     0,
       0,   108,   124,   119,   131,     0,   112,     0,    49,     0,
     128,   129
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -203,   288,    55,   176,  -203,   -11,   274,   154,   149,   156,
     172,   179,   197,   193,   198,   191,   167,    62,   276,    68,
      72,   278,    93,  -164,   -21,   164,   175,  -203,  -203,  -203,
     212,   166,  -203,  -203,  -203,  -134,  -203,  -203,  -203,  -203,
      65,  -203,  -203,  -203,  -203,  -203,  -203,    43,  -203,  -179,
    -203,    51,  -203,    61,  -203,  -203,    38,  -203,  -202,  -203
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,    13,    14,    15,    16,   144,    98,   104,   101,
     107,   110,    77,    81,    79,    83,    85,   145,    53,    54,
      55,    56,    34,    57,   111,   146,   147,    75,    21,    22,
     112,   113,   136,   148,   155,   149,   150,   151,   178,   179,
     201,   222,   238,   224,   241,   252,   152,   227,   261,   175,
     153,   213,   231,   256,   233,   154,   235,   236,   176,   205
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    44,   214,    23,   156,   184,   196,    46,   -79,     1,
       4,    -5,   247,   250,     4,   251,   167,    52,    58,    12,
       5,    23,     7,     9,    10,   180,    11,    65,   -67,     8,
     248,   -66,   228,    66,   207,    52,    28,    12,   -79,    26,
      29,    30,    12,    45,    47,    48,    49,    50,    51,    76,
      78,    80,    82,    84,   -77,     3,    35,   265,     3,    52,
      52,    52,    52,   206,   254,   208,    31,    32,    36,    11,
      17,   140,    89,   141,   142,    17,    67,    17,    70,    71,
     143,   228,    59,    17,   -77,    12,    76,    31,    32,    78,
     -77,    96,    80,    70,    71,    82,    72,    73,    84,    23,
     126,    18,    31,    32,    23,    11,    18,   140,    18,   141,
     142,   229,   230,   258,    18,    12,   143,    23,   239,   240,
      12,    12,    47,    48,    49,    50,    51,   170,   171,   172,
     173,    23,    74,    12,   269,    86,    23,   177,    91,    92,
     170,   171,   172,   194,    93,    94,   174,    12,    87,   181,
      88,    90,    12,    95,   217,   218,   219,   220,   183,   170,
     171,   172,   225,    97,    99,   100,   187,   102,    31,    32,
     105,    11,    19,   140,   195,   141,   142,    19,   200,    19,
     108,   103,   143,    20,   106,    19,   -77,    12,    20,    25,
      20,    27,   109,   174,   115,   120,    20,    37,   221,   223,
     226,    38,    39,    40,    41,    42,    43,    60,    61,    62,
      63,    64,   118,   122,    39,    40,    41,    42,    43,   127,
      47,    48,    49,    50,    51,   116,   200,   124,   128,   129,
     135,   137,   195,   138,   157,   159,   158,   166,   160,   169,
     185,   197,   161,   162,   163,   164,   165,   168,   174,   226,
     190,  -133,   182,  -134,   186,   188,   212,   191,   189,   199,
     192,   193,   198,   203,   202,   210,   211,   204,   215,   216,
     132,   130,   242,   232,   246,   131,   125,   244,   245,   253,
     209,   234,   259,   262,   264,   237,   268,   267,  -117,  -113,
     270,     6,    33,   243,   117,   133,   121,   123,   119,   114,
     260,   139,   249,   266,   134,   255,   257,   263,   271,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,     0,    69
};

static const yytype_int16 yycheck[] =
{
      11,    22,   204,    19,   138,   169,   185,     5,     4,    16,
      18,     4,     3,    42,    18,    44,   150,    28,    29,    35,
       0,    19,    19,    16,    17,   159,    19,    38,    36,     3,
      21,    36,   211,    44,   198,    46,     7,    35,    34,     4,
      11,     8,    35,     7,    42,    43,    44,    45,    46,    60,
      61,    62,    63,    64,     4,     0,     8,   259,     3,    70,
      71,    72,    73,   197,   243,   199,    16,    17,     8,    19,
       8,    21,     6,    23,    24,    13,    20,    15,    12,    13,
      30,   260,     8,    21,    34,    35,    97,    16,    17,   100,
       4,     7,   103,    12,    13,   106,    14,    15,   109,    19,
     111,     8,    16,    17,    19,    19,    13,    21,    15,    23,
      24,    42,    43,   247,    21,    35,    30,    19,    28,    29,
      35,    35,    42,    43,    44,    45,    46,    42,    43,    44,
      45,    19,     5,    35,   268,     5,    19,   158,    70,    71,
      42,    43,    44,    45,    72,    73,   157,    35,     5,   160,
      19,     6,    35,     6,    42,    43,    44,    45,   169,    42,
      43,    44,    45,    10,     7,    10,   177,     7,    16,    17,
       7,    19,     8,    21,   185,    23,    24,    13,   189,    15,
       7,    10,    30,     8,    10,    21,    34,    35,    13,    13,
      15,    15,    10,   204,     5,    44,    21,    21,   209,   210,
     211,    36,    37,    38,    39,    40,    41,    37,    38,    39,
      40,    41,    43,    45,    37,    38,    39,    40,    41,     6,
      42,    43,    44,    45,    46,    42,   237,    46,     6,     6,
      10,     3,   243,     3,     5,     3,     5,    34,     5,    34,
      26,     3,     8,     8,     8,     8,     4,     4,   259,   260,
       4,     6,     8,     6,     6,     6,    31,     6,     8,     3,
       8,     8,     7,     3,    25,     8,     5,    27,     4,     4,
     121,   117,     6,    32,     4,   119,   109,     9,     9,     8,
      26,    22,     5,     8,     4,    27,     3,     6,    26,    26,
       4,     3,    18,    26,    97,   123,   103,   106,   100,    87,
      27,   135,   237,   260,   125,    33,   245,   256,   270,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    48,    49,    18,     0,    48,    19,     3,    16,
      17,    19,    35,    49,    50,    51,    52,    64,    69,    72,
      73,    75,    76,    19,    52,    50,     4,    50,     7,    11,
       8,    16,    17,    53,    69,     8,     8,    50,    36,    37,
      38,    39,    40,    41,    71,     7,     5,    42,    43,    44,
      45,    46,    52,    65,    66,    67,    68,    70,    52,     8,
      37,    38,    39,    40,    41,    52,    52,    20,    65,    68,
      12,    13,    14,    15,     5,    74,    52,    59,    52,    61,
      52,    60,    52,    62,    52,    63,     5,     5,    19,     6,
       6,    66,    66,    67,    67,     6,     7,    10,    54,     7,
      10,    56,     7,    10,    55,     7,    10,    57,     7,    10,
      58,    71,    77,    78,    77,     5,    42,    59,    43,    61,
      44,    60,    45,    62,    46,    63,    52,     6,     6,     6,
      54,    56,    55,    57,    58,    10,    79,     3,     3,    78,
      21,    23,    24,    30,    53,    64,    72,    73,    80,    82,
      83,    84,    93,    97,   102,    81,    82,     5,     5,     3,
       5,     8,     8,     8,     8,     4,    34,    82,     4,    34,
      42,    43,    44,    45,    52,    96,   105,    71,    85,    86,
      82,    52,     8,    52,    70,    26,     6,    52,     6,     8,
       4,     6,     8,     8,    45,    52,    96,     3,     7,     3,
      52,    87,    25,     3,    27,   106,    82,    70,    82,    26,
       8,     5,    31,    98,   105,     4,     4,    42,    43,    44,
      45,    52,    88,    52,    90,    45,    52,    94,    96,    42,
      43,    99,    32,   101,    22,   103,   104,    27,    89,    28,
      29,    91,     6,    26,     9,     9,     4,     3,    21,    87,
      42,    44,    92,     8,    96,    33,   100,   100,    82,     5,
      27,    95,     8,    98,     4,   105,    94,     6,     3,    82,
       4,   103
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    49,    50,    50,    50,    50,    51,
      51,    51,    51,    52,    52,    53,    53,    53,    53,    53,
      54,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      59,    60,    61,    62,    63,    64,    65,    65,    65,    66,
      66,    66,    67,    67,    68,    68,    68,    69,    69,    69,
      70,    70,    70,    70,    70,    71,    71,    71,    71,    71,
      72,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    82,
      83,    83,    83,    83,    83,    83,    83,    83,    84,    85,
      86,    86,    87,    87,    88,    88,    88,    88,    88,    89,
      89,    90,    90,    91,    91,    92,    92,    93,    94,    94,
      94,    95,    95,    96,    96,    96,    96,    96,    97,    98,
      98,    99,    99,   100,   100,   101,   101,   102,   103,   103,
     103,   104,   105,   105,   105,   106,   106
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     6,     0,     2,     2,     2,     3,
       2,     2,     2,     1,     1,     4,     4,     4,     4,     4,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     1,     1,     3,     1,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       7,     4,     0,     2,     9,     9,     1,     1,     0,     1,
       3,     0,     2,     1,     3,     4,     4,     0,     2,     2,
       1,     1,     1,     1,     2,     2,     2,     2,     7,     5,
       0,     4,     0,     4,     1,     1,     1,     1,     1,     0,
       2,     0,     2,     1,     2,     1,     1,     9,     4,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     8,     5,
       0,     1,     1,     0,     2,     3,     0,     8,     0,     9,
       1,     4,     4,     1,     1,     0,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* class_identifier: PUBLIC CLASS CLASS_NAME CURLY_BRACKET_LEFT class_body CURLY_BRACKET_RIGHT  */
#line 90 "parser.y"
                                                                                            {printf("\nClass is identified\n");}
#line 1378 "parser.tab.c"
    break;

  case 65: /* functions: function_visibility variable_type VAR_NAME BRACKET_LEFT arguments BRACKET_RIGHT CURLY_BRACKET_LEFT inside_function CURLY_BRACKET_RIGHT  */
#line 161 "parser.y"
                                                                                                                                                   {printf("\n Function is identified\n");}
#line 1384 "parser.tab.c"
    break;

  case 88: /* for_statement: FOR BRACKET_LEFT for_condition BRACKET_RIGHT CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT  */
#line 179 "parser.y"
                                                                                                                     {printf("\n For is identified\n");}
#line 1390 "parser.tab.c"
    break;

  case 107: /* do_while: DO CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT WHILE BRACKET_LEFT do_condition BRACKET_RIGHT SEMICOLON  */
#line 194 "parser.y"
                                                                                                                             {printf("\n Do While is identified\n");}
#line 1396 "parser.tab.c"
    break;

  case 118: /* switch: SWITCH BRACKET_LEFT VAR_NAME BRACKET_RIGHT CURLY_BRACKET_LEFT case default CURLY_BRACKET_RIGHT  */
#line 202 "parser.y"
                                                                                                       {printf("\n Switch\n");}
#line 1402 "parser.tab.c"
    break;

  case 127: /* if: IF BRACKET_LEFT if_condition BRACKET_RIGHT CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT else_if  */
#line 215 "parser.y"
                                                                                                             {printf("\n If is identified\n");}
#line 1408 "parser.tab.c"
    break;

  case 129: /* else_if: ELSE IF BRACKET_LEFT if_condition BRACKET_RIGHT CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT else_if  */
#line 216 "parser.y"
                                                                                                                                  {printf("else if \n");}
#line 1414 "parser.tab.c"
    break;

  case 130: /* else_if: else  */
#line 216 "parser.y"
                                                                                                                                                                 {printf("\n If is identified\n");}
#line 1420 "parser.tab.c"
    break;

  case 131: /* else: ELSE CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT  */
#line 217 "parser.y"
                                                                   {printf("\n Else is identified\n");}
#line 1426 "parser.tab.c"
    break;

  case 134: /* if_condition: VAR_NAME  */
#line 218 "parser.y"
                                                                                           {printf("\n If Condition is identified\n");}
#line 1432 "parser.tab.c"
    break;


#line 1436 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 222 "parser.y"


int main(void)
{
    yyparse();
}

void yyerror(const char *s)
{
    printf("Error: %s\n",s);
}
