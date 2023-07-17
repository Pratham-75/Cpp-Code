// Problem12: Implement Tower of Hanoi Problem using Stack.
#include<bits/stdc++.h>
using namespace std;
void tower(int n,char start,char end,char mid){
 if(n==1)
 {
 cout<<"the disk 1 move from "<<start<<" to "<<end<<endl;
 return ;
 }
 tower(n-1,start,mid,end);
 cout<<"the disk " <<n<< " move from "<<start<<" to "<<end<<" "<<endl;
 tower(n-1,mid,end,start);

}
int main(){
 int n;
 cin>>n;
 tower(n,'A','C','B');
 return 0;
}