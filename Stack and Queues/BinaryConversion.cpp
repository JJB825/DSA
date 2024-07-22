#include<iostream>
using namespace std;
template <class T>
class stack
{
    int top=-1;
    T arr[100];
    public:
    bool isempty()
    {
        return (top==-1)? true:false;
    }
    bool isfull()
    {
        return (top==99)? true:false;
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
    int num;
    cout<<"Enter a decimal number : ";
    cin>>num;
    while(num!=0)
    {
        s.push(num%2);
        num/=2;
    }
    cout<<"The corresponding binary number is : ";
    while(!s.isempty())
    {
        cout<<s.pop();
    }
    cout<<endl;
    return 0;
} 