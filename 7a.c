//SJF
#include<stdio.h>
void main()
{
        int i,j,bt[10],n,pt[10],wt[10],tt[10];
        float at,aw,w1=0.0,t1=0.0,t;
        printf("\nEnter no. of jobs:"); scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("Enter burst time for Process %d:",i+1);
                scanf("%d",&bt[i]);
        }
        for(i=0;i<n;i++)
                for(j=i+1;j<n;j++)
                {
                        if(bt[j]<bt[i])
                        {
                                t=bt[i];
                                bt[i]=bt[j];
                                bt[j]=t;
                        }
                }
                wt[0]=0;
                for(i=0;i<n;i++)
                {
                        wt[i+1]=bt[i]+wt[i];
                        tt[i]=wt[i]+bt[i];
                        w1+=wt[i];
                        t1+=tt[i];
                }
                aw=w1/n;
                at=t1/n;
                printf("\nbt\twt\ttt\n");
                for(i=0;i<n;i++)
                        printf("%d\t%d\t%d\n",bt[i],wt[i],tt[i]);
                printf("aw=%f\nat=%f",aw,at);
                printf("\n");
                
}
