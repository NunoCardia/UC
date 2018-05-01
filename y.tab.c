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
#line 96 "uccompiler.y" /* yacc.c:355  */

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

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 251 "y.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   131,   139,   149,   150,   156,   162,   171,
     181,   190,   197,   205,   214,   220,   224,   233,   246,   251,
     255,   271,   277,   278,   279,   280,   281,   285,   300,   301,
     304,   305,   312,   313,   316,   317,   318,   319,   320,   321,
     337,   357,   373,   387,   422,   423,   436,   437,   445,   451,
     457,   463,   469,   475,   481,   487,   493,   499,   505,   511,
     517,   523,   529,   535,   541,   547,   552,   557,   562,   563,
     564,   565,   566,   567,   568,   574,   577,   578,   584,   585,
     592,   593,   596,   597,   601
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
  "REALLIT", "\"pos\"", "\"neg\"", "$accept", "Start", "Restart",
  "FunctionDefinition", "FunctionDeclaration", "FunctionDeclarator",
  "FunctionBody", "FandD", "ParameterList", "ParameterDeclaration",
  "CommaParameterDeclaration", "Declaration", "TypeSpec", "Declarator",
  "ZUAssignExpr", "CommaDeclarator", "Statement", "StatementSpecial",
  "StatList", "Restatement", "Expr", "ExprSpecial", "ZUExprZMComma",
  "ZMComma", "ZUid", "ZUExpr", "Empty", YY_NULLPTR
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
     295,   296,   297
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
     101,   114,    34,   -47,   -47,   103,   -13,   -47,   -47,    82,
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
       0,     1,    27,    28,    29,    34,    35,    44,    46,    47,
      54,    55,    17,     0,    45,    46,    47,    54,    69,    45,
      45,    37,    48,    56,    45,    45,    45,     9,    20,    57,
      69,    17,    18,    49,    16,    58,    69,    10,    20,    22,
      23,    37,    38,    39,    40,    63,    64,    51,    52,    55,
      18,    30,    32,    36,    50,    54,    55,    60,    63,    68,
      69,    37,    56,    17,    64,     1,    63,    64,    64,    20,
      16,     3,     4,     5,     6,     7,     8,     9,    11,    12,
      13,    14,    15,    22,    23,    24,    25,    26,    21,    16,
      53,    69,    37,    67,    69,     1,    19,    59,    60,    61,
      69,    20,    68,    20,    19,    50,    50,    17,    58,    21,
      21,     1,    64,    65,    69,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    52,    17,    19,     1,    19,    59,    19,
      63,    17,    63,    21,    16,    66,    69,    21,    53,    59,
      62,    69,    21,    21,    64,    62,    59,    59,    66,    31,
      59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    44,    45,    45,    45,    45,    46,
      47,    48,    49,    50,    50,    50,    51,    52,    53,    53,
      54,    54,    55,    55,    55,    55,    55,    56,    57,    57,
      58,    58,    59,    59,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    62,    62,    63,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    69
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 123 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("Program",yylineno,(int)(columnNumber));
                                                                                    root = (yyval.node);
                                                                                    if((yyvsp[-1].node) != NULL) {
                                                                                        add_child((yyval.node), (yyvsp[-1].node));
                                                                                        add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                    }
                                                                                }
#line 1602 "y.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 131 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("Program", yylineno, (int)(columnNumber));
                                                                                    root = (yyval.node);
                                                                                    if((yyvsp[-1].node) != NULL) {
                                                                                        add_child((yyval.node), (yyvsp[-1].node));
                                                                                        add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                    }
                                                                                }
#line 1615 "y.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 139 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("Program", yylineno, (int)(columnNumber));
                                                                                    root = (yyval.node);
                                                                                    if((yyvsp[-1].node) != NULL) {
                                                                                        add_child((yyval.node), (yyvsp[-1].node));
                                                                                        add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                    }
                                                                                }
#line 1628 "y.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 149 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1634 "y.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 150 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  if((yyvsp[-1].node) != NULL) {
                                                                                      add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                  }
                                                                                }
#line 1645 "y.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 156 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  if((yyvsp[-1].node) != NULL) {
                                                                                      add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                  }
                                                                                }
#line 1656 "y.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 162 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  if((yyvsp[-1].node) != NULL) {
                                                                                      add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                  }
                                                                                }
#line 1667 "y.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 171 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("FuncDefinition", yylineno, (int)(columnNumber));
                                                                                    add_child((yyval.node), (yyvsp[-2].node));
                                                                                    add_brother((yyvsp[-2].node),(yyvsp[-1].node));
                                                                                    add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                    (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 1679 "y.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 181 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("FuncDeclaration", yylineno, (int)(columnNumber));
                                                                                    add_child((yyval.node), (yyvsp[-2].node));
                                                                                    add_brother((yyval.node)->son,(yyvsp[-1].node));
                                                                                    (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 1690 "y.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 190 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_value_node("Id", (yyvsp[-3].id), yylineno, (int)((yyvsp[-1].node)->col - strlen((yyvsp[-3].id))));
                                                                                  add_brother((yyval.node), (yyvsp[-1].node));
                                                                                }
#line 1699 "y.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 197 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("FuncBody", yylineno, (int)(columnNumber));
                                                                                    if((yyvsp[-1].node) != NULL){
                                                                                      add_child((yyval.node),(yyvsp[-1].node));
                                                                                    }
                                                                                }
#line 1710 "y.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 205 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  if((yyvsp[-1].node) != NULL) {
                                                                                        add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                  }
                                                                                  else{
                                                                                        (yyval.node) = (yyvsp[0].node);
                                                                                    }
                                                                                }
#line 1724 "y.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 214 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  if((yyvsp[-1].node) != NULL) {
                                                                                        add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                  }
                                                                                }
#line 1735 "y.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 220 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1741 "y.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 224 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("ParamList", yylineno, (int)((yyvsp[-1].node)->col - 1));
                                                                                    add_child((yyval.node),(yyvsp[-1].node));
                                                                                    add_brother((yyvsp[-1].node),(yyvsp[0].node));
                                                                                    (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 1752 "y.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 233 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("ParamDeclaration", yylineno, (int)(columnNumber - (columnNumber - (yyvsp[-1].node)->col)));
                                                                                    add_child((yyval.node),(yyvsp[-1].node));
                                                                                    add_brother((yyvsp[-1].node),(yyvsp[0].node));
                                                                                    if((yyvsp[0].node) == NULL){
                                                                                      (yyval.node)->loc = (yylsp[-1]);
                                                                                    }
                                                                                    else{
                                                                                      (yyval.node)->loc = (yylsp[0]);
                                                                                    }
                                                                                }
#line 1768 "y.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 246 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  add_brother((yyvsp[-1].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 1778 "y.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 251 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1784 "y.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 255 "uccompiler.y" /* yacc.c:1661  */
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
#line 1805 "y.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 271 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = NULL;}
#line 1811 "y.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 277 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_simple_node("Int", yylineno, (int)(columnNumber - 3));(yyval.node)->loc = (yylsp[0]);}
#line 1817 "y.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 278 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_simple_node("Char", yylineno, (int)(columnNumber - 4));(yyval.node)->loc = (yylsp[0]);}
#line 1823 "y.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 279 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_simple_node("Void", yylineno, (int)(columnNumber - 4));(yyval.node)->loc = (yylsp[0]);}
#line 1829 "y.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 280 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_simple_node("Short", yylineno, (int)(columnNumber - 5));(yyval.node)->loc = (yylsp[0]);}
#line 1835 "y.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 281 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_simple_node("Double", yylineno, (int)(columnNumber - 6));(yyval.node)->loc = (yylsp[0]);}
#line 1841 "y.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 285 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Declaration", yylineno, (int)(columnNumber));
                                                                                  auxId = create_value_node("Id",(yyvsp[-1].id), yylineno, (int)(columnNumber - strlen((yyvsp[-1].id)) - 1));
                                                                                  if((yyvsp[0].node) != NULL){
                                                                                    add_child((yyval.node),auxId);
                                                                                    add_brother((yyval.node)->son,(yyvsp[0].node));
                                                                                  }
                                                                                  else{
                                                                                    add_child((yyval.node),auxId);
                                                                                  }
                                                                                  (yyval.node)->loc = (yylsp[-1]);

                                                                                }
#line 1859 "y.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 300 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1865 "y.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 301 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1871 "y.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 304 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1877 "y.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 305 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  add_brother((yyvsp[-1].node), (yyvsp[0].node));
                                                                                }
#line 1886 "y.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 312 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = NULL;}
#line 1892 "y.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 313 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1898 "y.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 316 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1904 "y.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 317 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1910 "y.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 318 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1916 "y.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 319 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = NULL;}
#line 1922 "y.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 320 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = NULL;}
#line 1928 "y.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 321 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                      if((yyvsp[-2].node) != NULL) {
                                                                                          (yyval.node) = create_simple_node("If", yylineno, (int)(columnNumber));

                                                                                          add_child((yyval.node),(yyvsp[-2].node));
                                                                                          if((yyvsp[0].node) != NULL) {
                                                                                              add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                          }else {
                                                                                              add_brother((yyvsp[-2].node),create_simple_node("Null", yylineno, (int)(columnNumber)));
                                                                                          }
                                                                                          add_brother((yyvsp[-2].node),create_simple_node("Null", yylineno, (int)(columnNumber)));
                                                                                      } else {
                                                                                          (yyval.node) = NULL;
                                                                                      }
                                                                                      (yyval.node)->loc = (yylsp[-2]);
                                                                                }
#line 1949 "y.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 337 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    if( (yyvsp[-4].node) != NULL ) {
                                                                                        (yyval.node) = create_simple_node("If", yylineno, (int)(columnNumber));
                                                                                        add_child((yyval.node), (yyvsp[-4].node));
                                                                                        if((yyvsp[-2].node) != NULL) {
                                                                                            add_brother((yyvsp[-4].node),(yyvsp[-2].node));
                                                                                        }else {
                                                                                            add_brother((yyvsp[-4].node),create_simple_node("Null", yylineno, (int)(columnNumber)));
                                                                                        }

                                                                                        if((yyvsp[0].node) != NULL) {
                                                                                            add_brother((yyvsp[-4].node),(yyvsp[0].node));
                                                                                        }else {
                                                                                            add_brother((yyvsp[-4].node),create_simple_node("Null", yylineno, (int)(columnNumber)));
                                                                                        }
                                                                                    } else {
                                                                                        (yyval.node) = NULL;
                                                                                    }
                                                                                    (yyval.node)->loc = (yylsp[-4]);
                                                                                }
#line 1974 "y.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 357 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("While", yylineno, (int)(columnNumber));
                                                                                    if((yyvsp[-2].node) != NULL) {
                                                                                      add_child((yyval.node),(yyvsp[-2].node));
                                                                                    } else {
                                                                                      auxNull = create_simple_node("Null", yylineno, (int)(columnNumber));
                                                                                      add_child((yyval.node),auxNull);
                                                                                    }
                                                                                    if((yyvsp[0].node) != NULL) {
                                                                                        add_brother((yyval.node)->son,(yyvsp[0].node));
                                                                                    }else {
                                                                                        add_brother((yyval.node)->son,create_simple_node("Null", yylineno, (int)(columnNumber)));
                                                                                    }
                                                                                    (yyval.node)->loc = (yylsp[-2]);
                                                                                }
#line 1994 "y.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 373 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    (yyval.node) = create_simple_node("Return", yylineno, (int)(columnNumber));
                                                                                    if((yyvsp[-1].node) == NULL){
                                                                                        add_child((yyval.node), create_simple_node("Null", yylineno, (int)(columnNumber)));
                                                                                        (yyval.node)->loc = (yylsp[-2]);
                                                                                    }
                                                                                    else{
                                                                                        add_child((yyval.node),(yyvsp[-1].node));
                                                                                        (yyval.node)->loc = (yylsp[-1]);
                                                                                    }
                                                                                }
#line 2010 "y.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 387 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    int stat_num = 0;
                                                                                    tree_node * stat_aux = (yyvsp[0].node);
                                                                                    while (stat_aux != NULL) {
                                                                                        stat_num +=1;
                                                                                        stat_aux = stat_aux -> next_brother;
                                                                                    }
                                                                                    if((yyvsp[-2].node) != NULL && (yyvsp[-1].node) != NULL) {
                                                                                        (yyval.node) = create_simple_node("StatList", yylineno, (int)(columnNumber));
                                                                                        add_child((yyval.node),(yyvsp[-2].node));
                                                                                        add_brother((yyval.node)->son,(yyvsp[-1].node));
                                                                                        add_brother((yyval.node)->son,(yyvsp[0].node));
                                                                                    } else {
                                                                                        if((yyvsp[-2].node) != NULL && (yyvsp[-1].node) == NULL && stat_num >=1) {
                                                                                            (yyval.node) = create_simple_node("StatList", yylineno, (int)(columnNumber));
                                                                                            add_child((yyval.node),(yyvsp[-2].node));
                                                                                            add_brother((yyval.node)->son, (yyvsp[0].node));
                                                                                        }else if((yyvsp[-1].node) != NULL && (yyvsp[-2].node) == NULL && stat_num >=1){
                                                                                            (yyval.node) = create_simple_node("StatList", yylineno, (int)(columnNumber));
                                                                                            add_child((yyval.node),(yyvsp[-1].node));
                                                                                            add_brother((yyval.node)->son, (yyvsp[0].node));
                                                                                        }else if((yyvsp[-1].node) != NULL && (yyvsp[-2].node) == NULL) {
                                                                                            (yyval.node) = (yyvsp[-1].node);
                                                                                            add_brother((yyval.node), (yyvsp[0].node));
                                                                                        }else if((yyvsp[-2].node) != NULL && (yyvsp[-1].node) == NULL){
                                                                                            (yyval.node) = (yyvsp[-2].node);
                                                                                            add_brother((yyval.node), (yyvsp[0].node));
                                                                                        }else if((yyvsp[-1].node) == NULL && (yyvsp[-2].node) == NULL && stat_num >=2) {
                                                                                            (yyval.node) = create_simple_node("StatList", yylineno, (int)(columnNumber));
                                                                                            add_child((yyval.node),(yyvsp[0].node));
                                                                                        }
                                                                                    }
                                                                                }
#line 2048 "y.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 422 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2054 "y.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 423 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                    if((yyvsp[-1].node) != NULL){
                                                                                        (yyval.node) = (yyvsp[-1].node);
                                                                                        add_brother((yyval.node),(yyvsp[0].node));
                                                                                    }
                                                                                    else{
                                                                                        (yyval.node) = (yyvsp[0].node);
                                                                                    }
                                                                                }
#line 2068 "y.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 436 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2074 "y.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 437 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Comma", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyval.node)->son,(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2085 "y.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 445 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Store", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2096 "y.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 451 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("And", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2107 "y.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 457 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Or", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2118 "y.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 463 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("BitWiseAnd", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2129 "y.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 469 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("BitWiseOr", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2140 "y.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 475 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("BitWiseXor", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2151 "y.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 481 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Eq", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2162 "y.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 487 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Ne", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2173 "y.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 493 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Lt", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2184 "y.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 499 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Gt", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2195 "y.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 505 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Le", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2206 "y.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 511 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Ge", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2217 "y.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 517 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Add", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2228 "y.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 523 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Sub", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2239 "y.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 529 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Mul", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2250 "y.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 535 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Div", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2261 "y.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 541 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Mod", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[-2].node));
                                                                                  add_brother((yyvsp[-2].node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2272 "y.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 547 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Not", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2282 "y.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 552 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Minus", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2292 "y.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 557 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Plus", yylineno, (int)(columnNumber));
                                                                                  add_child((yyval.node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2302 "y.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 562 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_value_node("Id",(yyvsp[0].id), yylineno, (int)(columnNumber- strlen((yyvsp[0].id))-2));(yyval.node)->loc = (yylsp[0]);}
#line 2308 "y.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 563 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_value_node("IntLit",(yyvsp[0].intlit), yylineno, (int)(columnNumber - strlen((yyvsp[0].intlit))));(yyval.node)->loc = (yylsp[0]);}
#line 2314 "y.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 564 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_value_node("ChrLit",(yyvsp[0].chrlit), yylineno, (int)(columnNumber - strlen((yyvsp[0].chrlit))));(yyval.node)->loc = (yylsp[0]);}
#line 2320 "y.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 565 "uccompiler.y" /* yacc.c:1661  */
    { (yyval.node) = create_value_node("RealLit",(yyvsp[0].reallit), yylineno, (int)(columnNumber - strlen((yyvsp[0].reallit))));(yyval.node)->loc = (yylsp[0]);}
#line 2326 "y.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 566 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2332 "y.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 567 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = NULL;}
#line 2338 "y.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 568 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = create_simple_node("Call", yylineno, (int)(columnNumber - strlen((yyvsp[-3].id))));
                                                                                  add_child((yyval.node), create_value_node("Id",(yyvsp[-3].id), yylineno, (int)(columnNumber- strlen((yyvsp[-3].id))-2)));
                                                                                  add_brother((yyval.node)->son,(yyvsp[-1].node));
                                                                                  (yyval.node)->loc = (yylsp[-2]);
                                                                                }
#line 2349 "y.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 574 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = NULL;}
#line 2355 "y.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 577 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2361 "y.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 578 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  add_brother((yyval.node),(yyvsp[0].node));
                                                                                }
#line 2370 "y.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 584 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2376 "y.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 585 "uccompiler.y" /* yacc.c:1661  */
    {
                                                                                  (yyval.node) = (yyvsp[-1].node);
                                                                                  add_brother((yyval.node),(yyvsp[0].node));
                                                                                  (yyval.node)->loc = (yylsp[-1]);
                                                                                }
#line 2386 "y.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 592 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = NULL;}
#line 2392 "y.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 593 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = create_value_node("Id",(yyvsp[0].id), yylineno, (int)(columnNumber - strlen((yyvsp[0].id))));(yyval.node)->loc = (yylsp[0]);}
#line 2398 "y.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 596 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = NULL;}
#line 2404 "y.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 597 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);(yyval.node)->loc = (yylsp[0]);}
#line 2410 "y.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 601 "uccompiler.y" /* yacc.c:1661  */
    {(yyval.node) = NULL;}
#line 2416 "y.tab.c" /* yacc.c:1661  */
    break;


#line 2420 "y.tab.c" /* yacc.c:1661  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 604 "uccompiler.y" /* yacc.c:1906  */


/* A função main() está do lado do lex */

void yyerror (char *s) {

    flag_error = 1;

    printf ("Line %d, col %d: %s: %s\n", yylineno, (int)(columnNumber - strlen(yytext)), s, yytext);
}
