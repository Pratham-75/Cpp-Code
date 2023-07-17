#include <iostream>
using namespace std;
  
int* insertX(int n, int arr[], int x, int pos)
{
    int i;

    n++;
  
    for (i = n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = x;
  
    return arr;
}
  
int main()
{
    int arr[50] = { 0 };
    int i, x, pos, n;
    cout<<"Enter the total elements of the array: ";
    cin>>n;
    
    cout<<"Enter the elements of the array: ";
    for (i = 0; i < n; i++)
        cin>>arr[i];
  
    cout<<"Original Array: ";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
  
    cout<<"Enter the element want to be inserted: ";
    cin>>x;

    cout<<"Enter the position of the entered array: ";
    cin>>pos;

    insertX(n, arr, x, pos);
  
    cout<<"Updated array: ";
    for (i = 0; i < n + 1; i++)
        cout << arr[i] << " ";
    cout << endl;
  
    return 0;
}
// #include<iostream>
// using namespace std;

// int* insert_element(int n, int arr[], int x, int pos)
// {
//     int i;
  
//     n++;
  
//     // shift elements forward
//     for (i = n; i >= pos; i--)
//         arr[i] = arr[i - 1];
  
//     // insert x at pos
//     arr[pos - 1] = x;
  
//     return arr;
// }
// int main() {
//     int n, arr[n], x, pos, i;
//     cout<<"Enter the total number of elements: ";
//     cin>>n;

//     for (i = 0; i < n; i++)
//     {
//         cin>>arr[i];
//     }
//     cout<<"Original array: ";
//     for(i=0; i<n; i++) {
//     cout<<arr[i]<<" ";
//     }

//     cout<<"Enter the element want to insert: ";
//     cin>>x;

//     cout<<"\nEnter the position of entered element: ";
//     cin>>pos;

//     cout<<"Updated array: ";
//     insert_element(n, arr, x, pos);
//     for (i = 0; i < n + 1; i++) {
//             cout << arr[i] << " ";
//             cout << endl;
//     }
//     return 0;
// }