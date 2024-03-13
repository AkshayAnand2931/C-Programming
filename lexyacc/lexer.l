/*lex program to match identifiers*/

%{

#include <stdio.h>
#include <string.h>
#include "y.tab.h"

%}

/* Rule selection */

%%

"=="    {return EQCOMP;}
">="    {return GREATEREQ;}
"<="    {return LESSEREQ;}
"!="    {return NOTEQ;}
"++"    {return INC;}
"--"    {return DEC;}
"||"    {return OROR;}
"&&"    {return ANDAND;}
"!"     {return NOT;}
"="     {return EQ;}
"("     {return OPENING_BRACKET;}
")"     {return CLOSING_BRACKET;}
"["     {return OPENING_ARRAY_INDEX;}
"]"     {return CLOSING_ARRAY_INDEX;}
"{"     {return OPENING_BRACE;}
"}"     {return CLOSING_BRACE;}
";"     {return SEMICOLON;}
","     {return COMMA;}

"int"       {return INT;}
"char"      {return CHAR;}
"float"     {return FLOAT;}
"double"    {return DOUBLE;}
"while"     {return WHILE;}
"for"       {return FOR;}
"do"        {return DO;}
"if"        {return IF;}
"else"      {return ELSE;}
"#include"  {return INCLUDE;}
"main"      {return MAIN;}

[a-zA-Z][a-zA-Z0-9_]*   {yylval.str = strdup(yytext); return ID;}
[0-9]+      {yylval.num = atoi(yytext); return NUM;}

\"([^\"\n])*\"      {yylval.str = strdup(yytext); return STRLITERAL;}
\<([^>\n])*\>       {yylval.str = strdup(yytext); return HEADER;}

[ \t\n]     ;//Ignore whitespace
.       {printf("Unknown tokens: %s\n",yytext);}    
%%