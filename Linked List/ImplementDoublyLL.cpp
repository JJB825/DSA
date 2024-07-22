#include<iostream>
using namespace std;
struct node
{
    int info;
    node *next, *prev;
    node(int d)
    {
        this->info=d;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
class doublylinkedlist
{
    public:
    node *start=nullptr;
    void insert(int val)
    {
        node *ptr=new node(val);
        if(start==nullptr)
        {
            start=ptr;
        }
        else
        {
            node *temp=start;
            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->prev=temp;
        }
    }
    void display()
    {
        node *temp=start;
        while(temp!=nullptr)
        {
            cout<<temp->info<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void displayRev()
    {
        node *temp=start;
        while (temp->next!=nullptr)
        {
            temp=temp->next;
        }
        while (temp!=nullptr)
        {
            cout<<temp->info<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }
};
int main()
{
    doublylinkedlist dll;
    int num,e;
    cout<<"Enter number of elements to be inserted : ";
    cin>>num;
    cout<<"Enter values : ";
    for(int i=0;i<num;i++)
    {
        cin>>e;
        dll.insert(e);
    }
    cout<<"Elements (in serial order) : ";
    dll.display();
    cout<<"Elements (in reverse order) : ";
    dll.displayRev();
    return 0;
}