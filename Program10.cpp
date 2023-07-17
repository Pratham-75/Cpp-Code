// To implement FCFS Page replacement algorithm
// optimal page replacement
#include<bits/stdc++.h>
using namespace std;
int fsize;
int frm[15];
void display();
int main()
{
 int pg[100],nPage,i,j,pf=0,top=-1,temp,flag=0;

 cout<<"\n Enter frame size:";
 cin>>fsize;
 cout<<"\n Enter number of pages:";
 cin>>nPage;

 for(i=0;i< nPage;i++)
 {
  cout<<"\n Enter page"<<i+1<<": ";
  cin>>pg[i];
 }
   for(i=0;i< fsize;i++)
    frm[i]=-1;
cout<<"\n page | \t Frame content ";
cout<<"\n--------------------------------------";
for(j=0;j< nPage;j++)
{
 flag=0;
  for(i=0;i< fsize;i++)
  {
   if(frm[i]==pg[j])
   {
    flag=1;
    break;
   }
  }


  if(flag==0)
  {
   if(top==fsize-1)
   {
    top=-1;
   }
   pf++;
   top++;
   frm[top]=pg[j];
  }
 cout<<"\n "<<pg[j];
 display();
}
  cout<<"\n--------------------------------------";
 cout<<"\n total page fault: "<<pf<< " :";
}
void display()
{
 int i;
 for(i=0;i< fsize;i++)
  cout<<"\t" <<frm[i];
}
