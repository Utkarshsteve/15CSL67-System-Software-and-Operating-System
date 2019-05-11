%{
        #include<stdio.h>
        #include<stdlib.h>
%}

%token num
%left '+''-'
%left '*''/'

%%
E:expr {printf("%d\n",$$);exit(0);}
expr:expr'+'expr {$$=$1+$3;}
|expr'-'expr {$$=$1-$3;}
|expr'*'expr {$$=$1*$3;}
|expr'/'expr {if ($3==0) {printf("Division by zero error\n");exit(0);} else $$=$1/$3;}
|'('expr')' {$$=$2;}
|num {$$=$1;}
;
%%

int yyerror()
{
        printf("Error");
        exit(0);
}

int main()
{
        printf("Enter an expression:");
        yyparse();
}
