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
        if(end==999&&front>0)    //Wrap around possible
            end = 0;
        else if((end==front&&end!=0)||end==999)
        {
            cout<<"Queue is full!\n";
            return;
        }
        else
        {
            q[end++] = x;
            return;
        }
        q[end++]=x;
    }
    void dequeue()
    {
        if(front<=999 && end<front)
        {
            front++;
            if(front==1000)
                front=0;
        }
        else if(front<end)
        {
            front++;
        }
        else
            cout<<"Error! Queue Empty!";
    }
    void display()
    {
        if(front<end)
        {
            cout<<endl;
            for(int i=front;i<end;i++)
                cout<<q[i]<<" ";
            cout<<endl<<"This is the queue from front to end\n";
        }
        else if(end<front)
        {
        cout<<endl;
        for(int i=front;i<999;i++)
            cout<<q[i]<<" ";
        cout<<"--Wrap around--";
        for(int i=0;i<end;i++)
            cout<<q[i]<<" ";
        cout<<endl<<"This is the queue from front to end\n";
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    for(int i=4;i<1000;i++)
        q.enqueue(i);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.enqueue(9999);
    q.display();
    return 0;
}
