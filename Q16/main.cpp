#include <iostream>
#include <cstdlib>

using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *start, *end;
public:
    LinkedList()
    {
        start = NULL;
        end = NULL;
    }
    void insert(int x)    //Inserts at the beginning
    {
        Node *t = new Node();
        t->data = x;
        t->next = NULL;
        if(start == NULL)
        {
            start = t;
            end = t;
            t->next = t;
        }
        else
        {
            t->next = start;
            start = t;
            end->next = start;
        }
    }
    void del()       //deletes from the start
    {
        Node *t = start;
        while(t != end)
            t = t->next;
        //We have now iterated till the last node the next one is the same as start
        t->next = start->next;
        Node *d = start;
        start = start->next;
        delete d;
    }
    void display()
    {
        Node *t = start;
        if(start != NULL)
        {
            while(t->next != start)
            {
                cout<<t->data<<"->";
                t = t->next;
            }
        }
        cout<<t->data<<"--wrap around--\n";
    }
    int count()
    {
        Node *t = start;
        int c = 1;
        if(start != NULL)
        {
            while(t->next != start)
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
    LinkedList l;
    l.insert(1);
    l.display();
    l.insert(2);
    l.display();
    l.insert(3);
    l.insert(4);
    l.display();
    cout<<l.count()<<endl;
    l.del();
    cout<<l.count()<<endl;
    return 0;
}
