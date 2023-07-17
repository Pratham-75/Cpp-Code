#include<iostream>
using namespace std;


int main() {
    int n, arr[n], i;
    cout<<"Enter the total no. of elements in array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for( i=0; i<n; i++) {
        cin>>arr[i];
    }

    int m, count=0; 
    cout<<"enter the element want to search: "<<endl;
    cin>>m;
    for( i=0; i<n; i++) {
        if(m==arr[i]) {
                count = 1;
                break;
        }
    }
    if(count==1) {
            cout<<m<<endl;
            cout<<"Element is present in the array at position: "<<i+1;
    }
    else {
        cout<<"element is not present in the array";
    }
    return 0;
}
