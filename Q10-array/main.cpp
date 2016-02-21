#include <iostream>

using namespace std;

class Queue
{
    int q[1000];    //Create 1000 element q
    int front,end;
public:
    Queue()
    {
        front = end = 0;
    }
    void enqueue(int x)
    {
        if(end < 1000)
            q[end++] = x;
        else
            cout<<"Error! Cannot insert element "<<x<<" at "<<end<<"\nQueue is full!\n";
    }
    void dequeue()
    {
        if(front<=end)
            front++;
        else
            cout<<"Error! Cannot Delete element Queue is Empty!\n";
    }
    void display()
    {
        cout<<endl;
        for(int i=front;i<end;i++)
            cout<<q[i]<<" ";
        cout<<endl<<"This is the queue from front to end\n";
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
