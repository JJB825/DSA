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
    node *sorted; //denotes first element in sorted list
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
    void insertinSorted(node *ptr)
    {
        if (sorted==nullptr || sorted->info>=ptr->info)
        {
            ptr->next=sorted;
            sorted=ptr;
        }
        else
        {
            node *curr=sorted;
            while (curr->next!=nullptr && curr->next->info<ptr->info)
            {
                curr=curr->next;
            }
            ptr->next=curr->next;
            curr->next=ptr;
        }    
        start=sorted;    
    }
    void deleteinSorted(int key)
    {
        node *temp=start;
        while (temp->next!=nullptr && temp->next->info!=key)
        {
            temp=temp->next;
        }
        if (!temp->next)
        {
            cout<<"Element not found\n";
            return;
        }
        temp->next=temp->next->next;
    }
    void deleteKthlastElement(int k)
    {
        int length=0;
        node *temp=start;
        while (temp!=nullptr)
        {
            length++;
            temp=temp->next;
        }
        if (k>length)
        {
            cout<<"Linked List doesn't have "<<k<<" nodes"<<endl;
            return;
        }
        temp=start;
        for (int i = 1; i <= length-k-1; i++)
        {
            temp=temp->next;
        }
        if (temp==start)
        {
            start=temp->next;
        }
        else
        {
            temp->next=temp->next->next;
        }
    }
    void insertionSort()
    {
        sorted=nullptr;
        node *temp=start;
        if (temp==nullptr)
        {
            return;
        }
        while (temp!=nullptr)
        {
            node *next=temp->next;
            insertinSorted(temp);
            temp=next;
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
    cout<<"Linked List before sorting : ";
    ll.display();
    ll.insertionSort();
    cout<<"Linked List after sorting : ";
    ll.display();
    cout<<"Enter element to be inserted : ";
    cin>>key;
    node *ptr=new node(key);
    ll.insertinSorted(ptr);
    cout<<"Linked List after inserting new element : ";
    ll.display();
    cout<<"Enter element to be deleted : ";
    cin>>key;
    ll.deleteinSorted(key);
    cout<<"Linked List after deleting element : ";
    ll.display();
    cout<<"Enter value of k : ";
    cin>>key;
    ll.deleteKthlastElement(key);
    cout<<"Linked List after deleting element : ";
    ll.display();
    return 0;
}