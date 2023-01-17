
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

extern YYSTYPE yylval;


