/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "uccompiler.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "ast.h"

    extern int yylineno;
    extern char * yytext;

    extern int columnNumber;

    void print(char *s);
    void yyerror (char *s);
    extern int yylex();

    int flag_error = 0;
    int stat_list = 0;

    tree_node* root = NULL;
    tree_node* auxId = NULL;
    tree_node* auxNull = NULL;
    tree_node* auxIntLit = NULL;
    tree_node* auxChrLit = NULL;
    tree_node* auxStrLit = NULL;

#line 92 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BITWISEAND = 258,
    BITWISEOR = 259,
    BITWISEXOR = 260,
    AND = 261,
    OR = 262,
    EQ = 263,
    ASSIGN = 264,
    NOT = 265,
    NE = 266,
    GT = 267,
    LT = 268,
    GE = 269,
    LE = 270,
    COMMA = 271,
    SEMI = 272,
    LBRACE = 273,
    RBRACE = 274,
    LPAR = 275,
    RPAR = 276,
    PLUS = 277,
    MINUS = 278,
    MUL = 279,
    DIV = 280,
    MOD = 281,
    INT = 282,
    CHAR = 283,
    VOID = 284,
    IF = 285,
    ELSE = 286,
    RETURN = 287,
    RESERVED = 288,
    SHORT = 289,
    DOUBLE = 290,
    WHILE = 291,
    ID = 292,
    INTLIT = 293,
    CHRLIT = 294,
    REALLIT = 295
  };
#endif
/* Tokens.  */
#define BITWISEAND 258
#define BITWISEOR 259
#define BITWISEXOR 260
#define AND 261
#define OR 262
#define EQ 263
#define ASSIGN 264
#define NOT 265
#define NE 266
#define GT 267
#define LT 268
#define GE 269
#define LE 270
#define COMMA 271
#define SEMI 272
#define LBRACE 273
#define RBRACE 274
#define LPAR 275
#define RPAR 276
#define PLUS 277
#define MINUS 278
#define MUL 279
#define DIV 280
#define MOD 281
#define INT 282
#define CHAR 283
#define VOID 284
#define IF 285
#define ELSE 286
#define RETURN 287
#define RESERVED 288
#define SHORT 289
#define DOUBLE 290
#define WHILE 291
#define ID 292
#define INTLIT 293
#define CHRLIT 294
#define REALLIT 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 95 "uccompiler.y" /* yacc.c:355  */

    char*   id;
    char*   intlit;
    char*   chrlit;
    char*   reallit;
    struct _tree_node* node;

#line 220 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 237 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   454

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
static const yytype_uint16 yyrline[] =
{
       0,   121,   121,   129,   137,   147,   148,   154,   160,   169,
     178,   186,   193,   201,   207,   213,   217,   225,   232,   236,
     240,   256,   262,   263,   264,   265,   266,   270,   284,   285,
     288,   289,   296,   297,   300,   301,   302,   303,   304,   305,
     320,   339,   353,   365,   400,   401,   414,   415,   422,   427,
     432,   437,   442,   447,   452,   457,   462,   467,   472,   477,
     482,   487,   492,   497,   502,   507,   511,   515,   519,   520,
     521,   522,   523,   524,   525,   530,   533,   534,   540,   541,
     547,   548,   551,   552,   556
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BITWISEAND", "BITWISEOR", "BITWISEXOR",
  "AND", "OR", "EQ", "ASSIGN", "NOT", "NE", "GT", "LT", "GE", "LE",
  "COMMA", "SEMI", "LBRACE", "RBRACE", "LPAR", "RPAR", "PLUS", "MINUS",
  "MUL", "DIV", "MOD", "INT", "CHAR", "VOID", "IF", "ELSE", "RETURN",
  "RESERVED", "SHORT", "DOUBLE", "WHILE", "ID", "INTLIT", "CHRLIT",
  "REALLIT", "$accept", "Start", "Restart", "FunctionDefinition",
  "FunctionDeclaration", "FunctionDeclarator", "FunctionBody", "FandD",
  "ParameterList", "ParameterDeclaration", "CommaParameterDeclaration",
  "Declaration", "TypeSpec", "Declarator", "ZUAssignExpr",
  "CommaDeclarator", "Statement", "StatementSpecial", "StatList",
  "Restatement", "Expr", "ExprSpecial", "ZUExprZMComma", "ZMComma", "ZUid",
  "ZUExpr", "Empty", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -47

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-47)))

#define YYTABLE_NINF -85

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     248,   -11,   -47,   -47,   -47,   -47,   -47,    21,    81,    81,
      81,   -28,   -47,   -47,   -47,    81,    81,    81,   -47,   -47,
     -47,    -4,    61,    34,   -47,   -47,   -47,   145,   252,   -47,
     -47,   -47,   124,   -47,    36,    63,   -47,   145,   251,   145,
     145,    68,   -47,   -47,   -47,   -47,   313,    69,    73,    56,
     156,    79,   145,    80,    92,   124,    36,   124,    85,    97,
     101,   114,    34,   -47,   -47,   103,   -13,    20,    20,    82,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   -47,   252,
     -47,   -47,   -47,   -47,   -47,    16,   -47,   180,   -47,   107,
     -47,   145,   112,   145,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   109,   289,   115,   -47,   313,   428,   385,   409,   361,
     337,    72,   313,    72,   231,   231,   231,   231,    20,    20,
     -47,   -47,   -47,    73,   -47,   -47,   118,   -47,   204,   -47,
      22,   -47,    26,   -47,   145,   -47,   -47,   -47,   -47,   204,
     -47,   101,   228,   228,   289,   -47,   106,   -47,   -47,   228,
     -47
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    22,    23,    24,    25,    26,     0,     0,     0,
       0,     0,    21,     1,     2,     0,     0,     0,     5,     3,
       4,    84,     0,    84,     6,     7,     8,     0,     0,    27,
      29,    10,     0,     9,     0,     0,    30,     0,     0,     0,
       0,    68,    69,    70,    71,    28,    46,     0,    84,    84,
       0,     0,    84,     0,     0,     0,     0,     0,    83,     0,
      15,    84,    84,    20,    65,     0,     0,    67,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
      16,    19,    81,    17,    80,     0,    37,     0,    33,     0,
      82,     0,     0,     0,    12,    14,    13,    34,    31,    73,
      72,     0,    84,     0,    76,    47,    51,    52,    53,    49,
      50,    54,    48,    55,    57,    56,    59,    58,    60,    61,
      62,    63,    64,    84,    32,    38,     0,    36,     0,    35,
       0,    42,     0,    75,     0,    77,    78,    74,    18,     0,
      43,    44,     0,     0,    84,    45,    39,    41,    79,     0,
      40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,   -47,     9,   139,   140,   -47,   -47,   -42,   -47,    59,
      12,    17,   -18,   116,   -47,    87,   -46,   -25,   -47,    23,
     -26,   -17,   -47,    15,   -47,   119,   -21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,    14,    15,    16,    22,    33,    54,    47,    48,
      90,    17,    11,    23,    29,    35,   149,    98,    99,   150,
      58,    46,   113,   145,    93,    59,    18
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    45,    36,    70,    97,    27,    12,    57,   110,    21,
      49,    60,    66,   105,    56,   106,    28,    10,    19,    20,
      64,    13,    67,    68,    24,    25,    26,    91,    94,   100,
      57,   100,    57,   134,    60,   135,    60,    56,    70,    56,
      30,    36,    70,   152,    85,    86,    87,   153,   114,    55,
      34,   138,   112,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    49,    55,    61,    55,   140,   100,   142,    31,    32,
      63,   -84,     1,   111,    79,    80,    81,    82,    69,    89,
      88,   146,    37,    92,    83,    84,    85,    86,    87,   101,
     103,    70,    38,   -84,    39,    40,   156,   157,     2,     3,
       4,   104,    91,   160,   107,     5,     6,   151,   -82,    41,
      42,    43,    44,    27,   109,     1,   139,   154,   151,   141,
     143,   100,   100,   146,    37,   134,   147,   159,   100,     8,
       9,   -84,    50,   -84,    38,   148,    39,    40,   133,   108,
      62,     2,     3,     4,    51,    37,    52,    95,     5,     6,
      53,    41,    42,    43,    44,    38,    37,    39,    40,   158,
       0,   102,   155,   -84,    50,    96,    38,     0,    39,    40,
       0,   136,    41,    42,    43,    44,    51,     0,    52,     0,
      37,     0,    53,    41,    42,    43,    44,   -84,    50,   137,
      38,     0,    39,    40,     0,   136,     0,     0,     0,     0,
      51,     0,    52,     0,    37,     0,    53,    41,    42,    43,
      44,   -84,    50,   -84,    38,     0,    39,    40,     0,   136,
       0,     0,     0,     0,    51,     0,    52,     0,    37,     0,
      53,    41,    42,    43,    44,   -84,    50,     0,    38,     1,
      39,    40,    65,    83,    84,    85,    86,    87,    51,     0,
      52,    37,     0,     0,    53,    41,    42,    43,    44,     0,
       0,    38,     0,    39,    40,     2,     3,     4,     0,     2,
       3,     4,     5,     6,     0,     0,     5,     6,    41,    42,
      43,    44,    71,    72,    73,    74,    75,    76,    77,     0,
      78,    79,    80,    81,    82,   144,     0,     0,     0,     0,
       0,    83,    84,    85,    86,    87,    71,    72,    73,    74,
      75,    76,    77,     0,    78,    79,    80,    81,    82,     0,
       0,     0,     0,     0,     0,    83,    84,    85,    86,    87,
      71,    72,    73,    74,     0,    76,     0,     0,    78,    79,
      80,    81,    82,     0,     0,     0,     0,     0,     0,    83,
      84,    85,    86,    87,    71,    72,    73,     0,     0,    76,
       0,     0,    78,    79,    80,    81,    82,     0,     0,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    71,     0,
      73,     0,     0,    76,     0,     0,    78,    79,    80,    81,
      82,     0,     0,     0,     0,     0,     0,    83,    84,    85,
      86,    87,    71,     0,     0,     0,     0,    76,     0,     0,
      78,    79,    80,    81,    82,     0,     0,     0,     0,     0,
       0,    83,    84,    85,    86,    87,    76,     0,     0,    78,
      79,    80,    81,    82,     0,     0,     0,     0,     0,     0,
      83,    84,    85,    86,    87
};

static const yytype_int16 yycheck[] =
{
      21,    27,    23,    16,    50,     9,    17,    32,    21,    37,
      28,    32,    38,    55,    32,    57,    20,     0,     9,    10,
      37,     0,    39,    40,    15,    16,    17,    48,    49,    50,
      55,    52,    57,    17,    55,    19,    57,    55,    16,    57,
      61,    62,    16,    21,    24,    25,    26,    21,    69,    32,
      16,    97,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    89,    55,    37,    57,   101,    97,   103,    17,    18,
      17,     0,     1,     1,    12,    13,    14,    15,    20,    16,
      21,   112,    10,    37,    22,    23,    24,    25,    26,    20,
      20,    16,    20,    21,    22,    23,   152,   153,    27,    28,
      29,    19,   133,   159,    17,    34,    35,   138,    17,    37,
      38,    39,    40,     9,    21,     1,    19,   144,   149,    17,
      21,   152,   153,   154,    10,    17,    21,    31,   159,     0,
       0,    17,    18,    19,    20,   133,    22,    23,    89,    62,
      34,    27,    28,    29,    30,    10,    32,     1,    34,    35,
      36,    37,    38,    39,    40,    20,    10,    22,    23,   154,
      -1,    52,   149,    17,    18,    19,    20,    -1,    22,    23,
      -1,     1,    37,    38,    39,    40,    30,    -1,    32,    -1,
      10,    -1,    36,    37,    38,    39,    40,    17,    18,    19,
      20,    -1,    22,    23,    -1,     1,    -1,    -1,    -1,    -1,
      30,    -1,    32,    -1,    10,    -1,    36,    37,    38,    39,
      40,    17,    18,    19,    20,    -1,    22,    23,    -1,     1,
      -1,    -1,    -1,    -1,    30,    -1,    32,    -1,    10,    -1,
      36,    37,    38,    39,    40,    17,    18,    -1,    20,     1,
      22,    23,     1,    22,    23,    24,    25,    26,    30,    -1,
      32,    10,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      -1,    20,    -1,    22,    23,    27,    28,    29,    -1,    27,
      28,    29,    34,    35,    -1,    -1,    34,    35,    37,    38,
      39,    40,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,     3,     4,     5,    -1,    -1,     8,
      -1,    -1,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,     3,    -1,
       5,    -1,    -1,     8,    -1,    -1,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,     3,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,     8,    -1,    -1,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    27,    28,    29,    34,    35,    42,    44,    45,
      52,    53,    17,     0,    43,    44,    45,    52,    67,    43,
      43,    37,    46,    54,    43,    43,    43,     9,    20,    55,
      67,    17,    18,    47,    16,    56,    67,    10,    20,    22,
      23,    37,    38,    39,    40,    61,    62,    49,    50,    53,
      18,    30,    32,    36,    48,    52,    53,    58,    61,    66,
      67,    37,    54,    17,    62,     1,    61,    62,    62,    20,
      16,     3,     4,     5,     6,     7,     8,     9,    11,    12,
      13,    14,    15,    22,    23,    24,    25,    26,    21,    16,
      51,    67,    37,    65,    67,     1,    19,    57,    58,    59,
      67,    20,    66,    20,    19,    48,    48,    17,    56,    21,
      21,     1,    62,    63,    67,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    50,    17,    19,     1,    19,    57,    19,
      61,    17,    61,    21,    16,    64,    67,    21,    51,    57,
      60,    67,    21,    21,    62,    60,    57,    57,    64,    31,
      57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    42,    43,    43,    43,    43,    44,
      45,    46,    47,    48,    48,    48,    49,    50,    51,    51,
      52,    52,    53,    53,    53,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    59,    60,    60,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    63,    64,    64,
      65,    65,    66,    66,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     1,     2,     2,     2,     3,
       3,     4,     3,     2,     2,     1,     2,     2,     3,     1,
       4,     2,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     3,     2,     1,     2,     3,     3,     2,     3,     5,
       7,     5,     3,     3,     1,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     1,     1,
       1,     1,     3,     3,     4,     4,     1,     2,     1,     3,
       1,     1,     1,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 121 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("Program");
                                                                                    root = (yyval.node);
                                                                                    if((yyvsp[-1].node) != NULL) {
                                                                                        add_child((yyval.node), (yyvsp[-1].node));
                                                                                        add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                    }
                                                                                }
#line 1493 "y.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 129 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("Program");
                                                                                    root = (yyval.node);
                                                                                    if((yyvsp[-1].node) != NULL) {
                                                                                        add_child((yyval.node), (yyvsp[-1].node));
                                                                                        add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                    }
                                                                                }
#line 1506 "y.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 137 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("Program");
                                                                                    root = (yyval.node);
                                                                                    if((yyvsp[-1].node) != NULL) {
                                                                                        add_child((yyval.node), (yyvsp[-1].node));
                                                                                        add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                    }
                                                                                }
#line 1519 "y.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 147 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1525 "y.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 148 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  if((yyvsp[-1].node) != NULL) {
                                                                                      add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                  }
                                                                                }
#line 1536 "y.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 154 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  if((yyvsp[-1].node) != NULL) {
                                                                                      add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                  }
                                                                                }
#line 1547 "y.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 160 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  if((yyvsp[-1].node) != NULL) {
                                                                                      add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                  }
                                                                                }
#line 1558 "y.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 169 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("FuncDefinition");
                                                                                    add_child((yyval.node), (yyvsp[-2].node));
                                                                                    add_brother((yyvsp[-2].node),(yyvsp[-1].node));
                                                                                    add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 1569 "y.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 178 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("FuncDeclaration");
                                                                                    add_child((yyval.node), (yyvsp[-2].node));
                                                                                    add_brother((yyval.node)->son,(yyvsp[-1].node));
                                                                                }
#line 1579 "y.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 186 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_value_node("Id", (yyvsp[-3].id));
                                                                                  add_brother((yyval.node), (yyvsp[-1].node));
                                                                                }
#line 1588 "y.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 193 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("FuncBody");
                                                                                    if((yyvsp[-1].node) != NULL){
                                                                                      add_child((yyval.node),(yyvsp[-1].node));
                                                                                    }
                                                                                }
#line 1599 "y.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 201 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  if((yyvsp[-1].node) != NULL) {
                                                                                        add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                  }
                                                                                }
#line 1610 "y.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 207 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  if((yyvsp[-1].node) != NULL) {
                                                                                        add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                  }
                                                                                }
#line 1621 "y.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 213 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1627 "y.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 217 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("ParamList");
                                                                                    add_child((yyval.node),(yyvsp[-1].node));
                                                                                    add_brother((yyvsp[-1].node),(yyvsp[0].node));
                                                                                }
#line 1637 "y.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 225 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("ParamDeclaration");
                                                                                    add_child((yyval.node),(yyvsp[-1].node));
                                                                                    add_brother((yyvsp[-1].node),(yyvsp[0].node));
                                                                                }
#line 1647 "y.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 232 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  add_brother((yyvsp[-1].node),(yyvsp[0].node));
                                                                                }
#line 1656 "y.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 236 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1662 "y.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 240 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                      (yyval.node) = (yyvsp[-2].node);
                                                                                      if((yyvsp[-1].node) != NULL) {
                                                                                          add_brother((yyval.node), (yyvsp[-1].node));
                                                                                      }
                                                                                      tree_node* aux = (yyval.node);
                                                                                      tree_node aux2 = *(yyvsp[-3].node);
                                                                                      while(aux != NULL) {
                                                                                          aux2.next_brother = aux->son;
                                                                                          aux2.father = aux;
                                                                                          aux->son = (tree_node*) malloc(sizeof(tree_node));
                                                                                          *(aux->son) = aux2;

                                                                                          aux = aux->next_brother;
                                                                                      }
                                                                                }
#line 1683 "y.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 256 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = NULL;}
#line 1689 "y.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 262 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_simple_node("Int");}
#line 1695 "y.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 263 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_simple_node("Char");}
#line 1701 "y.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 264 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_simple_node("Void");}
#line 1707 "y.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 265 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_simple_node("Short");}
#line 1713 "y.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 266 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_simple_node("Double");}
#line 1719 "y.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 270 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Declaration");
                                                                                  auxId = create_value_node("Id",(yyvsp[-1].id));
                                                                                  if((yyvsp[0].node) != NULL){
                                                                                    add_child((yyval.node),auxId);
                                                                                    add_brother((yyval.node)->son,(yyvsp[0].node));
                                                                                  }
                                                                                  else{
                                                                                    add_child((yyval.node),auxId);
                                                                                  }

                                                                                }
#line 1736 "y.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 284 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1742 "y.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 285 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1748 "y.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 288 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1754 "y.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 289 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                }
#line 1763 "y.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 296 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = NULL;}
#line 1769 "y.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 297 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1775 "y.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 300 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1781 "y.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 301 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1787 "y.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 302 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1793 "y.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 303 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = NULL;}
#line 1799 "y.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 304 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = NULL;}
#line 1805 "y.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 305 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                      if((yyvsp[-2].node) != NULL) {
                                                                                          (yyval.node) = create_simple_node("If");

                                                                                          add_child((yyval.node),(yyvsp[-2].node));
                                                                                          if((yyvsp[0].node) != NULL) {
                                                                                              add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                          }else {
                                                                                              add_brother((yyvsp[-2].node),create_simple_node("Null"));
                                                                                          }
                                                                                          add_brother((yyvsp[-2].node),create_simple_node("Null"));
                                                                                      } else {
                                                                                          (yyval.node) = NULL;
                                                                                      }
                                                                                }
#line 1825 "y.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 320 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    if( (yyvsp[-4].node) != NULL ) {
                                                                                        (yyval.node) = create_simple_node("If");
                                                                                        add_child((yyval.node), (yyvsp[-4].node));
                                                                                        if((yyvsp[-2].node) != NULL) {
                                                                                            add_brother((yyvsp[-4].node),(yyvsp[-2].node));
                                                                                        }else {
                                                                                            add_brother((yyvsp[-4].node),create_simple_node("Null"));
                                                                                        }

                                                                                        if((yyvsp[0].node) != NULL) {
                                                                                            add_brother((yyvsp[-4].node),(yyvsp[0].node));
                                                                                        }else {
                                                                                            add_brother((yyvsp[-4].node),create_simple_node("Null"));
                                                                                        }
                                                                                    } else {
                                                                                        (yyval.node) = NULL;
                                                                                    }
                                                                                }
#line 1849 "y.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 339 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    if((yyvsp[-2].node) != NULL) {
                                                                                        (yyval.node) = create_simple_node("While");
                                                                                        add_child((yyval.node),(yyvsp[-2].node));
                                                                                        if((yyvsp[0].node) != NULL) {
                                                                                            add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                        }else {
                                                                                            add_brother((yyvsp[-2].node),create_simple_node("Null"));
                                                                                        }
                                                                                    } else {
                                                                                        (yyval.node) = NULL;
                                                                                    }
                                                                                }
#line 1867 "y.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 353 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("Return");
                                                                                    if((yyvsp[-1].node) == NULL){
                                                                                        add_child((yyval.node), create_simple_node("Null"));
                                                                                    }
                                                                                    else{
                                                                                        add_child((yyval.node),(yyvsp[-1].node));
                                                                                    }
                                                                                }
#line 1881 "y.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 365 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    int stat_num = 0;
                                                                                    tree_node * stat_aux = (yyvsp[0].node);
                                                                                    while (stat_aux != NULL) {
                                                                                        stat_num +=1;
                                                                                        stat_aux = stat_aux -> next_brother;
                                                                                    }
                                                                                    if((yyvsp[-2].node) != NULL && (yyvsp[-1].node) != NULL) {
                                                                                        (yyval.node) = create_simple_node("StatList");
                                                                                        add_child((yyval.node),(yyvsp[-2].node));
                                                                                        add_brother((yyval.node)->son,(yyvsp[-1].node));
                                                                                        add_brother((yyval.node)->son,(yyvsp[0].node));
                                                                                    } else {
                                                                                        if((yyvsp[-2].node) != NULL && (yyvsp[-1].node) == NULL && stat_num >=1) {
                                                                                            (yyval.node) = create_simple_node("StatList");
                                                                                            add_child((yyval.node),(yyvsp[-2].node));
                                                                                            add_brother((yyval.node)->son, (yyvsp[0].node));
                                                                                        }else if((yyvsp[-1].node) != NULL && (yyvsp[-2].node) == NULL && stat_num >=1){
                                                                                            (yyval.node) = create_simple_node("StatList");
                                                                                            add_child((yyval.node),(yyvsp[-1].node));
                                                                                            add_brother((yyval.node)->son, (yyvsp[0].node));
                                                                                        }else if((yyvsp[-1].node) != NULL && (yyvsp[-2].node) == NULL) {
                                                                                            (yyval.node) = (yyvsp[-1].node);
                                                                                            add_brother((yyval.node), (yyvsp[0].node));
                                                                                        }else if((yyvsp[-2].node) != NULL && (yyvsp[-1].node) == NULL){
                                                                                            (yyval.node) = (yyvsp[-2].node);
                                                                                            add_brother((yyval.node), (yyvsp[0].node));
                                                                                        }else if((yyvsp[-1].node) == NULL && (yyvsp[-2].node) == NULL && stat_num >=2) {
                                                                                            (yyval.node) = create_simple_node("StatList");
                                                                                            add_child((yyval.node),(yyvsp[0].node));
                                                                                        }
                                                                                    }
                                                                                }
#line 1919 "y.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 400 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1925 "y.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 401 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    if((yyvsp[-1].node) != NULL){
                                                                                        (yyval.node) = (yyvsp[-1].node);
                                                                                        add_brother((yyval.node),(yyvsp[0].node));
                                                                                    }
                                                                                    else{
                                                                                        (yyval.node) = (yyvsp[0].node);
                                                                                    }
                                                                                }
#line 1939 "y.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 414 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1945 "y.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 415 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Comma");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyval.node)->son,(yyvsp[0].node));
                                                                                }
#line 1955 "y.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 422 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Store");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 1965 "y.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 427 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("And");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 1975 "y.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 432 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Or");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 1985 "y.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 437 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("BitWiseAnd");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 1995 "y.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 442 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("BitWiseOr");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 2005 "y.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 447 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("BitWiseXor");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 2015 "y.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 452 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Eq");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 2025 "y.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 457 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Ne");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 2035 "y.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 462 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Lt");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 2045 "y.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 467 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Gt");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 2055 "y.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 472 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Le");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 2065 "y.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 477 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Ge");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 2075 "y.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 482 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Add");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 2085 "y.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 487 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Sub");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 2095 "y.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 492 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Mul");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 2105 "y.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 497 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Div");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 2115 "y.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 502 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Mod");
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                }
#line 2125 "y.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 507 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Not");
                                                                                  add_child((yyval.node),(yyvsp[0].node));
                                                                                }
#line 2134 "y.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 511 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Minus");
                                                                                  add_child((yyval.node),(yyvsp[0].node));
                                                                                }
#line 2143 "y.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 515 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Plus");
                                                                                  add_child((yyval.node),(yyvsp[0].node));
                                                                                }
#line 2152 "y.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 519 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_value_node("Id",(yyvsp[0].id));}
#line 2158 "y.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 520 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_value_node("IntLit",(yyvsp[0].intlit));}
#line 2164 "y.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 521 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_value_node("ChrLit",(yyvsp[0].chrlit));}
#line 2170 "y.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 522 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_value_node("RealLit",(yyvsp[0].reallit));}
#line 2176 "y.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 523 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2182 "y.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 524 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = NULL;}
#line 2188 "y.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 525 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Call");
                                                                                  add_child((yyval.node), create_value_node("Id",(yyvsp[-3].id)));
                                                                                  add_brother((yyval.node)->son,(yyvsp[-1].node));
                                                                                }
#line 2198 "y.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 530 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = NULL;}
#line 2204 "y.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 533 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2210 "y.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 534 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  add_brother((yyval.node),(yyvsp[0].node));
                                                                                }
#line 2219 "y.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 540 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2225 "y.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 541 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  add_brother((yyval.node),(yyvsp[0].node));
                                                                                }
#line 2234 "y.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 547 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = NULL;}
#line 2240 "y.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 548 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = create_value_node("Id",(yyvsp[0].id));}
#line 2246 "y.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 551 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2252 "y.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 552 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2258 "y.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 556 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = NULL;}
#line 2264 "y.tab.c" /* yacc.c:1661  */
    break;


#line 2268 "y.tab.c" /* yacc.c:1661  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 559 "uccompiler.y" /* yacc.c:1906  */


/* A função main() está do lado do lex */

void yyerror (char *s) {

    flag_error = 1;

    printf ("Line %d, col %d: %s: %s\n", yylineno, (int)(columnNumber - strlen(yytext)), s, yytext);
}
