#include<stdio.h>
 int main()
{
    int burst_time[20],p[20],waiting_time[20],turnaround_time[20],i,j,n,total=0,pos,temp;
    float avg_waiting_time,avg_turnaround_time;
    printf("Enter number of process:");
    scanf("%d",&n);
  
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&burst_time[i]);
        p[i]=i+1;         
    }
  
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }
  
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
  
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
   
    waiting_time[0]=0;            
  
   
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
  
        total+=waiting_time[i];
    }
  
    avg_waiting_time=(float)total/n;      
    total=0;
  
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        turnaround_time[i]=burst_time[i]+waiting_time[i];   
        total+=turnaround_time[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],burst_time[i],waiting_time[i],turnaround_time[i]);
    }
  
    avg_turnaround_time=(float)total/n;    
    printf("\n\nAverage Waiting Time=%f",avg_waiting_time);
    printf("\nAverage Turnaround Time=%f\n",avg_turnaround_time);
}
