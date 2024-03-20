%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex();
extern int yylineno;
extern char* yytext;

#define MAX_ERROR 100
char error_buffer[MAX_ERROR][256];
int error_count = 0;

%}

%token INT CHAR FLOAT DOUBLE WHILE FOR DO IF SWITCH CASE BREAK DEFAULT ELSE INCLUDE MAIN 
%token TRUE FALSE RETURN SUBTRAC ID NUM STRLITERAL GREATER LESSER ADD EQ DIVIDE MULTIPLY 
%token EQCOMP GREATEREQ LESSEREQ NOTEQ INC DEC OROR ANDAND NOT LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE 
%token SEMICOLON COMMA COLON

%start Prog

%%

Prog : headers main LBRACE body return RBRACE
        ;

headers: INCLUDE headers
       |/*empty*/ 
       ;

main : datatype MAIN
     ;

datatype : INT
         | FLOAT
         | CHAR
         | DOUBLE
         ;

body : FOR LPAREN statement SEMICOLON condition SEMICOLON statement RPAREN LBRACE body RBRACE body
     | IF LPAREN condition RPAREN LBRACE body RBRACE else body
     | WHILE LPAREN condition RPAREN LBRACE body RBRACE body
     | statement SEMICOLON body
     | IF LPAREN condition RPAREN body else body
     | WHILE LPAREN condition RPAREN body
     | FOR LPAREN statement SEMICOLON condition SEMICOLON statement RPAREN body
     | SWITCH LPAREN expression RPAREN LBRACE case RBRACE
     | BREAK SEMICOLON body
     |/*empty*/ 
     ;

else : ELSE LBRACE body RBRACE
     | ELSE IF LPAREN condition RPAREN body else body
     | ELSE IF LPAREN condition RPAREN LBRACE body RBRACE else body
     |/*empty*/ 
     ;

case : CASE expression COLON body case 
     | DEFAULT COLON body
     | /*empty*/ 
     ;

condition : value relop value
          | value logical value
          | condition relop condition
          | condition logical condition 
          | LPAREN condition RPAREN
          | value
          | TRUE 
          | FALSE 
          ;

statement : datatype iden
          | ID EQ expression
          | ID relop expression
          | ID DEC
          | ID INC
          | DEC ID
          | INC ID
          ;

value : NUM
      | ID
      | STRLITERAL
      ;

iden : ID listvar init
     | ID listvar init COMMA iden
     ;

listvar : LBRACKET NUM RBRACKET listvar
        | LBRACKET ID RBRACKET listvar
        | /*empty*/
        ;

init : EQ expression
     | /*empty*/
     ;

expression : expression arithmetic expression
           | expression logical expression
           | expression relop expression
           | LPAREN expression RPAREN
           | value 
           ;

logical : ANDAND
        | OROR
        | NOT
        ;

arithmetic : ADD
           | SUBTRAC
           | MULTIPLY
           | DIVIDE
           ;

relop : LESSER
      | LESSEREQ
      | GREATER
      | GREATEREQ
      | EQCOMP
      | NOTEQ
      ;

return : RETURN value SEMICOLON
       | /*empty*/
       ;

%%

int yyerror(const char *s) {

  printf("Error at line %d: %s",yylineno,s);
  error_count++;
  return 0;
}

int main(int argc, char **argv) {
    yyparse();
    
  if(error_count == 0){
    printf("Parsing complete. No errors.");
  }
  else{
    printf("\n\nParsing failed with %d errors.\n",error_count);
  }
  return 0;
  
}