#include<bits/stdc++.h>
using namespace std;
bool palindromechk(string str){
 deque<char>dq;
 for(int i=0; i<str.size(); i++){
 dq.push_back(str[i]);
 }
 for(int i=0; i<str.size()/2; i++){
 if(dq.front()!=dq.back()){
 return false;
 }
 dq.pop_front();
 dq.pop_back();
 }
 return true;
}
int main(){
string str;
cin >> str;
if(palindromechk(str))
cout<<"the string is palindrome "<<endl;
else
cout<<"the string is not palindrome"<<endl;
 return 0;
}