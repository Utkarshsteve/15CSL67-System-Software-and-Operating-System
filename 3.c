#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int i,j,k,n,row,col;
char st[20],ip[20];
char m[2][3][10]={{"aBa","E","E"},{"n","bB","E"}};
int size[2][3]={{3,1,1},{1,2,1}};
printf("Enter string:");scanf("%s",ip);
strcat(ip,"$");
n=strlen(ip);
st[0]='$';
st[1]='A';
i=1;j=0;
printf("\nStack\t\tInput\n");
printf("________\t\t________\n");
while(st[i]!='$'&&ip[j]!='$')
{
        if(st[i]==ip[j])
        {
                i--;
                j++;
        }
        
        switch(st[i])
        {
                case 'A':row=0;break;
                case 'B':row=1;break;
        
        }
        
        switch(ip[j])
        {
                case 'a':col=0;
                         if(st[i]=='$')
                         {
                                printf("Error");exit(0);
                         }
                         break;
                         
               case 'b':col=1;
                        if(st[i]=='$')
                        {
                                printf("Error");exit(0);
                        }
                        break;
              
              case '$':col=2;
                       if(st[i]!='$')
                       {
                                printf("Error");exit(0);
                       }
                       else
                       {
                                printf("Success");exit(0);
                       }
                       break;
                       
        }
        
        if(m[row][col][0]=='E')
        {
        printf("Error");exit(0);
        }
        else if(m[row][col][0]=='n')
                i--;
        else if(m[row][col][0]==ip[j])
        {
                for(k=size[row][col]-1;k>=0;k--)
                {
                st[i]=m[row][col][k];
                i++;
                }
        
        i--;
        }
        for(k=0;k<=i;k++)
        printf("%c",st[k]);
        printf("\t\t");
        for(k=j;k<=n;k++)
        printf("%c",ip[k]);
        printf("\n");
        }
        k--;
}
