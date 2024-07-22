#include<iostream>
using namespace std;
template <class T>
class queue
{
    int rear=-1,front=-1;
    T arr[100];
    public:
    bool isempty()
    {
        return ((front==-1 && rear==-1) || (front>rear))? true:false;
    }
    bool isfull()
    {
        return (rear==99)? true:false;
    }
    void insert_element(T n)
    {
        if(isfull())
        {
            cout<<"Queue is full.\n";
            return;
        }
        else
        {
            arr[++rear]=n;
        }
        if(rear==0)
        {
            front=0;
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
            return arr[front++];
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
            return arr[front];
        }
    }
};
int main()
{
    queue <int>q;
    int num,e,i=1;
    cout<<"Enter number of elements to be inserted : ";
    cin>>num;
    cout<<"Enter elements one by one : \n";
    while(i<=num)
    {
        cin>>e;
        q.insert_element(e);
        i++;
    }
    cout<<"The entered elements are : ";
    while(!q.isempty())
    {
        cout<<q.delete_element()<<" ";
    }
    cout<<endl;
    return 0;
}