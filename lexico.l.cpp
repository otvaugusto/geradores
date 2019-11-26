%{
#include <stdio.h>
#include <stdlib.h>
#include "sintatico.tab.h"
int nlines=0;
%}

DIGITO [0-9]
ID [a-zA-Z][a-zA-Z0-9_]*

%%
{DIGITO}+("."{DIGITO}+)?    {return(TKN_NUM);}
"="                         {return(TKN_ATRIB);}
";"                         {return(TKN_PTOVIRGULA);}
"*"                         {return(TKN_MULTI);}
"/"                         {return(TKN_DIV);}
"+"                         {return(TKN_MAIS);}
"-"                         {return(TKN_MENOS);}
"("                         {return(TKN_PAA);}
")"                         {return(TKN_PAF);}
"cos"                       {return(TKN_COS);}
"sen"                       {return(TKN_SEN);}
"^"                         {return(TKN_POTENCIA);}
"sqrt"                      {return(TKN_RAIZ);}
"!"                         {return(TKN_FAT);}
{ID}                        {return(TKN_ID);}
"\n"                        {nlines++;}

%%

