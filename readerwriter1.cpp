#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

int sharedData = 0;
int readersWaiting = 0;
int writerWaiting = 0;

void reader(int i)
{

        while(readersWaiting)
        {
            ++readersWaiting;
            cout << "reader " << i <<" is reading data" <<endl;
            --writerWaiting;
            i--;
            // while(readersWaiting > 0)
            // {
            //     writer
            // }
        }

}

void writer(int i)
{
    while(writerWaiting)
        cout << "writer " << i <<" is writing data" <<endl;
        --writerWaiting;
    i--;
    while(readersWaiting > 0)
        writerWaiting = false;
}



/* 
    reader function  
    {
        reader wants to read thenn read++;
        s:the read1 {reader,}
    }
    writer fucntion
    {
        writer 

    }
*/
int main()
{
    reader(1);
     reader(2);
      writer(3);
       writer(4);
        writer(5);
}











