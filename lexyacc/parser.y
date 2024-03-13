%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yylineno;
extern char* yytext;
extern void yyerror(const char *s);
int error_flag = 0;
%}

%union {

    int num;
    char *str;

}

%token <num> NUM
%token <str> STRLITERAL HEADER ID
%token INT CHAR FLOAT DOUBLE WHILE FOR DO IF ELSE INCLUDE MAIN
%token EQCOMP GREATEREQ LESSEREQ NOTEQ INC DEC OROR ANDAND NOT EQ
%token OPENING_BRACKET CLOSING_BRACKET OPENING_ARRAY_INDEX CLOSING_ARRAY_INDEX
%token OPENING_BRACE CLOSING_BRACE SEMICOLON COMMA

%start program
%debug

%%

program : 
        | program statement
        ;

statement : OPENING_BRACE statement CLOSING_BRACE
          | variable_declaration SEMICOLON
          | assignment SEMICOLON
          | control_structure
          | expression SEMICOLON
          | INCLUDE HEADER
          ;

variable_declaration : type ID SEMICOLON
                     | type ID OPENING_ARRAY_INDEX NUM CLOSING_ARRAY_INDEX
                     ;

type : INT
     | CHAR
     | FLOAT
     | DOUBLE
     ;

assignment : ID EQ expression
           | ID OPENING_ARRAY_INDEX expression CLOSING_ARRAY_INDEX EQ expression
           ;

control_structure : IF OPENING_BRACKET expression CLOSING_BRACKET statement
                  | IF OPENING_BRACKET expression CLOSING_BRACKET statement ELSE statement
                  | WHILE OPENING_BRACKET expression CLOSING_BRACKET statement
                  | DO statement WHILE OPENING_BRACKET expression CLOSING_BRACKET
                  | FOR OPENING_BRACKET assignment SEMICOLON expression SEMICOLON assignment CLOSING_BRACKET statement
                  | FOR OPENING_BRACKET assignment SEMICOLON expression SEMICOLON expression CLOSING_BRACKET statement
                  ;

expression : expression EQCOMP expression
           | expression GREATEREQ expression
           | expression LESSEREQ expression
           | expression NOTEQ expression
           | expression INC
           | expression DEC
           | expression OROR expression
           | expression ANDAND expression
           | NOT expression
           | OPENING_BRACKET expression CLOSING_BRACKET
           | NUM
           | STRLITERAL
           | ID
           | ID OPENING_ARRAY_INDEX expression CLOSING_ARRAY_INDEX
           | expression '+' expression
           | expression '-' expression
           | expression '*' expression
           | expression '/' expression
           | '-' expression %prec NOT
           ;

%%

int main(){

    yyparse();
    return 0;
}

void yyerror(const char *s){
    printf("Error: %s, line number: %d, token: %s .\n",s,yylineno,yytext);
    error_flag = 1;
}

int yywrap(){

    if(error_flag == 0){
        printf("Valid Syntax\n");
    }
    return 1;
}