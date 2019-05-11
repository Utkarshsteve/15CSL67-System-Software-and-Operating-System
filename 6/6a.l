%{
#include<stdio.h>
int sl=0;
int ml=0;
%}
%%
"/*"[a-zA-Z0-9' '\t\n]+"*/"	ml++;
"//".*	sl++;
%%

void main()
{
	yyin=fopen("input.c","r");
	yyout=fopen("output.c","w");
	yylex();
	fclose(yyin);
	fclose(yyout);
	printf("\nNumber of single line comments are = %d\n",sl); 
	printf("\nNumber of multiline comments are =%d\n",ml);
}
