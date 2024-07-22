#include<iostream>
using namespace std;
struct node
{
    int info;
    node *next;
    node(int d)
    {
        this->info=d;
        this->next=nullptr;
    }
};
class linkedlist
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
        }
    }
    void deleteElement(int key)
    {
        node *p=start;
        node *q=nullptr;
        while(p!=nullptr && p->info!=key)
        {
            q=p;
            p=p->next;
        }
        if(p==nullptr)
        {
            return;
        }
        else if(p->info==key)
        {
            if(q==nullptr)
            {
                start=p->next;
            }
            else
            {
                q->next=p->next;
            }
            deleteElement(key);
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
};
int main()
{
    linkedlist ll;
    int num,e,key;
    cout<<"Enter number of elements to be inserted : ";
    cin>>num;
    cout<<"Enter values : ";
    for(int i=0;i<num;i++)
    {
        cin>>e;
        ll.insert(e);
    }
    cout<<"Elements before deletion : ";
    ll.display();
    cout<<"Enter value of key : ";
    cin>>key;
    ll.deleteElement(key);
    cout<<"Elements after deleting key : ";
    ll.display();
    return 0;
}