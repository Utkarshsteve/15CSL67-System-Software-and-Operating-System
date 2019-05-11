%{
        #include<stdio.h>
        #include "y.tab.h"
%}

%%
a {return A;}
b {return B;}
[\n] return '\n';
%%
