%{
        #include<stdio.h>
        #include"y.tab.h"
%}

%%
[+|\-|\*|\/|=|<|>|(|)|{|}|] {printf("Operator is:%s\n",yytext);return OP;}
int|char|bool|float|void|if|else|return|break|contine|printf|scanf|double|main {printf("Keyword is:%s\n",yytext);return KEY;}
_?[a-z|A-Z]_?[a-z|A-Z|0-9]* {printf("Identifier is:%s\n",yytext);return ID;}
. 
%%


