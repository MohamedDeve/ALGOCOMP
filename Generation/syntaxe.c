
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syntaxe.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symetique.h"

char *nomProgramme;
int estNomProgramme; /* variable pour verifier si l'identifiant est pour nomer le programme ou c'est une variable*/
int finDeclaration; /* 0 si la declaration n'est pas terminee 1 si la declaration est terminee */
int estConstante; /* 1 on est encors dans la declaration des constantes 0 sinon*/
int estVariable; /* 1 on est encors dans la declaration des variables  0 sinon */
int nbrVarDecEnC; /* le nombre des variables dejas declares dans le fichier .c */
int nbrConstDecEnC; /* le nombre des constantes dejas declares dans le fichier .c */
int numeroType; /* la variable qui va contenire a chaque fois le numero d'un type qu'on va utiliser pour associer le type a une variable ou une constante*/
int typeAffG; /* la variable qui va contenir le numero du type de la partie gauche de l'affectation */
int typeAffD; /* la variable qui va contenir le numero du type de la partie droite de l'affectation */
int typeAffDO;/* la variable qui va contenir le numero du type de chaque operande de l'affectation */
int symboleOperation; /* 1- pour la somme 2- pour la soustraction  3- pour le produit 4- pour la division */
int nature;/* identifiant ou valeur */
int typeVarSwitch;/* la variable qui stock le type de la variable de switch */
int estInstrEcrireOuLire;/* varaible utiliser pour autoriser l'affichage des chaine (en val) dans les instruction d'affichage (sa valeur est 1) */
int debutInstrAff; /* variable qui indique le debut d'une instruction de l'affectation si sa valeur est 1 et  o sinon */
int estFormateur;
int boucleTQueFinie; /* la variable qui indique qu'une boucle tantque est finie ( si sa valeur est 1 ) ou non ()*/
int boucleFTQueFinie; /* la variable qui indique qu'une boucle faire tantque est finie ( si sa valeur est 1 ) ou non ()*/
char *chaineSource;
char *chainePrincipale;
char *chaineSecondere;
char *nomConstante; /* variable qui va stocker le nom de la constante a chaque fois qu'on veut declarer une constante */
char *valConstante; /* variable qui va stocker la valeur de la constante a chaque fois qu'on veut convertire la declaration d'une constante dans le fichier .c*/
FILE *fichierProgEnC;
extern FILE* yyin; 
int 	yylex(void); 
extern char *yytext;
void	yyerror(const char * msg); 
int 	lineNumber; 
pileIdentifs pileIdentifiants;
pileValConst pileConstantes;


/* Line 189 of yacc.c  */
#line 114 "syntaxe.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ALGO = 258,
     VARS = 259,
     CSTS = 260,
     DEBUT = 261,
     FIN = 262,
     IDENT = 263,
     AFF = 264,
     DXPT = 265,
     PTVIRG = 266,
     VIRG = 267,
     ENTIER = 268,
     REEL = 269,
     CHAINE = 270,
     CARACTERE = 271,
     ENTIER_D = 272,
     REEL_D = 273,
     CHAINE_D = 274,
     CARACTERE_D = 275,
     SOMM = 276,
     SOUSTR = 277,
     PROD = 278,
     DIV = 279,
     PAR_OUV = 280,
     PAR_FERM = 281,
     INF = 282,
     SUP = 283,
     EG = 284,
     INF_EG = 285,
     SUP_EG = 286,
     DIFF = 287,
     CONJ = 288,
     DISJ = 289,
     NEG = 290,
     SI = 291,
     ALORS = 292,
     SINON = 293,
     SELON = 294,
     CAS = 295,
     POUR = 296,
     DE = 297,
     JUSQUA = 298,
     PAS = 299,
     FAIRE = 300,
     TANTQUE = 301,
     RETOURNE = 302,
     ECRIRE = 303,
     LIRE = 304
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 205 "syntaxe.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   246

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNRULES -- Number of states.  */
#define YYNSTATES  197

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     8,    11,    12,    15,    20,    25,
      28,    30,    31,    37,    41,    43,    46,    48,    49,    50,
      51,    61,    63,    65,    67,    69,    71,    73,    75,    77,
      81,    84,    86,    87,    93,    95,    97,    99,   101,   103,
     107,   108,   113,   114,   115,   123,   125,   127,   129,   131,
     133,   135,   137,   139,   142,   146,   150,   152,   153,   158,
     160,   162,   164,   166,   168,   170,   172,   174,   180,   188,
     189,   195,   198,   200,   201,   202,   210,   212,   214,   216,
     217,   218,   219,   220,   221,   237,   240,   241,   242,   243,
     251,   252,   259,   269,   273,   275,   276,   277,   282,   285,
     286,   290,   291,   293,   295,   296,   297,   298,   299,   309,
     310,   311,   312,   313,   323,   327
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    52,    53,    65,    -1,    -1,     3,     8,
      -1,    -1,     4,    54,    -1,     4,    54,     5,    58,    -1,
       5,    58,     4,    54,    -1,    54,    55,    -1,    55,    -1,
      -1,    57,    10,    64,    56,    11,    -1,    57,    12,     8,
      -1,     8,    -1,    58,    59,    -1,    59,    -1,    -1,    -1,
      -1,     8,    60,     9,    63,    61,    10,    64,    62,    11,
      -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,    17,
      -1,    18,    -1,    19,    -1,    20,    -1,     6,    66,     7,
      -1,    66,    67,    -1,    67,    -1,    -1,     8,     9,    68,
      69,    11,    -1,    81,    -1,    82,    -1,    88,    -1,   101,
      -1,   107,    -1,    69,    74,    73,    -1,    -1,    25,    70,
      69,    26,    -1,    -1,    -1,    69,    74,    71,    25,    72,
      69,    26,    -1,    73,    -1,    63,    -1,     8,    -1,    21,
      -1,    22,    -1,    23,    -1,    24,    -1,    76,    -1,    35,
      76,    -1,    76,    80,    77,    -1,    25,    76,    26,    -1,
      77,    -1,    -1,    69,    78,    79,    69,    -1,    27,    -1,
      28,    -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,
      33,    -1,    34,    -1,    36,    75,    37,    66,     7,    -1,
      36,    75,    37,    66,    38,    66,     7,    -1,    -1,    39,
       8,    83,    84,     7,    -1,    84,    85,    -1,    85,    -1,
      -1,    -1,    40,    69,    86,    45,    87,    66,     7,    -1,
      89,    -1,    96,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    90,     8,    91,    42,    92,    69,    93,    43,
      75,    95,    45,    94,    66,     7,    -1,    44,    73,    -1,
      -1,    -1,    -1,    46,    75,    97,    45,    98,    66,     7,
      -1,    -1,    45,   100,    66,    46,    75,     7,    -1,     8,
      25,   102,    26,   105,     6,    66,   106,     7,    -1,   102,
      12,   103,    -1,   103,    -1,    -1,    -1,     8,   104,    10,
      64,    -1,    10,    64,    -1,    -1,    47,    69,    11,    -1,
      -1,   108,    -1,   113,    -1,    -1,    -1,    -1,    -1,    49,
     109,    25,   110,   102,   111,    26,   112,    11,    -1,    -1,
      -1,    -1,    -1,    48,   114,    25,   115,   118,   116,    26,
     117,    11,    -1,   118,    12,    73,    -1,    73,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    54,    54,    55,    55,    57,    57,    57,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    62,
      62,    63,    63,    63,    63,    64,    64,    64,    64,    66,
      67,    67,    68,    68,    68,    68,    68,    68,    68,    69,
      69,    69,    69,    69,    69,    69,    70,    70,    71,    71,
      71,    71,    73,    73,    74,    74,    74,    75,    75,    76,
      76,    76,    76,    76,    76,    77,    77,    80,    80,    81,
      81,    82,    82,    83,    83,    83,    85,    85,    85,    86,
      86,    86,    86,    86,    86,    87,    87,    88,    88,    88,
      89,    89,    91,    92,    92,    92,    93,    93,    94,    94,
      95,    95,    97,    97,    98,    98,    98,    98,    98,    99,
      99,    99,    99,    99,   100,   100
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ALGO", "VARS", "CSTS", "DEBUT", "FIN",
  "IDENT", "AFF", "DXPT", "PTVIRG", "VIRG", "ENTIER", "REEL", "CHAINE",
  "CARACTERE", "ENTIER_D", "REEL_D", "CHAINE_D", "CARACTERE_D", "SOMM",
  "SOUSTR", "PROD", "DIV", "PAR_OUV", "PAR_FERM", "INF", "SUP", "EG",
  "INF_EG", "SUP_EG", "DIFF", "CONJ", "DISJ", "NEG", "SI", "ALORS",
  "SINON", "SELON", "CAS", "POUR", "DE", "JUSQUA", "PAS", "FAIRE",
  "TANTQUE", "RETOURNE", "ECRIRE", "LIRE", "$accept", "programme",
  "entete", "declaration", "ls_vars", "l_vars", "$@1", "l_ident", "l_csts",
  "d_cst", "$@2", "$@3", "$@4", "val", "type", "corps", "ls_instruction",
  "instruction", "$@5", "expr_ar", "$@6", "$@7", "$@8", "oper", "op_sym",
  "expr_cond", "expr_log", "expr_cmpr", "$@9", "op_cmpr", "op_log",
  "condition", "switch", "$@10", "les_cas", "un_cas", "$@11", "$@12",
  "boucle", "b_pour", "$@13", "$@14", "$@15", "$@16", "$@17", "le_pas",
  "b_tque", "$@18", "$@19", "b_ftque", "$@20", "routine", "ls_param",
  "param", "$@21", "rout_spec", "ret", "es_std", "e_std", "$@22", "$@23",
  "$@24", "$@25", "s_std", "$@26", "$@27", "$@28", "$@29", "msg", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    53,    53,    54,
      54,    56,    55,    57,    57,    58,    58,    60,    61,    62,
      59,    63,    63,    63,    63,    64,    64,    64,    64,    65,
      66,    66,    68,    67,    67,    67,    67,    67,    67,    69,
      70,    69,    71,    72,    69,    69,    73,    73,    74,    74,
      74,    74,    75,    75,    76,    76,    76,    78,    77,    79,
      79,    79,    79,    79,    79,    80,    80,    81,    81,    83,
      82,    84,    84,    86,    87,    85,    88,    88,    88,    90,
      91,    92,    93,    94,    89,    95,    95,    97,    98,    96,
     100,    99,   101,   102,   102,   102,   104,   103,   105,   105,
     106,   106,   107,   107,   109,   110,   111,   112,   108,   114,
     115,   116,   117,   113,   118,   118
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     2,     0,     2,     4,     4,     2,
       1,     0,     5,     3,     1,     2,     1,     0,     0,     0,
       9,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     1,     0,     5,     1,     1,     1,     1,     1,     3,
       0,     4,     0,     0,     7,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     1,     0,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     7,     0,
       5,     2,     1,     0,     0,     7,     1,     1,     1,     0,
       0,     0,     0,     0,    15,     2,     0,     0,     0,     7,
       0,     6,     9,     3,     1,     0,     0,     4,     2,     0,
       3,     0,     1,     1,     0,     0,     0,     0,     9,     0,
       0,     0,     0,     9,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     5,     4,     1,     0,     0,     0,    14,
       6,    10,     0,    17,     0,    16,     0,     2,     0,     9,
       0,     0,     0,     0,    15,     0,     0,     0,    79,    90,
       0,   109,   104,     0,    31,    34,    35,    36,    76,    77,
      78,    37,    38,   102,   103,     7,    25,    26,    27,    28,
      11,    13,     0,     8,    32,    95,    47,    21,    22,    23,
      24,     0,     0,    46,    57,    45,     0,    52,    56,    69,
       0,     0,    87,     0,     0,    29,    30,     0,    18,     0,
      96,     0,    94,     0,     0,    53,    48,    49,    50,    51,
      42,     0,     0,    65,    66,     0,     0,    80,     0,     0,
     110,   105,    12,     0,    40,     0,     0,     0,    99,     0,
      55,     0,    39,    59,    60,    61,    62,    63,    64,     0,
       0,    54,     0,     0,    72,     0,     0,    88,     0,    95,
       0,    33,     0,    93,     0,     0,    41,    43,    58,    67,
       0,    73,    70,    71,    81,    87,     0,   115,   111,   106,
      19,    97,    98,     0,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,   101,     0,    68,    74,    82,    89,
     114,   112,   107,    20,     0,     0,    44,     0,     0,     0,
       0,     0,    92,     0,     0,   113,   108,   100,    75,    86,
       0,     0,    85,    83,     0,     0,    84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    10,    11,    77,    12,    14,    15,
      22,   103,   163,    63,    50,    17,    33,    34,    79,    64,
      83,   111,   154,    65,    90,    66,    67,    68,    91,   119,
      95,    35,    36,    96,   123,   124,   156,   177,    37,    38,
      70,   125,   157,   178,   194,   191,    39,    99,   146,    40,
      71,    41,    81,    82,   106,   135,   175,    42,    43,    74,
     129,   162,   180,    44,    73,   128,   161,   179,   148
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -88
static const yytype_int16 yypact[] =
{
      48,    16,    72,    57,   -88,   -88,    66,    86,    92,   -88,
      24,   -88,    58,   -88,     5,   -88,   122,   -88,    86,   -88,
     218,    93,    96,    66,   -88,    21,     2,    94,   -88,   -88,
       2,   -88,   -88,    18,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,    86,   -88,   -88,   -88,   -88,
     -88,   -88,   226,    66,   -88,    98,   -88,   -88,   -88,   -88,
     -88,     6,     6,   -88,   222,   -88,    78,    47,   -88,   -88,
     104,   122,   -88,   107,   110,   -88,   -88,   117,   -88,    75,
     -88,    43,   -88,    75,    52,    47,   -88,   -88,   -88,   -88,
      20,   196,   122,   -88,   -88,    75,   105,   -88,   165,   101,
     -88,   -88,   -88,   128,   -88,   194,   137,    98,   143,    97,
     -88,   118,   -88,   -88,   -88,   -88,   -88,   -88,   -88,    75,
       4,   -88,    75,    -1,   -88,   112,     2,   -88,    20,    98,
     218,   -88,   218,   -88,   218,   151,   -88,   -88,   222,   -88,
     122,   222,   -88,   -88,   -88,   152,   122,   -88,   153,   154,
     -88,   -88,   -88,   122,    75,    68,   115,    75,   -88,    88,
      20,   138,   149,   166,   148,   208,   -88,   -88,   222,   -88,
     -88,   -88,   -88,   -88,    75,   169,   -88,   122,   140,   174,
     175,   198,   -88,   103,     2,   -88,   -88,   -88,   -88,   136,
      20,   145,   -88,   -88,   122,   133,   -88
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -88,   -88,   -88,   -88,   168,    -5,   -88,   -88,   170,    -7,
     -88,   -88,   -88,   146,   -74,   -88,   -69,   -33,   -88,   -75,
     -88,   -88,   -88,   -87,   -88,   -29,    31,   108,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,    69,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,    70,    95,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      76,    72,    98,   112,   105,    19,   142,    24,   109,    23,
      56,   139,    25,    13,    56,    57,    58,    59,    60,    57,
      58,    59,    60,   120,     4,    75,    25,    61,    56,    18,
      54,    61,     9,    57,    58,    59,    60,    62,    24,   122,
      26,   147,   140,    27,   138,    28,    55,   141,    19,    29,
      30,     1,    31,    32,    26,   107,   150,    27,   151,    28,
     152,     6,     7,    29,    30,    76,    31,    32,    20,   108,
      21,   155,     5,   170,     9,   166,    25,   159,   110,   165,
      93,    94,   168,    56,   164,    93,    94,    76,    57,    58,
      59,    60,    84,    85,    13,   169,    25,   145,    16,   181,
     104,    51,    69,   192,    26,    52,    80,    27,   183,    28,
     188,    25,    97,    29,    30,    92,    31,    32,    86,    87,
      88,    89,    76,   136,    26,   195,    76,    27,   102,    28,
      25,    76,   100,    29,    30,   101,    31,    32,   130,    26,
     196,    25,    27,   137,    28,   122,   127,   132,    29,    30,
      76,    31,    32,   134,   144,   189,    25,   153,    26,   158,
     167,    27,    76,    28,   171,   160,   107,    29,    30,    26,
      31,    32,    27,    25,    28,   172,   182,   173,    29,    30,
     190,    31,    32,   184,    26,   185,   186,    27,    45,    28,
     193,    53,   143,    29,    30,   174,    31,    32,    78,   149,
       0,    26,   133,   121,    27,   131,    28,     0,     0,   187,
      29,   126,     0,    31,    32,    86,    87,    88,    89,    86,
      87,    88,    89,   113,   114,   115,   116,   117,   118,    86,
      87,    88,    89,     0,   176,    46,    47,    48,    49,    57,
      58,    59,    60,    86,    87,    88,    89
};

static const yytype_int16 yycheck[] =
{
      33,    30,    71,    90,    79,    10,     7,    14,    83,     4,
       8,     7,     8,     8,     8,    13,    14,    15,    16,    13,
      14,    15,    16,    92,     8,     7,     8,    25,     8,     5,
       9,    25,     8,    13,    14,    15,    16,    35,    45,    40,
      36,   128,    38,    39,   119,    41,    25,   122,    53,    45,
      46,     3,    48,    49,    36,    12,   130,    39,   132,    41,
     134,     4,     5,    45,    46,    98,    48,    49,    10,    26,
      12,   140,     0,   160,     8,     7,     8,   146,    26,   154,
      33,    34,   157,     8,   153,    33,    34,   120,    13,    14,
      15,    16,    61,    62,     8,     7,     8,   126,     6,   174,
      25,     8,     8,   190,    36,     9,     8,    39,   177,    41,
       7,     8,     8,    45,    46,    37,    48,    49,    21,    22,
      23,    24,   155,    26,    36,   194,   159,    39,    11,    41,
       8,   164,    25,    45,    46,    25,    48,    49,    10,    36,
       7,     8,    39,    25,    41,    40,    45,    10,    45,    46,
     183,    48,    49,    10,    42,   184,     8,     6,    36,     7,
      45,    39,   195,    41,    26,    12,    12,    45,    46,    36,
      48,    49,    39,     8,    41,    26,     7,    11,    45,    46,
      44,    48,    49,    43,    36,    11,    11,    39,    18,    41,
      45,    23,   123,    45,    46,    47,    48,    49,    52,   129,
      -1,    36,   107,    95,    39,    11,    41,    -1,    -1,    11,
      45,    46,    -1,    48,    49,    21,    22,    23,    24,    21,
      22,    23,    24,    27,    28,    29,    30,    31,    32,    21,
      22,    23,    24,    -1,    26,    17,    18,    19,    20,    13,
      14,    15,    16,    21,    22,    23,    24
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    51,    52,     8,     0,     4,     5,    53,     8,
      54,    55,    57,     8,    58,    59,     6,    65,     5,    55,
      10,    12,    60,     4,    59,     8,    36,    39,    41,    45,
      46,    48,    49,    66,    67,    81,    82,    88,    89,    96,
      99,   101,   107,   108,   113,    58,    17,    18,    19,    20,
      64,     8,     9,    54,     9,    25,     8,    13,    14,    15,
      16,    25,    35,    63,    69,    73,    75,    76,    77,     8,
      90,   100,    75,   114,   109,     7,    67,    56,    63,    68,
       8,   102,   103,    70,    76,    76,    21,    22,    23,    24,
      74,    78,    37,    33,    34,    80,    83,     8,    66,    97,
      25,    25,    11,    61,    25,    69,   104,    12,    26,    69,
      26,    71,    73,    27,    28,    29,    30,    31,    32,    79,
      66,    77,    40,    84,    85,    91,    46,    45,   115,   110,
      10,    11,    10,   103,    10,   105,    26,    25,    69,     7,
      38,    69,     7,    85,    42,    75,    98,    73,   118,   102,
      64,    64,    64,     6,    72,    66,    86,    92,     7,    66,
      12,   116,   111,    62,    66,    69,     7,    45,    69,     7,
      73,    26,    26,    11,    47,   106,    26,    87,    93,   117,
     112,    69,     7,    66,    43,    11,    11,    11,     7,    75,
      44,    95,    73,    45,    94,    66,     7
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 11:

/* Line 1455 of yacc.c  */
#line 59 "syntaxe.y"
    { prendreTypeDec(yytext); associerType(); declarationEnReChCa(yytext);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 62 "syntaxe.y"
    {prendreNomConst(yytext);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 62 "syntaxe.y"
    { prendreValConst(yytext);typeAffDO = 3;;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 62 "syntaxe.y"
    {  prendreTypeDec(yytext); associerType(); empilerValConst(&pileConstantes,&pileIdentifiants,yytext); declarationEnReChCa(yytext); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 63 "syntaxe.y"
    {typeAffDO = 1;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 63 "syntaxe.y"
    {typeAffDO = 2;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 63 "syntaxe.y"
    {typeAffDO = 3;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 63 "syntaxe.y"
    {typeAffDO = 4;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 66 "syntaxe.y"
    {fermeturFichierC();;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 68 "syntaxe.y"
    {if(typeAffG != 3) fputs(" = ",fichierProgEnC);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 68 "syntaxe.y"
    {if(typeAffG != 3) fputs(";\n",fichierProgEnC); else executerAffCh();;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 69 "syntaxe.y"
    {fputs(yytext,fichierProgEnC);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 69 "syntaxe.y"
    {fputs(yytext,fichierProgEnC);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 69 "syntaxe.y"
    {fputs(yytext,fichierProgEnC);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 69 "syntaxe.y"
    {fputs(yytext,fichierProgEnC);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 69 "syntaxe.y"
    {fputs(yytext,fichierProgEnC);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 70 "syntaxe.y"
    {if(estInstrEcrireOuLire == 1){ stockerMessageCh(yytext);} else {nature = 2; typeAffDestValide(yytext,2); if(typeAffDO != 3){fputs(yytext,fichierProgEnC);}};}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 70 "syntaxe.y"
    {prendreTypeAff(yytext,2); if(estInstrEcrireOuLire == 1){ stockerMessageIdent(yytext); } else {nature = 1; typeAffDestValide(yytext,1);} ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 71 "syntaxe.y"
    {prendreSymOp(yytext); if(typeAffD != 3){ fputs(yytext,fichierProgEnC);};}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 71 "syntaxe.y"
    {prendreSymOp(yytext); if(typeAffD != 3){ fputs(yytext,fichierProgEnC);};}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 71 "syntaxe.y"
    {prendreSymOp(yytext); if(typeAffD != 3){ fputs(yytext,fichierProgEnC);};}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 71 "syntaxe.y"
    {prendreSymOp(yytext); if(typeAffD != 3){ fputs(yytext,fichierProgEnC);};}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 75 "syntaxe.y"
    { exprComprEstValide(typeAffD); typeAffD = 0;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 75 "syntaxe.y"
    { exprComprEstValide(typeAffD);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 80 "syntaxe.y"
    {fputs("}\n",fichierProgEnC);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 80 "syntaxe.y"
    {fputs("}\n",fichierProgEnC);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 81 "syntaxe.y"
    {typeVarSwitchEstValide(typeAffDO); fputs(" ){\n",fichierProgEnC);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 81 "syntaxe.y"
    {fputs("}\n",fichierProgEnC);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 83 "syntaxe.y"
    {typeCasEstValide(typeAffD);;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 83 "syntaxe.y"
    { fputs(":\n{\n",fichierProgEnC);;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 83 "syntaxe.y"
    {fputs("break;\n}\n",fichierProgEnC);;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 86 "syntaxe.y"
    {fputs("for( ",fichierProgEnC);;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 86 "syntaxe.y"
    {fputs(yytext,fichierProgEnC);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 86 "syntaxe.y"
    {fputs("=",fichierProgEnC);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 86 "syntaxe.y"
    {fputs(", ",fichierProgEnC);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 86 "syntaxe.y"
    {fputs("){\n",fichierProgEnC);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 86 "syntaxe.y"
    {fputs("}\n",fichierProgEnC);;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 88 "syntaxe.y"
    {boucleTQueFinie = 0;;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 88 "syntaxe.y"
    {fputs(" ){\n",fichierProgEnC); boucleTQueFinie = 1;;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 88 "syntaxe.y"
    {fputs("}\n",fichierProgEnC);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 89 "syntaxe.y"
    {fputs("do{\n",fichierProgEnC); boucleFTQueFinie = 0;;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 89 "syntaxe.y"
    {fputs(");\n",fichierProgEnC); boucleFTQueFinie = 1;;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 93 "syntaxe.y"
    {prendreTypeAff(yytext,2); prendreNomIdent(yytext);;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 93 "syntaxe.y"
    {prendreTypeLire(yytext);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 98 "syntaxe.y"
    {viderChaines(); fputs("scanf",fichierProgEnC);;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 98 "syntaxe.y"
    {fputs("(",fichierProgEnC);;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 98 "syntaxe.y"
    {formerMeg();;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 98 "syntaxe.y"
    {fputs(")",fichierProgEnC);;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 98 "syntaxe.y"
    {fputs(";\n",fichierProgEnC); estInstrEcrireOuLire = 0;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 99 "syntaxe.y"
    {viderChaines(); fputs("printf",fichierProgEnC);;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 99 "syntaxe.y"
    {fputs("(",fichierProgEnC);;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 99 "syntaxe.y"
    {formerMeg();;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 99 "syntaxe.y"
    {fputs(")",fichierProgEnC);;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 99 "syntaxe.y"
    {fputs(";\n",fichierProgEnC); estInstrEcrireOuLire = 0;}
    break;



/* Line 1455 of yacc.c  */
#line 1976 "syntaxe.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 101 "syntaxe.y"



void yyerror( const char * msg){
	printf("line %d : %s \n", lineNumber, msg);

}
int main(int argc,char ** argv){
	if(argc>1) yyin=fopen(argv[1],"r"); 
	/* declaration et creation de la pile des identifiant */
	pileIdentifiants = creerPileIdentifes();
	/* declaration et creation de la pile des valeurs des constantes */
	pileConstantes = creerPileConsts();
	/* initialiser estNomProgramme qui va etre utiliser apre pour stocker le nom du programme */
	estNomProgramme = 0;
	/* initialiser finDeclaration qui va etre utiliser apres pour marker la fin de la declaration */
	finDeclaration = 0;
	/* aucune variable n'est encore declare dans le fichier .c */
	nbrVarDecEnC = 0;
	/* aucune constante  n'est encore declare dans le fichier .c */
	nbrConstDecEnC = 0;
	/* initialiser la variable qui va s'occuper de l'affechage des instruction d'ecreture */
	estInstrEcrireOuLire = 0;
	estFormateur = 0;
	boucleFTQueFinie = 1;
	boucleTQueFinie = 1;
	printf("\nDEBUT compilation : \n");
	lineNumber=1;
	if(!yyparse()) printf("FIN compilation : \n");
	return 0;
}

void saisirNomProgramme(char * identif){
	nomProgramme = malloc((strlen(identif)+1)*sizeof(char));
	if(nomProgramme == NULL){
		printf("ERREUR : problemme dans l'allocation dynamique de la memoire en ( dans saisirNomProgramme ).\n");
		exit(1);
	}
	strcpy(nomProgramme,identif);
	estNomProgramme = 1; // 0 pour dir a la fonction identEstValide que cet identifiant est le nom du programme il  ne faut pas le stocker dans la pile des identifiants.
}

void identEstValide(char *identifiant){
	FILE* fichierMotsCles = NULL;
	int i = 0, trouve = 0;
	char mot[tailleMaxChaine] = "";
	
	// overture de fichier des mots cles 
	fichierMotsCles = fopen("motsCles.txt","r");
	if(fichierMotsCles == NULL){
		printf("ERREUR : probleme d'overture du fichier.\n");
		exit(1);
	}

	// verifier si l'identifiant n'est pas un mot cle du langege
	do{
		fgets(mot,tailleMaxChaine,fichierMotsCles);
		if(strcmp(mot,identifiant) == 0){
			printf("( la ligne %d ) ERREUR : le mot \" %s \" est reserve (c'est un mot cle)\n.",lineNumber,identifiant);
			trouve = 1;
			return;
		}
	}while(!feof(fichierMotsCles));
	fclose(fichierMotsCles); 

	 // si l'identifiant n'est pas un mot cle 
	if(trouve == 0){
		//printf("( la ligne %d ) la variable qui a l'identifiant \" %s \" est declaree avec succe (etape 1).\n",lineNumber,identifiant);
		// verifier si l'identifiant n'est pas dejas declare
		if(pileIdentifiants.nombreElement == 0){ 
			// si aucun identifiant n'est encors declare
			empilerIdentif(&pileIdentifiants,identifiant);
			//printf("( la ligne %d ) la variable qui a l'identifiant \" %s \" est declaree avec succe (etape 2-a).\n",lineNumber,identifiant);
		}
		else{ 
			// si on a dejas declare d'autre identifiant
			if(identifEstDeclarer(pileIdentifiants,identifiant) == 1){
				// si il existe une autre variable dejas declaree qui prent le meme nom de la variable actuielle
				//printf("( la ligne %d ) ERREUR : une variable nomee \" %s \" est deja declare.\n",lineNumber,identifiant);
				return;
			}
			else{
				// si aucune variable dejas decleree n'a le meme nom de la variable actuelle 
				empilerIdentif(&pileIdentifiants,identifiant);
				//printf("( la ligne %d ) la variable qui a l'identifiant \" %s \" est declaree avec succe (etape 2-b).\n",lineNumber,identifiant);
			}
		}
	}
}

pileIdentifs creerPileIdentifes(){
	pileIdentifs pile;
	pile.nombreElement = 0;
	pile.premier = NULL;
	return pile;
}

void empilerIdentif(pileIdentifs *p,char *identif){
	p->nombreElement++;
	identifiant *elem = NULL;
	elem = malloc(sizeof(identifiant));
	if(elem == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans empiler).\n");
		exit(1);
	}
	elem->mot = malloc((strlen(identif)+1)*sizeof(char));
	if(elem->mot == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans empiler).\n");
		exit(1);
	}
	strcpy(elem->mot,identif);
	elem->numType = 0; // initialiser le numero du type de cet element pour qu'on puissent le detecter lorsqu'on veut lui associer son type apres 
	if(estVariable == 1) {
		elem->valVarChaine = NULL; // on a suposer que l'initialisation est interdit lors de la declaration
		elem->estInitialise = 0; // la variable n'est pas initialise il ne contient aucune valeur
	}
	if(estConstante == 1){
		elem->estInitialise = 1; // la variable est toujour initialise a la declaration
	}

	elem->suivant = malloc(sizeof(identifiant));
	if(elem->suivant == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans empiler).\n");
		exit(1);
	}

	elem->suivant = p->premier;
	p->premier = elem;
}

int identifEstDeclarer(pileIdentifs p,char *identif){
	int i = 1;
	identifiant *elementCourant = malloc(sizeof(identifiant));
	if(elementCourant == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans identifEstDeclarer).\n");
		exit(1);
	}
	elementCourant->mot = malloc((1+strlen(p.premier->mot))*sizeof(char));
	if(elementCourant->mot == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans identifEstDeclarer).\n");
		exit(1);
	}
	elementCourant->suivant = malloc(sizeof(identifiant));
	if(elementCourant->suivant == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans identifEstDeclarer).\n");
		exit(1);
	}

	strcpy(elementCourant->mot,p.premier->mot);
	elementCourant->suivant = p.premier->suivant;
	do{
		if(strcmp(elementCourant->mot,identif) == 0){
			return 1;
		}
		elementCourant = elementCourant->suivant;
		i++;
	}while(elementCourant != NULL);
	free(elementCourant);
	return 0; // si l'identifiant n'est pas trouve
}

void variableEstDeclaree(pileIdentifs p,char *identif){
	int identifEstTrouve = identifEstDeclarer(p,identif);
	if(identifEstTrouve == 1){ 
		//printf("( la ligne %d ) la variable\" %s \" est dejas declaree tu peut l'utiliser.\n",lineNumber,identif);
	}
	else{
		printf("( la ligne %d ) ERREUR : la variable \" %s \" n'est pas encors declaree tu doit la declare dabord.\n",lineNumber,identif);
	}
}

// la generation de code c 

void overtureFichierC(char *nomAlgo){
	fichierProgEnC = NULL;
	char *nomFichierProgEnC = NULL;

	// stocker le nom du programme suivie d'un .c dans la variable nomFichierProgEnC
	nomFichierProgEnC = malloc((strlen(nomAlgo)+3)*sizeof(char));
	if(nomFichierProgEnC == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire ( dans overtureFichierC ).\n");
		exit(1);
	}
	strcpy(nomFichierProgEnC,nomAlgo);
	strcat(nomFichierProgEnC,".c");
	// overture du fichier .c qui va contenire la convertion du programme source en c
	fichierProgEnC = fopen(nomFichierProgEnC,"w");
	if(fichierProgEnC == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire ( dans overtureFichierC ).\n");
		exit(1);
	}
	fputs("#include <stdio.h>\n",fichierProgEnC);
	fputs("int main(){\n",fichierProgEnC);
	fputs("// la declaration des variables et des constantes\n",fichierProgEnC);
}

void declarationEnReChCa(char *typeVouC){
	int i;
	int nbrVarADeclarer; // le nombre de variable que cette fonction va declares dans le fichier .c
	int nbrConstADeclarer; // le nombre de constantes que cette fonction va declares dans le fichier .c
	char *leType = NULL;
	identifiant *varOuConst = NULL;
	constante *cst = NULL;

	// determination du type de la variable ou la constante
	if(strcmp(typeVouC,"entier") == 0){ // le type entier
		leType = malloc(5*sizeof(char));
		if(leType == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n ");
			exit(1);
		}
		strcpy(leType,"int ");
	}
	if(strcmp(typeVouC,"reel") == 0){ // le type reel
		leType = malloc(8*sizeof(char));
		if(leType == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n ");
			exit(1);
		}
		strcpy(leType,"double ");
	}
	if(strcmp(typeVouC,"chaine") == 0){ // le type chaine
		leType = malloc(6*sizeof(char));
		if(leType == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n ");
			exit(1);
		}
		strcpy(leType,"char ");
	}
	if(strcmp(typeVouC,"caractere") == 0){ // le type caractere
		leType = malloc(6*sizeof(char));
		if(leType == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n ");
			exit(1);
		}
		strcpy(leType,"char ");
	}

	// la declaration des variables dans le fichier .c 
	if(estVariable == 1){
		nbrVarADeclarer = pileIdentifiants.nombreElement - nbrConstDecEnC - nbrVarDecEnC; 
		varOuConst = malloc(sizeof(identifiant));
		if(varOuConst == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n");
			exit(1);
		}
		varOuConst = pileIdentifiants.premier;
		if(strcmp(leType,"char ") == 0 && strcmp(typeVouC,"chaine") == 0){ // si la variable est de type chaine de caractere
			for(i=1; i<=nbrVarADeclarer; i++){
				if(i == 1) fputs(leType,fichierProgEnC);
				if(i != nbrVarADeclarer){
					fprintf(fichierProgEnC,"*%s ,",varOuConst->mot);
					varOuConst = varOuConst->suivant;
				}
				else{
					fprintf(fichierProgEnC," *%s;\n",varOuConst->mot);
				}
			}
		}
		else{ // si la variable est de type autre que chaine
			for(i=1; i<=nbrVarADeclarer; i++){
				if(i == 1) fputs(leType,fichierProgEnC);
				if(i != nbrVarADeclarer){
					fprintf(fichierProgEnC,"%s ,",varOuConst->mot);
					varOuConst = varOuConst->suivant;
				}
				else{
					fprintf(fichierProgEnC,"%s;\n",varOuConst->mot);
				}
			}
		}
		nbrVarDecEnC = nbrVarDecEnC + nbrVarADeclarer;/* ajouter le nombre de variables declares dans cette fonction
		au nombre des variables qu'on a dejas declares */ 
	}

	// la declaration des constantes dans le fichier .c
	if(estConstante == 1){
		nbrConstADeclarer = pileIdentifiants.nombreElement - nbrVarDecEnC - nbrConstDecEnC;
		varOuConst = malloc(sizeof(identifiant));
		if(varOuConst == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n");
			exit(1);
		}
		varOuConst = pileIdentifiants.premier;
		
		cst = malloc(sizeof(constante));
		if(cst == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n");
			exit(1);
		}
		cst = pileConstantes.premier;
		
		for(i=0; i<nbrConstADeclarer; i++){
			fputs("const ",fichierProgEnC);
			fputs(leType,fichierProgEnC);
			if(strcmp(leType,"char ") == 0 && strcmp(typeVouC,"chaine") == 0){ // si la constante est du type chaine
				fprintf(fichierProgEnC,"%s[] = %s;\n",varOuConst->mot,cst->valConstanteS);
				varOuConst = varOuConst->suivant;
				cst = cst->suivant;
			}
			if(strcmp(leType,"double ") == 0){ // si la constante est de type reel
				fprintf(fichierProgEnC,"%s = %lf;\n",varOuConst->mot,cst->valConstanteD);
				varOuConst = varOuConst->suivant;
				cst = cst->suivant;
			}
			if(strcmp(leType,"int ") == 0){ // si la constante est du type entier
				fprintf(fichierProgEnC,"%s = %d;\n",varOuConst->mot,cst->valConstanteE);
				varOuConst = varOuConst->suivant;
				cst = cst->suivant;
			}
			if(strcmp(leType,"char ") == 0 && strcmp(typeVouC,"caractere") == 0){ // si la constante est du type caractere
				fprintf(fichierProgEnC,"%s = \'%c\';\n",varOuConst->mot,cst->valConstanteC);
				varOuConst = varOuConst->suivant;
				cst = cst->suivant;
			}
		}
		nbrConstDecEnC = nbrConstDecEnC + nbrConstADeclarer;/* ajouter le nombre de constantes declares dans cette fonction
		au nombre des constantes qu'on a dejas declares */ 
	}
	
}

pileValConst creerPileConsts(){
	pileValConst pile;
	pile.nombreConstantes = 0;
	pile.premier = NULL;
	return pile;
}

void prendreValConst(char * valeurC){
	valConstante = malloc((strlen(valeurC)+1)*sizeof(char));
	if(valConstante == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreValConst).\n");
		exit(1);
	}
	strcpy(valConstante,valeurC);
}

void prendreNomConst(char *nom){
	nomConstante = malloc((strlen(nom)+1)*sizeof(char));
	if(nomConstante == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreNomConst).\n");
		exit(1);
	}
	strcpy(nomConstante,nom);
}

void empilerValConst(pileValConst *p,pileIdentifs *pE, char *typeC){
	constante *elementCourant = NULL;
	identifiant *elem = NULL;
	elementCourant = malloc(sizeof(constante));
	if(elementCourant == NULL){
		printf("ERREUR : probleme d'allocation de la memoire dans (empilerValConst).\n");
		exit(1);
	}
	p->nombreConstantes++;
	if(strcmp(typeC,"entier") == 0){ // si la constante est de type entier 
		elementCourant->valConstanteE = atoi(valConstante);
	}
	if(strcmp(typeC,"reel") == 0){ // si la constante est de type reel
		elementCourant->valConstanteD = atol(valConstante);
	}
	if(strcmp(typeC,"caractere") == 0){ // si la constante est de type caractere
		elementCourant->valConstanteC = valConstante[1];
	}
	if(strcmp(typeC,"chaine") == 0){ // si la constante est de type chaine  
		// stocker la valeur de la constante dans la pile des valeur des constantes
		elementCourant->valConstanteS = malloc((strlen(valConstante)+1)*sizeof(char));
		if(elementCourant->valConstanteS == NULL){
			printf("ERREUR : problemme d'allocation dynamique de la memoire (dans empilerValConst).\n");
			exit(1);
		}
		strcpy(elementCourant->valConstanteS,valConstante);

		// stocker la valeur de la constante dans la pile des identifiants
		elem = malloc(sizeof(identifiant));
		if(elem == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans empiler).\n");
			exit(1);
		}
		elem = pE->premier;
		while(elem != NULL){
			if(strcmp(elem->mot,nomConstante) == 0){
				elem->valVarChaine = malloc((strlen(valConstante)+1)*sizeof(char));
				if(elem->valVarChaine == NULL){
					printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans empilerValConst).\n");
					exit(1);
				}
				strcpy(elem->valVarChaine,valConstante);
				break;
			}
			elem = elem->suivant;
		}
	}
	elementCourant->suivant = p->premier;
	p->premier = elementCourant;
}

void prendreTypeDec(char *typeVC){
	if(strcmp(typeVC,"entier") == 0){ // le type entier
		numeroType = 1;
	}
	if(strcmp(typeVC,"reel") == 0){ // le type reel
		numeroType = 2;
	}
	if(strcmp(typeVC,"chaine") == 0){ // le type chaine
		numeroType = 3;
	}
	if(strcmp(typeVC,"caractere") == 0){ // le type caractere
		numeroType = 4;
	}
}

void associerType(){
	identifiant *elem = NULL;
	elem = malloc(sizeof(identifiant));
	if(elem == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
		exit(1);
	}
	elem = pileIdentifiants.premier;
	while(elem != NULL && elem->numType == 0){
		elem->numType = numeroType;
		elem = elem->suivant;
	}
}

void prendreTypeAff(char *ident,int direction){ // direction : 1- pour gauche et 2- pour droite
	int i=0;
	int limiteEntreVarConst; // la limite entre les variables est les constantes
	identifiant *elem = NULL;
	elem = malloc(sizeof(identifiant));
	if(elem == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
		exit(1);
	}
	elem = pileIdentifiants.premier;

	while(elem != NULL){
		i++;
		if(strcmp(ident,elem->mot) == 0){
			if(direction == 1 && debutInstrAff == 1){// si on est au debut de l'instruction de l'affectation
				typeAffD = 0; // initialiser typeAffD pour une nouvelle affectation
				typeAffG = elem->numType;
				elem->estInitialise = 1; // pour s'assurer la prochaine fois qu'on utilise cette variable qu'elle est dejas initialise 
				if(estConstante == 1){ // si on a declare les variables avant les constantes
					// calcule de la limite 
					limiteEntreVarConst = pileConstantes.nombreConstantes;

					if(i <= limiteEntreVarConst){ // si l'affectation essaye de modifier une constante
						printf("( la ligne %d ) ERREUR : \" %s \" est une constante tu ne peut pas changer sa valeur.\n",lineNumber,ident);
					}
				}
				if(estVariable == 1){ // si on a declare les constantes avant les variables
					// calcule de la limite 
					limiteEntreVarConst = pileIdentifiants.nombreElement-pileConstantes.nombreConstantes;

					if(i > limiteEntreVarConst){ // si l'affectation essaye de modifier une constante
						printf("( la ligne %d ) ERREUR : \" %s \" est une constante tu ne peut pas changer sa valeur.\n",lineNumber,ident);
					}
				}
			} 
			if(direction == 2){ 
				typeAffDO = elem->numType;
				if(estInstrEcrireOuLire != 1) identifEstInitialise(ident); // pour savoire que la variable est initialise ou non si on est dans une affectation
			}
			return;
		}
		elem = elem->suivant;
	}
}

void identifEstInitialise(char *ident){
	identifiant *elem = NULL;
	elem = malloc(sizeof(identifiant));
	if(elem == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
		exit(1);
	}
	elem = pileIdentifiants.premier;

	while(elem != NULL){
		if(strcmp(ident,elem->mot) == 0){
			if(elem->estInitialise == 0){
				printf("( la ligne %d ) ERREUR : \" %s \" n'est pas initialise.\n",lineNumber,ident);
				break;
			}
		}
		elem = elem->suivant;
	}
}

void prendreSymOp(char *symbole){
	if(strcmp(symbole,"+") == 0) symboleOperation = 1;
	if(strcmp(symbole,"-") == 0) symboleOperation = 2;
	if(strcmp(symbole,"*") == 0) symboleOperation = 3;
	if(strcmp(symbole,"/") == 0) symboleOperation = 4;   
}

void prendreChaine(char *chainePr,int nature){
	identifiant *elem = NULL;
	if(nature == 1){ // si on traite une variable de type chaine
		if(vallCouVexiste(chainePr) == 0){ // si on a pas initialiser une variable de type chaine
			printf("( la ligne %d ) ERREUR : la variable %s n'a pas de valeur.\n",lineNumber,chainePr);
			return;
		}
		else{ // si on a dejas initialiser la variable de type chaine
			elem = malloc(sizeof(identifiant));
			if(elem == NULL){
				printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
				exit(1);
			}
			elem = pileIdentifiants.premier;
			while(elem != NULL){
				if(strcmp(chainePr,elem->mot) == 0){
					strcpy(elem->valVarChaine,corrigerChaine(elem->valVarChaine));
					chainePrincipale = malloc((strlen(elem->valVarChaine)+1)*sizeof(char));
					if(chainePrincipale == NULL){
						printf("ERREUR : probleme d'allocation dynamique de la memoire dans (prendreChaine).\n");
						exit(1);
					}
					
					if(elem->valVarChaine != NULL) strcpy(chainePrincipale,elem->valVarChaine);  
					break;
				}
				elem = elem->suivant;
			}
		}
	}
	else{ // si on traite une valeur de type chaine
		strcpy(chainePr,corrigerChaine(chainePr));
		chainePrincipale = malloc((strlen(chainePr)+1)*sizeof(char));
		if(chainePrincipale == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire dans (prendreChaine).\n");
			exit(1);
		}
		strcpy(chainePrincipale,chainePr);
	}	
}

void typeAffDestValide(char *identOuVal,int nature){
	identifiant *elem = NULL;
	if(typeAffD == 0){ // si on a tombe dans le premeir operande 
		typeAffD = typeAffDO; 
		if(typeAffDO == 4 && typeAffG == 3) typeAffD = 3; // si le premier operande est un caractere et typeAffG = 3 on va le considerer comme une chaine 
		if(typeAffD == 3) prendreChaine(identOuVal,nature); // si cet operande est de type chaine
	}
	else{ // si on a dejas passe par d'autre operande 
		// comparaison du type de la partie gauche et le type de la partie droite de l'affectation
		if((typeAffG == 1 || typeAffG == 2 || typeAffG == 4) && typeAffD == 3){
			printf("( la ligne %d ) ERREUR : le type de \" %s \" est incompatible.\n ",lineNumber,identOuVal);
			return;
		}
		if(typeAffG == 3 && (typeAffD == 1 || typeAffD == 2 || typeAffD == 4)){
			printf("( la ligne %d ) ERREUR : le type de \" %s \" est incompatible.\n ",lineNumber,identOuVal);
			return;
		}
		// comparaison du type de l'operande actuile et le type de l'expretion arethmetique precedent
		// les cas ou les types son incompatible
		if(typeAffD == 1 || typeAffD == 2 || typeAffD == 4 ){
			if(typeAffDO == 3){
				printf("( la ligne %d ) ERREUR : operation impossible le type de \" %s \" est incompatible.\n",lineNumber,identOuVal);
				return;
			}
			else{
				typeAffD = 2; // quel que soit le type de l'expresion precedent on va toujour garder le resultat comme etant une valeur reel 
			}
		}
		if(typeAffD == 3){ // les operation entre les chaines
			
			if(typeAffDO == 1 || typeAffDO == 2){
				printf("( la ligne %d ) ERREUR : operation impossible le type de \" %s \" est incompatible.\n",lineNumber,identOuVal);
				return;
			}
			else{
				if(symboleOperation == 2 || symboleOperation == 3 || symboleOperation == 4){
					if(symboleOperation == 2) printf("( la ligne %d ) ERREUR : l'operation \" - \" est imposible dans le type chaine.\n",lineNumber);
					if(symboleOperation == 3) printf("( la ligne %d ) ERREUR : l'operation \" * \" est imposible dans le type chaine.\n",lineNumber);
					if(symboleOperation == 4) printf("( la ligne %d ) ERREUR : l'operation \" / \" est imposible dans le type chaine.\n",lineNumber);
					return;
				}
				if(symboleOperation == 1){ // la concatenation
					
					if(nature == 1){ // si on traite une variable de type chaine 
						if(vallCouVexiste(identOuVal) == 0){ // si la variable n'est pas initialise
							printf("( la ligne %d ) ERREUR : la variable %s n'a pas de valeur.\n",lineNumber,identOuVal);
							return;
						}
						else{ // si on a dejas initialiser la variable de type chaine
							elem = malloc(sizeof(identifiant));
							if(elem == NULL){
								printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
								exit(1);
							}
							elem = pileIdentifiants.premier;
							// on garde la valeur qui est stocker dans chainePrincipale 
							chaineSecondere = malloc((strlen(chainePrincipale)+1)*sizeof(char));
							if(chaineSecondere == NULL){
								printf("ERREUR : probleme d'allocation dynamique de la memoire dans (typeAffDestValide).\n");
								exit(1);
							}
							strcpy(chaineSecondere,chainePrincipale);
							free(chainePrincipale);
							chainePrincipale = NULL;

							while(elem != NULL){
								if(strcmp(identOuVal,elem->mot) == 0){
									strcpy(elem->valVarChaine,corrigerChaine(elem->valVarChaine));
									chainePrincipale = malloc((strlen(chaineSecondere)+strlen(elem->valVarChaine)+1)*sizeof(char));
									if(chainePrincipale == NULL){
										printf("ERREUR : probleme d'allocation dynamique de la memoire dans (prendreChaine).\n");
										exit(1);
									}
									strcpy(chainePrincipale,chaineSecondere);
									strcat(chainePrincipale,elem->valVarChaine);
									return;
								}
								elem = elem->suivant;
							}
						}
					}
					else{
						
						chaineSecondere = malloc((strlen(chainePrincipale)+1)*sizeof(char));
						if(chaineSecondere == NULL){
							printf("ERREUR : probleme d'allocation dynamique de la memoire dans (typeAffDestValide).\n");
							exit(1);
						}
						strcpy(chaineSecondere,chainePrincipale);
						free(chainePrincipale);
						chainePrincipale = NULL;
						strcpy(identOuVal,corrigerChaine(identOuVal));
						chainePrincipale =  malloc((strlen(identOuVal)+strlen(chaineSecondere)+1)*sizeof(char));
						if(chainePrincipale == NULL){
							printf("ERREUR : probleme d'allocation dynamique de la memoire dans (typeAffDestValide).\n");
							exit(1); 
						}
						strcpy(chainePrincipale,chaineSecondere);
						strcat(chainePrincipale,identOuVal);
					}
					free(chaineSecondere);
					chaineSecondere = NULL;
				}
				
			}
		}
		
	}
}

int vallCouVexiste(char *ident){
	identifiant *elem = NULL;
	elem = malloc(sizeof(identifiant));
	if(elem == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
		exit(1);
	}
	elem = pileIdentifiants.premier;
	while(elem != NULL){
		if(strcmp(ident,elem->mot) == 0){ 
			if(elem->valVarChaine == NULL) return 0;
			else return 1;
		}
		elem = elem->suivant;
	}
}

void prendreChSource(char *chaineS){
	chaineSource = malloc((strlen(chaineS)+1)*sizeof(char));
	if(chaineSource == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire dans (prendreChSource).\n");
		exit(1);
	}
	strcpy(chaineSource,chaineS);
}

void executerAffCh(){
	identifiant *elem = NULL;
	elem = malloc(sizeof(identifiant));
	if(elem == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
		exit(1);
	}
	elem = pileIdentifiants.premier;
	while(elem != NULL){
		if(strcmp(chaineSource,elem->mot) == 0){
			elem->valVarChaine = malloc((strlen(chainePrincipale)+1)*sizeof(char));
			if(elem->valVarChaine == NULL){
				printf("ERREUR : probleme d'allocation dynamique de la memoire dans (executerAffCh).\n");
				exit(1);
			}
			strcpy(elem->valVarChaine,chainePrincipale);
			free(chainePrincipale);
			chainePrincipale = NULL;
			free(chaineSource);
			chaineSource = NULL;
			return;
		}
		elem = elem->suivant;
	}
}

char *corrigerChaine(char *chaineNC){
	int i = 1,j;
	chaineNC[0] = chaineNC[1];
	j = i;
	for(i=1;i<strlen(chaineNC)-1;i++){
		j++;
		chaineNC[i] = chaineNC[j];
	}
	chaineNC[i-1] = '\0';
	return chaineNC;
}

void exprComprEstValide(int typeExpr){
	if(typeExpr == 3){
		printf("( la ligne %d ) ERREUR : la comparison est impossible dans le type chaine.\n",lineNumber);
	}
}

void typeVarSwitchEstValide(int typeVar){
	typeVarSwitch = typeVar;
	if(typeVar == 3){
		printf("( la ligne %d ) ERREUR : le type de la variable utilisee dans le switch doit etre different du type chaine.\n");
	}
}

void typeCasEstValide(int typeCas){// le cas ou la variable de switch est de type int et le type du cas est de type char ou le contraire est a voir apre
	if(typeVarSwitch != typeAffD){
		printf("( la ligne %d ) ERREUR : le type de la variable de switch est different du type de ce cas.\n",lineNumber);
	}
}

void stockerMessageCh(char *message){
	char *msg = NULL;
	if(chainePrincipale == NULL){
		chainePrincipale = malloc((strlen(message)+1)*sizeof(char));
		if(chainePrincipale == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans stockerMessageCh).\n");
			exit(1);
		}
		strcpy(chainePrincipale,corrigerChaine(message));
	}
	else{
		msg = malloc((strlen(chainePrincipale)+1)*sizeof(char));
		if(msg == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans stockerMessageCh).\n");
			exit(1);
		}
		strcpy(msg,chainePrincipale);
		free(chainePrincipale);
		chainePrincipale = NULL;
		chainePrincipale = malloc((strlen(msg)+strlen(message)+1)*sizeof(char));
		if(chainePrincipale == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans stockerMessageCh).\n");
			exit(1);
		}
		strcpy(chainePrincipale,msg);
		if(estFormateur == 0) strcat(chainePrincipale,corrigerChaine(message));
		else strcat(chainePrincipale,message);
		free(msg);
		msg = NULL;
	}
}

void stockerMessageIdent(char *nomIdent){
	char *msg = NULL;
	// determination du formateur et l'ajoutter dans la chainePrincipale
	estFormateur = 1;
	if(typeAffDO == 1) stockerMessageCh("%d");
	if(typeAffDO == 2) stockerMessageCh("%lf");
	if(typeAffDO == 3) stockerMessageCh("%s");
	if(typeAffDO == 4) stockerMessageCh("%c");
	// stocker le nom de la variable 
	if(chaineSecondere == NULL){
		chaineSecondere = malloc((strlen(nomIdent)+2)*sizeof(char));
		if(chainePrincipale == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans stockerMessageTdent).\n");
			exit(1);
		}
		strcpy(chaineSecondere,",");
		strcat(chaineSecondere,nomIdent);
	}
	else{
		msg = malloc((strlen(chaineSecondere)+1)*sizeof(char));
		if(msg == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans stockerMessageCh).\n");
			exit(1);
		}
		strcpy(msg,chaineSecondere);
		free(chaineSecondere);
		chaineSecondere = NULL;
		chaineSecondere = malloc((strlen(msg)+strlen(nomIdent)+2)*sizeof(char));
		if(chaineSecondere == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans stockerMessageCh).\n");
			exit(1);
		}
		strcpy(chaineSecondere,msg);
		strcat(chaineSecondere,",");
		strcat(chaineSecondere,nomIdent);
		free(msg);
		msg = NULL;
	}
	estFormateur = 0;
}

void formerMeg(){
	fputs("\"",fichierProgEnC);
	fputs(chainePrincipale,fichierProgEnC);
	fputs("\"",fichierProgEnC);
	fputs(chaineSecondere,fichierProgEnC);
}

void viderChaines(){
	free(chainePrincipale);
	chainePrincipale = NULL;
	free(chaineSecondere);
	chaineSecondere = NULL;
}

void prendreNomIdent(char *nomIdent){
	char *msg = NULL;
	// stocker le nom de la variable 
	if(chaineSecondere == NULL){
		chaineSecondere = malloc((strlen(nomIdent)+3)*sizeof(char));
		if(chaineSecondere == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreNomIdent).\n");
			exit(1);
		}
		strcpy(chaineSecondere,",&");
		strcat(chaineSecondere,nomIdent);
	}
	else{
		msg = malloc((strlen(chaineSecondere)+1)*sizeof(char));
		if(msg == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreNomIdent).\n");
			exit(1);
		}
		strcpy(msg,chaineSecondere);
		free(chaineSecondere);
		chaineSecondere = NULL;
		chaineSecondere = malloc((strlen(msg)+strlen(nomIdent)+3)*sizeof(char));
		if(chaineSecondere == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreNomIdent).\n");
			exit(1);
		}
		strcpy(chaineSecondere,msg);
		strcat(chaineSecondere,",&");
		strcat(chaineSecondere,nomIdent);
		free(msg);
		msg = NULL;
	}
}

void prendreTypeLire(char *type){
	char *msg = NULL;
	if(strcmp(type,"entier") == 0) typeAffD = 1;
	if(strcmp(type,"reel") == 0) typeAffD = 2;
	if(strcmp(type,"chaine") == 0) typeAffD = 3;
	if(strcmp(type,"caractere") == 0) typeAffD = 4;
	if(typeAffD != typeAffDO){
		printf("( la ligne %d ) ERREUR : le type de la donne a stocke est different du type de la variable distinataire.\n",lineNumber);
		return;
	}
	if(chainePrincipale == NULL){
		chainePrincipale = malloc(4*sizeof(char));
		if(chainePrincipale == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreTypeLire).\n");
			exit(1);
		}
		if(typeAffD == 1) strcpy(chainePrincipale,"%d");
		if(typeAffD == 2) strcpy(chainePrincipale,"%lf");
		if(typeAffD == 3) strcpy(chainePrincipale,"%s");
		if(typeAffD == 4) strcpy(chainePrincipale,"%c");
	}
	else{
		msg = malloc((strlen(chainePrincipale)+1)*sizeof(char));
		if(msg == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreTypeLire).\n");
			exit(1);
		}
		strcpy(msg,chainePrincipale);
		free(chainePrincipale);
		chainePrincipale = NULL;
		chainePrincipale = malloc((strlen(msg)+5)*sizeof(char));
		if(chainePrincipale == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreTypeLire).\n");
			exit(1);
		}
		strcpy(chainePrincipale,msg);
		if(typeAffD == 1) strcat(chainePrincipale," %d");
		if(typeAffD == 2) strcat(chainePrincipale," %lf");
		if(typeAffD == 3) strcat(chainePrincipale," %s");
		if(typeAffD == 4) strcat(chainePrincipale," %c");
		free(msg);
		msg = NULL;
	}
}

void fermeturFichierC(){
	fputs("return 0;\n}",fichierProgEnC);
	fclose(fichierProgEnC);
}
