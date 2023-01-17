
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
#line 1 "syntaxe_generation.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "generation.h"

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
int eatBoucle;
int estFonction; /* variable qui va nous dir que nous somme entrain de declarer une fonction si sa valeur est 1 et sinon si sa valeur est 0 */
int niveauFonct;
int fonctPossedeArgs;/* la variable qui permet de dire qu'une fonction possede des arguments ou non */
int fonctEstTrouve; /* la variable qui permet de dire qu'une fonction existe ou non (pour ne pas afficher les autre erreur si une fonction n'existe pas)*/
int numArgum; /* la variable qui stock le numero de l'argument d'une fonction */
int estAppelFonct; /* la variable qui indique qu'une unstruction est une appelle d'une fonction */
int typeAffG_appelFonct; /* la variable qui va contenir le type de la partie gauche lors de l'appele d'une fonction*/
int nomFonctEstPasse;/* cette variable va nous indique qu'on a verifie l'existance d'une fonction l'hors de son appelle  */
int erreur;
int estRetourne;/* si sa valeur est 1 on est dans une instruction de return d'une fonction 0 sinon utilisee pour empecher l'affichage de l'erreur lier au changement de la valeur stockee dans une constante */
int estBoucle;/* si sa valeur est 1 on est dans une expresion conditionnele d'une boucle 0 sinon utilisee pour empecher l'affichage de l'erreur lier au changement de la valeur stockee dans une constante */
int varEstGlobale; /* la variable qui indique si une variable est globale pour une fonction ou non */
char c;
char *affAppeleFonct;
char *nomF;
char *identPour; /* la variable qui va stocker le nom de la variable utilise dans la boucle pour */
char *chaineSource;
char *chainePrincipale;
char *chaineSecondere;
char *chaineParametres;
char *nomConstante; /* variable qui va stocker le nom de la constante a chaque fois qu'on veut declarer une constante */
char *valConstante; /* variable qui va stocker la valeur de la constante a chaque fois qu'on veut convertire la declaration d'une constante dans le fichier .c*/
FILE *fichierProgEnC;
FILE *fichierHeader;
FILE *fichierFonction;
FILE *fichierVarGlobale;
extern FILE* yyin; 
int 	yylex(void); 
extern char *yytext;
void	yyerror(const char * msg); 
int 	lineNumber; 
pileIdentifs pileIdentifiants;
pileValConst pileConstantes;
fonction ExFonction;
pileFonctions pileFoncs;


/* Line 189 of yacc.c  */
#line 137 "syntaxeY.c"

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
     FONCTION = 303,
     ECRIRE = 304,
     LIRE = 305
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
#line 229 "syntaxeY.c"

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
#define YYLAST   270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  84
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNRULES -- Number of states.  */
#define YYNSTATES  224

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     9,    10,    13,    14,    17,    22,
      27,    30,    32,    33,    39,    43,    45,    48,    50,    51,
      52,    53,    63,    65,    67,    69,    71,    73,    75,    77,
      79,    80,    85,    88,    90,    91,    97,    99,   101,   103,
     105,   107,   109,   113,   114,   119,   120,   121,   129,   131,
     133,   135,   137,   139,   141,   143,   145,   147,   150,   154,
     158,   160,   161,   166,   168,   170,   172,   174,   176,   178,
     180,   182,   188,   196,   197,   203,   206,   208,   209,   210,
     218,   220,   222,   224,   225,   226,   227,   228,   229,   230,
     248,   249,   253,   254,   255,   256,   265,   266,   267,   276,
     277,   278,   279,   294,   298,   300,   301,   302,   307,   310,
     311,   312,   313,   319,   320,   321,   322,   323,   332,   336,
     338,   339,   341,   343,   344,   345,   346,   347,   357,   358,
     359,   360,   361,   371,   375
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      52,     0,    -1,    -1,    54,    53,    55,    67,    -1,    -1,
       3,     8,    -1,    -1,     4,    56,    -1,     4,    56,     5,
      60,    -1,     5,    60,     4,    56,    -1,    56,    57,    -1,
      57,    -1,    -1,    59,    10,    66,    58,    11,    -1,    59,
      12,     8,    -1,     8,    -1,    60,    61,    -1,    61,    -1,
      -1,    -1,    -1,     8,    62,     9,    65,    63,    10,    66,
      64,    11,    -1,    13,    -1,    14,    -1,    15,    -1,    16,
      -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,    -1,
       6,    68,    69,     7,    -1,    69,    70,    -1,    70,    -1,
      -1,     8,     9,    71,    72,    11,    -1,    84,    -1,    85,
      -1,    91,    -1,   107,    -1,   118,    -1,   123,    -1,    72,
      77,    76,    -1,    -1,    25,    73,    72,    26,    -1,    -1,
      -1,    72,    77,    74,    25,    75,    72,    26,    -1,   118,
      -1,    76,    -1,    65,    -1,     8,    -1,    21,    -1,    22,
      -1,    23,    -1,    24,    -1,    79,    -1,    35,    79,    -1,
      79,    83,    80,    -1,    25,    79,    26,    -1,    80,    -1,
      -1,    72,    81,    82,    72,    -1,    27,    -1,    28,    -1,
      29,    -1,    30,    -1,    31,    -1,    32,    -1,    33,    -1,
      34,    -1,    36,    78,    37,    69,     7,    -1,    36,    78,
      37,    69,    38,    69,     7,    -1,    -1,    39,     8,    86,
      87,     7,    -1,    87,    88,    -1,    88,    -1,    -1,    -1,
      40,    72,    89,    45,    90,    69,     7,    -1,    92,    -1,
     101,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    41,    93,     8,    94,    42,    95,    72,    96,    43,
      78,    97,    99,    45,    98,    69,     7,    -1,    -1,    44,
     100,    76,    -1,    -1,    -1,    -1,    10,    46,   102,    78,
      45,   103,    69,     7,    -1,    -1,    -1,    10,    45,   105,
      69,    46,   106,    78,     7,    -1,    -1,    -1,    -1,    48,
     108,     8,   109,    25,   111,    26,   114,   110,    55,     6,
      69,   115,     7,    -1,   111,    12,   112,    -1,   112,    -1,
      -1,    -1,     8,   113,    10,    66,    -1,    10,    66,    -1,
      -1,    -1,    -1,    47,   116,    72,   117,    11,    -1,    -1,
      -1,    -1,    -1,    10,   119,     8,   120,    25,   121,   122,
      26,    -1,   122,    12,    76,    -1,    76,    -1,    -1,   124,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    50,   125,    25,
     126,   111,   127,    26,   128,    11,    -1,    -1,    -1,    -1,
      -1,    49,   130,    25,   131,   134,   132,    26,   133,    11,
      -1,   134,    12,    76,    -1,    76,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    77,    77,    77,    78,    78,    80,    80,    80,    80,
      81,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      85,    85,    86,    86,    86,    86,    87,    87,    87,    87,
      89,    89,    90,    90,    91,    91,    91,    91,    91,    91,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    92,
      93,    93,    94,    94,    94,    94,    96,    96,    97,    97,
      97,    98,    98,    99,    99,    99,    99,    99,    99,   100,
     100,   103,   103,   104,   104,   105,   105,   106,   106,   106,
     108,   108,   108,   109,   109,   109,   109,   109,   109,   109,
     110,   110,   110,   111,   111,   111,   112,   112,   112,   114,
     114,   114,   114,   115,   115,   115,   116,   116,   117,   117,
     118,   118,   118,   118,   120,   120,   120,   120,   121,   121,
     121,   123,   123,   124,   124,   124,   124,   124,   125,   125,
     125,   125,   125,   126,   126
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
  "TANTQUE", "RETOURNE", "FONCTION", "ECRIRE", "LIRE", "$accept",
  "programme", "$@1", "entete", "declaration", "ls_vars", "l_vars", "$@2",
  "l_ident", "l_csts", "d_cst", "$@3", "$@4", "$@5", "val", "type",
  "corps", "$@6", "ls_instruction", "instruction", "$@7", "expr_ar", "$@8",
  "$@9", "$@10", "oper", "op_sym", "expr_cond", "expr_log", "expr_cmpr",
  "$@11", "op_cmpr", "op_log", "condition", "switch", "$@12", "les_cas",
  "un_cas", "$@13", "$@14", "boucle", "b_pour", "$@15", "$@16", "$@17",
  "$@18", "$@19", "$@20", "le_pas", "$@21", "b_tque", "$@22", "$@23",
  "b_ftque", "$@24", "$@25", "routine", "$@26", "$@27", "$@28", "ls_param",
  "param", "$@29", "rout_spec", "ret", "$@30", "$@31", "appel_fonct",
  "$@32", "$@33", "$@34", "ls_argument", "es_std", "e_std", "$@35", "$@36",
  "$@37", "$@38", "s_std", "$@39", "$@40", "$@41", "$@42", "msg", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    53,    52,    54,    54,    55,    55,    55,    55,
      56,    56,    58,    57,    59,    59,    60,    60,    62,    63,
      64,    61,    65,    65,    65,    65,    66,    66,    66,    66,
      68,    67,    69,    69,    71,    70,    70,    70,    70,    70,
      70,    70,    72,    73,    72,    74,    75,    72,    72,    72,
      76,    76,    77,    77,    77,    77,    78,    78,    79,    79,
      79,    81,    80,    82,    82,    82,    82,    82,    82,    83,
      83,    84,    84,    86,    85,    87,    87,    89,    90,    88,
      91,    91,    91,    93,    94,    95,    96,    97,    98,    92,
     100,    99,    99,   102,   103,   101,   105,   106,   104,   108,
     109,   110,   107,   111,   111,   111,   113,   112,   114,   114,
     116,   117,   115,   115,   119,   120,   121,   118,   122,   122,
     122,   123,   123,   125,   126,   127,   128,   124,   130,   131,
     132,   133,   129,   134,   134
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     0,     2,     0,     2,     4,     4,
       2,     1,     0,     5,     3,     1,     2,     1,     0,     0,
       0,     9,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     2,     1,     0,     5,     1,     1,     1,     1,
       1,     1,     3,     0,     4,     0,     0,     7,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     3,
       1,     0,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     7,     0,     5,     2,     1,     0,     0,     7,
       1,     1,     1,     0,     0,     0,     0,     0,     0,    17,
       0,     3,     0,     0,     0,     8,     0,     0,     8,     0,
       0,     0,    14,     3,     1,     0,     0,     4,     2,     0,
       0,     0,     5,     0,     0,     0,     0,     8,     3,     1,
       0,     1,     1,     0,     0,     0,     0,     9,     0,     0,
       0,     0,     9,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     2,     5,     1,     6,     0,     0,     0,
      15,     7,    11,     0,    18,     0,    17,    30,     3,     0,
      10,     0,     0,     0,     0,    16,     0,     8,    26,    27,
      28,    29,    12,    14,     0,     9,     0,   114,     0,     0,
      99,   128,   123,     0,    33,    36,    37,    38,    80,    81,
      82,    39,    40,    41,   121,   122,     0,    22,    23,    24,
      25,    19,    34,    83,    96,    93,     0,    51,   114,     0,
       0,    50,    61,    49,     0,    56,    60,    48,    73,     0,
       0,     0,    31,    32,    13,     0,     0,     0,     0,     0,
     115,     0,     0,    57,    52,    53,    54,    55,    45,     0,
       0,    69,    70,     0,     0,   100,   129,   124,     0,    43,
       0,    84,     0,     0,     0,     0,    59,     0,    42,    63,
      64,    65,    66,    67,    68,     0,     0,    58,     0,     0,
      76,     0,     0,   105,    20,    35,     0,    97,    94,   116,
      44,    46,    62,    71,     0,    77,    74,    75,   105,   134,
     130,   106,   125,   104,     0,    85,     0,     0,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,   119,     0,     0,    72,    78,   109,   133,   131,
       0,   103,   126,    86,    98,    95,     0,   117,    47,     0,
       0,   101,     0,   107,     0,     0,   118,     0,   108,     6,
     132,   127,     0,    79,     0,    87,     0,    92,   113,    90,
       0,   110,     0,     0,    88,     0,   102,    91,     0,   111,
       0,     0,    89,   112
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     3,     9,    11,    12,    56,    13,    15,
      16,    23,    85,   154,    71,    32,    18,    26,    43,    44,
      86,    72,    91,   117,   159,    73,    98,    74,    75,    76,
      99,   125,   103,    45,    46,   104,   129,   130,   161,   189,
      47,    48,    87,   136,   169,   195,   207,   218,   210,   213,
      49,    89,   157,    50,    88,   156,    51,    79,   131,   199,
     152,   153,   165,   191,   212,   215,   221,    52,    66,   114,
     158,   173,    53,    54,    81,   133,   167,   194,    55,    80,
     132,   164,   192,   150
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -103
static const yytype_int16 yypact[] =
{
      14,    36,    52,  -103,  -103,  -103,     7,    46,    48,    56,
    -103,    17,  -103,    31,  -103,    29,  -103,  -103,  -103,    48,
    -103,   242,    62,    63,    46,  -103,   185,    48,  -103,  -103,
    -103,  -103,  -103,  -103,   250,    46,    70,    18,     5,    76,
    -103,  -103,  -103,    87,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,    80,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,    85,  -103,  -103,    67,
      67,  -103,   246,  -103,    69,    16,  -103,  -103,  -103,    99,
      83,    86,  -103,  -103,  -103,   104,    88,   107,   185,     5,
    -103,    88,    13,    16,  -103,  -103,  -103,  -103,   224,   214,
     185,  -103,  -103,    88,    77,  -103,  -103,  -103,   242,  -103,
     186,  -103,   166,    79,   100,   226,  -103,   103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,    88,    19,  -103,    88,    -2,
    -103,   108,   224,   119,  -103,  -103,   105,  -103,  -103,  -103,
    -103,  -103,   246,  -103,   185,   246,  -103,  -103,   119,  -103,
     117,  -103,   133,  -103,   137,  -103,     5,   185,   224,    88,
     102,   109,    -3,   224,   123,   143,   119,   129,  -103,    88,
     150,   132,  -103,     2,   232,  -103,  -103,   152,  -103,  -103,
     242,  -103,  -103,   246,  -103,  -103,   224,  -103,  -103,   185,
     242,  -103,   149,  -103,   154,   120,  -103,   136,  -103,     7,
    -103,  -103,     5,  -103,   160,  -103,   185,   125,   181,  -103,
     128,  -103,   163,   224,  -103,    88,  -103,  -103,   185,   246,
     151,   167,  -103,  -103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,  -103,  -103,   -16,   164,    -1,  -103,  -103,   173,
       9,  -103,  -103,  -103,   162,  -102,  -103,  -103,   -84,   -41,
    -103,   -83,  -103,  -103,  -103,   -97,  -103,   -82,    30,    91,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,    74,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
      50,    38,  -103,  -103,  -103,  -103,  -103,   -38,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      77,   118,    83,   110,   112,   146,   134,   113,   115,   166,
      20,     7,     8,    67,   186,    68,   126,     1,    57,    58,
      59,    60,    19,   177,    25,    10,   143,    36,   187,    37,
      69,    77,    77,    24,    20,   149,    25,    14,   128,   116,
      70,    21,   142,    22,     4,   145,   101,   102,    77,   101,
     102,    77,     5,    77,    10,    38,    14,   144,    39,    63,
     160,   172,    17,    64,    65,    77,   178,    40,    41,    42,
      33,    83,    34,   171,   170,    67,   174,    68,   193,    62,
      57,    58,    59,    60,    78,    83,   183,    77,   198,   196,
      77,    84,    69,    90,    82,    36,    67,    37,    68,    92,
      93,    57,    58,    59,    60,   197,   100,   105,   106,   175,
      36,   107,    37,   109,   108,   111,   217,   128,    77,    83,
     205,    77,   208,    38,   138,   139,    39,   151,   141,   163,
      83,    77,   219,   148,   220,    40,    41,    42,    38,   185,
      36,    39,    37,   203,    36,   166,    37,   155,   168,   179,
      40,    41,    42,   180,   176,   182,    83,   184,   222,    36,
     200,    37,   190,   202,    77,   201,   206,    83,    38,   209,
     216,    39,    38,   214,    36,    39,    37,    77,   223,    83,
      40,    41,    42,   204,    40,    41,    42,    38,    35,    36,
      39,    37,    27,    36,   127,    37,    61,   135,   162,    40,
      41,    42,    38,   147,   181,    39,     0,    94,    95,    96,
      97,     0,   137,     0,    40,    41,    42,    38,     0,     0,
      39,    38,     0,     0,    39,     0,     0,     0,   211,    40,
      41,    42,    67,    40,    41,    42,     0,    57,    58,    59,
      60,   119,   120,   121,   122,   123,   124,    94,    95,    96,
      97,     0,   140,    94,    95,    96,    97,     0,   188,    28,
      29,    30,    31,    57,    58,    59,    60,    94,    95,    96,
      97
};

static const yytype_int16 yycheck[] =
{
      38,    98,    43,    86,    88,     7,   108,    89,    91,    12,
      11,     4,     5,     8,    12,    10,   100,     3,    13,    14,
      15,    16,     5,    26,    15,     8,     7,     8,    26,    10,
      25,    69,    70,     4,    35,   132,    27,     8,    40,    26,
      35,    10,   125,    12,     8,   128,    33,    34,    86,    33,
      34,    89,     0,    91,     8,    36,     8,    38,    39,    41,
     144,   158,     6,    45,    46,   103,   163,    48,    49,    50,
       8,   112,     9,   157,   156,     8,   159,    10,   180,     9,
      13,    14,    15,    16,     8,   126,   169,   125,   190,   186,
     128,    11,    25,     8,     7,     8,     8,    10,    10,    69,
      70,    13,    14,    15,    16,   189,    37,     8,    25,     7,
       8,    25,    10,    25,    10,     8,   213,    40,   156,   160,
     202,   159,   206,    36,    45,    25,    39,     8,    25,    12,
     171,   169,   215,    25,   218,    48,    49,    50,    36,     7,
       8,    39,    10,     7,     8,    12,    10,    42,    11,    26,
      48,    49,    50,    10,    45,    26,   197,     7,     7,     8,
      11,    10,    10,    43,   202,    11,     6,   208,    36,    44,
       7,    39,    36,    45,     8,    39,    10,   215,    11,   220,
      48,    49,    50,   199,    48,    49,    50,    36,    24,     8,
      39,    10,    19,     8,   103,    10,    34,    11,   148,    48,
      49,    50,    36,   129,   166,    39,    -1,    21,    22,    23,
      24,    -1,    46,    -1,    48,    49,    50,    36,    -1,    -1,
      39,    36,    -1,    -1,    39,    -1,    -1,    -1,    47,    48,
      49,    50,     8,    48,    49,    50,    -1,    13,    14,    15,
      16,    27,    28,    29,    30,    31,    32,    21,    22,    23,
      24,    -1,    26,    21,    22,    23,    24,    -1,    26,    17,
      18,    19,    20,    13,    14,    15,    16,    21,    22,    23,
      24
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    52,    54,     8,     0,    53,     4,     5,    55,
       8,    56,    57,    59,     8,    60,    61,     6,    67,     5,
      57,    10,    12,    62,     4,    61,    68,    60,    17,    18,
      19,    20,    66,     8,     9,    56,     8,    10,    36,    39,
      48,    49,    50,    69,    70,    84,    85,    91,    92,   101,
     104,   107,   118,   123,   124,   129,    58,    13,    14,    15,
      16,    65,     9,    41,    45,    46,   119,     8,    10,    25,
      35,    65,    72,    76,    78,    79,    80,   118,     8,   108,
     130,   125,     7,    70,    11,    63,    71,    93,   105,   102,
       8,    73,    79,    79,    21,    22,    23,    24,    77,    81,
      37,    33,    34,    83,    86,     8,    25,    25,    10,    25,
      72,     8,    69,    78,   120,    72,    26,    74,    76,    27,
      28,    29,    30,    31,    32,    82,    69,    80,    40,    87,
      88,   109,   131,   126,    66,    11,    94,    46,    45,    25,
      26,    25,    72,     7,    38,    72,     7,    88,    25,    76,
     134,     8,   111,   112,    64,    42,   106,   103,   121,    75,
      69,    89,   111,    12,   132,   113,    12,   127,    11,    95,
      78,    69,    76,   122,    72,     7,    45,    26,    76,    26,
      10,   112,    26,    72,     7,     7,    12,    26,    26,    90,
      10,   114,   133,    66,   128,    96,    76,    69,    66,   110,
      11,    11,    43,     7,    55,    78,     6,    97,    69,    44,
      99,    47,   115,   100,    45,   116,     7,    76,    98,    72,
      69,   117,     7,    11
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
        case 2:

/* Line 1455 of yacc.c  */
#line 77 "syntaxe_generation.y"
    {niveauFonct = 0;varEstGlobale = 0;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 82 "syntaxe_generation.y"
    { prendreTypeDec(yytext); associerType(); declarationEnReChCa(yytext);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 85 "syntaxe_generation.y"
    {prendreNomConst(yytext);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 85 "syntaxe_generation.y"
    { prendreValConst(yytext);typeAffDO = 3;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 85 "syntaxe_generation.y"
    {  prendreTypeDec(yytext); associerType(); empilerValConst(&pileConstantes,&pileIdentifiants,yytext); declarationEnReChCa(yytext); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 86 "syntaxe_generation.y"
    {typeAffDO = 1;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 86 "syntaxe_generation.y"
    {typeAffDO = 2;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 86 "syntaxe_generation.y"
    {typeAffDO = 3;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 86 "syntaxe_generation.y"
    {typeAffDO = 4;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 89 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs("int main(){\n",fichierProgEnC);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 89 "syntaxe_generation.y"
    {fermeturFichierC();;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 91 "syntaxe_generation.y"
    {if(typeAffG != 3){ if(niveauFonct == 0) fputs(" = ",fichierProgEnC); else fputs(" = ",fichierFonction);};}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 91 "syntaxe_generation.y"
    {if(typeAffG != 3){ if(niveauFonct == 0) fputs(";\n",fichierProgEnC); else fputs(";\n",fichierFonction);} else executerAffCh();;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 92 "syntaxe_generation.y"
    { if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 92 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 92 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 92 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 92 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 93 "syntaxe_generation.y"
    {if(estInstrEcrireOuLire == 1){ stockerMessageCh(yytext);} else {nature = 2; if(estAppelFonct == 0){typeAffDestValide(yytext,2);} if(typeAffDO != 3 && typeAffG !=3 && estAppelFonct == 0){if(typeAffDO == 4){if(niveauFonct == 0){ fputs("'",fichierProgEnC); fputs(corrigerChaine(yytext),fichierProgEnC); fputs("'",fichierProgEnC);} else{ fputs("'",fichierFonction); fputs(corrigerChaine(yytext),fichierFonction); fputs("'",fichierFonction);}}else{ if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);}}};}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 93 "syntaxe_generation.y"
    {prendreTypeAff(yytext,2); if(estInstrEcrireOuLire == 1){ stockerMessageIdent(yytext); } else { nature = 1; if(estAppelFonct == 0){typeAffDestValide(yytext,1);}};}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 94 "syntaxe_generation.y"
    {prendreSymOp(yytext); if(typeAffD != 3){ if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);};}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 94 "syntaxe_generation.y"
    {prendreSymOp(yytext); if(typeAffD != 3){ if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);};}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 94 "syntaxe_generation.y"
    {prendreSymOp(yytext); if(typeAffD != 3){  if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);};}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 94 "syntaxe_generation.y"
    {prendreSymOp(yytext); if(typeAffD != 3){ if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);};}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 98 "syntaxe_generation.y"
    { exprComprEstValide(typeAffD); typeAffD = 0;;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 98 "syntaxe_generation.y"
    { exprComprEstValide(typeAffD);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 103 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs("}\n",fichierProgEnC); else fputs("}\n",fichierFonction);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 103 "syntaxe_generation.y"
    {if(niveauFonct == 0)  fputs("}\n",fichierProgEnC); else fputs("}\n",fichierFonction);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 104 "syntaxe_generation.y"
    {typeVarSwitchEstValide(typeAffDO); if(niveauFonct == 0) fputs(" ){\n",fichierProgEnC); else fputs(" ){\n",fichierFonction);;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 104 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs("}\n",fichierProgEnC); else fputs("}\n",fichierFonction);;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 106 "syntaxe_generation.y"
    {typeCasEstValide(typeAffD);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 106 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs(":\n{\n",fichierProgEnC); else fputs(":\n{\n",fichierFonction);;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 106 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs("break;\n}\n",fichierProgEnC); else fputs("break;\n}\n",fichierFonction);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 109 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs("for(",fichierProgEnC); else fputs("for(",fichierFonction);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 109 "syntaxe_generation.y"
    {typeVarPourEstValide();prendreIdentPour(yytext);;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 109 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs("=",fichierProgEnC); else fputs("=",fichierFonction);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 109 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs("; ",fichierProgEnC); else fputs("; ",fichierFonction);;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 109 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs("; ",fichierProgEnC); else fputs("; ",fichierFonction);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 109 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs("){\n",fichierProgEnC); else fputs("){\n",fichierFonction);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 109 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs("}\n",fichierProgEnC); else fputs("}\n",fichierFonction);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 110 "syntaxe_generation.y"
    {if(niveauFonct == 0) {fputs(identPour,fichierProgEnC);fputs("+=",fichierProgEnC);} else {fputs(identPour,fichierFonction);fputs("+=",fichierFonction);};}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 110 "syntaxe_generation.y"
    {typePasEstValide();;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 110 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs("1",fichierProgEnC); else fputs("1",fichierFonction);;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 111 "syntaxe_generation.y"
    {if(niveauFonct == 0) {fputs("while( ",fichierProgEnC);} else {fputs("while( ",fichierFonction);} estBoucle = 1;;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 111 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs(" ){\n",fichierProgEnC); else fputs(" ){\n",fichierFonction); estBoucle = 0;;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 111 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs("}\n",fichierProgEnC); else fputs("}\n",fichierFonction); boucleTQueFinie = 1;;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 112 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs("do{\n",fichierProgEnC); else fputs("do{\n",fichierFonction);;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 112 "syntaxe_generation.y"
    {if(niveauFonct == 0) {fputs("}while( ",fichierProgEnC);} else {fputs("}while( ",fichierFonction);} estBoucle = 1;;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 112 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs(");\n",fichierProgEnC); else fputs(");\n",fichierFonction);  boucleFTQueFinie = 1; estBoucle = 0;;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 114 "syntaxe_generation.y"
    {estFonction = 1;;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 114 "syntaxe_generation.y"
    {prendreNomFonction(yytext); fonctionEstValide(yytext);;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 114 "syntaxe_generation.y"
    {ecrireEnteteFonct(); empilerFonction(&pileFoncs); niveauFonct++; finDeclaration = 0; estFonction = 0;;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 114 "syntaxe_generation.y"
    {niveauFonct--;;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 116 "syntaxe_generation.y"
    {if(estInstrEcrireOuLire == 1){ prendreTypeAff(yytext,2); prendreNomIdent(yytext);} if(estFonction == 1){prendreNomParametre(yytext);};}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 116 "syntaxe_generation.y"
    {if(estInstrEcrireOuLire == 1){prendreTypeLire(yytext);} if(estFonction == 1){prendreTypeDec(yytext); associerType();};}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 117 "syntaxe_generation.y"
    {prendreTypeRetoure(yytext);;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 117 "syntaxe_generation.y"
    {ExFonction.typeRetoure = 0;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 118 "syntaxe_generation.y"
    {fputs("return ",fichierFonction);typeAffG = 0; typeAffD = 0; estRetourne = 1;;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 118 "syntaxe_generation.y"
    {verifierTypeRetoure();;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 118 "syntaxe_generation.y"
    {fputs(";\n}\n",fichierFonction); estRetourne = 0;;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 118 "syntaxe_generation.y"
    {if(ExFonction.typeRetoure != 0) printf("( la ligne %d ) ERREUR : la fonction \" %s \" doit retourner une donne.\n",lineNumber,ExFonction.nomFonction); fputs("}\n",fichierFonction);;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 120 "syntaxe_generation.y"
    {estAppelFonct = 1; typeAffG_appelFonct = typeAffG; typeAffG = 0; nomFonctEstPasse = 0;;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 120 "syntaxe_generation.y"
    {nomFonctEstPasse = 1; fonctionExiste(yytext); if(typeAffG_appelFonct == 3 && erreur == 0){ strcat(affAppeleFonct,yytext); } chaineParametres = NULL;;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 120 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs("(",fichierProgEnC); else fputs("(",fichierFonction); if(typeAffG_appelFonct == 3 && erreur == 0) strcat(affAppeleFonct,"("); numArgum = 1; debutInstrAff = 0; ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 120 "syntaxe_generation.y"
    {  ecrireLsParametres(); fonctAParams(nomF); verefierNbrArgums(); if(niveauFonct == 0) fputs(")",fichierProgEnC); else fputs(")",fichierFonction); nomFonctEstPasse = 0; if(typeAffG_appelFonct == 3 && erreur == 0){ comleterAffAppeleFonct();} estAppelFonct = 0;;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 121 "syntaxe_generation.y"
    {argumentEstValide(yytext); numArgum++;;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 121 "syntaxe_generation.y"
    {argumentEstValide(yytext); numArgum++;;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 121 "syntaxe_generation.y"
    {fonctNAPasParams(nomF);;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 124 "syntaxe_generation.y"
    {viderChaines(); if(niveauFonct == 0) fputs("scanf",fichierProgEnC); else fputs("scanf",fichierFonction);;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 124 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs("(",fichierProgEnC); else fputs("(",fichierFonction);;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 124 "syntaxe_generation.y"
    {formerMeg();;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 124 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs(")",fichierProgEnC); else fputs(")",fichierFonction);;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 124 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs(";\n",fichierProgEnC); else fputs(";\n",fichierFonction); estInstrEcrireOuLire = 0;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 125 "syntaxe_generation.y"
    {viderChaines(); if(niveauFonct == 0) fputs("printf",fichierProgEnC); else fputs("printf",fichierFonction);;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 125 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs("(",fichierProgEnC); else fputs("(",fichierFonction);;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 125 "syntaxe_generation.y"
    {formerMeg();;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 125 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs(")",fichierProgEnC); else fputs(")",fichierFonction);;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 125 "syntaxe_generation.y"
    {if(niveauFonct == 0) fputs(";\n",fichierProgEnC); else fputs(";\n",fichierFonction); estInstrEcrireOuLire = 0;}
    break;



/* Line 1455 of yacc.c  */
#line 2203 "syntaxeY.c"
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
#line 127 "syntaxe_generation.y"



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
	estFonction = 0;
	estAppelFonct = 0;
	nomFonctEstPasse = 0;
	typeAffG_appelFonct = 0;
	erreur = 0;
	estRetourne = 0;
	estBoucle = 0;
	/* declaration et creation de des piles utilisees */
	pileFoncs = creerPileFoncts();
	overtureFichierFonction();
	overtureFichierHeader();
	overtureFichierVarGlobale();
	printf("DEBUT compilation : \n");
	lineNumber=1;
	if(!yyparse()) printf("FIN compilation : \n");
	return 0;
}

/*####################################### LES FONCTIONS DE L'ANALYSE SYMENTIQUE #########################*/

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
		printf("ERREUR : probleme d'overture du fichier des mots cles.\n");
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
		if(estFonction == 1){ // la declaration des parametres d'une fonction
			if(ExFonction.listeParametres.nombreElement == 0){ 
				// si aucun identifiant n'est encors declare
				empilerIdentif(&(ExFonction.listeParametres),identifiant);
				//printf("( la ligne %d ) la variable qui a l'identifiant \" %s \" est declaree avec succe (etape 2-a).\n",lineNumber,identifiant);
			}
			else{ 
				// si on a dejas declare d'autre identifiant
				if(identifEstDeclarer(ExFonction.listeParametres,identifiant) == 1){
					// si il existe une autre variable dejas declaree dans la meme fonction qui prent le meme nom de la variable actuielle
					printf("( la ligne %d ) ERREUR : une variable nomee \" %s \" est deja declare.\n",lineNumber,identifiant);
					return;
				}
				else{
					// si aucune variable dejas decleree n'a le meme nom de la variable actuelle 
					empilerIdentif(&(ExFonction.listeParametres),identifiant);
					//printf("( la ligne %d ) la variable qui a l'identifiant \" %s \" est declaree avec succe (etape 2-b).\n",lineNumber,identifiant);
				}
			}
		}
		else{ // la declaration normale des variables
			if(pileIdentifiants.nombreElement == 0){ 
				// si aucun identifiant n'est encors declare
				empilerIdentif(&pileIdentifiants,identifiant);
				//printf("( la ligne %d ) la variable qui a l'identifiant \" %s \" est declaree avec succe (etape 2-a).\n",lineNumber,identifiant);
			}
			else{ 
				// si on a dejas declare d'autre identifiant
				if(identifEstDeclarer(pileIdentifiants,identifiant) == 1){
					// si il existe une autre variable dejas declaree dans la meme fonction qui prent le meme nom de la variable actuielle
					printf("( la ligne %d ) ERREUR : une variable nomee \" %s \" est deja declare.\n",lineNumber,identifiant);
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
		elem->estConst = 0; // c'est une variable
	}
	if(estConstante == 1){
		elem->estInitialise = 1; // la constante est toujour initialise a la declaration
		elem->estConst = 1; // c'est une constante
	}
	elem->niveauFonction = niveauFonct; // entrer le niveau de la fonction
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
	elementCourant = p.premier;
	do{
		if(strcmp(elementCourant->mot,identif) == 0){
			if(elementCourant->niveauFonction == niveauFonct) return 1;// si la variable est declare dans la meme fonction
			else{
				if(finDeclaration == 1 && elementCourant->estConst == 0){
					varEstGlobale = 1;// on presise que la variable est globale donc on doit l'ecrire dans fichierVarGlobale
					fputs("\nextern ",fichierVarGlobale);
					if(elementCourant->numType == 1) fputs("int ",fichierVarGlobale);
					if(elementCourant->numType == 2) fputs("double ",fichierVarGlobale);
					if(elementCourant->numType == 3) fputs("char *",fichierVarGlobale);
					if(elementCourant->numType == 4) fputs("char ",fichierVarGlobale);
				}
				return 2;// si la variable est declare dans une fonction pere de la fonction actuielle
			}
		}
		elementCourant = elementCourant->suivant;
		i++;
	}while(elementCourant != NULL);
	free(elementCourant);
	return 0; // si l'identifiant n'est pas trouve
}

void variableEstDeclaree(pileIdentifs p,char *identif){
	int identifEstTrouve = identifEstDeclarer(p,identif);
	if(identifEstTrouve == 1 || identifEstTrouve == 2){ 
		//printf("( la ligne %d ) la variable\" %s \" est dejas declaree tu peut l'utiliser.\n",lineNumber,identif);
	}
	else{
		printf("( la ligne %d ) ERREUR : la variable \" %s \" n'est pas encors declaree tu doit la declare dabord.\n",lineNumber,identif);
		erreur = 1;
	}
}

/*####################################### LES FONCTIONS DE LA GENERATION DE CODE #########################*/

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
	fputs("#include <string.h>\n",fichierProgEnC);
	fputs("#include <stdlib.h>\n",fichierProgEnC);
	fputs("#include \"header.h\"\n",fichierProgEnC);
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
		leType = malloc(5*sizeof(char));
		if(leType == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n ");
			exit(1);
		}
		strcpy(leType,"char");
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
		if(strcmp(leType,"char") == 0 && strcmp(typeVouC,"chaine") == 0){ // si la variable est de type chaine de caractere
			for(i=1; i<=nbrVarADeclarer; i++){
				if(i == 1){
					if(niveauFonct == 0) fputs(leType,fichierProgEnC);
					else{
						fputs(leType,fichierFonction);
					}
				}
				if(i != nbrVarADeclarer){
					if(niveauFonct == 0) fprintf(fichierProgEnC,"*%s ,",varOuConst->mot);
					else fprintf(fichierFonction,"*%s ,",varOuConst->mot);
					varOuConst = varOuConst->suivant;
				}
				else{
					if(niveauFonct == 0) fprintf(fichierProgEnC," *%s;\n",varOuConst->mot);
					else fprintf(fichierFonction," *%s;\n",varOuConst->mot);
				}
			}
		}
		else{ // si la variable est de type autre que chaine
			for(i=1; i<=nbrVarADeclarer; i++){
				if(i == 1){
					if(niveauFonct == 0) fputs(leType,fichierProgEnC);
					else fputs(leType,fichierFonction);
				}
				if(i != nbrVarADeclarer){
					if(niveauFonct == 0) fprintf(fichierProgEnC,"%s ,",varOuConst->mot);
					else fprintf(fichierFonction,"%s ,",varOuConst->mot);
					varOuConst = varOuConst->suivant;
				}
				else{
					if(niveauFonct == 0) fprintf(fichierProgEnC,"%s;\n",varOuConst->mot);
					else fprintf(fichierFonction,"%s;\n",varOuConst->mot);
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
			if(niveauFonct == 0){
				fputs("const ",fichierProgEnC);
				fputs(leType,fichierProgEnC);
			}
			else{
				fputs("const ",fichierFonction);
				fputs(leType,fichierFonction);
			}
			
			if(strcmp(leType,"char") == 0 && strcmp(typeVouC,"chaine") == 0){ // si la constante est du type chaine
				if(niveauFonct == 0) fprintf(fichierProgEnC," %s[] = %s;\n",varOuConst->mot,cst->valConstanteS);
				else fprintf(fichierFonction," %s[] = %s;\n",varOuConst->mot,cst->valConstanteS);
				varOuConst = varOuConst->suivant;
				cst = cst->suivant;
			}
			if(strcmp(leType,"double ") == 0){ // si la constante est de type reel
				if(niveauFonct == 0) fprintf(fichierProgEnC,"%s = %lf;\n",varOuConst->mot,cst->valConstanteD);
				else fprintf(fichierFonction,"%s = %lf;\n",varOuConst->mot,cst->valConstanteD);
				varOuConst = varOuConst->suivant;
				cst = cst->suivant;
			}
			if(strcmp(leType,"int ") == 0){ // si la constante est du type entier
				if(niveauFonct == 0) fprintf(fichierProgEnC,"%s = %d;\n",varOuConst->mot,cst->valConstanteE);
				else fprintf(fichierFonction,"%s = %d;\n",varOuConst->mot,cst->valConstanteE);
				varOuConst = varOuConst->suivant;
				cst = cst->suivant;
			}
			if(strcmp(leType,"char ") == 0 && strcmp(typeVouC,"caractere") == 0){ // si la constante est du type caractere
				if(niveauFonct == 0) fprintf(fichierProgEnC,"%s = \'%c\';\n",varOuConst->mot,cst->valConstanteC);
				else fprintf(fichierFonction,"%s = \'%c\';\n",varOuConst->mot,cst->valConstanteC);
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
		elementCourant->valConstanteD = atof(valConstante);
	}
	if(strcmp(typeC,"caractere") == 0){ // si la constante est de type caractere
		elementCourant->valConstanteC = valConstante[1];

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
	if(estFonction == 1) elem = ExFonction.listeParametres.premier;
	else elem = pileIdentifiants.premier;
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

				if(elem->estConst == 1 && estRetourne == 0 && estBoucle == 0){ // si l'affectation essaye de modifier une constante
					printf("( la ligne %d ) ERREUR : \" %s \" est une constante tu ne peut pas changer sa valeur.\n",lineNumber,ident);
				}
			} 
			if(direction == 2 && debutInstrAff == 0){ 
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
			printf("( la ligne %d ) ERREUR : la variable %s n'est pas initialisee.\n",lineNumber,chainePr);
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
		if(typeAffDO == 4 && typeAffG == 3) typeAffD = 3;  // si le premier operande est un caractere et typeAffG = 3 on va le considerer comme une chaine 
		// comparaison du type de la partie gauche et le type de la partie droite de l'affectation
		if((typeAffG == 1 || typeAffG == 2 || typeAffG == 4) && typeAffD == 3){
			printf("( la ligne %d ) ERREUR : le type de \" %s \" est incompatible.\n",lineNumber,identOuVal);
			return;
		}
		if(typeAffG == 3 && (typeAffD == 1 || typeAffD == 2 || typeAffD == 4)){
			printf("( la ligne %d ) ERREUR : le type de \" %s \" est incompatible.\n",lineNumber,identOuVal);
			return;
		}
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
							printf("( la ligne %d ) ERREUR : la variable %s n'est pas initialisee.\n",lineNumber,identOuVal);
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
			if(elem->valVarChaine == NULL && elem->estConst == 0) return 0;
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
			// ecreture dans le fichier
			if(niveauFonct == 0){
				fputs(chaineSource,fichierProgEnC);
				fputs(" = ",fichierProgEnC);
				fputs("malloc((strlen(\"",fichierProgEnC);
				fputs(chainePrincipale,fichierProgEnC);
				fputs("\")+1)*sizeof(char));\n",fichierProgEnC);
				fputs("if(",fichierProgEnC);
				fputs(chaineSource,fichierProgEnC);
				fputs(" == NULL){\nprintf(\"ERREUR : probleme d'allocation dynamique de la memoire.\");\nexit(1);\n}\n",fichierProgEnC);
				fputs("strcpy(",fichierProgEnC);
				fputs(chaineSource,fichierProgEnC);
				fputs(",\"",fichierProgEnC);
				fputs(chainePrincipale,fichierProgEnC);
				fputs("\");\n",fichierProgEnC);
			}
			else{
				fputs(chaineSource,fichierFonction);
				fputs(" = ",fichierFonction);
				fputs("malloc((strlen(\"",fichierFonction);
				fputs(chainePrincipale,fichierFonction);
				fputs("\")+1)*sizeof(char));\n",fichierFonction);
				fputs("if(",fichierFonction);
				fputs(chaineSource,fichierFonction);
				fputs(" == NULL){\nprintf(\"ERREUR : probleme d'allocation dynamique de la memoire.\");\nexit(1);\n}\n",fichierFonction);
				fputs("strcpy(",fichierFonction);
				fputs(chaineSource,fichierFonction);
				fputs(",\"",fichierFonction);
				fputs(chainePrincipale,fichierFonction);
				fputs("\");\n",fichierFonction);
			}

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
	if(chaineNC[0] == '"'){
		chaineNC[0] = chaineNC[1];
		j = i;
		for(i=1;i<strlen(chaineNC)-1;i++){
			j++;
			chaineNC[i] = chaineNC[j];
		}
		chaineNC[i-1] = '\0';
	}
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
	if(niveauFonct == 0){
		fputs("\"",fichierProgEnC);
		fputs(chainePrincipale,fichierProgEnC);
		fputs("\"",fichierProgEnC);
		fputs(chaineSecondere,fichierProgEnC);
	}
	else{
		fputs("\"",fichierFonction);
		fputs(chainePrincipale,fichierFonction);
		fputs("\"",fichierFonction);
		fputs(chaineSecondere,fichierFonction);
	}
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
		if(erreur != 1) printf("( la ligne %d ) ERREUR : le type de la donne a stocke est different du type de la variable distinataire.\n",lineNumber);
		erreur = 0;
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

void prendreIdentPour(char *ident){
	identPour = malloc((strlen(ident)+1)*sizeof(char));
	if(identPour == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreIdentPour).\n");
		exit(1);
	}
	strcpy(identPour,ident);
}

void typeVarPourEstValide(){
	if(typeAffG == 3){
		printf("( la ligne %d ) ERREUR : Impossible d'utiliser une variable de type chaine comme compteur de la boucle Pour.\n",lineNumber);
	}
}

void typePasEstValide(){
	if(typeAffDO == 3){
		printf("( la ligne %d ) ERREUR : le type du Pas doit etre different du type chaine.\n",lineNumber);
		return;
	}
	if(typeAffDO != typeAffG){
		printf("( la ligne %d ) ERREUR : le type du Pas est different du type de la variable utilisee comme compteur de la boucle Pour.\n",lineNumber);
	}
}

void prendreNomFonction(char *nomf){
	ExFonction.nomFonction = malloc((strlen(nomf)+1)*sizeof(char));
	if(ExFonction.nomFonction == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreNomFonction).\n");
		exit(1);
	}
	strcpy(ExFonction.nomFonction,nomf);
	ExFonction.listeParametres = creerPileIdentifes();
}

void prendreNomParametre(char *nomp){
	identEstValide(nomp);
}

void overtureFichierHeader(){
	fichierHeader = fopen("header.h","w");
	if(fichierHeader == NULL){
		printf("ERREUR : probleme d'overture du fichier header.h\n");
		exit(1);
	}
	fputs("#ifndef __header\n",fichierHeader);
	fputs("#define __header\n\n",fichierHeader);
}

void overtureFichierVarGlobale(){
	fichierVarGlobale = fopen("varGlobale.h","w");
	if(fichierVarGlobale == NULL){
		printf("ERREUR : probleme d'overture du fichier varGlobale.h\n");
		exit(1);
	}
	fputs("#ifndef __varGlobale\n",fichierVarGlobale);
	fputs("#define __varGlobale\n",fichierVarGlobale);
}

void overtureFichierFonction(){
	fichierFonction = fopen("fonction.c","w");
	if(fichierFonction == NULL){
		printf("ERREUR : probleme d'overture du fichier fonction.c\n");
		exit(1);
	}
	fputs("#include <stdio.h>\n",fichierFonction);
	fputs("#include <string.h>\n",fichierFonction);
	fputs("#include <stdlib.h>\n",fichierFonction);
	fputs("#include \"varGlobale.h\"\n",fichierFonction);
	fputs("#include \"header.h\"\n",fichierFonction);
}

void prendreTypeRetoure(char *type){
	if(strcmp(type,"entier") == 0){
		ExFonction.typeRetoure = 1;
	}
	if(strcmp(type,"reel") == 0){
		ExFonction.typeRetoure = 2;
	}
	if(strcmp(type,"chaine") == 0){
		ExFonction.typeRetoure = 3;
	}
	if(strcmp(type,"caractere") == 0){
		ExFonction.typeRetoure = 4;
	}
}

void ecrireEnteteFonct(){
	identifiant *elem = NULL;
	char *leType = NULL;
	if(ExFonction.typeRetoure == 0){
		fputs("void ",fichierFonction);
		fputs("void ",fichierHeader);
	}
	if(ExFonction.typeRetoure == 1){
		fputs("int ",fichierFonction);
		fputs("int ",fichierHeader);
	}
	if(ExFonction.typeRetoure == 2){
		fputs("double ",fichierFonction);
		fputs("double ",fichierHeader);
	}
	if(ExFonction.typeRetoure == 3){
		fputs("char *",fichierFonction);
		fputs("char *",fichierHeader);
	}
	if(ExFonction.typeRetoure == 4){
		fputs("char ",fichierFonction);
		fputs("char ",fichierHeader);
	}
	fputs(ExFonction.nomFonction,fichierFonction);
	fputs("(",fichierFonction);
	fputs(ExFonction.nomFonction,fichierHeader);
	fputs("(",fichierHeader);
	
	elem = malloc(sizeof(identifiant));
	if(elem == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
		exit(1);
	}
	elem = ExFonction.listeParametres.premier;

	while(elem != NULL){
			// determination du type de la variable ou la constante
		if(elem->numType == 1){ // le type entier
			leType = malloc(5*sizeof(char));
			if(leType == NULL){
				printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n ");
				exit(1);
			}
			strcpy(leType,"int ");
		}
		if(elem->numType == 2){ // le type reel
			leType = malloc(8*sizeof(char));
			if(leType == NULL){
				printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n ");
				exit(1);
			}
			strcpy(leType,"double ");
		}
		if(elem->numType == 3){ // le type chaine
			leType = malloc(7*sizeof(char));
			if(leType == NULL){
				printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n ");
				exit(1);
			}
			strcpy(leType,"char *");
		}
		if(elem->numType == 4){ // le type caractere
			leType = malloc(6*sizeof(char));
			if(leType == NULL){
				printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n ");
				exit(1);
			}
			strcpy(leType,"char ");
		}

		fputs(leType,fichierFonction);
		fputs(elem->mot,fichierFonction);
		if(elem->suivant != NULL) fputs(", ",fichierFonction);
		fputs(leType,fichierHeader);
		fputs(elem->mot,fichierHeader);
		if(elem->suivant != NULL) fputs(", ",fichierHeader);

		elem = elem->suivant;
	}
	fputs("){\n",fichierFonction);
	fputs(");\n",fichierHeader);
}

void verifierTypeRetoure(){
	if(ExFonction.typeRetoure == 0 && typeAffD != 0){
		printf("( la ligne %d ) ERREUR : le fonction \" %s \" ne retourn rien.\n",lineNumber,ExFonction.nomFonction);
		return;
	}
	if(typeAffD != ExFonction.typeRetoure){
		printf("( la ligne %d ) ERREUR : le type du retoure est incompatible.\n",lineNumber);
		return;
	}
}

pileFonctions creerPileFoncts(){
	pileFonctions pile;
	pile.nombreFonction = 0;
	pile.premier = NULL;
}

void empilerFonction(pileFonctions *pileF){
	fonction *fonctInter = NULL;
	pileF->nombreFonction++;
	fonctInter = malloc(sizeof(fonction));
	if(fonctInter == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans empilerFonction).\n");
		exit(1);
	}
	fonctInter->nomFonction = ExFonction.nomFonction;
	fonctInter->typeRetoure = ExFonction.typeRetoure;
	fonctInter->listeParametres.premier = ExFonction.listeParametres.premier;
	fonctInter->listeParametres.nombreElement = ExFonction.listeParametres.nombreElement;
	fonctInter->suivant = pileF->premier;
	pileF->premier = fonctInter;
}

void fonctionEstValide(char *nomFonct){
	fonction *fonctInter = NULL;
	fonctInter = malloc(sizeof(fonction));
	if(fonctInter == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans empilerFonction).\n");
		exit(1);
	}
	fonctInter = pileFoncs.premier;
	while(fonctInter != NULL){
		if(strcmp(fonctInter->nomFonction,nomFonct) == 0){
			printf("( la ligne %d ) ERREUR : une fonction a le meme nom \" %s \" est dejas declare.\n",lineNumber,nomFonct);
		}
		fonctInter = fonctInter->suivant;
	}
	free(fonctInter);
	fonctInter = NULL;
}

void fonctionExiste(char *nomf){
	fonction *fonctInter = NULL;
	int trouve = 0;
	fonctInter = malloc(sizeof(fonction));
	if(fonctInter == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans fonctionExiste).\n");
		exit(1);
	}
	fonctInter = pileFoncs.premier;
	while(fonctInter != NULL){
		nomF = NULL;
		if(strcmp(fonctInter->nomFonction,nomf) == 0){
			trouve = 1; // la fonction est trouve
			if(fonctInter->listeParametres.nombreElement == 0) fonctPossedeArgs = 0;
			else fonctPossedeArgs = 1;
			nomF = malloc((strlen(fonctInter->nomFonction)+1)*sizeof(char));
			if(nomF == NULL){
				printf("ERREUR : probleme d'allocation dynamique de la memoire (dans fonctionExiste).\n");
				exit(1);
			}
			strcpy(nomF,fonctInter->nomFonction);
		}
		fonctInter = fonctInter->suivant;
	}
	if(trouve == 0 ){
		printf("( la ligne %d ) ERREUR : la fonction \" %s \" n'est pas trouve (elle n'est pas encors deffinit).\n",lineNumber,nomf);
	}
	fonctEstTrouve = trouve;
}

void fonctAParams(char *nomf){
	if(fonctEstTrouve == 1 && fonctPossedeArgs == 0 && numArgum != 1){
		printf("( la ligne %d ) ERREUR : la fonction \" %s \" n'a aucun parametres (il ne faut pas mettre des arguments).\n",lineNumber,nomf);
	}
}

void fonctNAPasParams(char *nomf){
	if(fonctEstTrouve == 1 && fonctPossedeArgs == 1 && numArgum == 1){
		printf("( la ligne %d ) ERREUR : la fonction \" %s \" a des parametres (tu doit mettre les arguments correspondants).\n",lineNumber,nomf);
	}
}

void argumentEstValide(char *Arg){
	int i = 0;
	char *chaineSecour = NULL;
	fonction *fonctInter = NULL;
	identifiant *elem = NULL;
	if(fonctEstTrouve == 1){
		fonctInter = malloc(sizeof(fonction));
		if(fonctInter == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans fonctionExiste).\n");
			exit(1);
		}
		fonctInter = pileFoncs.premier;
		while(fonctInter != NULL){
			if(strcmp(fonctInter->nomFonction,nomF) == 0){
				elem = malloc(sizeof(identifiant));
				if(elem == NULL){
					printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
					exit(1);
				}
				elem = fonctInter->listeParametres.premier;	
				i = fonctInter->listeParametres.nombreElement;
				while(elem != NULL){
					if(i == numArgum){
						if(elem->numType != typeAffDO){
							printf("( la ligne %d ) ERREUR : dans la fonction \" %s \" le type de l'argument numero %d est incompatible.\n",lineNumber,fonctInter->nomFonction,numArgum);
							return;
						}
						else{
							if(chaineParametres == NULL){
								chaineParametres = malloc((strlen(Arg)+1)*sizeof(char));
								if(chaineParametres == NULL){
									printf("ERREUR : probleme d'allocation dynamique de la memoire (dans argumentEstValide).\n");
									exit(1);
								}
								strcpy(chaineParametres,Arg);
								return;
							}
							else{
								chaineSecour = malloc((strlen(chaineParametres)+1)*sizeof(char));
								strcpy(chaineSecour,chaineParametres);
								free(chaineParametres);
								chaineParametres = NULL;
								chaineParametres = malloc((strlen(Arg)+strlen(chaineSecour)+2)*sizeof(char));
								if(chaineParametres == NULL){
									printf("ERREUR : probleme d'allocation dynamique de la memoire (dans argumentEstValide).\n");
									exit(1);
								}
								strcpy(chaineParametres,Arg);
								strcat(chaineParametres,",");
								strcat(chaineParametres,chaineSecour);
								free(chaineSecour);
								chaineSecour = NULL;
								return;
							}
						}
					}
					i--;
					elem = elem->suivant;
				}
			}
			fonctInter = fonctInter->suivant;
		}
	}
}

void verefierNbrArgums(){
	fonction *fonctInter = NULL;
	if(fonctEstTrouve == 1){
		fonctInter = malloc(sizeof(fonction));
		if(fonctInter == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans fonctionExiste).\n");
			exit(1);
		}
		fonctInter = pileFoncs.premier;
		while(fonctInter != NULL){
			if(strcmp(fonctInter->nomFonction,nomF) == 0){
				if(fonctInter->listeParametres.nombreElement != numArgum-1){
					printf("( la ligne %d ) ERREUR : dans la fonction %s le nombre d'argument entres est incorrect (tu as oblie ou tu as ajouter un argument de plus).\n",lineNumber,nomF);
					return;
				}
			}
			fonctInter = fonctInter->suivant;
		}
	}
}

void typeRetoureEstValide(char *nomf){
	fonction *fonctInter = NULL;
	if(nomFonctEstPasse == 0){
		fonctInter = malloc(sizeof(fonction));
		if(fonctInter == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans fonctionExiste).\n");
			exit(1);
		}
		fonctInter = pileFoncs.premier;
		while(fonctInter != NULL){
			if(strcmp(fonctInter->nomFonction,nomf) == 0){
				if(typeAffG_appelFonct != 0){
					if(typeAffG_appelFonct != fonctInter->typeRetoure){
						printf("( la ligne %d ) ERREUR : le type de la donne retournee par la fonction \" %s \"est incompatible avec le type de la variable qui va contenir le resultat.\n",lineNumber,nomf);
						erreur = 1;
						return;
					}
					else{

						if(typeAffG_appelFonct == 3){
							affAppeleFonct = malloc(256*sizeof(char));
							if(affAppeleFonct == NULL){
								printf("ERREUR : probleme d'allocation dynamique de la memoire (dans typeRetoureEstValide).\n");
								exit(1);
							}
							strcpy(affAppeleFonct," ");
							if(niveauFonct == 0){
								fputs(chaineSource,fichierProgEnC);
								fputs(" = malloc((strlen(",fichierProgEnC);
							}
							else{
								fputs(chaineSource,fichierFonction);
								fputs(" = malloc((strlen(",fichierFonction);
							}
						}
					}
				}
			}
			fonctInter = fonctInter->suivant;
		}
		nomFonctEstPasse = 1;
	}
}

void comleterAffAppeleFonct(){
	if(niveauFonct == 0 && typeAffG_appelFonct == 3){
		fputs(")+1)*sizeof(char));\n",fichierProgEnC);
		fputs("if(",fichierProgEnC);
		fputs(chaineSource,fichierProgEnC);
		fputs(" == NULL){\n",fichierProgEnC);
		fputs("printf(\"ERREUR : probleme d'allocation dynamique de la memoire.\n\");\nexit(1);\n}\n",fichierProgEnC);
		fputs("strcpy(",fichierProgEnC);
		fputs(chaineSource,fichierProgEnC);
		fputs(",",fichierProgEnC);
		fputs(affAppeleFonct,fichierProgEnC);
		fputs(chaineParametres,fichierProgEnC);
		fputs("));\n",fichierProgEnC);
	}
	if(niveauFonct != 0 && typeAffG_appelFonct == 3){
		fputs(")+1)*sizeof(char));\n",fichierFonction);
		fputs("if(",fichierFonction);
		fputs(chaineSource,fichierFonction);
		fputs(" == NULL){\n",fichierFonction);
		fputs("printf(\"ERREUR : probleme d'allocation dynamique de la memoire.\n\");\nexit(1);\n}\n",fichierFonction);
		fputs("strcpy(",fichierFonction);
		fputs(chaineSource,fichierFonction);
		fputs(",",fichierFonction);
		fputs(affAppeleFonct,fichierFonction);
		fputs(chaineParametres,fichierFonction);
		fputs("));\n",fichierFonction);
	}
	
}

void ecrireLsParametres(){
	if(niveauFonct == 0){ fputs(chaineParametres,fichierProgEnC);}
	else fputs(chaineParametres,fichierFonction);
}


void fermeturFichierC(){
	fputs("return 0;\n}",fichierProgEnC);
	fclose(fichierProgEnC);
	fclose(fichierFonction);
	fputs("\n#endif",fichierHeader);
	fclose(fichierHeader);
	fputs("\n\n#endif",fichierVarGlobale);
	fclose(fichierVarGlobale);
}
