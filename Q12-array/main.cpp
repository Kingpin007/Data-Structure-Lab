#include <iostream>
#include <cstdlib>

using namespace std;

class Queue
{
    int q[1000][2];    //Create 1000 element q
    int front,end;
public:
    Queue()
    {
        front = end = 0;
    }
    void enqueue(int x,int p=0)
    {
        if(end < 1000)
        {
            int pos=end;
            for(int i=0;i<end;i++)
            {
                if(q[i][1]<p)
                {
                    pos = i;
                    break;
                }
            }
            end++;
            for(int i=end;i>=pos;i--)
            {
                q[i][0]=q[i-1][0];
                q[i][1]=q[i-1][1];
            }
            q[pos][0]=x;
            q[pos][1]=p;
        }
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
            cout<<q[i][0]<<" ";
        cout<<endl<<"This is the queue from front to end\n";
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.display();
    q.enqueue(2);
    q.display();
    q.enqueue(5,1);
    q.display();
    q.enqueue(3,2);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
