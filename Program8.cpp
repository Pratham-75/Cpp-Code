// Earliest Deadline First
#include <bits/stdc++.h>
using namespace std;
int main (){
    vector<int> p_time;
    vector<int> period;
    for (int i = 0; i < 2; i++){
        cout << "Process time of " << i+1 << " process:";
        int a;
        cin >> a;
        p_time.push_back (a);
        cout << "period of " << i+1 << " process:";
        int b;
        cin >> b;
        period.push_back (b);
    }
    vector<int> d1;
    vector<int> d2;
    int i = 1;
    while (period[0]*i <= 200){
        d1.push_back (period[0]*i);
        i++;
    }
    i = 1;
    while (period[1]*i <= 200){
    d2.push_back (period[1]*i);
    i++;
    }
    vector<bool> visited1 (d1.size (),false);
    vector<bool> visited2 (d2.size (),false);
    int curr = 0;
    int ptr1 = 0, ptr2 = 0;
    int v1 = 0, v2 = 0;
    int t1 = 0, t2 = 0;
    while (curr <= 200 && ptr1 != d1.size () && ptr2 != d2.size
    ()){
    if (d1[ptr1] <= d2[ptr2] && visited1[v1] == false){
        if (t1 == 0){
        cout << "Executing Process 1: " << curr << " to " <<
        curr+min(p_time[0],d2[ptr2]-curr) << endl;
        curr = curr+min(p_time[0],d2[ptr2]-curr);
    }
    else{
        cout << "Executing Process 1: " << curr << " to " << curr+t1 <<
        endl;
        curr = curr+t1;
        t1 = 0;
    }
    visited1[v1] = true;
    ptr1++;
    }
    else if (d2[ptr2] < d1[ptr1] && visited2[v2] == false){
    if (t2 == 0){
        cout << "Executing Process 2: " << curr << " to " <<
        curr+min(p_time[1],d1[ptr1]-curr) << endl;
        curr += min(p_time[1],d1[ptr1]-curr);
    }
    else{
        cout << "Executing Process 2: " << curr << " to " << curr+t2 <<
        endl;
        curr = curr + t2;
        t2 = 0;
    }
    visited2[v2] = true;
    ptr2++;
    }
    else if (curr < d1[ptr1-1] && visited1 [v1]){
        cout << "Executing Process 2: " << curr << " to " <<
        curr+min(p_time[1],d1[ptr1-1]-curr) << endl;
        t2 = p_time[1]-min(p_time[1],d1[ptr1-1]-curr);
        curr += min(p_time[1],d1[ptr1-1]-curr);
        visited2[v2] = true;
    }
    else if (curr < d2[ptr2-1] && visited2[v2]){
        cout << "Executing Process 1: " << curr << " to " <<
        curr+min(p_time[0],d2[ptr2-1]-curr) << endl;
        t1 = p_time[0]-min(p_time[0],d1[ptr2-1]-curr);
        curr = curr+min(p_time[0],d2[ptr2-1]-curr);
        visited1[v1] = true;
        }
    else {
        curr++;
    }
    if (curr >= d1[ptr1-1])
        v1++;
    if (curr >= d2[ptr2-1])
    v2++;
    }
}