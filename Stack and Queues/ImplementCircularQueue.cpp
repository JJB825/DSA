#include<iostream>
using namespace std;
#define MAX 5
template <class T>
class queue
{
    int rear=-1,front=-1;
    T arr[MAX];
    public:
    bool isempty()
    {
        return ((front==-1 && rear==-1))? true : false;
    }
    bool isfull()
    {
        return ((rear+1)%MAX==front)? true:false;
    }
    void enqueue(T n)
    {
        if(isempty())
        {
            rear=front=0;
            arr[rear]=n;
        }
        else if(isfull())
        {
            cout<<"Queue is full.\n";
            return;
        }
        else
        {
            rear=(rear+1)%MAX;
            arr[rear]=n;
        }
    }
    void dequeue()
    {
        if(isempty())
        {
            cout<<"Queue is empty.\n";
        }
        else if(front==rear)
        {
            cout<<arr[front];
            front=rear=-1;
        }
        else
        {
            cout<<arr[front];
            front=(front+1)%MAX;
        }
    }
    void peek()
    {
        if(isempty())
        {
            cout<<"Queue is empty.\n";
        }
        else
        {
            cout<<arr[front];
        }
    }
};
int main()
{
    queue <int>q;
    int num,e,i=1;
    cout<<"Enter number of elements to be inserted : ";
    cin>>num;
    cout<<"Enter elements one by one : ";
    while(i<=num)
    {
        cin>>e;
        q.enqueue(e);
        i++;
    }
    cout<<"The entered elements are : ";
    while(!q.isempty())
    {
        q.dequeue();
        cout<<" ";
    }
    cout<<endl;
    return 0;
}