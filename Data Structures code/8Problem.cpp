//Problem 8: Write a program to find the minimum element of the stack in constant time without using extra space.
#include <iostream>
using namespace std;
#define size 100
class stack
{
    public:
    int top;
    int *arr;
    stack()
    {
        arr = new int[size];
        top = -1;
    }
    void push(int n)
    {
        if (top == size - 1)
            cout << "Stack overflow\n";
        else
        {
            if (top == -1)
            {
            top++;
            arr[top] = n;
            }
        else
        {
            top++;
            arr[top] = n;
            if (arr[top - 1] < arr[top])
            {
            int temp = arr[top - 1];
            arr[top - 1] = arr[top];
            arr[top] = temp;
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
    void smallstack()
    {
        cout << "\nsmallest element in the stack is " << arr[top]<<"\n\n";
    }
};
    int main()
    {
        stack ptr;
        ptr.push(4);
        ptr.push(9);
        ptr.push(6);
        ptr.push(3);
        ptr.push(8);
        ptr.push(7);
        ptr.smallstack();
    return 0;
}