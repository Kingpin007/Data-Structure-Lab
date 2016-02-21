#include <iostream>

using namespace std;

class Queue
{
private:
    struct Node
    {
        int data;
        Node* next;
    };
    Node *front,*end,*tmp;
public:
    Queue()
    {
        front=end=NULL;
    }
    void enqueue(int x)
    {
        tmp = new Node();
        tmp->data = x;
        tmp->next = end;
        end = tmp;
    }
    void deque()
    {
      tmp = end;
      end = end->next;
      delete tmp;
    }
    void display()
    {
      cout<<"\nThe queue from end to front is: \n";
      tmp = end;
      while(tmp!=NULL)
      {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
      }
      cout<<"--Wrap Around--";
    }
};

int main()
{
    Queue l;
    l.enqueue(1);
    l.display();
    l.enqueue(2);
    l.display();
    l.enqueue(3);
    l.display();
    l.deque();
    l.display();
    l.deque();
    l.display();
    return 0;
}
