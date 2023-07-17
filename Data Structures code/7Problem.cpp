//Problem 7: Write a program to find the minimum element of the stack in constant time with using extra space. 
#include <iostream>
using namespace std;
#define size 100
class stack
{
    public:
        int top;
        int *arr;
        int *arr2;
        int s;
    stack()
        {
        arr = new int[size];
        arr2 = new int[size];
        top = -1;
        s = -1;
        }
    void push(int n)
        {
        if (top == size - 1)
        cout << "Stack overflow\n";
        else
        {
        top++;
        arr[top] = n;
        if (s == -1)
        {
        s++;
        arr2[s] = n;
        }
        else
        {
        if (arr2[s] > arr[top])
        {
        s++;
        arr2[s] = arr2[top];
        }
        } 
        }
        }
    void pop()
        {
        if (top == -1)
        cout << "stack underflow\n";
        else
        top--;
        }
    void show()
        {
        while (top != 0)
            {
        cout << arr[top] << "\n";
        top--;
            }
        }
        void smallstack(){
        cout<<"\nsmallest element in the stack is "<<arr2[s]<<endl<<endl;
    }
};
int main()
{
    stack ptr;
    ptr.push(1);
    ptr.push(2);
    ptr.push(3);
    ptr.push(4);
    ptr.push(5);
    ptr.push(6);
    ptr.smallstack();
 return 0;
}