//Round Robin
#include<stdio.h>
void main()
{
        int s[10],st[10],p[10],n,i,j,w[10],t[10],tq,tst=0,w1=0;
        float tt=0.0,tw=0.0,aw,at;
        printf("Enter no. of process:");        scanf("%d",&n);
        printf("Enter quantum number:");        scanf("%d",&tq);
        for(i=0;i<n;i++)
        {
                printf("Enter bt[%d] and process %d:",i+1,i+1);
                scanf("%d %d",&s[i],&p[i]);
        }

        for(i=0;i<n;i++)
        {
                st[i]=s[i];
                tst+=s[i];
        }

        for(j=0;j<tst;j++)
                for(i=0;i<n;i++)
                {
                        if(s[i]>tq)
                        {
                                s[i]-=tq;
                                w1+=tq;
                                t[i]=w1;
                                w[i]=t[i]-st[i];
                        }
                        else if(s[i]!=0)
                        {
                                w1+=tq;
                                t[i]=w1;
                                w[i]=t[i]-st[i];
                                s[i]-=tq;  
                        }
        
                }
        
        for(i=0;i<n;i++)
        {
                tw+=w[i];
                tt+=t[i];
        }
        printf("\n");
        aw=tw/n;
        at=tt/n;
        printf("process\t tst\t twt\t tt\n");
        for(i=0;i<n;i++)
        printf("%d\t %d\t %d\t %d\n",p[i],st[i],w[i],t[i]);
        printf("awt=%f\tatt=%f",aw,at);
        printf("\n");
 }        
