#include<iostream>
#define MAX 100
using namespace std;
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
int main()
{
    stack <int>s;
    int num,e,i=1;
    cout<<"Enter number of elements to be pushed : ";
    cin>>num;
    cout<<"Enter elements one by one : \n";
    while (i<=num)
    {
        cin>>e;
        s.push(e);
        i++;
    }
    cout<<"The entered elements are : ";
    while (!s.isempty())
    {
        cout<<s.pop()<<" ";
    }
    cout<<endl;
    return 0;
}