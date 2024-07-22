#include<iostream>
using namespace std;
struct node
{
    int info,pr;
    node *next;
    node(int d,int p)
    {
        this->info=d;
        this->pr=p;
        this->next=nullptr;
    }
};
class llpq
{
    public:
    node *start=nullptr;
    void insert(int val,int p)
    {
        node *ptr=new node(val,p);
        if(start==nullptr)
        {
            start=ptr;
        }
        else
        {
            node *temp=start;
            node *temp2=nullptr;
            while(temp!=nullptr && ptr->pr>temp->pr)
            {
                temp2=temp;
                temp=temp->next;
            }
            if(temp==nullptr)
            {
                temp2->next=ptr;
            }
            else if(temp2==nullptr)
            {
                if(ptr->info>temp->info)
                {
                    ptr->next=temp->next;
                    temp->next=ptr;
                }
                else
                {
                    ptr->next=temp;
                    start=ptr;
                }
            }
            else if(ptr->pr<temp->pr)
            {
                ptr->next=temp2->next;
                temp2->next=ptr;
            }
            else if(ptr->pr==temp->pr)
            {
                if(ptr->info<=temp->info)
                {
                    ptr->next=temp2->next;
                    temp2->next=ptr;
                }
                else
                {
                    ptr->next=temp->next;
                    temp->next=ptr;
                }
            }
        }
    }
    int extractmin()
    {
        node *temp=start;
        if(temp==nullptr)
        {
            return -1;
        }
        else
        {
            int x=temp->info;
            start=temp->next;
            return x;
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
    llpq lp;
    int num,e,p;
    cout<<"Enter number of elements to be inserted : ";
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cout<<"Enter value : ";
        cin>>e;
        cout<<"Enter priority : ";
        cin>>p;
        lp.insert(e,p);
    }
    cout<<"Elements : ";
    lp.display();
    int minVal = lp.extractmin();
    if(minVal==-1)
    {
        cout<<"Empty priority queue\n";
    }
    else
    {
        cout<<"Element with maximum priority : "<<minVal<<endl;
    }
    cout<<"Elements after deleting min : ";
    lp.display();
    return 0;
}