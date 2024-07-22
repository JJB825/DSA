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
    stack <int>s1;
    stack <int>s2;
    stack <int>s3;
    int num,e,i=1;
    cout<<"Enter number of digits in number 1 : ";
    cin>>num;
    cout<<"Enter number 1 (Separate digits by space) : \n";
    while(i<=num)
    {
        cin>>e;
        s1.push(e);
        i++;
    }
    cout<<"Enter number of digits in number 2 : ";
    cin>>num;
    cout<<"Enter number 2 (Separate digits by space) : \n";
    i=1;
    while(i<=num)
    {
        cin>>e;
        s2.push(e);
        i++;
    }
    int sum,carry=0,res;
    while(!s1.isempty() || !s2.isempty())
    {
        if(s1.isempty())
        {
            res=carry+s2.pop();
        }
        else if(s2.isempty())
        {
            res=carry+s1.pop();
        }
        else
        {
            res=carry+s1.pop()+s2.pop();
        }
        sum=res%10;
        s3.push(sum);
        carry=res/10;
    }
    cout<<"The sum of numbers is : ";
    while(!s3.isempty())
    {
        cout<<s3.pop();
    }
    cout<<endl;
    return 0;
}