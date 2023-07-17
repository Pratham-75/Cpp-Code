// // Problem 9: Write a program to implement Queue Data structure.
// #include <iostream>
// using namespace std;
// int queue[100], n = 100, front = - 1, rear = - 1;
// void Insert() {
//    int val;
//    if (rear == n - 1)
//    cout<<"Queue Overflow"<<endl;
//    else {
//       if (front == - 1)
//       front = 0;
//       cout<<"Insert the element in queue : "<<endl;
//       cin>>val;
//       rear++;
//       queue[rear] = val;
//    }
// }
// void Delete() {
//    if (front == - 1 || front > rear) {
//       cout<<"Queue Underflow ";
//       return ;
//    } else {
//       cout<<"Element deleted from queue is : "<< queue[front] <<endl;
//       front++;;
//    }
// }
// void Display() {
//    if (front == - 1)
//    cout<<"Queue is empty"<<endl;
//    else {
//       cout<<"Queue elements are : ";
//       for (int i = front; i <= rear; i++)
//       cout<<queue[i]<<" ";
//          cout<<endl;
//    }
// }
// int main() {
//    int ch;
//    cout<<"1) Insert element to queue"<<endl;
//    cout<<"2) Delete element from queue"<<endl;
//    cout<<"3) Display all the elements of queue"<<endl;
//    cout<<"4) Exit"<<endl;
//    do {
//       cout<<"Enter your choice : "<<endl;
//       cin>>ch;
//       switch (ch) {
//          case 1: Insert();
//          break;
//          case 2: Delete();
//          break;
//          case 3: Display();
//          break;
//          case 4: cout<<"Exit"<<endl;
//          break;
//          default: cout<<"Invalid choice"<<endl;
//       }
//    } while(ch!=4);
//    return 0;
// }


// Problem 9: Write a program to implement Queue Data structure.
// Queue implementation using array.

#include<iostream>
using namespace std;

#define CAPACITY 100

int queue[CAPACITY];
unsigned int size  = 0;
unsigned int rear  = CAPACITY - 1;   
unsigned int front = 0;

int enqueue(int data);
int dequeue();
int isFull();
int isEmpty();
int getRear();
int getFront();

int main()
{
    int ch, data;

    while (1)
    {
        
        cout<<"  QUEUE ARRAY IMPLEMENTATION PROGRAM  \n";
   
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Size\n";
        cout<<"4. Get Rear\n";
        cout<<"5. Get Front\n";
        cout<<"0. Exit\n";
    
        cout<<"Select an option: ";

        cin>>ch;

        switch (ch)
        {
            case 1:
                cout<<"\nEnter data to enqueue: ";
                cin>>data;

                if (enqueue(data))
                    cout<<"Element added to queue.";
                else
                    cout<<"Queue is full.";

                break;

            case 2:
                data = dequeue();

                if (data == INT_MIN)
                    cout<<"Queue is empty.";
                else
                    cout<<"Data => "<<data;

                break;

            case 3: 

                if (isEmpty())
                    cout<<"Queue is empty.";
                else 
                    cout<<"Queue size => "<< size;

                break;

            case 4: 

                if (isEmpty())
                    cout<<"Queue is empty.";
                else 
                    cout<<"Rear => "<< getRear();

                break;

            case 5: 

                if (isEmpty())
                    cout<<"Queue is empty.";
                else 
                    cout<<"Front => "<< getFront();

                break;

            case 0:
                cout<<"Exiting from app.\n";
                exit(0);
        
            default:
                cout<<"Invalid choice, please input number between (0-5).";
                break;
        }

        cout<<"\n\n";
    }
}

int enqueue(int data)
{
    if (isFull()) 
    {
        return 0;
    }

    rear = (rear + 1) % CAPACITY;

    size++;

    queue[rear] = data;

    return 1;
}

int dequeue()
{
    int data = INT_MIN;

    if (isEmpty())
    {
        return INT_MIN;
    }

    data = queue[front];

    front = (front + 1) % CAPACITY;

    size--;

    return data;
}

int isFull()
{
    return (size == CAPACITY);
}
int isEmpty()
{
    return (size == 0);
}
int getFront()
{
    return (isEmpty())
            ? INT_MIN
            : queue[front];
}
int getRear()
{
    return (isEmpty())
            ? INT_MIN
            : queue[rear];
}