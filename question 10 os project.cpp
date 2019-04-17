 #include <stdio.h>
#include<conio.h>
struct first{
	int a,b;
};
struct second{
	int c, d;
};

struct first SRTF(int n,int arrival_time[10],int burst_time[10],int temp[10])
	{
		printf("Shortest job remaining time scheduling algoritham is under processing\n");
		struct first re;
	int i, lowest, count = 0, time;
	double wait_time = 0, turnaround_time = 0, last;
	float average_waiting_time, average_turnaround_time;
	burst_time[9] = 9999;  
 	for(time = 0; count != n; time++)
 	{
   		lowest = 9;
  		for(i = 0; i < n; i++)
  		{
   			if(arrival_time[i] <= time && burst_time[i] < burst_time[lowest] && burst_time[i] > 0)
			{
   				lowest = i;
			}
  		}
  		burst_time[lowest]--;
  		if(burst_time[lowest] == 0)
  		{
   			count++;
   			last = time + 1;
   			wait_time = wait_time + last - arrival_time[lowest] - temp[lowest];
   			turnaround_time = turnaround_time + last - arrival_time[lowest];
  		}
 	}
 	re.a=	average_waiting_time = wait_time / n; 
	re.b= average_turnaround_time = turnaround_time / n;
  return re;
	 }
		
	
	struct second RR(int n,int at[10],int bt[10],int rt[10])
	{
		printf("Round robin process scheduling algorithm is under processing\n");
		struct second ret;
		 int count,j,time,remain=n,flag=0; 
  int wait_time=0,turnaround_time=0; 
for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=2 && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=2; 
      time+=2; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  
  ret.c=wait_time*1.0/n; 
 
  ret.d=turnaround_time*1.0/n;
  return ret;
  
	}
 
 int main()
{
	int i,n;
	float avgwaiting_time,avgturnaround_time;
	printf("\nEnter the Total Number of Processes:\t");
	scanf("%d", &n); 
 int arrival_time[10], burst_time[10],temp[10],rt[10];
	printf("\nEnter Details of %d Processes like Arrival time and burst time\n", n);
	printf("##############################################################################\n");
	
	for(i = 0; i <n; i++)
 	{
		printf("\nEnter Arrival Time %d:\t",i+1);
		scanf("%d", &arrival_time[i]);
		printf("Enter Burst Time%d:\t",i+1);
		scanf("%d", &burst_time[i]); 
		temp[i] = burst_time[i];
		rt[i]=burst_time[i]; 
	}
	struct first n2;
	 struct second n1;
 n2=SRTF(n,arrival_time, burst_time,temp);
 n1= RR(n, arrival_time, burst_time,rt);
avgwaiting_time=n2.a+n1.c;
 avgturnaround_time=n2.b+n1.d;
 printf("##############################################################################\n");
  printf("Avg Turnaround Time = %f", avgwaiting_time); 
 printf("\nAverage Waiting Time= %f\n",avgturnaround_time);
 }

