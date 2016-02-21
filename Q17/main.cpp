#include <iostream>
#include <cstdlib>

using namespace std;

class DLinkedList
{
private:
    struct Node
    {
        int data;
        Node *next,*prev;
    };
    Node *start, *end;
public:
    DLinkedList()
    {
        start = NULL;
        end = NULL;
    }
    void insert(int x,int p = 0)    //Inserts at the beginning
    {
        Node *t = new Node();
        t->data = x;
        t->next = NULL;
        t->prev = NULL;
        Node *temp = start;
        if(start == NULL)
        {
            start = t;
            end = t;
        }
        else if(length() < p)
            cout<<"\n\n Exception: index of insertion invalid \n\n";
        else
        {
            while(p--)
                temp = temp->next;
            t->prev = temp->prev;
            if(temp->prev != NULL)
                temp->prev->next = t;
            t->next = temp;
            temp->prev = t;
            start = t;
        }
    }
    void display()
    {
        Node *t = start;
        while(t != NULL)
        {
            if(t != NULL)
            {
                cout<<t->data<<"<=>";
                t = t->next;
            }
        }
        cout<<"!!!\n";
    }
    int length()
    {
        Node *t = start;
        int c = 1;
        if(start != NULL)
        {
            while(t->next != NULL)
            {
                c++;
                t = t->next;
            }
        }
        if(start == NULL)
            return 0;
        return c;
    }
};

int main()
{
    DLinkedList l;
    l.insert(1);
    l.display();
    l.insert(2);
    l.display();
    l.insert(3);
    l.insert(4);
    l.display();
    cout<<l.length()<<endl;
    return 0;
}
