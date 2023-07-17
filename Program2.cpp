//implementation of non-preemptive shortest job first
#include<bits/stdc++.h>
using namespace std;

int main()
{
   int time,bt[10],at[10],sum_bt=0,smallest,n,i;
   int sumt=0,sumw=0;
   cout << "No. of Processes: ";
   cin >> n;

   for(i=0;i<n;i++)
   {
      cout<< "arrival time for process P"<<i+1<<": ";
      cin>>at[i];
      cout<< "burst time for process P"<<i+1<<": ";
      cin>>bt[i];
      sum_bt+=bt[i];
   }
   bt[9]=9999;
   for(time=0;time<sum_bt;)
   {
      smallest=9;
      for(i=0;i<n;i++)
      {
         if(at[i]<=time && bt[i]>0 && bt[i]<bt[smallest])
         smallest=i;
      }
         cout<< "P"<<smallest+1<<"\t"<<bt[smallest]<<"\t"<<time+bt[smallest]-at[smallest]<<"\t"<<time-at[smallest]<<endl;
         sumt+=time+bt[smallest]-at[smallest];
         sumw+=time-at[smallest];
         time+=bt[smallest];
         bt[smallest]=0;
   }
   cout<< "\n average waiting time = "<<sumw*1.0/n;
   cout<< "\n average turnaround time = "<<sumt*1.0/n;
   return 0;
}
