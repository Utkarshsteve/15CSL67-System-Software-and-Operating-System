#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int l,i,j,z;
char ip[10],ac[20],act[10],st[10];
void check();
void main()
{
        puts("Grammar: E->E+T|T\nT->T*F|F\nF->(E)\nF->id");
        puts("Enter the string:");gets(ip);
        l=strlen(ip);
        strcpy(act,"SHIFT->");
        puts("STACk\tINPUT\tACTION");
        for(i=0;j<l;i++,j++)
        {
                if(ip[j]=='i'&&ip[j+1]=='d')
                {
                        st[i]=ip[j]; st[i+1]=ip[j+1];st[i+2]='\0';
                        ip[j]=' ';ip[j+1]=' ';
                        printf("\n$%s\t%s$\t%sid",st,ip,act);
                        check();
                }
                else
                {
                        st[i]=ip[j];st[i+1]='\0';
                        ip[j]=' ';
                        printf("\n$%s\t%s$\t%ssymbol",st,ip,act);
                        check();
                }
      }
}

void check()
{
        strcpy(ac,"REDUCE:");
        for(z=0;z<l;z++)
                if(st[z]=='('&&st[z+1]=='E'&&st[z+2]==')')
                {
                        st[z]='F';st[z+1]='\0';st[z+2]='\0';
                        printf("\n$%s\t%s$\t%sF->(E)",st,ip,ac);
                        i=i-2;
                }
                
       for(z=0;z<=l;z++)
                if(st[z]=='i'&&st[z+1]=='d')
                {
                        st[z]='F';st[z+1]='\0';
                        printf("\n$%s\t%s$\t%sF->(id)",st,ip,ac);
                        j++;
                
                }
                
      for(z=0;z<l;z++)
      {          if(st[z]=='T'&&st[z+1]=='*'&&st[z+2]=='F')
                {
                        st[z]='T';st[z+1]='\0';st[z+2]='\0';
                        printf("\n$%s\t%s$\t%sT->T*F",st,ip,ac);
                        i=i-2;
                }
                else if(st[z]=='F')
                {
                        st[z]=='T';
                        printf("\n$%s\t%s$\t%sT->F",st,ip,ac);
                
                }
         
     }
     
     for(z=0;z<l;z++)
      {          if(st[z]=='E'&&st[z+1]=='+'&&st[z+2]=='T'&&st[z+3]=='*')
                        break;
                 if(st[z]=='E'&&st[z+1]=='+'&&st[z+2]=='T')
                 if(ip[j+1]=='*')
                        break;
                else 
                {
                        st[z]=='E';st[z+1]='\0';st[z+2]='\0';
                        printf("\n$%s\t%s$\t%sE->E+T",st,ip,ac);
                        i=i-2;
                
                }
                else if(st[z]=='T')
                {
                        st[z]='E';
                        printf("\n$%s\t%s$\t%sE->T",st,ip,ac);
                }
         
     }               

}
