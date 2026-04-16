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
#line 1 "src/parser.y"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<../src/tree.h>
#include<../src/strtab.h>

extern int yylineno;
extern int yylex(void);

int yywarning(char *msg);
int yyerror(char *msg);


typedef struct treenode tree;
extern tree *ast;

/* nodeTypes refer to different types of internal and external nodes
  that can be part of the abstract syntax tree.
  */

/* NOTE: mC has two kinds of scopes for variables : local and global.
  Variables declared outside any function are considered globals,
    whereas variables (and parameters) declared inside a function foo
    are local to foo.
  You should update the scope variable whenever you are inside a production
    that matches function definition (funDecl production).
  The rationale is that you are entering that function, so all variables,
    arrays, and other functions should be within this scope.
  You should pass this variable whenever you are
    calling the ST_insert or ST_lookup functions.
  This variable should be updated to scope = ""
    to indicate global scope whenever funDecl finishes.
  Treat these hints as helpful directions only.
  You may implement all of the functions as you like
    and not adhere to my instructions.
  As long as the directory structure is correct and the file names are correct,
    we are okay with it.
  */
char* scope = "";

#line 113 "obj/y.tab.c"

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

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INTCONST = 4,                   /* INTCONST  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_CHAR = 10,                      /* CHAR  */
  YYSYMBOL_INT = 11,                       /* INT  */
  YYSYMBOL_LBRACE = 12,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 13,                    /* RBRACE  */
  YYSYMBOL_LPARENTHESIS = 14,              /* LPARENTHESIS  */
  YYSYMBOL_RPARENTHESIS = 15,              /* RPARENTHESIS  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_LBRACKET = 17,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 18,                  /* RBRACKET  */
  YYSYMBOL_PLUS = 19,                      /* PLUS  */
  YYSYMBOL_MINUS = 20,                     /* MINUS  */
  YYSYMBOL_DIVIDE = 21,                    /* DIVIDE  */
  YYSYMBOL_MULT = 22,                      /* MULT  */
  YYSYMBOL_SEMICOLON = 23,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 24,                     /* COMMA  */
  YYSYMBOL_LESSTHAN = 25,                  /* LESSTHAN  */
  YYSYMBOL_LESSTHANEQ = 26,                /* LESSTHANEQ  */
  YYSYMBOL_GREATERTHAN = 27,               /* GREATERTHAN  */
  YYSYMBOL_GREATERTHANEQ = 28,             /* GREATERTHANEQ  */
  YYSYMBOL_EQ = 29,                        /* EQ  */
  YYSYMBOL_NEQ = 30,                       /* NEQ  */
  YYSYMBOL_STRCONST = 31,                  /* STRCONST  */
  YYSYMBOL_CHARCONST = 32,                 /* CHARCONST  */
  YYSYMBOL_ERROR = 33,                     /* ERROR  */
  YYSYMBOL_ILLEGAL_TOK = 34,               /* ILLEGAL_TOK  */
  YYSYMBOL_OPER_AT = 35,                   /* OPER_AT  */
  YYSYMBOL_OPER_INC = 36,                  /* OPER_INC  */
  YYSYMBOL_OPER_DEC = 37,                  /* OPER_DEC  */
  YYSYMBOL_OPER_AND = 38,                  /* OPER_AND  */
  YYSYMBOL_OPER_OR = 39,                   /* OPER_OR  */
  YYSYMBOL_OPER_NOT = 40,                  /* OPER_NOT  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_declList = 43,                  /* declList  */
  YYSYMBOL_decl = 44,                      /* decl  */
  YYSYMBOL_funDecl = 45,                   /* funDecl  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_typeSpec = 47,                  /* typeSpec  */
  YYSYMBOL_varDecl = 48,                   /* varDecl  */
  YYSYMBOL_formalDeclListOpt = 49,         /* formalDeclListOpt  */
  YYSYMBOL_formalDeclList = 50,            /* formalDeclList  */
  YYSYMBOL_formalDecl = 51,                /* formalDecl  */
  YYSYMBOL_funBody = 52,                   /* funBody  */
  YYSYMBOL_localDeclListOpt = 53,          /* localDeclListOpt  */
  YYSYMBOL_localDeclList = 54,             /* localDeclList  */
  YYSYMBOL_statementListOpt = 55,          /* statementListOpt  */
  YYSYMBOL_statementList = 56,             /* statementList  */
  YYSYMBOL_statement = 57,                 /* statement  */
  YYSYMBOL_compoundStmt = 58,              /* compoundStmt  */
  YYSYMBOL_assignStmt = 59,                /* assignStmt  */
  YYSYMBOL_returnStmt = 60,                /* returnStmt  */
  YYSYMBOL_loopStmt = 61,                  /* loopStmt  */
  YYSYMBOL_condStmt = 62,                  /* condStmt  */
  YYSYMBOL_expression = 63,                /* expression  */
  YYSYMBOL_relop = 64,                     /* relop  */
  YYSYMBOL_addExpr = 65,                   /* addExpr  */
  YYSYMBOL_addop = 66,                     /* addop  */
  YYSYMBOL_term = 67,                      /* term  */
  YYSYMBOL_mulop = 68,                     /* mulop  */
  YYSYMBOL_factor = 69,                    /* factor  */
  YYSYMBOL_var = 70,                       /* var  */
  YYSYMBOL_funCallExpr = 71,               /* funCallExpr  */
  YYSYMBOL_argListOpt = 72,                /* argListOpt  */
  YYSYMBOL_argList = 73                    /* argList  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   93

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  108

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   103,   103,   112,   118,   129,   135,   148,   147,   171,
     176,   181,   189,   198,   212,   215,   221,   226,   234,   243,
     255,   263,   266,   273,   279,   286,   289,   295,   300,   309,
     311,   313,   315,   317,   395,   403,   408,   416,   420,   427,
     435,   441,   450,   455,   467,   471,   475,   479,   483,   487,
     493,   498,   507,   511,   517,   522,   532,   536,   542,   547,
     552,   557,   565,   574,   586,   599,   602,   608,   613
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INTCONST", "IF",
  "ELSE", "WHILE", "RETURN", "VOID", "CHAR", "INT", "LBRACE", "RBRACE",
  "LPARENTHESIS", "RPARENTHESIS", "ASSIGN", "LBRACKET", "RBRACKET", "PLUS",
  "MINUS", "DIVIDE", "MULT", "SEMICOLON", "COMMA", "LESSTHAN",
  "LESSTHANEQ", "GREATERTHAN", "GREATERTHANEQ", "EQ", "NEQ", "STRCONST",
  "CHARCONST", "ERROR", "ILLEGAL_TOK", "OPER_AT", "OPER_INC", "OPER_DEC",
  "OPER_AND", "OPER_OR", "OPER_NOT", "$accept", "program", "declList",
  "decl", "funDecl", "$@1", "typeSpec", "varDecl", "formalDeclListOpt",
  "formalDeclList", "formalDecl", "funBody", "localDeclListOpt",
  "localDeclList", "statementListOpt", "statementList", "statement",
  "compoundStmt", "assignStmt", "returnStmt", "loopStmt", "condStmt",
  "expression", "relop", "addExpr", "addop", "term", "mulop", "factor",
  "var", "funCallExpr", "argListOpt", "argList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      43,   -93,   -93,   -93,    17,    43,   -93,   -93,     9,   -93,
     -93,   -93,    -7,    18,   -93,    16,    21,    43,    25,    47,
      40,   -93,    32,   -93,    41,    48,    43,    44,    43,   -93,
     -93,   -93,    56,    43,    37,   -93,    -7,   -93,    12,   -93,
      49,    50,     1,    43,     1,    52,   -93,    37,   -93,    38,
      45,   -93,   -93,   -93,     8,     3,   -93,    53,   -93,     1,
       1,     1,     1,   -93,   -93,    37,    55,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,     1,
       1,   -93,   -93,     1,     1,   -93,    58,    51,    59,    61,
      63,    66,   -93,    27,     3,   -93,   -93,   -93,     1,   -93,
      37,    37,   -93,   -93,    65,   -93,    37,   -93
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,    10,     9,     0,     2,     3,     6,     0,     5,
       1,     4,     7,     0,    12,     0,     0,    14,     0,     0,
       0,    15,    16,    13,    18,     0,     0,     0,    21,     8,
      17,    19,     0,    24,    25,    22,     0,    23,    62,    58,
       0,     0,    37,    21,     0,     0,    26,    27,    29,     0,
       0,    32,    31,    36,    42,    50,    54,    59,    60,    65,
       0,     0,     0,    38,    59,    25,     0,    20,    28,    30,
      33,    52,    53,    44,    45,    46,    47,    48,    49,     0,
       0,    57,    56,     0,     0,    67,     0,    66,     0,     0,
       0,     0,    61,    43,    51,    55,    35,    64,     0,    63,
       0,     0,    34,    68,    40,    39,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,   -93,    69,   -93,   -93,     6,     2,   -93,    54,
     -93,   -93,    39,    57,    19,    34,   -92,   -93,   -93,   -93,
     -93,   -93,   -41,   -93,     4,   -93,     5,   -93,    10,   -34,
     -93,   -93,   -93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    15,    32,    33,    20,    21,
      22,    29,    34,    35,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    79,    54,    80,    55,    83,    56,    64,
      58,    86,    87
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      57,    63,     9,    66,    38,    39,     8,     9,   104,   105,
      13,     8,    12,    57,   107,    44,    14,    10,    85,    88,
      89,    90,    16,    19,    81,    82,    59,    71,    72,    60,
      17,    57,    19,    73,    74,    75,    76,    77,    78,    18,
      38,    39,    40,    96,    41,    42,    71,    72,    23,    43,
      24,    44,     1,     2,     3,    25,    26,   103,    27,    36,
      28,    69,    31,    61,    62,    67,    57,    57,    70,    84,
      92,   106,    57,    97,    11,    98,   100,    99,   101,   102,
      30,    68,    65,    93,    91,    94,     0,     0,     0,     0,
      37,     0,     0,    95
};

static const yytype_int8 yycheck[] =
{
      34,    42,     0,    44,     3,     4,     0,     5,   100,   101,
      17,     5,     3,    47,   106,    14,    23,     0,    59,    60,
      61,    62,     4,    17,    21,    22,    14,    19,    20,    17,
      14,    65,    26,    25,    26,    27,    28,    29,    30,    18,
       3,     4,     5,    84,     7,     8,    19,    20,    23,    12,
       3,    14,     9,    10,    11,    15,    24,    98,    17,     3,
      12,    23,    18,    14,    14,    13,   100,   101,    23,    16,
      15,     6,   106,    15,     5,    24,    15,    18,    15,    13,
      26,    47,    43,    79,    65,    80,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    83
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    11,    42,    43,    44,    45,    47,    48,
       0,    44,     3,    17,    23,    46,     4,    14,    18,    47,
      49,    50,    51,    23,     3,    15,    24,    17,    12,    52,
      50,    18,    47,    48,    53,    54,     3,    54,     3,     4,
       5,     7,     8,    12,    14,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    65,    67,    69,    70,    71,    14,
      17,    14,    14,    63,    70,    53,    63,    13,    56,    23,
      23,    19,    20,    25,    26,    27,    28,    29,    30,    64,
      66,    21,    22,    68,    16,    63,    72,    73,    63,    63,
      63,    55,    15,    65,    67,    69,    63,    15,    24,    18,
      15,    15,    13,    63,    57,    57,     6,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    46,    45,    47,
      47,    47,    48,    48,    49,    49,    50,    50,    51,    51,
      52,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    57,    57,    57,    58,    59,    59,    60,    60,    61,
      62,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      65,    65,    66,    66,    67,    67,    68,    68,    69,    69,
      69,    69,    70,    70,    71,    72,    72,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     0,     7,     1,
       1,     1,     3,     6,     0,     1,     1,     3,     2,     4,
       4,     0,     1,     2,     1,     0,     1,     1,     2,     1,
       2,     1,     1,     2,     4,     3,     1,     1,     2,     5,
       5,     7,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     1,     4,     4,     0,     1,     1,     3
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
  case 2: /* program: declList  */
#line 104 "src/parser.y"
                 {
                    tree *progNode = maketree(PROGRAM);
                    addChild(progNode, (yyvsp[0].node));
                    ast = progNode;
                    (yyval.node) = progNode;
                 }
#line 1251 "obj/y.tab.c"
    break;

  case 3: /* declList: decl  */
#line 113 "src/parser.y"
                 {
                    tree* declListNode = maketree(DECLLIST);
                    addChild(declListNode, (yyvsp[0].node));
                    (yyval.node) = declListNode;
                 }
#line 1261 "obj/y.tab.c"
    break;

  case 4: /* declList: declList decl  */
#line 119 "src/parser.y"
                 {
                    tree* declListNode = maketree(DECLLIST);
                    addChild(declListNode, (yyvsp[-1].node));
                    addChild(declListNode, (yyvsp[0].node));
                    (yyval.node) = declListNode;
                 }
#line 1272 "obj/y.tab.c"
    break;

  case 5: /* decl: varDecl  */
#line 130 "src/parser.y"
                 {
                  (yyval.node) = maketree(DECL);
                    // so $$ is now NULL, we can't dereference it
                  addChild((yyval.node),(yyvsp[0].node));
                 }
#line 1282 "obj/y.tab.c"
    break;

  case 6: /* decl: funDecl  */
#line 136 "src/parser.y"
                 {
                    // $1 is an INTCONST
                    // INTCONST defined above as a token with yylval.value
                    // the tree functions aren't implemented
                    // so $$ is now NULL, we can't dereference it
                    (yyval.node) = maketree(DECL);
                    addChild((yyval.node), (yyvsp[0].node));
                 }
#line 1295 "obj/y.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 148 "src/parser.y"
      {
        int funID = ST_insert((yyvsp[0].strval), "", (yyvsp[-1].node)->val, FUNCTION);
        (void)funID;
        scope = (yyvsp[0].strval);
      }
#line 1305 "obj/y.tab.c"
    break;

  case 8: /* funDecl: typeSpec ID $@1 LPARENTHESIS formalDeclListOpt RPARENTHESIS funBody  */
#line 154 "src/parser.y"
      {

        (yyval.node) = maketree(FUNDECL);

        tree *funcTypeNode = maketree(FUNCTYPENAME);
        addChild(funcTypeNode, (yyvsp[-6].node));
        addChild(funcTypeNode, maketreeWithName(IDENTIFIER, (yyvsp[-5].strval)));
        addChild((yyval.node), funcTypeNode);

        if ((yyvsp[-2].node)) addChild((yyval.node), (yyvsp[-2].node));
        if ((yyvsp[0].node)) addChild((yyval.node), (yyvsp[0].node));

        scope = "";
      }
#line 1324 "obj/y.tab.c"
    break;

  case 9: /* typeSpec: INT  */
#line 172 "src/parser.y"
      {
          (yyval.node) = maketreeWithName(TYPESPEC, "int");
          (yyval.node)->val = INT_TYPE;
      }
#line 1333 "obj/y.tab.c"
    break;

  case 10: /* typeSpec: CHAR  */
#line 177 "src/parser.y"
      {
          (yyval.node) = maketreeWithName(TYPESPEC, "char");
          (yyval.node)->val = CHAR_TYPE;
      }
#line 1342 "obj/y.tab.c"
    break;

  case 11: /* typeSpec: VOID  */
#line 182 "src/parser.y"
      {
          (yyval.node) = maketreeWithName(TYPESPEC, "void");
          (yyval.node)->val = VOID_TYPE;
      }
#line 1351 "obj/y.tab.c"
    break;

  case 12: /* varDecl: typeSpec ID SEMICOLON  */
#line 190 "src/parser.y"
      {
          int valID = ST_insert((yyvsp[-1].strval), scope, (yyvsp[-2].node)->val, SCALAR);
          (void)valID;

          (yyval.node) = maketree(VARDECL);
          addChild((yyval.node), (yyvsp[-2].node));
          addChild((yyval.node), maketreeWithName(IDENTIFIER, (yyvsp[-1].strval)));
      }
#line 1364 "obj/y.tab.c"
    break;

  case 13: /* varDecl: typeSpec ID LBRACKET INTCONST RBRACKET SEMICOLON  */
#line 199 "src/parser.y"
      {
          int valID = ST_insert((yyvsp[-4].strval), scope, (yyvsp[-5].node)->val, ARRAY);
          (void)valID;

          (yyval.node) = maketree(VARDECL);
          addChild((yyval.node), (yyvsp[-5].node));
          addChild((yyval.node), maketreeWithName(IDENTIFIER, (yyvsp[-4].strval)));
          addChild((yyval.node), maketreeWithVal(INTEGER, (yyvsp[-2].value)));
      }
#line 1378 "obj/y.tab.c"
    break;

  case 14: /* formalDeclListOpt: %empty  */
#line 212 "src/parser.y"
                {
                  (yyval.node) = NULL;
                }
#line 1386 "obj/y.tab.c"
    break;

  case 15: /* formalDeclListOpt: formalDeclList  */
#line 216 "src/parser.y"
                {
                  (yyval.node) = (yyvsp[0].node);
                }
#line 1394 "obj/y.tab.c"
    break;

  case 16: /* formalDeclList: formalDecl  */
#line 222 "src/parser.y"
                {
                  (yyval.node) = maketree(FORMALDECLLIST);
                  addChild((yyval.node), (yyvsp[0].node));
                }
#line 1403 "obj/y.tab.c"
    break;

  case 17: /* formalDeclList: formalDecl COMMA formalDeclList  */
#line 227 "src/parser.y"
                {
                  (yyval.node) = maketree(FORMALDECLLIST);
                  addChild((yyval.node), (yyvsp[-2].node));
                  addChild((yyval.node), (yyvsp[0].node));
                }
#line 1413 "obj/y.tab.c"
    break;

  case 18: /* formalDecl: typeSpec ID  */
#line 235 "src/parser.y"
      {
          int valID = ST_insert((yyvsp[0].strval), scope, (yyvsp[-1].node)->val, SCALAR);
          (void)valID;

          (yyval.node) = maketree(FORMALDECL);
          addChild((yyval.node), (yyvsp[-1].node));
          addChild((yyval.node), maketreeWithName(IDENTIFIER, (yyvsp[0].strval)));
      }
#line 1426 "obj/y.tab.c"
    break;

  case 19: /* formalDecl: typeSpec ID LBRACKET RBRACKET  */
#line 244 "src/parser.y"
      {
          int valID = ST_insert((yyvsp[-2].strval), scope, (yyvsp[-3].node)->val, ARRAY);
          (void)valID;

          (yyval.node) = maketree(FORMALDECL);
          addChild((yyval.node), (yyvsp[-3].node));
          addChild((yyval.node), maketreeWithName(IDENTIFIER, (yyvsp[-2].strval)));
          addChild((yyval.node), maketree(ARRAYDECL));
      }
#line 1440 "obj/y.tab.c"
    break;

  case 20: /* funBody: LBRACE localDeclListOpt statementListOpt RBRACE  */
#line 256 "src/parser.y"
{
  (yyval.node) = maketree(FUNBODY);
  addChild((yyval.node), (yyvsp[-2].node));
  addChild((yyval.node), (yyvsp[-1].node));
}
#line 1450 "obj/y.tab.c"
    break;

  case 21: /* localDeclListOpt: %empty  */
#line 263 "src/parser.y"
                {
                  (yyval.node) = NULL;
                }
#line 1458 "obj/y.tab.c"
    break;

  case 22: /* localDeclListOpt: localDeclList  */
#line 267 "src/parser.y"
                {
                  (yyval.node) = (yyvsp[0].node);
                }
#line 1466 "obj/y.tab.c"
    break;

  case 23: /* localDeclList: varDecl localDeclList  */
#line 274 "src/parser.y"
    {
        (yyval.node) = maketree(LOCALDECLLIST);
        addChild((yyval.node), (yyvsp[-1].node));  
        addChild((yyval.node), (yyvsp[0].node));  
    }
#line 1476 "obj/y.tab.c"
    break;

  case 24: /* localDeclList: varDecl  */
#line 280 "src/parser.y"
    {
        (yyval.node) = maketree(LOCALDECLLIST);
        addChild((yyval.node), (yyvsp[0].node));
    }
#line 1485 "obj/y.tab.c"
    break;

  case 25: /* statementListOpt: %empty  */
#line 286 "src/parser.y"
      {
          (yyval.node) = NULL;
      }
#line 1493 "obj/y.tab.c"
    break;

  case 26: /* statementListOpt: statementList  */
#line 290 "src/parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1501 "obj/y.tab.c"
    break;

  case 27: /* statementList: statement  */
#line 296 "src/parser.y"
      {
        (yyval.node) = maketree(STATEMENTLIST);
        addChild((yyval.node), (yyvsp[0].node));
      }
#line 1510 "obj/y.tab.c"
    break;

  case 28: /* statementList: statement statementList  */
#line 301 "src/parser.y"
      {
        (yyval.node) = maketree(STATEMENTLIST);
        addChild((yyval.node), (yyvsp[-1].node));
        addChild((yyval.node), (yyvsp[0].node));
      }
#line 1520 "obj/y.tab.c"
    break;

  case 29: /* statement: compoundStmt  */
#line 310 "src/parser.y"
      { (yyval.node) = maketree(STATEMENT); addChild((yyval.node), (yyvsp[0].node)); }
#line 1526 "obj/y.tab.c"
    break;

  case 30: /* statement: assignStmt SEMICOLON  */
#line 312 "src/parser.y"
      { (yyval.node) = maketree(STATEMENT); addChild((yyval.node), (yyvsp[-1].node)); }
#line 1532 "obj/y.tab.c"
    break;

  case 31: /* statement: condStmt  */
#line 314 "src/parser.y"
      { (yyval.node) = maketree(STATEMENT); addChild((yyval.node), (yyvsp[0].node)); }
#line 1538 "obj/y.tab.c"
    break;

  case 32: /* statement: loopStmt  */
#line 316 "src/parser.y"
      { (yyval.node) = maketree(STATEMENT); addChild((yyval.node), (yyvsp[0].node)); }
#line 1544 "obj/y.tab.c"
    break;

  case 33: /* statement: returnStmt SEMICOLON  */
#line 318 "src/parser.y"
      { (yyval.node) = maketree(STATEMENT); addChild((yyval.node), (yyvsp[-1].node)); }
#line 1550 "obj/y.tab.c"
    break;

  case 34: /* compoundStmt: LBRACE localDeclListOpt statementListOpt RBRACE  */
#line 396 "src/parser.y"
            {
              (yyval.node) = maketree(COMPOUNDSTMT);
              addChild((yyval.node), (yyvsp[-2].node));
              addChild((yyval.node), (yyvsp[-1].node));
            }
#line 1560 "obj/y.tab.c"
    break;

  case 35: /* assignStmt: var ASSIGN expression  */
#line 403 "src/parser.y"
                           {
      (yyval.node) = maketree(ASSIGNSTMT);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1570 "obj/y.tab.c"
    break;

  case 36: /* assignStmt: expression  */
#line 409 "src/parser.y"
      {
          (yyval.node) = maketree(ASSIGNSTMT);
          addChild((yyval.node), (yyvsp[0].node));
      }
#line 1579 "obj/y.tab.c"
    break;

  case 37: /* returnStmt: RETURN  */
#line 417 "src/parser.y"
          {
            (yyval.node) = maketree(RETURNSTMT);
          }
#line 1587 "obj/y.tab.c"
    break;

  case 38: /* returnStmt: RETURN expression  */
#line 421 "src/parser.y"
          {
            (yyval.node) = maketree(RETURNSTMT);
            addChild((yyval.node), (yyvsp[0].node));
          }
#line 1596 "obj/y.tab.c"
    break;

  case 39: /* loopStmt: WHILE LPARENTHESIS expression RPARENTHESIS statement  */
#line 428 "src/parser.y"
        {
          (yyval.node) = maketree(LOOPSTMT);
          addChild((yyval.node), (yyvsp[-2].node));
          addChild((yyval.node), (yyvsp[0].node));
        }
#line 1606 "obj/y.tab.c"
    break;

  case 40: /* condStmt: IF LPARENTHESIS expression RPARENTHESIS statement  */
#line 436 "src/parser.y"
        {
          (yyval.node) = maketree(CONDSTMT);
          addChild((yyval.node), (yyvsp[-2].node));
          addChild((yyval.node), (yyvsp[0].node));
        }
#line 1616 "obj/y.tab.c"
    break;

  case 41: /* condStmt: IF LPARENTHESIS expression RPARENTHESIS statement ELSE statement  */
#line 442 "src/parser.y"
        {
          (yyval.node) = maketree(CONDSTMT);
          addChild((yyval.node), (yyvsp[-4].node));
          addChild((yyval.node), (yyvsp[-2].node));
          addChild((yyval.node), (yyvsp[0].node));
        }
#line 1627 "obj/y.tab.c"
    break;

  case 42: /* expression: addExpr  */
#line 451 "src/parser.y"
      {
        (yyval.node) = maketree(EXPRESSION);
        addChild((yyval.node), (yyvsp[0].node));
      }
#line 1636 "obj/y.tab.c"
    break;

  case 43: /* expression: addExpr relop addExpr  */
#line 456 "src/parser.y"
      {
        (yyval.node) = maketree(EXPRESSION);

        tree *leftExpr = maketree(EXPRESSION);
        addChild(leftExpr, (yyvsp[-2].node));
        addChild((yyval.node), leftExpr);
        addChild((yyval.node), (yyvsp[-1].node));
        addChild((yyval.node), (yyvsp[0].node));
      }
#line 1650 "obj/y.tab.c"
    break;

  case 44: /* relop: LESSTHAN  */
#line 468 "src/parser.y"
      {
        (yyval.node) = maketreeWithVal(RELOP, LT);
      }
#line 1658 "obj/y.tab.c"
    break;

  case 45: /* relop: LESSTHANEQ  */
#line 472 "src/parser.y"
      {
        (yyval.node) = maketreeWithVal(RELOP, LTE);
      }
#line 1666 "obj/y.tab.c"
    break;

  case 46: /* relop: GREATERTHAN  */
#line 476 "src/parser.y"
      {
        (yyval.node) = maketreeWithVal(RELOP, GT);
      }
#line 1674 "obj/y.tab.c"
    break;

  case 47: /* relop: GREATERTHANEQ  */
#line 480 "src/parser.y"
      {
        (yyval.node) = maketreeWithVal(RELOP, GTE);
      }
#line 1682 "obj/y.tab.c"
    break;

  case 48: /* relop: EQ  */
#line 484 "src/parser.y"
      {
        (yyval.node) = maketreeWithVal(RELOP, OP_EQ);
      }
#line 1690 "obj/y.tab.c"
    break;

  case 49: /* relop: NEQ  */
#line 488 "src/parser.y"
      {
        (yyval.node) = maketreeWithVal(RELOP, OP_NEQ);
      }
#line 1698 "obj/y.tab.c"
    break;

  case 50: /* addExpr: term  */
#line 494 "src/parser.y"
      {
        (yyval.node) = maketree(ADDEXPR);
        addChild((yyval.node), (yyvsp[0].node));
      }
#line 1707 "obj/y.tab.c"
    break;

  case 51: /* addExpr: addExpr addop term  */
#line 499 "src/parser.y"
      {
        (yyval.node) = maketree(ADDEXPR);
        addChild((yyval.node), (yyvsp[-2].node));
        addChild((yyval.node), (yyvsp[-1].node));
        addChild((yyval.node), (yyvsp[0].node));
      }
#line 1718 "obj/y.tab.c"
    break;

  case 52: /* addop: PLUS  */
#line 508 "src/parser.y"
      {
        (yyval.node) = maketreeWithOp(ADDOP, '+');
      }
#line 1726 "obj/y.tab.c"
    break;

  case 53: /* addop: MINUS  */
#line 512 "src/parser.y"
      {
        (yyval.node) = maketreeWithOp(ADDOP, '-');
      }
#line 1734 "obj/y.tab.c"
    break;

  case 54: /* term: factor  */
#line 518 "src/parser.y"
      {
        (yyval.node) = maketree(TERM);
        addChild((yyval.node), (yyvsp[0].node));
      }
#line 1743 "obj/y.tab.c"
    break;

  case 55: /* term: term mulop factor  */
#line 523 "src/parser.y"
      {
        (yyval.node) = maketree(TERM);
        addChild((yyval.node), (yyvsp[-2].node));
        addChild((yyval.node), (yyvsp[-1].node));
        addChild((yyval.node), (yyvsp[0].node));
      }
#line 1754 "obj/y.tab.c"
    break;

  case 56: /* mulop: MULT  */
#line 533 "src/parser.y"
      {
        (yyval.node) = maketreeWithOp(MULOP, '*');
      }
#line 1762 "obj/y.tab.c"
    break;

  case 57: /* mulop: DIVIDE  */
#line 537 "src/parser.y"
      {
        (yyval.node) = maketreeWithOp(MULOP, '/');
      }
#line 1770 "obj/y.tab.c"
    break;

  case 58: /* factor: INTCONST  */
#line 543 "src/parser.y"
      {
        (yyval.node) = maketree(FACTOR);
        addChild((yyval.node), maketreeWithVal(INTEGER, (yyvsp[0].value)));
      }
#line 1779 "obj/y.tab.c"
    break;

  case 59: /* factor: var  */
#line 548 "src/parser.y"
      {
        (yyval.node) = maketree(FACTOR);
        addChild((yyval.node), (yyvsp[0].node));
      }
#line 1788 "obj/y.tab.c"
    break;

  case 60: /* factor: funCallExpr  */
#line 553 "src/parser.y"
      {
        (yyval.node) = maketree(FACTOR);
        addChild((yyval.node), (yyvsp[0].node));
      }
#line 1797 "obj/y.tab.c"
    break;

  case 61: /* factor: LPARENTHESIS expression RPARENTHESIS  */
#line 558 "src/parser.y"
      {
        (yyval.node) = maketree(FACTOR);
        addChild((yyval.node), (yyvsp[-1].node));
      }
#line 1806 "obj/y.tab.c"
    break;

  case 62: /* var: ID  */
#line 566 "src/parser.y"
      {
          int valID = ST_lookup((yyvsp[0].strval), scope);
          if (valID < 0) {
              yywarning("undeclared symbol");
          }
          (yyval.node) = maketree(VAR);
          addChild((yyval.node), maketreeWithName(IDENTIFIER, (yyvsp[0].strval)));
      }
#line 1819 "obj/y.tab.c"
    break;

  case 63: /* var: ID LBRACKET expression RBRACKET  */
#line 575 "src/parser.y"
      {
          int valID = ST_lookup((yyvsp[-3].strval), scope);
          if (valID < 0) {
              yywarning("undeclared symbol");
          }
          (yyval.node) = maketree(VAR);
          addChild((yyval.node), maketreeWithName(IDENTIFIER, (yyvsp[-3].strval)));
          addChild((yyval.node), (yyvsp[-1].node));
      }
#line 1833 "obj/y.tab.c"
    break;

  case 64: /* funCallExpr: ID LPARENTHESIS argListOpt RPARENTHESIS  */
#line 587 "src/parser.y"
{
  int valID = ST_lookup((yyvsp[-3].strval), "");
  if(valID < 0){
    yywarning("undeclared symbol");
  }
  (yyval.node) = maketree(FUNCCALLEXPR);
  addChild((yyval.node), maketreeWithName(IDENTIFIER, (yyvsp[-3].strval)));
  addChild((yyval.node), (yyvsp[-1].node));
}
#line 1847 "obj/y.tab.c"
    break;

  case 65: /* argListOpt: %empty  */
#line 599 "src/parser.y"
          {
            (yyval.node) = NULL;
          }
#line 1855 "obj/y.tab.c"
    break;

  case 66: /* argListOpt: argList  */
#line 603 "src/parser.y"
          {
            (yyval.node) = (yyvsp[0].node);
          }
#line 1863 "obj/y.tab.c"
    break;

  case 67: /* argList: expression  */
#line 609 "src/parser.y"
        {
          (yyval.node) = maketree(ARGLIST);
          addChild((yyval.node), (yyvsp[0].node));
        }
#line 1872 "obj/y.tab.c"
    break;

  case 68: /* argList: argList COMMA expression  */
#line 614 "src/parser.y"
        {
          (yyval.node) = maketree(ARGLIST);
          addChild((yyval.node), (yyvsp[-2].node));
          addChild((yyval.node), (yyvsp[0].node));
        }
#line 1882 "obj/y.tab.c"
    break;


#line 1886 "obj/y.tab.c"

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

#line 619 "src/parser.y"


int yywarning(char *msg){
  printf("warning: line %d: %s\n", yylineno, msg);
  return 0;
}

int yyerror(char * msg){
  printf("error: line %d: %s\n", yylineno, msg);
  return 0;
}
