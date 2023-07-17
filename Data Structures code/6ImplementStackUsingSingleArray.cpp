#include <iostream>
using namespace std;
#define SIZE 10 
 
int ar[SIZE];
int top1 = -1;
int top2 = SIZE;
 
//Functions to push data
void push_stack1 (int data)
{
  if (top1 < top2 - 1)
  {
    ar[++top1] = data;
  }
  else
  {
   cout<<"Stack Full! Cannot Push\n";
  }
}
void push_stack2 (int data)
{
  if (top1 < top2 - 1)
  {
    ar[--top2] = data; 
  }
  else
  {
   cout<<"Stack Full! Cannot Push\n";
  }
}
 
//Functions to pop data
void pop_stack1 ()
{
  if (top1 >= 0)
  {
    int popped_value = ar[top1--];
    cout<<popped_value<< " is being popped from Stack 1\n";
  }
  else
  {
    cout<<"Stack Empty! Cannot Pop\n";
  }
}
void pop_stack2 ()
{
  if (top2 < SIZE)
  {
    int popped_value = ar[top2++];
    cout<<popped_value<<" is being popped from Stack 2\n";
  }
  else
  {
    cout<<"Stack Empty! Cannot Pop\n";
  }
}
 
//Functions to Print Stack 1 and Stack 2
void print_stack1 ()
{
  int i;
  for (i = top1; i >= 0; --i)
  {
    cout<<ar[i];
  }
  cout<<"\n";
}
void print_stack2 ()
{
  int i;
  for (i = top2; i < SIZE; ++i)
  {
    cout<< ar[i];
  }
  cout<<endl;
}
 
int main()
{
  int ar[SIZE];
  int i;
  int num_of_ele;
 
  cout<<"We can push a total of 10 values\n";
 
  for (i = 1; i <= 6; ++i)
  {
    push_stack1 (i);
    cout<<"Value Pushed in Stack 1 is "<< i<<endl;
  }
  for (i = 1; i <= 4; ++i)
  {
    push_stack2 (i);
    cout<<"Value Pushed in Stack 2 is "<< i<<endl;
  }
 
  //Print Both Stacks
  print_stack1 ();
  print_stack2 ();
 
  //Pushing on Stack Full
  cout<<"Pushing Value in Stack 1 is "<<11<<endl;
  push_stack1 (11);
 
  //Popping All Elements From Stack 1
  num_of_ele = top1 + 1;
  while (num_of_ele)
  {
    pop_stack1 ();
    --num_of_ele;
  }
 
  //Trying to Pop From Empty Stack
  pop_stack1 ();
 
  return 0;
}