%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "factorial.h"
extern int yylex(void);
extern char *yytext;
extern int nlines;
extern FILE *yyin;
void yyerror(char *s);
%}

%verbose
%union
{
    float real;
}

%start Calculadora

%token <real> TKN_NUM
%token TKN_ATRIB
%token TKN_PTOVIRGULA
%token TKN_MULTI
%token TKN_DIV
%token TKN_MAIS
%token TKN_MENOS
%token TKN_PAA
%token TKN_PAF
%token TKN_COS
%token TKN_SEN
%token TKN_POTENCIA
%token TKN_RAIZ
%token TKN_FAT
%token <real> TKN_ID

%type <real> calc
%type <real> expr

%left TKN_MAS TKN_MENOS
%left TKN_MULT TKN_DIV

%%
Calculadora :   TKN_ID {printf("Valor de %s:", yytext);}  TKN_ATRIBUICAO expr TKN_PONTOEVIRGULA {printf("%5.2f\n", $4);} ; |
                calc calc {$2;} ;

Expressao :     TKN_NUM {$$=$1;}|
                expr TKN_MAIS expr {$$=$1+$3;}| 
                expr TKN_MENOS expr {$$=$1-$3;}|
                expr TKN_MULTI expr {$$=$1*$3;}|  
                expr TKN_DIV expr {$$=$1/$3;} |
                expr TKN_POTENCIA expr {$$=pow($1,$3);} |
                expr TKN_FAT {$$=factorial($1);} |
                TKN_PAA expr TKN_PAF  {$$=$2;}|
                TKN_RAIZ TKN_PAA expr TKN_PAF {$$=sqrt($3);} |
                TKN_COS TKN_PAA expr TKN_PAF {$$=cos($3);}| 
                TKN_SEN TKN_PAA expr TKN_PAF {$$=sin($3);} ;
%%

void yyerror(char *s)
{
    printf("Error %s",s);
}

float factorial(float n) 
{
	float x; float f=1;
	
	for (x=1; x<=n; x++) { 
		f *= x; 
	}
	return f;
}

int main(int argc,char **argv)
    {
    if (argc>1)
        yyin=fopen(argv[1],"rt");
    else
        yyin=stdin;

    yyparse();

    printf("\nLinhas analisadas: %d\n", nlines);

    return 0;
}

