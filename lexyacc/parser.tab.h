
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
     INT = 258,
     CHAR = 259,
     FLOAT = 260,
     DOUBLE = 261,
     WHILE = 262,
     FOR = 263,
     DO = 264,
     IF = 265,
     SWITCH = 266,
     CASE = 267,
     BREAK = 268,
     DEFAULT = 269,
     ELSE = 270,
     INCLUDE = 271,
     MAIN = 272,
     TRUE = 273,
     FALSE = 274,
     RETURN = 275,
     SUBTRAC = 276,
     ID = 277,
     NUM = 278,
     STRLITERAL = 279,
     GREATER = 280,
     LESSER = 281,
     ADD = 282,
     EQ = 283,
     DIVIDE = 284,
     MULTIPLY = 285,
     EQCOMP = 286,
     GREATEREQ = 287,
     LESSEREQ = 288,
     NOTEQ = 289,
     INC = 290,
     DEC = 291,
     OROR = 292,
     ANDAND = 293,
     NOT = 294,
     LPAREN = 295,
     RPAREN = 296,
     LBRACKET = 297,
     RBRACKET = 298,
     LBRACE = 299,
     RBRACE = 300,
     SEMICOLON = 301,
     COMMA = 302,
     COLON = 303
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


