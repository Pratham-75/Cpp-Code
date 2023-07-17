#include <iostream>
using namespace std;

int BinarySearch(int arr[], int left, int right, int element) 
{ 
     while (left <= right) 
    { 
        int middle = (left + right) / 2; 
        if (arr[middle] == element) 
            return middle; 

        if (arr[middle] < element) 
            left = middle + 1; 

        else
            right = middle - 1; 
    } 

    return -1; 
}
int main()
{
    cout<<"Enter the total no. of elements in array: ";
    int n, arr[n];
    cin>>n;
    cout<<"Enter the elements: of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int element;
    cout<<"enter the element want to search: "<<endl;
    cin>>element;

    int result = BinarySearch(arr, 0, n - 1, element); 
    if(result == -1)
        cout<<"Element is not present in array";
    else
        cout<<"Element is present at index "<< result+1;
    return 0;
}