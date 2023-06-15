#include<stdio.h>
#define MAX 30

int main()
{
    int i,j,n;
    
    int bt[MAX], wt[MAX], tat[MAX];
    
    float awt=0, atat=0;
    
    printf("Enter the Nuumber of Process=>");
    scanf("%d",&n);
    
    printf("Enter the number of Burst time of Each Process => ");
    for(i=0; i<n; i++)
    {
        printf("\n Process %d : ",i+1);
        scanf("%d",&bt[i]);
    }
    
    printf("\nProcess\tBurst Time\tWating Time\tTurnaround Time\n");
    
    for(i=0; i<n; i++)
    {
        wt[0]=0;
        tat[0]=0;
        
        for(j=0; j<i; j++)
        {
            wt[i]=wt[i]+bt[j];
            
        }
        
        tat[i] = wt[i]+bt[i];
        awt =  awt+wt[i];
        atat =   atat+tat[i]; 
        
        printf("%d\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }
    
    awt = awt/n;
    atat = atat/n;
    
    printf("Average Waiting Timr => %.2f ms\n",awt);
    printf("Average Turn Around Timr => %.2f ms\n",atat);
    
    
    
    return 0;
}

