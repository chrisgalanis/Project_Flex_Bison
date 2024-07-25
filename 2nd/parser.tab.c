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
  YYSYMBOL_SINGLE_MARK = 9,                /* SINGLE_MARK  */
  YYSYMBOL_COLON = 10,                     /* COLON  */
  YYSYMBOL_COMMA = 11,                     /* COMMA  */
  YYSYMBOL_DOT = 12,                       /* DOT  */
  YYSYMBOL_PLUS = 13,                      /* PLUS  */
  YYSYMBOL_MINUS = 14,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 15,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 16,                    /* DIVIDE  */
  YYSYMBOL_PUBLIC = 17,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 18,                   /* PRIVATE  */
  YYSYMBOL_CLASS = 19,                     /* CLASS  */
  YYSYMBOL_CLASS_NAME = 20,                /* CLASS_NAME  */
  YYSYMBOL_NEW = 21,                       /* NEW  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_ELSE = 23,                      /* ELSE  */
  YYSYMBOL_FOR = 24,                       /* FOR  */
  YYSYMBOL_DO = 25,                        /* DO  */
  YYSYMBOL_WHILE = 26,                     /* WHILE  */
  YYSYMBOL_CONDITION_SYMBOL = 27,          /* CONDITION_SYMBOL  */
  YYSYMBOL_BOOL_SYMBOL = 28,               /* BOOL_SYMBOL  */
  YYSYMBOL_INCREAMENT_DECREAMENT = 29,     /* INCREAMENT_DECREAMENT  */
  YYSYMBOL_LOOP_STEP = 30,                 /* LOOP_STEP  */
  YYSYMBOL_SWITCH = 31,                    /* SWITCH  */
  YYSYMBOL_CASE = 32,                      /* CASE  */
  YYSYMBOL_DEFAULT = 33,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 34,                     /* BREAK  */
  YYSYMBOL_RETURN = 35,                    /* RETURN  */
  YYSYMBOL_VAR_NAME = 36,                  /* VAR_NAME  */
  YYSYMBOL_VOID = 37,                      /* VOID  */
  YYSYMBOL_INT = 38,                       /* INT  */
  YYSYMBOL_CHAR = 39,                      /* CHAR  */
  YYSYMBOL_DOUBLE = 40,                    /* DOUBLE  */
  YYSYMBOL_BOOLEAN = 41,                   /* BOOLEAN  */
  YYSYMBOL_STRING = 42,                    /* STRING  */
  YYSYMBOL_INT_VALUE = 43,                 /* INT_VALUE  */
  YYSYMBOL_CHAR_VALUE = 44,                /* CHAR_VALUE  */
  YYSYMBOL_DOUBLE_VALUE = 45,              /* DOUBLE_VALUE  */
  YYSYMBOL_BOOLEAN_VALUE = 46,             /* BOOLEAN_VALUE  */
  YYSYMBOL_STRING_VALUE = 47,              /* STRING_VALUE  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_class_identifier = 50,          /* class_identifier  */
  YYSYMBOL_class_body = 51,                /* class_body  */
  YYSYMBOL_class_members = 52,             /* class_members  */
  YYSYMBOL_variable_initialization = 53,   /* variable_initialization  */
  YYSYMBOL_next_int = 54,                  /* next_int  */
  YYSYMBOL_next_double = 55,               /* next_double  */
  YYSYMBOL_next_char = 56,                 /* next_char  */
  YYSYMBOL_next_bool = 57,                 /* next_bool  */
  YYSYMBOL_next_string = 58,               /* next_string  */
  YYSYMBOL_int_init = 59,                  /* int_init  */
  YYSYMBOL_doulbe_init = 60,               /* doulbe_init  */
  YYSYMBOL_char_init = 61,                 /* char_init  */
  YYSYMBOL_bool_init = 62,                 /* bool_init  */
  YYSYMBOL_string_init = 63,               /* string_init  */
  YYSYMBOL_variable_assignment = 64,       /* variable_assignment  */
  YYSYMBOL_65_1 = 65,                      /* $@1  */
  YYSYMBOL_expression = 66,                /* expression  */
  YYSYMBOL_term = 67,                      /* term  */
  YYSYMBOL_id = 68,                        /* id  */
  YYSYMBOL_visibility = 69,                /* visibility  */
  YYSYMBOL_variable_value = 70,            /* variable_value  */
  YYSYMBOL_variable_type = 71,             /* variable_type  */
  YYSYMBOL_class_instance = 72,            /* class_instance  */
  YYSYMBOL_member_access = 73,             /* member_access  */
  YYSYMBOL_functions = 74,                 /* functions  */
  YYSYMBOL_function_visibility = 75,       /* function_visibility  */
  YYSYMBOL_arguments = 76,                 /* arguments  */
  YYSYMBOL_parameters = 77,                /* parameters  */
  YYSYMBOL_arguments_end = 78,             /* arguments_end  */
  YYSYMBOL_inside_void_function = 79,      /* inside_void_function  */
  YYSYMBOL_inside_function = 80,           /* inside_function  */
  YYSYMBOL_inside_brackets = 81,           /* inside_brackets  */
  YYSYMBOL_loops_n_condition = 82,         /* loops_n_condition  */
  YYSYMBOL_for_statement = 83,             /* for_statement  */
  YYSYMBOL_for_condition = 84,             /* for_condition  */
  YYSYMBOL_for_variable = 85,              /* for_variable  */
  YYSYMBOL_for_comparison = 86,            /* for_comparison  */
  YYSYMBOL_comparison_value = 87,          /* comparison_value  */
  YYSYMBOL_for_bool_operator = 88,         /* for_bool_operator  */
  YYSYMBOL_for_step = 89,                  /* for_step  */
  YYSYMBOL_step = 90,                      /* step  */
  YYSYMBOL_step_value = 91,                /* step_value  */
  YYSYMBOL_do_while = 92,                  /* do_while  */
  YYSYMBOL_do_condition = 93,              /* do_condition  */
  YYSYMBOL_do_bool_operator = 94,          /* do_bool_operator  */
  YYSYMBOL_operand = 95,                   /* operand  */
  YYSYMBOL_switch = 96,                    /* switch  */
  YYSYMBOL_case = 97,                      /* case  */
  YYSYMBOL_switch_value = 98,              /* switch_value  */
  YYSYMBOL_switch_content = 99,            /* switch_content  */
  YYSYMBOL_default = 100,                  /* default  */
  YYSYMBOL_if = 101,                       /* if  */
  YYSYMBOL_else_if = 102,                  /* else_if  */
  YYSYMBOL_else = 103,                     /* else  */
  YYSYMBOL_if_condition = 104,             /* if_condition  */
  YYSYMBOL_if_bool_operator = 105          /* if_bool_operator  */
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
#define YYLAST   312

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  268

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    86,    86,    86,    89,    93,    93,    94,    95,    97,
      97,    97,   104,   105,   106,   107,   108,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   116,   116,   117,
     117,   118,   118,   119,   119,   120,   120,   122,   122,   123,
     123,   123,   123,   124,   124,   124,   124,   125,   125,   125,
     128,   128,   128,   129,   129,   129,   129,   129,   130,   131,
     132,   133,   134,   136,   137,   140,   141,   142,   142,   144,
     144,   145,   146,   146,   148,   148,   149,   149,   152,   152,
     152,   156,   156,   156,   156,   156,   156,   156,   156,   159,
     160,   162,   162,   164,   164,   165,   165,   165,   165,   165,
     166,   166,   168,   168,   169,   169,   170,   170,   174,   175,
     175,   175,   176,   176,   177,   177,   177,   177,   177,   182,
     183,   184,   186,   186,   187,   187,   189,   190,   195,   196,
     196,   196,   197,   198,   198,   198,   199,   199
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
  "SEMICOLON", "SINGLE_MARK", "COLON", "COMMA", "DOT", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "PUBLIC", "PRIVATE", "CLASS", "CLASS_NAME", "NEW",
  "IF", "ELSE", "FOR", "DO", "WHILE", "CONDITION_SYMBOL", "BOOL_SYMBOL",
  "INCREAMENT_DECREAMENT", "LOOP_STEP", "SWITCH", "CASE", "DEFAULT",
  "BREAK", "RETURN", "VAR_NAME", "VOID", "INT", "CHAR", "DOUBLE",
  "BOOLEAN", "STRING", "INT_VALUE", "CHAR_VALUE", "DOUBLE_VALUE",
  "BOOLEAN_VALUE", "STRING_VALUE", "$accept", "program",
  "class_identifier", "class_body", "class_members",
  "variable_initialization", "next_int", "next_double", "next_char",
  "next_bool", "next_string", "int_init", "doulbe_init", "char_init",
  "bool_init", "string_init", "variable_assignment", "$@1", "expression",
  "term", "id", "visibility", "variable_value", "variable_type",
  "class_instance", "member_access", "functions", "function_visibility",
  "arguments", "parameters", "arguments_end", "inside_void_function",
  "inside_function", "inside_brackets", "loops_n_condition",
  "for_statement", "for_condition", "for_variable", "for_comparison",
  "comparison_value", "for_bool_operator", "for_step", "step",
  "step_value", "do_while", "do_condition", "do_bool_operator", "operand",
  "switch", "case", "switch_value", "switch_content", "default", "if",
  "else_if", "else", "if_condition", "if_bool_operator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-197)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-136)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,     0,    24,    16,    38,  -197,  -197,    25,     4,   -12,
      28,    49,     4,    71,     4,    74,   111,    76,     4,   106,
      50,   108,  -197,  -197,  -197,  -197,    81,    83,    84,    94,
      96,   130,  -197,  -197,   100,  -197,  -197,  -197,  -197,  -197,
     104,  -197,     1,   152,   154,   159,   156,   161,   158,   163,
     160,   165,   162,  -197,   169,   170,     1,  -197,  -197,  -197,
    -197,  -197,  -197,    41,    52,  -197,  -197,   133,    81,  -197,
     134,    83,  -197,   132,    84,  -197,   135,    94,  -197,   136,
      96,  -197,   116,   116,   128,    11,   173,     6,     6,    26,
      26,  -197,   154,  -197,   156,  -197,   158,  -197,   160,  -197,
     162,   144,   176,  -197,   178,  -197,  -197,  -197,     6,    52,
      52,    26,  -197,  -197,  -197,  -197,  -197,  -197,  -197,   174,
     183,   184,    11,   173,   116,  -197,    54,    54,  -197,   153,
     185,   186,   189,   188,   180,   187,   190,   191,   192,   166,
      54,  -197,  -197,  -197,  -197,   193,   167,   196,    61,   116,
      54,   164,  -197,     8,  -197,  -197,  -197,   197,  -197,  -197,
      55,   194,   198,  -197,  -197,  -197,   200,   181,   201,   175,
     203,   202,   208,   207,  -197,   206,   209,   199,    67,   213,
     211,   217,   195,   168,   218,  -197,  -197,   219,  -197,  -197,
     204,    54,   117,    54,   210,   214,   220,   212,   221,    61,
    -197,   222,  -197,   224,    78,   205,    82,    45,   215,  -197,
    -197,   216,  -197,  -197,  -197,  -197,  -197,  -197,   223,    79,
    -197,   225,   226,   227,   228,  -197,  -197,   230,   232,   231,
       7,  -197,  -197,   195,  -197,  -197,   -11,  -197,   235,    67,
     229,   229,  -197,    54,   233,  -197,  -197,  -197,  -197,  -197,
     234,   237,   212,  -197,   242,    61,    82,  -197,  -197,  -197,
    -197,   241,  -197,   246,    54,   250,   216,  -197
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     2,     0,     1,     3,     0,    52,    50,
      51,    37,    52,     0,    52,     0,     0,     0,    52,     0,
       0,     0,     8,     4,     7,    10,     0,     0,     0,     0,
       0,     0,    11,     6,     0,    58,    60,    59,    61,    62,
       0,    64,     0,    27,    17,    31,    21,    29,    19,    33,
      23,    35,    25,     9,     0,     0,     0,    48,    53,    54,
      55,    56,    57,    38,    42,    46,    47,     0,     0,    12,
       0,     0,    14,     0,     0,    13,     0,     0,    15,     0,
       0,    16,    69,    69,     0,    42,    46,     0,     0,     0,
       0,    28,    17,    32,    21,    30,    19,    34,    23,    36,
      25,     0,     0,    70,     0,    41,    45,    49,     0,    39,
      40,     0,    43,    44,    18,    22,    20,    24,    26,    72,
       0,     0,     0,     0,     0,    71,    78,    78,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      78,    81,    83,    82,    84,     0,     0,     0,     0,    91,
      78,     0,    85,    86,    87,    88,    65,     0,    79,    66,
       0,     0,   114,   115,   117,   116,   118,     0,     0,     0,
       0,     0,     0,     0,    75,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,    76,    77,     0,   114,   118,
     136,    78,     0,    78,     0,     0,     0,   121,     0,     0,
     133,     0,    92,     0,     0,   102,     0,     0,   127,    63,
     137,   129,    89,    99,    95,    97,    96,    98,   100,     0,
      90,   111,   110,     0,     0,   122,   123,     0,     0,     0,
       0,   128,   131,    93,    94,   104,     0,   103,     0,     0,
     124,   124,   119,    78,     0,   101,   106,   107,   105,   108,
     112,     0,   121,   126,     0,     0,     0,   109,   125,   120,
     132,     0,   113,     0,    78,     0,   129,   130
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -197,   247,    15,     2,  -197,   240,   131,   138,   142,   171,
     129,   236,   238,   239,   182,   150,    69,  -197,   243,   -52,
     -51,  -197,  -151,   -18,  -197,   121,  -197,  -197,   177,   137,
    -197,  -197,  -197,  -127,  -197,  -197,  -197,  -197,    31,  -197,
    -197,  -197,  -197,  -197,  -197,     9,  -197,  -176,  -197,     5,
    -197,    17,  -197,  -197,    10,  -197,  -196,  -197
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,    12,    13,    14,   134,    69,    75,    72,    78,
      81,    44,    48,    46,    50,    52,   135,    21,    63,    64,
      65,    16,    66,   101,   136,   137,    18,    19,   102,   103,
     125,   138,   145,   139,   140,   141,   170,   171,   195,   218,
     234,   220,   237,   248,   142,   223,   257,   167,   143,   208,
     227,   252,   229,   144,   231,   232,   168,   200
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     146,    40,   190,   210,    85,    86,    56,     4,    -5,   176,
     243,   108,   -80,   158,    22,     3,    24,   106,     3,     4,
      33,     9,    10,   172,     5,   -68,    89,    90,     8,   244,
     224,   111,   246,     1,   247,   109,   110,    57,   112,   113,
      11,   202,    57,   -80,    58,    59,    60,    61,    62,    58,
      59,    60,    61,    62,    87,    88,   122,    86,     7,   261,
     123,    20,    57,   250,   201,   -67,   203,    89,    90,    58,
      59,    60,    61,    62,   129,    23,   130,    15,   131,   132,
     224,    15,    25,    15,    32,   133,    41,    15,   225,   226,
      11,   175,    26,    27,    28,    29,    30,   162,    58,    59,
      60,    61,    62,   188,   163,   164,   165,   166,   235,   236,
     163,   164,   165,   189,   213,    42,   254,    43,   221,    45,
      47,   214,   215,   216,   217,   163,   164,   165,   222,    17,
      49,   169,    51,    17,   105,    17,    54,   265,    53,    17,
      55,    87,    88,    34,    35,    36,    37,    38,    39,    26,
      27,    28,    29,    30,    35,    36,    37,    38,    39,    67,
      58,    59,    60,    61,    62,    68,    70,    71,    73,    74,
      76,    77,    79,    80,    82,    83,    91,    95,    93,   107,
     119,    97,   120,    99,   121,   124,   126,   127,   152,   147,
     148,   149,   150,   151,   196,   153,   156,   159,   154,   155,
     173,   157,   160,   161,  -135,   174,  -134,   179,   178,   181,
     182,   180,   183,   184,   185,   177,   191,   186,   192,   187,
     193,   197,   205,   114,   198,   206,   211,   209,   212,   118,
     100,   194,   199,   238,   116,   242,   115,   204,   255,   230,
     240,   219,   241,   249,   207,   258,   260,   263,   228,   264,
       6,   233,  -114,  -118,   266,   239,    31,   259,   253,    98,
     104,   128,   256,   251,   245,   262,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,   267,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,    92,     0,     0,     0,     0,     0,
      94,     0,    96
};

static const yytype_int16 yycheck[] =
{
     127,    19,   178,   199,    56,    56,     5,    19,     4,   160,
       3,     5,     4,   140,    12,     0,    14,     6,     3,    19,
      18,    17,    18,   150,     0,    37,    15,    16,     3,    22,
     206,     5,    43,    17,    45,    87,    88,    36,    89,    90,
      36,   192,    36,    35,    43,    44,    45,    46,    47,    43,
      44,    45,    46,    47,    13,    14,   108,   108,    20,   255,
     111,    12,    36,   239,   191,    37,   193,    15,    16,    43,
      44,    45,    46,    47,    20,     4,    22,     8,    24,    25,
     256,    12,     8,    14,     8,    31,    36,    18,    43,    44,
      36,    36,    38,    39,    40,    41,    42,    36,    43,    44,
      45,    46,    47,    36,    43,    44,    45,    46,    29,    30,
      43,    44,    45,    46,    36,     7,   243,    36,    36,    36,
      36,    43,    44,    45,    46,    43,    44,    45,    46,     8,
      36,   149,    36,    12,     6,    14,    36,   264,     8,    18,
      36,    13,    14,    37,    38,    39,    40,    41,    42,    38,
      39,    40,    41,    42,    38,    39,    40,    41,    42,     7,
      43,    44,    45,    46,    47,    11,     7,    11,     7,    11,
       7,    11,     7,    11,     5,     5,    43,    45,    44,     6,
      36,    46,     6,    47,     6,    11,     3,     3,     8,    36,
       5,     5,     3,     5,    26,     8,     4,     4,     8,     8,
      36,    35,    35,     7,     6,     8,     6,     6,    27,     6,
       8,    36,     4,     6,     8,    21,     3,     8,     7,    20,
       3,     3,     8,    92,     5,     5,     4,     6,     4,   100,
      80,    36,    28,     6,    96,     4,    94,    27,     5,    23,
      10,    36,    10,     8,    32,     8,     4,     6,    33,     3,
       3,    28,    27,    27,     4,    27,    16,   252,   241,    77,
      83,   124,    28,    34,   233,   256,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    74
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    17,    49,    50,    19,     0,    49,    20,     3,    17,
      18,    36,    50,    51,    52,    64,    69,    73,    74,    75,
      12,    65,    51,     4,    51,     8,    38,    39,    40,    41,
      42,    53,     8,    51,    37,    38,    39,    40,    41,    42,
      71,    36,     7,    36,    59,    36,    61,    36,    60,    36,
      62,    36,    63,     8,    36,    36,     5,    36,    43,    44,
      45,    46,    47,    66,    67,    68,    70,     7,    11,    54,
       7,    11,    56,     7,    11,    55,     7,    11,    57,     7,
      11,    58,     5,     5,    66,    67,    68,    13,    14,    15,
      16,    43,    59,    44,    61,    45,    60,    46,    62,    47,
      63,    71,    76,    77,    76,     6,     6,     6,     5,    67,
      67,     5,    68,    68,    54,    56,    55,    57,    58,    36,
       6,     6,    67,    68,    11,    78,     3,     3,    77,    20,
      22,    24,    25,    31,    53,    64,    72,    73,    79,    81,
      82,    83,    92,    96,   101,    80,    81,    36,     5,     5,
       3,     5,     8,     8,     8,     8,     4,    35,    81,     4,
      35,     7,    36,    43,    44,    45,    46,    95,   104,    71,
      84,    85,    81,    36,     8,    36,    70,    21,    27,     6,
      36,     6,     8,     4,     6,     8,     8,    20,    36,    46,
      95,     3,     7,     3,    36,    86,    26,     3,     5,    28,
     105,    81,    70,    81,    27,     8,     5,    32,    97,     6,
     104,     4,     4,    36,    43,    44,    45,    46,    87,    36,
      89,    36,    46,    93,    95,    43,    44,    98,    33,   100,
      23,   102,   103,    28,    88,    29,    30,    90,     6,    27,
      10,    10,     4,     3,    22,    86,    43,    45,    91,     8,
      95,    34,    99,    99,    81,     5,    28,    94,     8,    97,
       4,   104,    93,     6,     3,    81,     4,   102
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    50,    51,    51,    51,    51,    52,
      52,    52,    53,    53,    53,    53,    53,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    62,    62,    63,    63,    65,    64,    66,
      66,    66,    66,    67,    67,    67,    67,    68,    68,    68,
      69,    69,    69,    70,    70,    70,    70,    70,    71,    71,
      71,    71,    71,    72,    73,    74,    74,    75,    75,    76,
      76,    77,    78,    78,    79,    79,    80,    80,    81,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    83,
      84,    85,    85,    86,    86,    87,    87,    87,    87,    87,
      88,    88,    89,    89,    90,    90,    91,    91,    92,    93,
      93,    93,    94,    94,    95,    95,    95,    95,    95,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   102,
     102,   102,   103,   104,   104,   104,   105,   105
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     6,     0,     2,     2,     2,     3,
       2,     2,     3,     3,     3,     3,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     0,     4,     3,
       3,     3,     1,     3,     3,     3,     1,     1,     1,     3,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     7,     3,     9,     9,     1,     1,     0,
       1,     3,     0,     2,     1,     3,     4,     4,     0,     2,
       2,     1,     1,     1,     1,     2,     2,     2,     2,     7,
       5,     0,     4,     0,     4,     1,     1,     1,     1,     1,
       0,     2,     0,     2,     1,     2,     1,     1,     9,     4,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     8,
       5,     0,     1,     1,     0,     2,     3,     0,     8,     0,
       9,     1,     4,     4,     1,     1,     0,     2
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
#line 89 "parser.y"
                                                                                            {printf("\nClass is identified\n");}
#line 1372 "parser.tab.c"
    break;

  case 28: /* int_init: VAR_NAME EQUAL_SIGN INT_VALUE  */
#line 116 "parser.y"
                                                      {printf("int %s = %d",(yyvsp[-2].sval),(yyvsp[0].ival));}
#line 1378 "parser.tab.c"
    break;

  case 30: /* doulbe_init: VAR_NAME EQUAL_SIGN DOUBLE_VALUE  */
#line 117 "parser.y"
                                                         {printf("double %s = %f",(yyvsp[-2].sval),(yyvsp[0].dval));}
#line 1384 "parser.tab.c"
    break;

  case 32: /* char_init: VAR_NAME EQUAL_SIGN CHAR_VALUE  */
#line 118 "parser.y"
                                                       {printf("char %s = '%c'",(yyvsp[-2].sval),(yyvsp[0].cval));}
#line 1390 "parser.tab.c"
    break;

  case 34: /* bool_init: VAR_NAME EQUAL_SIGN BOOLEAN_VALUE  */
#line 119 "parser.y"
                                                          {printf("bool %s = %s",(yyvsp[-2].sval),(yyvsp[0].sval));}
#line 1396 "parser.tab.c"
    break;

  case 36: /* string_init: VAR_NAME EQUAL_SIGN STRING_VALUE  */
#line 120 "parser.y"
                                                         {printf("char* %s = %s",(yyvsp[-2].sval),(yyvsp[0].sval));}
#line 1402 "parser.tab.c"
    break;

  case 37: /* $@1: %empty  */
#line 122 "parser.y"
                               {printf("init");}
#line 1408 "parser.tab.c"
    break;

  case 66: /* functions: function_visibility variable_type VAR_NAME BRACKET_LEFT arguments BRACKET_RIGHT CURLY_BRACKET_LEFT inside_function CURLY_BRACKET_RIGHT  */
#line 141 "parser.y"
                                                                                                                                                   {printf("\n Function is identified\n");}
#line 1414 "parser.tab.c"
    break;

  case 89: /* for_statement: FOR BRACKET_LEFT for_condition BRACKET_RIGHT CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT  */
#line 159 "parser.y"
                                                                                                                     {printf("\n For is identified\n");}
#line 1420 "parser.tab.c"
    break;

  case 108: /* do_while: DO CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT WHILE BRACKET_LEFT do_condition BRACKET_RIGHT SEMICOLON  */
#line 174 "parser.y"
                                                                                                                             {printf("\n Do While is identified\n");}
#line 1426 "parser.tab.c"
    break;

  case 119: /* switch: SWITCH BRACKET_LEFT VAR_NAME BRACKET_RIGHT CURLY_BRACKET_LEFT case default CURLY_BRACKET_RIGHT  */
#line 182 "parser.y"
                                                                                                       {printf("\n Switch\n");}
#line 1432 "parser.tab.c"
    break;

  case 128: /* if: IF BRACKET_LEFT if_condition BRACKET_RIGHT CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT else_if  */
#line 195 "parser.y"
                                                                                                             {printf("\n If is identified\n");}
#line 1438 "parser.tab.c"
    break;

  case 130: /* else_if: ELSE IF BRACKET_LEFT if_condition BRACKET_RIGHT CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT else_if  */
#line 196 "parser.y"
                                                                                                                                  {printf("else if \n");}
#line 1444 "parser.tab.c"
    break;

  case 131: /* else_if: else  */
#line 196 "parser.y"
                                                                                                                                                                 {printf("\n If is identified\n");}
#line 1450 "parser.tab.c"
    break;

  case 132: /* else: ELSE CURLY_BRACKET_LEFT inside_brackets CURLY_BRACKET_RIGHT  */
#line 197 "parser.y"
                                                                   {printf("\n Else is identified\n");}
#line 1456 "parser.tab.c"
    break;

  case 135: /* if_condition: VAR_NAME  */
#line 198 "parser.y"
                                                                                           {printf("\n If Condition is identified\n");}
#line 1462 "parser.tab.c"
    break;


#line 1466 "parser.tab.c"

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

#line 202 "parser.y"


int main(void)
{
    yyparse();
}

void yyerror(const char *s)
{
    printf("Error: %s\n",s);
}
