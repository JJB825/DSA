#include<iostream>
using namespace std;
#define MAX 100
template <class T>
class stack
{
    int top=-1;
    T arr[MAX];
    public:
    bool isempty()
    {
        return (top==-1)? true:false;
    }
    bool isfull()
    {
        return (top==MAX-1)? true:false;
    }
    void push(T n)
    {
        if(isfull())
        {
            cout<<"Stack Overflow.\n";
            return;
        }
        else
        {
            arr[++top]=n;
        }
    }
    T pop()
    {
        if(isempty())
        {
            cout<<"Stack Underflow.\n";
            return T();
        }
        else
        {
            return arr[top--];
        }
    }
    T peek()
    {
        if(isempty())
        {
            cout<<"Stack Underflow.\n";
            return T();
        }
        else
        {
            return arr[top];
        }
    }
};
template <class T> 
class queue
{
    stack <T>s1;
    stack <T>s2;
    public:
    bool isempty()
    {
        return (s1.isempty() && s2.isempty())? true:false;
    }
    bool isfull()
    {
        return (s1.isfull())? true:false;
    }
    void insert_element(T e)
    {
        if(isfull())
        {
            cout<<"Queue is full.\n";
        }
        else
        {
            s1.push(e);
        }
    }
    T delete_element()
    {
        if(isempty())
        {
            cout<<"Queue is empty.\n";
            return T();
        }
        else 
        {
            while (!s1.isempty())
            {
                s2.push(s1.pop());
            }
            T x = s2.pop();
            while (!s2.isempty())
            {
                s1.push(s2.pop());
            }
            return x;
        }
    }
    T peek()
    {
        if(isempty())
        {
            cout<<"Queue is empty.\n";
            return T();
        }
        else 
        {
            while (!s1.isempty())
            {
                s2.push(s1.pop());
            }
            T x = s2.peek();
            while (!s2.isempty())
            {
                s1.push(s2.pop());
            }
            return x;
        }
    }
};
int main()
{
    queue <int>q;
    int choice,num,e,i=1;
    while(true)
    {
        cout<<"Choose any one : \n1. Check Empty\n2. Check Full\n3. Insertion\n4. Display\n5. Exit\nEnter choice code : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                (q.isempty())? cout<<"Queue is empty\n" : cout<<"Queue is not empty\n";
                continue;
            case 2:
                (q.isfull())? cout<<"Queue is full\n" : cout<<"Queue is not full\n";
                continue;
            case 3:
                i=1;
                cout<<"Enter number of elements to be inserted : ";
                cin>>num;
                cout<<"Enter elements one by one : \n";
                while(i<=num)
                {
                    cin>>e;
                    q.insert_element(e);
                    i++;
                }
                continue;
            case 4:
                cout<<"Queue elements : ";
                while(!q.isempty())
                {
                    cout<<q.delete_element()<<" ";
                }
                cout<<endl;
                continue;
            case 5:
                cout<<"Do you wish to continue ? (y/n) : ";
                char ch;
                cin>>ch;
                if(ch=='y')
                {
                    continue;
                }
                else
                {
                    cout<<"Thank you\n";
                    break;
                } 
            default:
                cout<<"Invalid Choice\n";
        }
        break;
    }
    return 0;
}