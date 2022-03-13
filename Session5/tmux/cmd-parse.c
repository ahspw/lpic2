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
#line 19 "cmd-parse.y" /* yacc.c:339  */


#include <sys/types.h>

#include <ctype.h>
#include <errno.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>

#include "tmux.h"

static int			 yylex(void);
static int			 yyparse(void);
static int printflike(1,2)	 yyerror(const char *, ...);

static char			*yylex_token(int);
static char			*yylex_format(void);

struct cmd_parse_scope {
	int				 flag;
	TAILQ_ENTRY (cmd_parse_scope)	 entry;
};

enum cmd_parse_argument_type {
	CMD_PARSE_STRING,
	CMD_PARSE_COMMANDS,
	CMD_PARSE_PARSED_COMMANDS
};

struct cmd_parse_argument {
	enum cmd_parse_argument_type	 type;
	char				*string;
	struct cmd_parse_commands	*commands;
	struct cmd_list			*cmdlist;

	TAILQ_ENTRY(cmd_parse_argument)	 entry;
};
TAILQ_HEAD(cmd_parse_arguments, cmd_parse_argument);

struct cmd_parse_command {
	u_int				 line;
	struct cmd_parse_arguments	 arguments;

	TAILQ_ENTRY(cmd_parse_command)	 entry;
};
TAILQ_HEAD(cmd_parse_commands, cmd_parse_command);

struct cmd_parse_state {
	FILE				*f;

	const char			*buf;
	size_t				 len;
	size_t				 off;

	int				 condition;
	int				 eol;
	int				 eof;
	struct cmd_parse_input		*input;
	u_int				 escapes;

	char				*error;
	struct cmd_parse_commands	*commands;

	struct cmd_parse_scope		*scope;
	TAILQ_HEAD(, cmd_parse_scope)	 stack;
};
static struct cmd_parse_state parse_state;

static char	*cmd_parse_get_error(const char *, u_int, const char *);
static void	 cmd_parse_free_command(struct cmd_parse_command *);
static struct cmd_parse_commands *cmd_parse_new_commands(void);
static void	 cmd_parse_free_commands(struct cmd_parse_commands *);
static void	 cmd_parse_build_commands(struct cmd_parse_commands *,
		     struct cmd_parse_input *, struct cmd_parse_result *);
static void	 cmd_parse_print_commands(struct cmd_parse_input *,
		     struct cmd_list *);


#line 148 "cmd-parse.c" /* yacc.c:339  */

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
    ERROR = 258,
    HIDDEN = 259,
    IF = 260,
    ELSE = 261,
    ELIF = 262,
    ENDIF = 263,
    FORMAT = 264,
    TOKEN = 265,
    EQUALS = 266
  };
#endif
/* Tokens.  */
#define ERROR 258
#define HIDDEN 259
#define IF 260
#define ELSE 261
#define ELIF 262
#define ENDIF 263
#define FORMAT 264
#define TOKEN 265
#define EQUALS 266

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 102 "cmd-parse.y" /* yacc.c:355  */

	char					 *token;
	struct cmd_parse_arguments		 *arguments;
	struct cmd_parse_argument		 *argument;
	int					  flag;
	struct {
		int				  flag;
		struct cmd_parse_commands	 *commands;
	} elif;
	struct cmd_parse_commands		 *commands;
	struct cmd_parse_command		 *command;

#line 220 "cmd-parse.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 237 "cmd-parse.c" /* yacc.c:358  */

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
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   104

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  16
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  75

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   266

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      12,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    13,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    14,     2,    15,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   134,   134,   135,   142,   146,   154,   158,   163,   174,
     186,   190,   195,   219,   220,   222,   233,   244,   258,   270,
     283,   293,   302,   312,   326,   343,   354,   372,   383,   387,
     393,   407,   412,   420,   434,   452,   461,   471,   485,   502,
     513,   531,   538,   544,   550,   556,   563,   567
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ERROR", "HIDDEN", "IF", "ELSE", "ELIF",
  "ENDIF", "FORMAT", "TOKEN", "EQUALS", "'\\n'", "';'", "'{'", "'}'",
  "$accept", "lines", "statements", "statement", "format", "expanded",
  "optional_assignment", "assignment", "hidden_assignment", "if_open",
  "if_else", "if_elif", "if_close", "condition", "elif", "commands",
  "command", "condition1", "elif1", "arguments", "argument",
  "argument_statements", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,    10,    59,   123,   125
};
# endif

#define YYPACT_NINF -32

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-32)))

#define YYTABLE_NINF -15

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      49,     3,    14,   -32,    33,    49,    29,    47,    60,   -32,
       4,   -32,    35,   -32,   -32,   -32,   -32,   -32,   -32,   -32,
     -32,    68,   -32,    83,    81,    38,     5,    17,   -32,   -32,
     -32,    81,   -32,    83,    71,   -32,    14,   -32,    38,    38,
     -32,    -1,   -32,   -32,    81,    40,   -32,   -32,    76,    86,
     -32,    -1,   -32,    32,    58,    38,   -32,    84,   -32,    81,
      81,    88,   -32,   -32,   -32,    32,   -32,    79,    62,    81,
     -32,   -32,   -32,    79,   -32
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,    15,     0,     3,     0,     0,    32,     7,
      13,     8,     9,    27,    31,    16,    10,    11,    12,    17,
       1,     0,     4,    33,     6,    13,     0,    28,     5,    43,
      44,     6,    34,    41,     6,    18,     0,    20,    13,    13,
      35,     0,    30,    29,     6,     0,    45,    42,     0,     0,
      21,     0,    19,     0,    39,    13,    37,     0,    46,     6,
       6,     0,    23,    36,    40,     0,    47,     6,    25,     6,
      38,    22,    26,     6,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,   -23,    -5,   -32,    59,   -32,   -32,   -32,    -8,
     -31,   -30,    -9,   -32,   -18,    -4,    74,    75,    50,    70,
     -32,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    18,    19,     7,     8,     9,    10,
      38,    39,    40,    11,    51,    12,    13,    14,    41,    32,
      33,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      21,    34,    25,    48,    49,    35,    26,    37,    44,     2,
      55,    35,    36,    37,    15,     3,    24,    25,    27,    25,
      61,    26,     2,    16,    17,    50,    45,   -13,     3,    21,
      25,    25,    56,    20,    53,    54,    67,    68,    49,    57,
      37,    22,    62,     2,    63,    27,    73,    25,    27,     3,
      72,    65,    22,     1,     2,    58,    70,    23,    71,   -13,
       3,    -6,    21,    21,    74,    36,     1,     2,    21,    36,
     -14,    27,   -13,     3,    -6,     1,     2,    35,    36,    37,
      28,   -13,     3,     1,     2,     1,     2,    37,    59,   -13,
       3,   -13,     3,    29,    30,    52,    28,    31,    60,    66,
      69,    42,    43,    47,    64
};

static const yytype_uint8 yycheck[] =
{
       5,    24,    10,    34,    34,     6,    10,     8,    31,     5,
      41,     6,     7,     8,    11,    11,    12,    25,    13,    27,
      51,    25,     5,     9,    10,    34,    31,    10,    11,    34,
      38,    39,    41,     0,    38,    39,    59,    60,    68,    44,
       8,    12,    51,     5,    53,    13,    69,    55,    13,    11,
      68,    55,    12,     4,     5,    15,    65,    10,    67,    10,
      11,    12,    67,    68,    73,     7,     4,     5,    73,     7,
      10,    13,    10,    11,    12,     4,     5,     6,     7,     8,
      12,    10,    11,     4,     5,     4,     5,     8,    12,    10,
      11,    10,    11,    10,    11,    36,    12,    14,    12,    15,
      12,    27,    27,    33,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    11,    17,    18,    19,    22,    23,    24,
      25,    29,    31,    32,    33,    11,     9,    10,    20,    21,
       0,    19,    12,    10,    12,    25,    31,    13,    12,    10,
      11,    14,    35,    36,    18,     6,     7,     8,    26,    27,
      28,    34,    32,    33,    18,    19,    37,    35,    26,    27,
      28,    30,    21,    31,    31,    26,    28,    19,    15,    12,
      12,    26,    28,    28,    34,    31,    15,    18,    18,    12,
      28,    28,    30,    18,    28
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    16,    17,    17,    18,    18,    19,    19,    19,    19,
      20,    20,    21,    22,    22,    23,    24,    25,    26,    27,
      28,    29,    29,    29,    29,    30,    30,    31,    31,    31,
      31,    31,    32,    32,    32,    33,    33,    33,    33,    34,
      34,    35,    35,    36,    36,    36,    37,    37
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     2,     3,     0,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     2,     2,     1,     2,
       1,     4,     7,     5,     8,     3,     4,     1,     2,     3,
       3,     1,     1,     2,     3,     3,     5,     4,     6,     2,
       3,     1,     2,     1,     1,     2,     2,     3
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
        case 3:
#line 136 "cmd-parse.y" /* yacc.c:1646  */
    {
			struct cmd_parse_state	*ps = &parse_state;

			ps->commands = (yyvsp[0].commands);
		}
#line 1370 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 4:
#line 143 "cmd-parse.y" /* yacc.c:1646  */
    {
			(yyval.commands) = (yyvsp[-1].commands);
		}
#line 1378 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 5:
#line 147 "cmd-parse.y" /* yacc.c:1646  */
    {
			(yyval.commands) = (yyvsp[-2].commands);
			TAILQ_CONCAT((yyval.commands), (yyvsp[-1].commands), entry);
			free((yyvsp[-1].commands));
		}
#line 1388 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 6:
#line 154 "cmd-parse.y" /* yacc.c:1646  */
    {
			(yyval.commands) = xmalloc (sizeof *(yyval.commands));
			TAILQ_INIT((yyval.commands));
		}
#line 1397 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 7:
#line 159 "cmd-parse.y" /* yacc.c:1646  */
    {
			(yyval.commands) = xmalloc (sizeof *(yyval.commands));
			TAILQ_INIT((yyval.commands));
		}
#line 1406 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 8:
#line 164 "cmd-parse.y" /* yacc.c:1646  */
    {
			struct cmd_parse_state	*ps = &parse_state;

			if (ps->scope == NULL || ps->scope->flag)
				(yyval.commands) = (yyvsp[0].commands);
			else {
				(yyval.commands) = cmd_parse_new_commands();
				cmd_parse_free_commands((yyvsp[0].commands));
			}
		}
#line 1421 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 9:
#line 175 "cmd-parse.y" /* yacc.c:1646  */
    {
			struct cmd_parse_state	*ps = &parse_state;

			if (ps->scope == NULL || ps->scope->flag)
				(yyval.commands) = (yyvsp[0].commands);
			else {
				(yyval.commands) = cmd_parse_new_commands();
				cmd_parse_free_commands((yyvsp[0].commands));
			}
		}
#line 1436 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 10:
#line 187 "cmd-parse.y" /* yacc.c:1646  */
    {
			(yyval.token) = (yyvsp[0].token);
		}
#line 1444 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 11:
#line 191 "cmd-parse.y" /* yacc.c:1646  */
    {
			(yyval.token) = (yyvsp[0].token);
		}
#line 1452 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 12:
#line 196 "cmd-parse.y" /* yacc.c:1646  */
    {
			struct cmd_parse_state	*ps = &parse_state;
			struct cmd_parse_input	*pi = ps->input;
			struct format_tree	*ft;
			struct client		*c = pi->c;
			struct cmd_find_state	*fsp;
			struct cmd_find_state	 fs;
			int			 flags = FORMAT_NOJOBS;

			if (cmd_find_valid_state(&pi->fs))
				fsp = &pi->fs;
			else {
				cmd_find_from_client(&fs, c, 0);
				fsp = &fs;
			}
			ft = format_create(NULL, pi->item, FORMAT_NONE, flags);
			format_defaults(ft, c, fsp->s, fsp->wl, fsp->wp);

			(yyval.token) = format_expand(ft, (yyvsp[0].token));
			format_free(ft);
			free((yyvsp[0].token));
		}
#line 1479 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 15:
#line 223 "cmd-parse.y" /* yacc.c:1646  */
    {
			struct cmd_parse_state	*ps = &parse_state;
			int			 flags = ps->input->flags;

			if ((~flags & CMD_PARSE_PARSEONLY) &&
			    (ps->scope == NULL || ps->scope->flag))
				environ_put(global_environ, (yyvsp[0].token), 0);
			free((yyvsp[0].token));
		}
#line 1493 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 16:
#line 234 "cmd-parse.y" /* yacc.c:1646  */
    {
			struct cmd_parse_state	*ps = &parse_state;
			int			 flags = ps->input->flags;

			if ((~flags & CMD_PARSE_PARSEONLY) &&
			    (ps->scope == NULL || ps->scope->flag))
				environ_put(global_environ, (yyvsp[0].token), ENVIRON_HIDDEN);
			free((yyvsp[0].token));
		}
#line 1507 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 17:
#line 245 "cmd-parse.y" /* yacc.c:1646  */
    {
			struct cmd_parse_state	*ps = &parse_state;
			struct cmd_parse_scope	*scope;

			scope = xmalloc(sizeof *scope);
			(yyval.flag) = scope->flag = format_true((yyvsp[0].token));
			free((yyvsp[0].token));

			if (ps->scope != NULL)
				TAILQ_INSERT_HEAD(&ps->stack, ps->scope, entry);
			ps->scope = scope;
		}
#line 1524 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 18:
#line 259 "cmd-parse.y" /* yacc.c:1646  */
    {
			struct cmd_parse_state	*ps = &parse_state;
			struct cmd_parse_scope	*scope;

			scope = xmalloc(sizeof *scope);
			scope->flag = !ps->scope->flag;

			free(ps->scope);
			ps->scope = scope;
		}
#line 1539 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 19:
#line 271 "cmd-parse.y" /* yacc.c:1646  */
    {
			struct cmd_parse_state	*ps = &parse_state;
			struct cmd_parse_scope	*scope;

			scope = xmalloc(sizeof *scope);
			(yyval.flag) = scope->flag = format_true((yyvsp[0].token));
			free((yyvsp[0].token));

			free(ps->scope);
			ps->scope = scope;
		}
#line 1555 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 20:
#line 284 "cmd-parse.y" /* yacc.c:1646  */
    {
			struct cmd_parse_state	*ps = &parse_state;

			free(ps->scope);
			ps->scope = TAILQ_FIRST(&ps->stack);
			if (ps->scope != NULL)
				TAILQ_REMOVE(&ps->stack, ps->scope, entry);
		}
#line 1568 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 21:
#line 294 "cmd-parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-3].flag))
				(yyval.commands) = (yyvsp[-1].commands);
			else {
				(yyval.commands) = cmd_parse_new_commands();
				cmd_parse_free_commands((yyvsp[-1].commands));
			}
		}
#line 1581 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 22:
#line 303 "cmd-parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-6].flag)) {
				(yyval.commands) = (yyvsp[-4].commands);
				cmd_parse_free_commands((yyvsp[-1].commands));
			} else {
				(yyval.commands) = (yyvsp[-1].commands);
				cmd_parse_free_commands((yyvsp[-4].commands));
			}
		}
#line 1595 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 23:
#line 313 "cmd-parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-4].flag)) {
				(yyval.commands) = (yyvsp[-2].commands);
				cmd_parse_free_commands((yyvsp[-1].elif).commands);
			} else if ((yyvsp[-1].elif).flag) {
				(yyval.commands) = (yyvsp[-1].elif).commands;
				cmd_parse_free_commands((yyvsp[-2].commands));
			} else {
				(yyval.commands) = cmd_parse_new_commands();
				cmd_parse_free_commands((yyvsp[-2].commands));
				cmd_parse_free_commands((yyvsp[-1].elif).commands);
			}
		}
#line 1613 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 24:
#line 327 "cmd-parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-7].flag)) {
				(yyval.commands) = (yyvsp[-5].commands);
				cmd_parse_free_commands((yyvsp[-4].elif).commands);
				cmd_parse_free_commands((yyvsp[-1].commands));
			} else if ((yyvsp[-4].elif).flag) {
				(yyval.commands) = (yyvsp[-4].elif).commands;
				cmd_parse_free_commands((yyvsp[-5].commands));
				cmd_parse_free_commands((yyvsp[-1].commands));
			} else {
				(yyval.commands) = (yyvsp[-1].commands);
				cmd_parse_free_commands((yyvsp[-5].commands));
				cmd_parse_free_commands((yyvsp[-4].elif).commands);
			}
		}
#line 1633 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 25:
#line 344 "cmd-parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-2].flag)) {
				(yyval.elif).flag = 1;
				(yyval.elif).commands = (yyvsp[0].commands);
			} else {
				(yyval.elif).flag = 0;
				(yyval.elif).commands = cmd_parse_new_commands();
				cmd_parse_free_commands((yyvsp[0].commands));
			}
		}
#line 1648 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 26:
#line 355 "cmd-parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-3].flag)) {
				(yyval.elif).flag = 1;
				(yyval.elif).commands = (yyvsp[-1].commands);
				cmd_parse_free_commands((yyvsp[0].elif).commands);
			} else if ((yyvsp[0].elif).flag) {
				(yyval.elif).flag = 1;
				(yyval.elif).commands = (yyvsp[0].elif).commands;
				cmd_parse_free_commands((yyvsp[-1].commands));
			} else {
				(yyval.elif).flag = 0;
				(yyval.elif).commands = cmd_parse_new_commands();
				cmd_parse_free_commands((yyvsp[-1].commands));
				cmd_parse_free_commands((yyvsp[0].elif).commands);
			}
		}
#line 1669 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 27:
#line 373 "cmd-parse.y" /* yacc.c:1646  */
    {
			struct cmd_parse_state	*ps = &parse_state;

			(yyval.commands) = cmd_parse_new_commands();
			if (!TAILQ_EMPTY(&(yyvsp[0].command)->arguments) &&
			    (ps->scope == NULL || ps->scope->flag))
				TAILQ_INSERT_TAIL((yyval.commands), (yyvsp[0].command), entry);
			else
				cmd_parse_free_command((yyvsp[0].command));
		}
#line 1684 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 28:
#line 384 "cmd-parse.y" /* yacc.c:1646  */
    {
			(yyval.commands) = (yyvsp[-1].commands);
		}
#line 1692 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 29:
#line 388 "cmd-parse.y" /* yacc.c:1646  */
    {
			(yyval.commands) = (yyvsp[-2].commands);
			TAILQ_CONCAT((yyval.commands), (yyvsp[0].commands), entry);
			free((yyvsp[0].commands));
		}
#line 1702 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 30:
#line 394 "cmd-parse.y" /* yacc.c:1646  */
    {
			struct cmd_parse_state	*ps = &parse_state;

			if (!TAILQ_EMPTY(&(yyvsp[0].command)->arguments) &&
			    (ps->scope == NULL || ps->scope->flag)) {
				(yyval.commands) = (yyvsp[-2].commands);
				TAILQ_INSERT_TAIL((yyval.commands), (yyvsp[0].command), entry);
			} else {
				(yyval.commands) = cmd_parse_new_commands();
				cmd_parse_free_commands((yyvsp[-2].commands));
				cmd_parse_free_command((yyvsp[0].command));
			}
		}
#line 1720 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 31:
#line 408 "cmd-parse.y" /* yacc.c:1646  */
    {
			(yyval.commands) = (yyvsp[0].commands);
		}
#line 1728 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 32:
#line 413 "cmd-parse.y" /* yacc.c:1646  */
    {
			struct cmd_parse_state	*ps = &parse_state;

			(yyval.command) = xcalloc(1, sizeof *(yyval.command));
			(yyval.command)->line = ps->input->line;
			TAILQ_INIT(&(yyval.command)->arguments);
		}
#line 1740 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 33:
#line 421 "cmd-parse.y" /* yacc.c:1646  */
    {
			struct cmd_parse_state		*ps = &parse_state;
			struct cmd_parse_argument	*arg;

			(yyval.command) = xcalloc(1, sizeof *(yyval.command));
			(yyval.command)->line = ps->input->line;
			TAILQ_INIT(&(yyval.command)->arguments);

			arg = xcalloc(1, sizeof *arg);
			arg->type = CMD_PARSE_STRING;
			arg->string = (yyvsp[0].token);
			TAILQ_INSERT_HEAD(&(yyval.command)->arguments, arg, entry);
		}
#line 1758 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 34:
#line 435 "cmd-parse.y" /* yacc.c:1646  */
    {
			struct cmd_parse_state		*ps = &parse_state;
			struct cmd_parse_argument	*arg;

			(yyval.command) = xcalloc(1, sizeof *(yyval.command));
			(yyval.command)->line = ps->input->line;
			TAILQ_INIT(&(yyval.command)->arguments);

			TAILQ_CONCAT(&(yyval.command)->arguments, (yyvsp[0].arguments), entry);
			free((yyvsp[0].arguments));

			arg = xcalloc(1, sizeof *arg);
			arg->type = CMD_PARSE_STRING;
			arg->string = (yyvsp[-1].token);
			TAILQ_INSERT_HEAD(&(yyval.command)->arguments, arg, entry);
		}
#line 1779 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 35:
#line 453 "cmd-parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-2].flag))
				(yyval.commands) = (yyvsp[-1].commands);
			else {
				(yyval.commands) = cmd_parse_new_commands();
				cmd_parse_free_commands((yyvsp[-1].commands));
			}
		}
#line 1792 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 36:
#line 462 "cmd-parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-4].flag)) {
				(yyval.commands) = (yyvsp[-3].commands);
				cmd_parse_free_commands((yyvsp[-1].commands));
			} else {
				(yyval.commands) = (yyvsp[-1].commands);
				cmd_parse_free_commands((yyvsp[-3].commands));
			}
		}
#line 1806 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 37:
#line 472 "cmd-parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-3].flag)) {
				(yyval.commands) = (yyvsp[-2].commands);
				cmd_parse_free_commands((yyvsp[-1].elif).commands);
			} else if ((yyvsp[-1].elif).flag) {
				(yyval.commands) = (yyvsp[-1].elif).commands;
				cmd_parse_free_commands((yyvsp[-2].commands));
			} else {
				(yyval.commands) = cmd_parse_new_commands();
				cmd_parse_free_commands((yyvsp[-2].commands));
				cmd_parse_free_commands((yyvsp[-1].elif).commands);
			}
		}
#line 1824 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 38:
#line 486 "cmd-parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-5].flag)) {
				(yyval.commands) = (yyvsp[-4].commands);
				cmd_parse_free_commands((yyvsp[-3].elif).commands);
				cmd_parse_free_commands((yyvsp[-1].commands));
			} else if ((yyvsp[-3].elif).flag) {
				(yyval.commands) = (yyvsp[-3].elif).commands;
				cmd_parse_free_commands((yyvsp[-4].commands));
				cmd_parse_free_commands((yyvsp[-1].commands));
			} else {
				(yyval.commands) = (yyvsp[-1].commands);
				cmd_parse_free_commands((yyvsp[-4].commands));
				cmd_parse_free_commands((yyvsp[-3].elif).commands);
			}
		}
#line 1844 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 39:
#line 503 "cmd-parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-1].flag)) {
				(yyval.elif).flag = 1;
				(yyval.elif).commands = (yyvsp[0].commands);
			} else {
				(yyval.elif).flag = 0;
				(yyval.elif).commands = cmd_parse_new_commands();
				cmd_parse_free_commands((yyvsp[0].commands));
			}
		}
#line 1859 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 40:
#line 514 "cmd-parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-2].flag)) {
				(yyval.elif).flag = 1;
				(yyval.elif).commands = (yyvsp[-1].commands);
				cmd_parse_free_commands((yyvsp[0].elif).commands);
			} else if ((yyvsp[0].elif).flag) {
				(yyval.elif).flag = 1;
				(yyval.elif).commands = (yyvsp[0].elif).commands;
				cmd_parse_free_commands((yyvsp[-1].commands));
			} else {
				(yyval.elif).flag = 0;
				(yyval.elif).commands = cmd_parse_new_commands();
				cmd_parse_free_commands((yyvsp[-1].commands));
				cmd_parse_free_commands((yyvsp[0].elif).commands);
			}
		}
#line 1880 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 41:
#line 532 "cmd-parse.y" /* yacc.c:1646  */
    {
			(yyval.arguments) = xcalloc(1, sizeof *(yyval.arguments));
			TAILQ_INIT((yyval.arguments));

			TAILQ_INSERT_HEAD((yyval.arguments), (yyvsp[0].argument), entry);
		}
#line 1891 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 42:
#line 539 "cmd-parse.y" /* yacc.c:1646  */
    {
			TAILQ_INSERT_HEAD((yyvsp[0].arguments), (yyvsp[-1].argument), entry);
			(yyval.arguments) = (yyvsp[0].arguments);
		}
#line 1900 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 43:
#line 545 "cmd-parse.y" /* yacc.c:1646  */
    {
			(yyval.argument) = xcalloc(1, sizeof *(yyval.argument));
			(yyval.argument)->type = CMD_PARSE_STRING;
			(yyval.argument)->string = (yyvsp[0].token);
		}
#line 1910 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 44:
#line 551 "cmd-parse.y" /* yacc.c:1646  */
    {
			(yyval.argument) = xcalloc(1, sizeof *(yyval.argument));
			(yyval.argument)->type = CMD_PARSE_STRING;
			(yyval.argument)->string = (yyvsp[0].token);
		}
#line 1920 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 45:
#line 557 "cmd-parse.y" /* yacc.c:1646  */
    {
			(yyval.argument) = xcalloc(1, sizeof *(yyval.argument));
			(yyval.argument)->type = CMD_PARSE_COMMANDS;
			(yyval.argument)->commands = (yyvsp[0].commands);
		}
#line 1930 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 46:
#line 564 "cmd-parse.y" /* yacc.c:1646  */
    {
				(yyval.commands) = (yyvsp[-1].commands);
			}
#line 1938 "cmd-parse.c" /* yacc.c:1646  */
    break;

  case 47:
#line 568 "cmd-parse.y" /* yacc.c:1646  */
    {
				(yyval.commands) = (yyvsp[-2].commands);
				TAILQ_CONCAT((yyval.commands), (yyvsp[-1].commands), entry);
				free((yyvsp[-1].commands));
			}
#line 1948 "cmd-parse.c" /* yacc.c:1646  */
    break;


#line 1952 "cmd-parse.c" /* yacc.c:1646  */
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
#line 574 "cmd-parse.y" /* yacc.c:1906  */


static char *
cmd_parse_get_error(const char *file, u_int line, const char *error)
{
	char	*s;

	if (file == NULL)
		s = xstrdup(error);
	else
		xasprintf(&s, "%s:%u: %s", file, line, error);
	return (s);
}

static void
cmd_parse_print_commands(struct cmd_parse_input *pi, struct cmd_list *cmdlist)
{
	char	*s;

	if (pi->item == NULL || (~pi->flags & CMD_PARSE_VERBOSE))
		return;
	s = cmd_list_print(cmdlist, 0);
	if (pi->file != NULL)
		cmdq_print(pi->item, "%s:%u: %s", pi->file, pi->line, s);
	else
		cmdq_print(pi->item, "%u: %s", pi->line, s);
	free(s);
}

static void
cmd_parse_free_argument(struct cmd_parse_argument *arg)
{
	switch (arg->type) {
	case CMD_PARSE_STRING:
		free(arg->string);
		break;
	case CMD_PARSE_COMMANDS:
		cmd_parse_free_commands(arg->commands);
		break;
	case CMD_PARSE_PARSED_COMMANDS:
		cmd_list_free(arg->cmdlist);
		break;
	}
	free(arg);
}

static void
cmd_parse_free_arguments(struct cmd_parse_arguments *args)
{
	struct cmd_parse_argument	*arg, *arg1;

	TAILQ_FOREACH_SAFE(arg, args, entry, arg1) {
		TAILQ_REMOVE(args, arg, entry);
		cmd_parse_free_argument(arg);
	}
}

static void
cmd_parse_free_command(struct cmd_parse_command *cmd)
{
	cmd_parse_free_arguments(&cmd->arguments);
	free(cmd);
}

static struct cmd_parse_commands *
cmd_parse_new_commands(void)
{
	struct cmd_parse_commands	*cmds;

	cmds = xmalloc(sizeof *cmds);
	TAILQ_INIT(cmds);
	return (cmds);
}

static void
cmd_parse_free_commands(struct cmd_parse_commands *cmds)
{
	struct cmd_parse_command	*cmd, *cmd1;

	TAILQ_FOREACH_SAFE(cmd, cmds, entry, cmd1) {
		TAILQ_REMOVE(cmds, cmd, entry);
		cmd_parse_free_command(cmd);
	}
	free(cmds);
}

static struct cmd_parse_commands *
cmd_parse_run_parser(char **cause)
{
	struct cmd_parse_state	*ps = &parse_state;
	struct cmd_parse_scope	*scope, *scope1;
	int			 retval;

	ps->commands = NULL;
	TAILQ_INIT(&ps->stack);

	retval = yyparse();
	TAILQ_FOREACH_SAFE(scope, &ps->stack, entry, scope1) {
		TAILQ_REMOVE(&ps->stack, scope, entry);
		free(scope);
	}
	if (retval != 0) {
		*cause = ps->error;
		return (NULL);
	}

	if (ps->commands == NULL)
		return (cmd_parse_new_commands());
	return (ps->commands);
}

static struct cmd_parse_commands *
cmd_parse_do_file(FILE *f, struct cmd_parse_input *pi, char **cause)
{
	struct cmd_parse_state	*ps = &parse_state;

	memset(ps, 0, sizeof *ps);
	ps->input = pi;
	ps->f = f;
	return (cmd_parse_run_parser(cause));
}

static struct cmd_parse_commands *
cmd_parse_do_buffer(const char *buf, size_t len, struct cmd_parse_input *pi,
    char **cause)
{
	struct cmd_parse_state	*ps = &parse_state;

	memset(ps, 0, sizeof *ps);
	ps->input = pi;
	ps->buf = buf;
	ps->len = len;
	return (cmd_parse_run_parser(cause));
}

static void
cmd_parse_log_commands(struct cmd_parse_commands *cmds, const char *prefix)
{
	struct cmd_parse_command	*cmd;
	struct cmd_parse_argument	*arg;
	u_int				 i, j;
	char				*s;

	i = 0;
	TAILQ_FOREACH(cmd, cmds, entry) {
		j = 0;
		TAILQ_FOREACH(arg, &cmd->arguments, entry) {
			switch (arg->type) {
			case CMD_PARSE_STRING:
				log_debug("%s %u:%u: %s", prefix, i, j,
				    arg->string);
				break;
			case CMD_PARSE_COMMANDS:
				xasprintf(&s, "%s %u:%u", prefix, i, j);
				cmd_parse_log_commands(arg->commands, s);
				free(s);
				break;
			case CMD_PARSE_PARSED_COMMANDS:
				s = cmd_list_print(arg->cmdlist, 0);
				log_debug("%s %u:%u: %s", prefix, i, j, s);
				free(s);
				break;
			}
			j++;
		}
		i++;
	}
}

static int
cmd_parse_expand_alias(struct cmd_parse_command *cmd,
    struct cmd_parse_input *pi, struct cmd_parse_result *pr)
{
	struct cmd_parse_argument	*arg, *arg1, *first;
	struct cmd_parse_commands	*cmds;
	struct cmd_parse_command	*last;
	char				*alias, *name, *cause;

	if (pi->flags & CMD_PARSE_NOALIAS)
		return (0);
	memset(pr, 0, sizeof *pr);

	first = TAILQ_FIRST(&cmd->arguments);
	if (first == NULL || first->type != CMD_PARSE_STRING) {
		pr->status = CMD_PARSE_SUCCESS;
		pr->cmdlist = cmd_list_new();
		return (1);
	}
	name = first->string;

	alias = cmd_get_alias(name);
	if (alias == NULL)
		return (0);
	log_debug("%s: %u alias %s = %s", __func__, pi->line, name, alias);

	cmds = cmd_parse_do_buffer(alias, strlen(alias), pi, &cause);
	free(alias);
	if (cmds == NULL) {
		pr->status = CMD_PARSE_ERROR;
		pr->error = cause;
		return (1);
	}

	last = TAILQ_LAST(cmds, cmd_parse_commands);
	if (last == NULL) {
		pr->status = CMD_PARSE_SUCCESS;
		pr->cmdlist = cmd_list_new();
		return (1);
	}

	TAILQ_REMOVE(&cmd->arguments, first, entry);
	cmd_parse_free_argument(first);

	TAILQ_FOREACH_SAFE(arg, &cmd->arguments, entry, arg1) {
		TAILQ_REMOVE(&cmd->arguments, arg, entry);
		TAILQ_INSERT_TAIL(&last->arguments, arg, entry);
	}
	cmd_parse_log_commands(cmds, __func__);

	pi->flags |= CMD_PARSE_NOALIAS;
	cmd_parse_build_commands(cmds, pi, pr);
	pi->flags &= ~CMD_PARSE_NOALIAS;
	return (1);
}

static void
cmd_parse_build_command(struct cmd_parse_command *cmd,
    struct cmd_parse_input *pi, struct cmd_parse_result *pr)
{
	struct cmd_parse_argument	*arg;
	struct cmd			*add;
	char				*cause;
	struct args_value		*values = NULL;
	u_int				 count = 0, idx;

	memset(pr, 0, sizeof *pr);

	if (cmd_parse_expand_alias(cmd, pi, pr))
		return;

	TAILQ_FOREACH(arg, &cmd->arguments, entry) {
		values = xrecallocarray(values, count, count + 1,
		    sizeof *values);
		switch (arg->type) {
		case CMD_PARSE_STRING:
			values[count].type = ARGS_STRING;
			values[count].string = xstrdup(arg->string);
			break;
		case CMD_PARSE_COMMANDS:
			cmd_parse_build_commands(arg->commands, pi, pr);
			if (pr->status != CMD_PARSE_SUCCESS)
				goto out;
			values[count].type = ARGS_COMMANDS;
			values[count].cmdlist = pr->cmdlist;
			break;
		case CMD_PARSE_PARSED_COMMANDS:
			values[count].type = ARGS_COMMANDS;
			values[count].cmdlist = arg->cmdlist;
			values[count].cmdlist->references++;
			break;
		}
		count++;
	}

	add = cmd_parse(values, count, pi->file, pi->line, &cause);
	if (add == NULL) {
		pr->status = CMD_PARSE_ERROR;
		pr->error = cmd_parse_get_error(pi->file, pi->line, cause);
		free(cause);
		goto out;
	}
	pr->status = CMD_PARSE_SUCCESS;
	pr->cmdlist = cmd_list_new();
	cmd_list_append(pr->cmdlist, add);

out:
	for (idx = 0; idx < count; idx++)
		args_free_value(&values[idx]);
	free(values);
}

static void
cmd_parse_build_commands(struct cmd_parse_commands *cmds,
    struct cmd_parse_input *pi, struct cmd_parse_result *pr)
{
	struct cmd_parse_command	*cmd;
	u_int				 line = UINT_MAX;
	struct cmd_list			*current = NULL, *result;
	char				*s;

	memset(pr, 0, sizeof *pr);

	/* Check for an empty list. */
	if (TAILQ_EMPTY(cmds)) {
		pr->status = CMD_PARSE_SUCCESS;
		pr->cmdlist = cmd_list_new();
		return;
	}
	cmd_parse_log_commands(cmds, __func__);

	/*
	 * Parse each command into a command list. Create a new command list
	 * for each line (unless the flag is set) so they get a new group (so
	 * the queue knows which ones to remove if a command fails when
	 * executed).
	 */
	result = cmd_list_new();
	TAILQ_FOREACH(cmd, cmds, entry) {
		if (((~pi->flags & CMD_PARSE_ONEGROUP) && cmd->line != line)) {
			if (current != NULL) {
				cmd_parse_print_commands(pi, current);
				cmd_list_move(result, current);
				cmd_list_free(current);
			}
			current = cmd_list_new();
		}
		if (current == NULL)
			current = cmd_list_new();
		line = pi->line = cmd->line;

		cmd_parse_build_command(cmd, pi, pr);
		if (pr->status != CMD_PARSE_SUCCESS) {
			cmd_list_free(result);
			cmd_list_free(current);
			return;
		}
		cmd_list_append_all(current, pr->cmdlist);
		cmd_list_free(pr->cmdlist);
	}
	if (current != NULL) {
		cmd_parse_print_commands(pi, current);
		cmd_list_move(result, current);
		cmd_list_free(current);
	}

	s = cmd_list_print(result, 0);
	log_debug("%s: %s", __func__, s);
	free(s);

	pr->status = CMD_PARSE_SUCCESS;
	pr->cmdlist = result;
}

struct cmd_parse_result *
cmd_parse_from_file(FILE *f, struct cmd_parse_input *pi)
{
	static struct cmd_parse_result	 pr;
	struct cmd_parse_input		 input;
	struct cmd_parse_commands	*cmds;
	char				*cause;

	if (pi == NULL) {
		memset(&input, 0, sizeof input);
		pi = &input;
	}
	memset(&pr, 0, sizeof pr);

	cmds = cmd_parse_do_file(f, pi, &cause);
	if (cmds == NULL) {
		pr.status = CMD_PARSE_ERROR;
		pr.error = cause;
		return (&pr);
	}
	cmd_parse_build_commands(cmds, pi, &pr);
	cmd_parse_free_commands(cmds);
	return (&pr);

}

struct cmd_parse_result *
cmd_parse_from_string(const char *s, struct cmd_parse_input *pi)
{
	struct cmd_parse_input	input;

	if (pi == NULL) {
		memset(&input, 0, sizeof input);
		pi = &input;
	}

	/*
	 * When parsing a string, put commands in one group even if there are
	 * multiple lines. This means { a \n b } is identical to "a ; b" when
	 * given as an argument to another command.
	 */
	pi->flags |= CMD_PARSE_ONEGROUP;
	return (cmd_parse_from_buffer(s, strlen(s), pi));
}

enum cmd_parse_status
cmd_parse_and_insert(const char *s, struct cmd_parse_input *pi,
    struct cmdq_item *after, struct cmdq_state *state, char **error)
{
	struct cmd_parse_result	*pr;
	struct cmdq_item	*item;

	pr = cmd_parse_from_string(s, pi);
	switch (pr->status) {
	case CMD_PARSE_ERROR:
		if (error != NULL)
			*error = pr->error;
		else
			free(pr->error);
		break;
	case CMD_PARSE_SUCCESS:
		item = cmdq_get_command(pr->cmdlist, state);
		cmdq_insert_after(after, item);
		cmd_list_free(pr->cmdlist);
		break;
	}
	return (pr->status);
}

enum cmd_parse_status
cmd_parse_and_append(const char *s, struct cmd_parse_input *pi,
    struct client *c, struct cmdq_state *state, char **error)
{
	struct cmd_parse_result	*pr;
	struct cmdq_item	*item;

	pr = cmd_parse_from_string(s, pi);
	switch (pr->status) {
	case CMD_PARSE_ERROR:
		if (error != NULL)
			*error = pr->error;
		else
			free(pr->error);
		break;
	case CMD_PARSE_SUCCESS:
		item = cmdq_get_command(pr->cmdlist, state);
		cmdq_append(c, item);
		cmd_list_free(pr->cmdlist);
		break;
	}
	return (pr->status);
}

struct cmd_parse_result *
cmd_parse_from_buffer(const void *buf, size_t len, struct cmd_parse_input *pi)
{
	static struct cmd_parse_result	 pr;
	struct cmd_parse_input		 input;
	struct cmd_parse_commands	*cmds;
	char				*cause;

	if (pi == NULL) {
		memset(&input, 0, sizeof input);
		pi = &input;
	}
	memset(&pr, 0, sizeof pr);

	if (len == 0) {
		pr.status = CMD_PARSE_SUCCESS;
		pr.cmdlist = cmd_list_new();
		return (&pr);
	}

	cmds = cmd_parse_do_buffer(buf, len, pi, &cause);
	if (cmds == NULL) {
		pr.status = CMD_PARSE_ERROR;
		pr.error = cause;
		return (&pr);
	}
	cmd_parse_build_commands(cmds, pi, &pr);
	cmd_parse_free_commands(cmds);
	return (&pr);
}

struct cmd_parse_result *
cmd_parse_from_arguments(struct args_value *values, u_int count,
    struct cmd_parse_input *pi)
{
	static struct cmd_parse_result	 pr;
	struct cmd_parse_input		 input;
	struct cmd_parse_commands	*cmds;
	struct cmd_parse_command	*cmd;
	struct cmd_parse_argument	*arg;
	u_int				 i;
	char				*copy;
	size_t				 size;
	int				 end;

	/*
	 * The commands are already split up into arguments, so just separate
	 * into a set of commands by ';'.
	 */

	if (pi == NULL) {
		memset(&input, 0, sizeof input);
		pi = &input;
	}
	memset(&pr, 0, sizeof pr);

	cmds = cmd_parse_new_commands();

	cmd = xcalloc(1, sizeof *cmd);
	cmd->line = pi->line;
	TAILQ_INIT(&cmd->arguments);

	for (i = 0; i < count; i++) {
		end = 0;
		if (values[i].type == ARGS_STRING) {
			copy = xstrdup(values[i].string);
			size = strlen(copy);
			if (size != 0 && copy[size - 1] == ';') {
				copy[--size] = '\0';
				if (size > 0 && copy[size - 1] == '\\')
					copy[size - 1] = ';';
				else
					end = 1;
			}
			if (!end || size != 0) {
				arg = xcalloc(1, sizeof *arg);
				arg->type = CMD_PARSE_STRING;
				arg->string = copy;
				TAILQ_INSERT_TAIL(&cmd->arguments, arg, entry);
			}
		} else if (values[i].type == ARGS_COMMANDS) {
			arg = xcalloc(1, sizeof *arg);
			arg->type = CMD_PARSE_PARSED_COMMANDS;
			arg->cmdlist = values[i].cmdlist;
			arg->cmdlist->references++;
			TAILQ_INSERT_TAIL(&cmd->arguments, arg, entry);
		} else
			fatalx("unknown argument type");
		if (end) {
			TAILQ_INSERT_TAIL(cmds, cmd, entry);
			cmd = xcalloc(1, sizeof *cmd);
			cmd->line = pi->line;
			TAILQ_INIT(&cmd->arguments);
		}
	}
	if (!TAILQ_EMPTY(&cmd->arguments))
		TAILQ_INSERT_TAIL(cmds, cmd, entry);
	else
		free(cmd);

	cmd_parse_build_commands(cmds, pi, &pr);
	cmd_parse_free_commands(cmds);
	return (&pr);
}

static int printflike(1, 2)
yyerror(const char *fmt, ...)
{
	struct cmd_parse_state	*ps = &parse_state;
	struct cmd_parse_input	*pi = ps->input;
	va_list			 ap;
	char			*error;

	if (ps->error != NULL)
		return (0);

	va_start(ap, fmt);
	xvasprintf(&error, fmt, ap);
	va_end(ap);

	ps->error = cmd_parse_get_error(pi->file, pi->line, error);
	free(error);
	return (0);
}

static int
yylex_is_var(char ch, int first)
{
	if (ch == '=')
		return (0);
	if (first && isdigit((u_char)ch))
		return (0);
	return (isalnum((u_char)ch) || ch == '_');
}

static void
yylex_append(char **buf, size_t *len, const char *add, size_t addlen)
{
	if (addlen > SIZE_MAX - 1 || *len > SIZE_MAX - 1 - addlen)
		fatalx("buffer is too big");
	*buf = xrealloc(*buf, (*len) + 1 + addlen);
	memcpy((*buf) + *len, add, addlen);
	(*len) += addlen;
}

static void
yylex_append1(char **buf, size_t *len, char add)
{
	yylex_append(buf, len, &add, 1);
}

static int
yylex_getc1(void)
{
	struct cmd_parse_state	*ps = &parse_state;
	int			 ch;

	if (ps->f != NULL)
		ch = getc(ps->f);
	else {
		if (ps->off == ps->len)
			ch = EOF;
		else
			ch = ps->buf[ps->off++];
	}
	return (ch);
}

static void
yylex_ungetc(int ch)
{
	struct cmd_parse_state	*ps = &parse_state;

	if (ps->f != NULL)
		ungetc(ch, ps->f);
	else if (ps->off > 0 && ch != EOF)
		ps->off--;
}

static int
yylex_getc(void)
{
	struct cmd_parse_state	*ps = &parse_state;
	int			 ch;

	if (ps->escapes != 0) {
		ps->escapes--;
		return ('\\');
	}
	for (;;) {
		ch = yylex_getc1();
		if (ch == '\\') {
			ps->escapes++;
			continue;
		}
		if (ch == '\n' && (ps->escapes % 2) == 1) {
			ps->input->line++;
			ps->escapes--;
			continue;
		}

		if (ps->escapes != 0) {
			yylex_ungetc(ch);
			ps->escapes--;
			return ('\\');
		}
		return (ch);
	}
}

static char *
yylex_get_word(int ch)
{
	char	*buf;
	size_t	 len;

	len = 0;
	buf = xmalloc(1);

	do
		yylex_append1(&buf, &len, ch);
	while ((ch = yylex_getc()) != EOF && strchr(" \t\n", ch) == NULL);
	yylex_ungetc(ch);

	buf[len] = '\0';
	log_debug("%s: %s", __func__, buf);
	return (buf);
}

static int
yylex(void)
{
	struct cmd_parse_state	*ps = &parse_state;
	char			*token, *cp;
	int			 ch, next, condition;

	if (ps->eol)
		ps->input->line++;
	ps->eol = 0;

	condition = ps->condition;
	ps->condition = 0;

	for (;;) {
		ch = yylex_getc();

		if (ch == EOF) {
			/*
			 * Ensure every file or string is terminated by a
			 * newline. This keeps the parser simpler and avoids
			 * having to add a newline to each string.
			 */
			if (ps->eof)
				break;
			ps->eof = 1;
			return ('\n');
		}

		if (ch == ' ' || ch == '\t') {
			/*
			 * Ignore whitespace.
			 */
			continue;
		}

		if (ch == '\n') {
			/*
			 * End of line. Update the line number.
			 */
			ps->eol = 1;
			return ('\n');
		}

		if (ch == ';' || ch == '{' || ch == '}') {
			/*
			 * A semicolon or { or } is itself.
			 */
			return (ch);
		}

		if (ch == '#') {
			/*
			 * #{ after a condition opens a format; anything else
			 * is a comment, ignore up to the end of the line.
			 */
			next = yylex_getc();
			if (condition && next == '{') {
				yylval.token = yylex_format();
				if (yylval.token == NULL)
					return (ERROR);
				return (FORMAT);
			}
			while (next != '\n' && next != EOF)
				next = yylex_getc();
			if (next == '\n') {
				ps->input->line++;
				return ('\n');
			}
			continue;
		}

		if (ch == '%') {
			/*
			 * % is a condition unless it is all % or all numbers,
			 * then it is a token.
			 */
			yylval.token = yylex_get_word('%');
			for (cp = yylval.token; *cp != '\0'; cp++) {
				if (*cp != '%' && !isdigit((u_char)*cp))
					break;
			}
			if (*cp == '\0')
				return (TOKEN);
			ps->condition = 1;
			if (strcmp(yylval.token, "%hidden") == 0) {
				free(yylval.token);
				return (HIDDEN);
			}
			if (strcmp(yylval.token, "%if") == 0) {
				free(yylval.token);
				return (IF);
			}
			if (strcmp(yylval.token, "%else") == 0) {
				free(yylval.token);
				return (ELSE);
			}
			if (strcmp(yylval.token, "%elif") == 0) {
				free(yylval.token);
				return (ELIF);
			}
			if (strcmp(yylval.token, "%endif") == 0) {
				free(yylval.token);
				return (ENDIF);
			}
			free(yylval.token);
			return (ERROR);
		}

		/*
		 * Otherwise this is a token.
		 */
		token = yylex_token(ch);
		if (token == NULL)
			return (ERROR);
		yylval.token = token;

		if (strchr(token, '=') != NULL && yylex_is_var(*token, 1)) {
			for (cp = token + 1; *cp != '='; cp++) {
				if (!yylex_is_var(*cp, 0))
					break;
			}
			if (*cp == '=')
				return (EQUALS);
		}
		return (TOKEN);
	}
	return (0);
}

static char *
yylex_format(void)
{
	char	*buf;
	size_t	 len;
	int	 ch, brackets = 1;

	len = 0;
	buf = xmalloc(1);

	yylex_append(&buf, &len, "#{", 2);
	for (;;) {
		if ((ch = yylex_getc()) == EOF || ch == '\n')
			goto error;
		if (ch == '#') {
			if ((ch = yylex_getc()) == EOF || ch == '\n')
				goto error;
			if (ch == '{')
				brackets++;
			yylex_append1(&buf, &len, '#');
		} else if (ch == '}') {
			if (brackets != 0 && --brackets == 0) {
				yylex_append1(&buf, &len, ch);
				break;
			}
		}
		yylex_append1(&buf, &len, ch);
	}
	if (brackets != 0)
		goto error;

	buf[len] = '\0';
	log_debug("%s: %s", __func__, buf);
	return (buf);

error:
	free(buf);
	return (NULL);
}

static int
yylex_token_escape(char **buf, size_t *len)
{
	int	 ch, type, o2, o3, mlen;
	u_int	 size, i, tmp;
	char	 s[9], m[MB_LEN_MAX];

	ch = yylex_getc();

	if (ch >= '4' && ch <= '7') {
		yyerror("invalid octal escape");
		return (0);
	}
	if (ch >= '0' && ch <= '3') {
		o2 = yylex_getc();
		if (o2 >= '0' && o2 <= '7') {
			o3 = yylex_getc();
			if (o3 >= '0' && o3 <= '7') {
				ch = 64 * (ch - '0') +
				      8 * (o2 - '0') +
					  (o3 - '0');
				yylex_append1(buf, len, ch);
				return (1);
			}
		}
		yyerror("invalid octal escape");
		return (0);
	}

	switch (ch) {
	case EOF:
		return (0);
	case 'a':
		ch = '\a';
		break;
	case 'b':
		ch = '\b';
		break;
	case 'e':
		ch = '\033';
		break;
	case 'f':
		ch = '\f';
		break;
	case 's':
		ch = ' ';
		break;
	case 'v':
		ch = '\v';
		break;
	case 'r':
		ch = '\r';
		break;
	case 'n':
		ch = '\n';
		break;
	case 't':
		ch = '\t';
		break;
	case 'u':
		type = 'u';
		size = 4;
		goto unicode;
	case 'U':
		type = 'U';
		size = 8;
		goto unicode;
	}

	yylex_append1(buf, len, ch);
	return (1);

unicode:
	for (i = 0; i < size; i++) {
		ch = yylex_getc();
		if (ch == EOF || ch == '\n')
			return (0);
		if (!isxdigit((u_char)ch)) {
			yyerror("invalid \\%c argument", type);
			return (0);
		}
		s[i] = ch;
	}
	s[i] = '\0';

	if ((size == 4 && sscanf(s, "%4x", &tmp) != 1) ||
	    (size == 8 && sscanf(s, "%8x", &tmp) != 1)) {
		yyerror("invalid \\%c argument", type);
		return (0);
	}
	mlen = wctomb(m, tmp);
	if (mlen <= 0 || mlen > (int)sizeof m) {
		yyerror("invalid \\%c argument", type);
		return (0);
	}
	yylex_append(buf, len, m, mlen);
	return (1);
}

static int
yylex_token_variable(char **buf, size_t *len)
{
	struct environ_entry	*envent;
	int			 ch, brackets = 0;
	char			 name[1024];
	size_t			 namelen = 0;
	const char		*value;

	ch = yylex_getc();
	if (ch == EOF)
		return (0);
	if (ch == '{')
		brackets = 1;
	else {
		if (!yylex_is_var(ch, 1)) {
			yylex_append1(buf, len, '$');
			yylex_ungetc(ch);
			return (1);
		}
		name[namelen++] = ch;
	}

	for (;;) {
		ch = yylex_getc();
		if (brackets && ch == '}')
			break;
		if (ch == EOF || !yylex_is_var(ch, 0)) {
			if (!brackets) {
				yylex_ungetc(ch);
				break;
			}
			yyerror("invalid environment variable");
			return (0);
		}
		if (namelen == (sizeof name) - 2) {
			yyerror("environment variable is too long");
			return (0);
		}
		name[namelen++] = ch;
	}
	name[namelen] = '\0';

	envent = environ_find(global_environ, name);
	if (envent != NULL && envent->value != NULL) {
		value = envent->value;
		log_debug("%s: %s -> %s", __func__, name, value);
		yylex_append(buf, len, value, strlen(value));
	}
	return (1);
}

static int
yylex_token_tilde(char **buf, size_t *len)
{
	struct environ_entry	*envent;
	int			 ch;
	char			 name[1024];
	size_t			 namelen = 0;
	struct passwd		*pw;
	const char		*home = NULL;

	for (;;) {
		ch = yylex_getc();
		if (ch == EOF || strchr("/ \t\n\"'", ch) != NULL) {
			yylex_ungetc(ch);
			break;
		}
		if (namelen == (sizeof name) - 2) {
			yyerror("user name is too long");
			return (0);
		}
		name[namelen++] = ch;
	}
	name[namelen] = '\0';

	if (*name == '\0') {
		envent = environ_find(global_environ, "HOME");
		if (envent != NULL && *envent->value != '\0')
			home = envent->value;
		else if ((pw = getpwuid(getuid())) != NULL)
			home = pw->pw_dir;
	} else {
		if ((pw = getpwnam(name)) != NULL)
			home = pw->pw_dir;
	}
	if (home == NULL)
		return (0);

	log_debug("%s: ~%s -> %s", __func__, name, home);
	yylex_append(buf, len, home, strlen(home));
	return (1);
}

static char *
yylex_token(int ch)
{
	char			*buf;
	size_t			 len;
	enum { START,
	       NONE,
	       DOUBLE_QUOTES,
	       SINGLE_QUOTES }	 state = NONE, last = START;

	len = 0;
	buf = xmalloc(1);

	for (;;) {
		/* EOF or \n are always the end of the token. */
		if (ch == EOF || (state == NONE && ch == '\n'))
			break;

		/* Whitespace or ; or } ends a token unless inside quotes. */
		if ((ch == ' ' || ch == '\t' || ch == ';' || ch == '}') &&
		    state == NONE)
			break;

		/*
		 * Spaces and comments inside quotes after \n are removed but
		 * the \n is left.
		 */
		if (ch == '\n' && state != NONE) {
			yylex_append1(&buf, &len, '\n');
			while ((ch = yylex_getc()) == ' ' || ch == '\t')
				/* nothing */;
			if (ch != '#')
				continue;
			ch = yylex_getc();
			if (strchr(",#{}:", ch) != NULL) {
				yylex_ungetc(ch);
				ch = '#';
			} else {
				while ((ch = yylex_getc()) != '\n' && ch != EOF)
					/* nothing */;
			}
			continue;
		}

		/* \ ~ and $ are expanded except in single quotes. */
		if (ch == '\\' && state != SINGLE_QUOTES) {
			if (!yylex_token_escape(&buf, &len))
				goto error;
			goto skip;
		}
		if (ch == '~' && last != state && state != SINGLE_QUOTES) {
			if (!yylex_token_tilde(&buf, &len))
				goto error;
			goto skip;
		}
		if (ch == '$' && state != SINGLE_QUOTES) {
			if (!yylex_token_variable(&buf, &len))
				goto error;
			goto skip;
		}
		if (ch == '}' && state == NONE)
			goto error;  /* unmatched (matched ones were handled) */

		/* ' and " starts or end quotes (and is consumed). */
		if (ch == '\'') {
			if (state == NONE) {
				state = SINGLE_QUOTES;
				goto next;
			}
			if (state == SINGLE_QUOTES) {
				state = NONE;
				goto next;
			}
		}
		if (ch == '"') {
			if (state == NONE) {
				state = DOUBLE_QUOTES;
				goto next;
			}
			if (state == DOUBLE_QUOTES) {
				state = NONE;
				goto next;
			}
		}

		/* Otherwise add the character to the buffer. */
		yylex_append1(&buf, &len, ch);

	skip:
		last = state;

	next:
		ch = yylex_getc();
	}
	yylex_ungetc(ch);

	buf[len] = '\0';
	log_debug("%s: %s", __func__, buf);
	return (buf);

error:
	free(buf);
	return (NULL);
}
