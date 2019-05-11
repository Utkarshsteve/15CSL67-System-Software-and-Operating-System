#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void FIFO(char[],char[],int,int);
void LRU(char[],char[],int,int);
int findLRU(int[],int);
int main()
{
        int f,l,i,ch,YN;
        char F[7],s[7];
        printf("Enter no. of frames:"); scanf("%d",&f);
        for(i=0;i<f;i++)
                F[i]=-1;
        do
        {
                printf("Enter String:"); scanf("%s",s);
                l=strlen(s);
                printf("\nEnter ch 1)FIFO 2)LRU 3)EXIT:");scanf("%d",&ch);
                switch(ch)
                {
                        case 1: for(i=0;i<f;i++)
                                        F[i]=-1;
                                FIFO(s,F,l,f);
                                break;
                                
                        case 2: for(i=0;i<f;i++)
                                        F[i]=-1;
                                LRU(s,F,l,f);
                                break;
                                
                        case 3: exit(0);
               }
               printf("\nTo continue Press 1 else Press 0:");scanf("%d",&YN);
        }while(YN==1);
    exit(0);        
}

void FIFO(char s[],char F[],int l,int f)
{
        int i,j=0,c=0,k,flag=0;
        printf("\n\nPage\tFrames\tFaults");
        for(i=0;i<l;i++)
        {     
                for(k=0;k<f;k++)
                {
                        if(F[k]==s[i])
                                flag=1;
                }
                
        if(flag==0)
        {
                printf("\n%c\t",s[i]);F[j]=s[i];j++;
                for(k=0;k<f;k++) printf("%c",F[k]);
                printf("\tPage Fault:%d",c);c++;
        
        }
        else
        {
                flag=0;
                printf("\n%c\t",s[i]);
                for(k=0;k<f;k++) printf("%c",F[k]);
                printf("\tNo page Fault");
        
        }
        if(j==f)
                j=0;
        }

}

void LRU(char s[],char F[],int l,int f)
{
        int k,c=0,flag1=0,flag2=0,faults=0,lru[10],i,pos;
        printf("\n\nPage\tFrames\tFaults");
        for(i=0;i<l;i++)
        {
                flag1=flag2=0;printf("\n%c\t",s[i]);
                for(k=0;k<f;k++)
                {
                        if(F[k]==s[i])
                        {
                        c++;lru[k]=c;
                        flag1=flag2=1;break;
                        }
        
                }
                
                if(flag1==0)
                {
                        for(k=0;k<f;k++)
                        {
                                if(F[k]==-1)
                                {
                                        c++;faults++;F[k]=s[i];
                                        lru[k]=c;flag2=1;break;
                                }
                        }
                
                }
                if(flag2==0)
                {
                        pos=findLRU(lru,f);c++;faults++;F[pos]=s[i];
                        lru[pos]=c;
                }
                for(k=0;k<f;k++) printf("%c",F[k]);
                if(flag1==0||flag2==0) printf("\tPage-Fault:%d",faults);
                else printf("\tNo page fault");
        }
}

int findLRU(int lru[],int f)
{
        int i,min=lru[0],pos=0;
        for(i=1;i<f;i++)
        {
                if(lru[i]<min)
                {
                        min=lru[i];pos=i;
                }
        }
        return pos;
}
