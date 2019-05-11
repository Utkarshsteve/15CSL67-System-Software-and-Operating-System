%{
        #include<stdio.h>
        #include<stdlib.h>
        #include<string.h>
        
%}

%token A B

%%
input:S {printf("Parsed Successfully\n");exit(0);}
S:A S1 B|B
S1:A S1
|;
%%

extern FILE *yyin;
int main()
{
        char str[30];
        int n=0;
        for(int i=0;i<30;i++)
                str[i]='\0';
        printf("Enter n:"); scanf("%d",&n);
        for(int i=0;i<n;i++)
                strcat(str,"a");
        strcat(str,"b");
        strcat(str,"\0");
        printf("%s",str);printf("\n");
        FILE *input = fopen("input.txt","w");
        fprintf(input,"%s",str);
        fclose(input);
        input=fopen("input.txt","r");
        yyin=input;
        yyparse();        
}
int yyerror()
{
        printf("Error");exit(0);
}

int yywrap()
{
        return -1;
}
