%{
#include "parser.tab.h"
#include <string.h>
extern void yyerror(const char *s);
int lineno = 1;
%}

%option yylineno
%option noyywrap
alpha [a-zA-Z_]
digit [0-9]
%%

"int"                           { return INT; }
"char"                          { return CHAR; }
"float"                         { return FLOAT; }
"double"                        { return DOUBLE; }
"while"                         { return WHILE; }
"for"                           { return FOR; }
"do"                            { return DO; }
"if"                            { return IF; }
"switch"                        {return SWITCH;}
"case"                          {return CASE;}
"break"                         {return BREAK;}
"default"                       {return DEFAULT;}
"else"                          { return ELSE; }
^"#include"[ ]*<.+\.h>          { return INCLUDE; }
"main()"                          { return MAIN; }
"true"                          { return TRUE; }
"false"                         { return FALSE; }
"return"                        { return RETURN; }
"-"                             { return SUBTRAC; }
[-]?{digit}+[.]?{digit}*        { return NUM; }
{alpha}({alpha}|{digit})*       { return ID; }
[']{alpha}[']                   { return STRLITERAL; }
["]{alpha}["]                   { return STRLITERAL; }
"=="                            { return EQCOMP; }
">="                            { return GREATEREQ; }
"<="                            { return LESSEREQ; }
"!="                            { return NOTEQ; }
"++"                            { return INC; }
"--"                            { return DEC; }
">"	                            { return GREATER; }
"<"	                            { return LESSER; }
"||"                            { return OROR; }
"&&"                            { return ANDAND; }
"!"                             { return NOT; }
"("                             { return LPAREN; }
")"                             { return RPAREN; }
"["                             { return LBRACKET; }
"]"                             { return RBRACKET; }
"{"                             { return LBRACE; }
"}"                             { return RBRACE; }
":"                             { return COLON; }
";"                             { return SEMICOLON; }
","                             { return COMMA; }
"+"                             { return ADD; }
"="                             { return EQ; }
"/"                             { return DIVIDE; }
"*"                             { return MULTIPLY; }
\/\/.*                          { ; }
\/\*(.*\n)*.*\*\/               { ; } 
[ \t]*                          { ; }
[\n]                            { lineno++;}
.                               { yyerror("Unknown character"); return *yytext;}

%%