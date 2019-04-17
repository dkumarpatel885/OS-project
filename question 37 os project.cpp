#include<stdio.h>
#include<conio.h>
int main()
{
 int n;
 printf("\nEnter the number of Processes: ");
 scanf("%d",&n);
 int arival_time[10],burst_time[10],store_burst_time[10];
 int waiting_time[10],turnaround_time[10],completion_time[10];
 int i,j,lowest,count=0,time;
 double avg_waiting_time=0,avg_tt=0,last;
 /*for(i=0;i<n;i++)
 {
   printf("\nEnter arrival time of process %d : ",i+1);
   scanf("%d",&arival_time[i]);
 }*/
 for(i=0;i<n;i++)
 {
 	 printf("\nEnter arrival time of process %d : ",i+1);
   scanf("%d",&arival_time[i]);
   printf("\nEnter burst time of process %d : ",i+1);
   scanf("%d",&burst_time[i]);
 }
for(i=0;i<n;i++)
 store_burst_time[i]=burst_time[i];

  burst_time[9]=9999;
 for(time=0;count!=n;time++)
 {
   lowest=9;
  for(i=0;i<n;i++)
  {
   if(arival_time[i]<=time && burst_time[i]<burst_time[lowest] && burst_time[i]>0 )
   lowest=i;
  }
  burst_time[lowest]--;
  if(burst_time[lowest]==0)
  {
   count++;
   last=time+1;
   completion_time[lowest] = last;
   waiting_time[lowest] = last - arival_time[lowest] - store_burst_time[lowest];
   turnaround_time[lowest] = last - arival_time[lowest];
  
  }
 }
 printf("#############################################################################################\n");
 printf("pid \t arrival \tburst\t\twaiting \tturnaround \tcompletion");
 
 for(i=0;i<n;i++)
 {
   printf("\n %d \t   %d \t\t%d\t\t%d   \t\t%d\t\t%d",i+1,arival_time[i],store_burst_time[i],waiting_time[i],turnaround_time[i],completion_time[i]);
   avg_waiting_time = avg_waiting_time+ waiting_time[i];
   avg_tt = avg_tt + turnaround_time[i];
 }
 printf("\n\nAverage waiting time = %lf\n",avg_waiting_time/n);
 printf("Average Turnaround time = %lf",avg_tt/n);
 getch();
}

